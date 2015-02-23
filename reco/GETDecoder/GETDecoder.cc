// =================================================
//  GETDecoder Class
// 
//  Author:
//    Genie Jhang ( geniejhang@majimak.com )
//  
//  Log:
//    - 2013. 09. 23
//      Start writing class
// =================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <arpa/inet.h>

#include "TSystem.h"
#include "TObjArray.h"
#include "TObjString.h"
#include "TString.h"

#include "GETDecoder.hh"
#include "GETFrame.hh"
#include "GETPlot.hh"
#include "GETMath.hh"

ClassImp(GETDecoder);

GETDecoder::GETDecoder()
{
  /**
    * If you use this constructor, you have to add the rawdata using
    * AddData() method and set the file with SetData() method, manually.
   **/
   
  Initialize();
}

GETDecoder::GETDecoder(TString filename)
{
  /**
    * Automatically add the rawdata file to the list
    * and set the file to read.
   **/

  Initialize();
  AddData(filename);
  SetData(0);
}

GETDecoder::~GETDecoder()
{
  /*
  if (fFrame != 0)
    delete fFrame;

  if (fGETPlot != 0)
    delete fGETPlot;

  if (fGETMath != 0)
    delete fGETMath;
    */
}

void GETDecoder::Initialize()
{
  fNumTbs = 512;

  fEndianness = 0;
  fMergedUnitBlock = 1;
  fFrameType = -1;
  fMergedHeaderSize = 0;
  fNumMergedFrames = 0;
  fUnitBlock = 1;
  fMergedFrameStartPoint = 0;
  fCurrentMergedFrameSize = 0;
  fCurrentInnerFrameSize = 0;

  fDebugMode = kFALSE;
  fIsAutoReload = kTRUE;
  fIsPositivePolarity = kFALSE;

  fFileSize = 0;
  fCurrentDataID = -1;

  fFrame = 0;
  fCurrentFrameID = -1;
  fCurrentInnerFrameID = -1;
  fEOF = kFALSE;

  fGETMath = 0;
  fGETPlot = 0;
}

void GETDecoder::SetNumTbs(Int_t value)
{
  fNumTbs = value;
}

void GETDecoder::SetDebugMode(Bool_t value)
{
  fDebugMode = value;
}

Bool_t GETDecoder::AddData(TString filename)
{
  /**
    * Check if there is a file named `filename`. If exists, add it to the list.
   **/

  TString nextData = filename;

  TObjArray *pathElements = 0;
  pathElements = nextData.Tokenize("/");

  Int_t numElements = pathElements -> GetLast();

  TString path = "";
  if (numElements == 0)
    path = gSystem -> pwd();
  else {
    if (filename(0, 1) == "/")
      path.Append("/");

    for (Int_t i = 0; i < numElements; i++) {
      path.Append(((TObjString *) pathElements -> At(i)) -> GetString());
      path.Append("/");
    }
  }

  TString tempDataFile = ((TObjString *) pathElements -> Last()) -> GetString();

  nextData = gSystem -> Which(path, tempDataFile);
  if (!nextData.EqualTo("")) {
    std::cout << "== [GETDecoder] Data file found: " << filename << std::endl;

    Bool_t isExist = 0;
    for (Int_t iIdx = 0; iIdx < fDataList.size(); iIdx++) {
      if (fDataList.at(0) == nextData) {
        std::cout << "== [GETDecoder] The file already exists in the list!" << std::endl;
        isExist = 1;
      }
    }

    if (!isExist)
      fDataList.push_back(nextData);
  } else {
    std::cout << "== [GETDecoder] Data file not found: " << filename << std::endl;

    return kFALSE;
  }

  delete pathElements;

  return kTRUE;
}

Bool_t GETDecoder::SetData(Int_t index)
{
  if (index >= fDataList.size()) {
    std::cout << "== [GETDecoder] End of list!" << std::endl;

    return kFALSE;
  }

  if (fData.is_open())
    fData.close();

  fEOF = kFALSE;

  TString filename = fDataList.at(index);

  fData.open(filename.Data(), std::ios::in|std::ios::ate|std::ios::binary);

  if (!(fData.is_open())) {
    std::cout << "== [GETDecoder] GRAW file open error! Check it exists!" << std::endl;

    return kFALSE;
  } else {
    fFileSize = fData.tellg();

    std::cout << "== [GETDecoder] " << filename << " is opened!" << std::endl;
    fData.seekg(0);

    UShort_t metaType = 0;
    UShort_t headerSize = 0;
    UInt_t numMergedFrames = 0;
    fData.read(reinterpret_cast<Char_t *>(&metaType), 1);
    fData.seekg(5);
    fData.read(reinterpret_cast<Char_t *>(&fFrameType), 2);
    fData.seekg(8);
    fData.read(reinterpret_cast<Char_t *>(&headerSize), 2);
    fData.seekg(0);

    /*
      Note:
        In the merged frame data file, merged frame header appears only once
        in front of merged frames.
    */

    fEndianness = ((metaType&0x80) >> 7);
    if (fEndianness == kBig) {// MSB of the first byte determines endianness. 0:Big, 1:Little
      headerSize = htons(headerSize);
      fFrameType = htons(fFrameType);
    }

    if (fFrameType == 0xff01) { // Merged frame by event number
      fFrameType = kMergedID;
      fMergedUnitBlock = pow(2, metaType&0xf);
      fMergedHeaderSize = headerSize*fMergedUnitBlock;
    } else if (fFrameType == 0xff02) { // Merged frame by event time
      fFrameType = kMergedTime;
      fMergedUnitBlock = pow(2, metaType&0xf);
      fMergedHeaderSize = headerSize*fMergedUnitBlock;
    } else { // Normal frame by CoBo
      fFrameType = kNormal;
      fUnitBlock = pow(2, metaType&0xf);
      fMergedHeaderSize = 0;
      fNumMergedFrames = 0;
    }

    std::cout << "== [GETDecoder] Frame Type: ";
    if (fFrameType == kNormal) std::cout << "Normal CoBo frame";
    else if (fFrameType == kMergedID) std::cout << "Event number merged frame";
    else if (fFrameType == kMergedTime) std::cout << "Event time merged frame";
    std::cout << std::endl;

    fCurrentDataID = index;

    fCurrentFrameID = -1;
    fCurrentInnerFrameID = -1;

    return kTRUE;
  }
}

Bool_t GETDecoder::SetNextFile()
{
  return SetData(fCurrentDataID + 1);
}

void GETDecoder::SetNoAutoReload(Bool_t value)
{
  fIsAutoReload = value;
}

void GETDecoder::SetPositivePolarity(Bool_t value)
{
  fIsPositivePolarity = value;
}

void GETDecoder::ShowList()
{
  std::cout << "== [GETDecoder] Index GRAW file" << std::endl;
  for (Int_t iItem = 0; iItem < fDataList.size(); iItem++) {
    if (iItem == fCurrentDataID)
      std::cout << " *" << std::setw(6);
    else
      std::cout << std::setw(8);

    std::cout << iItem << "  " << fDataList.at(iItem) << std::endl;
  }
}

Int_t GETDecoder::GetNumData()
{
  return fDataList.size();
}

TString GETDecoder::GetDataName(Int_t index)
{
  if (index >= fDataList.size()) {
    std::cout << "== [GETDecoder] Size of the list is " << fDataList.size() << "!" << std::endl;

    return TString("No data!");
  }

  return fDataList.at(index);
}

Int_t GETDecoder::GetNumTbs()
{
  return fNumTbs;
}

GETPlot *GETDecoder::GetGETPlot()
{
  if (!fGETPlot)
    fGETPlot = new GETPlot(this);

  return fGETPlot;
}

GETMath *GETDecoder::GetGETMath()
{
  if (!fGETMath)
    fGETMath = new GETMath(this);

  return fGETMath;
}

Int_t GETDecoder::GetFrameType()
{
  return fFrameType;
}

Int_t GETDecoder::GetCurrentFrameID()
{
  return fCurrentFrameID;
}

Int_t GETDecoder::GetCurrentInnerFrameID()
{
  return fCurrentInnerFrameID;
}

GETFrame *GETDecoder::GetFrame(Int_t frameNo)
{
  if (fFrameType != kNormal)
    return GetFrame(frameNo, -1);

  if (frameNo == -1)
    frameNo = fCurrentFrameID + 1;

  if (fCurrentFrameID == frameNo) {
    if (fDebugMode)
      PrintFrameInfo(frameNo, fFrame -> GetEventID(), fFrame -> GetCoboID(), fFrame -> GetAsadID());

    return fFrame;
  } else if (frameNo < -1) {
    std::cout << "== [GETDecoder] Frame number should be a positive integer!" << std::endl;

    return 0;
  }

  while (1) {
    UInt_t frameSize;
    UShort_t headerSize;
    UInt_t nItems;
    UInt_t eventIdx;
    UShort_t coboIdx;
    UShort_t asadIdx;

    // Skip the frames until it reaches the given frame number, frameNo.
    while (frameNo > fCurrentFrameID + 1) {
      if (fDebugMode)
        std::cout << "== [GETDecoder] Skipping Frame No. " << fCurrentFrameID + 1 << std::endl;

      UShort_t metaType = 0;
      fData.read(reinterpret_cast<Char_t *>(&metaType), 1);
      fData.read(reinterpret_cast<Char_t *>(&frameSize), 3);

      fEndianness = ((metaType&0x80) >> 7);
      fUnitBlock = pow(2, metaType&0xf);

      if (fData.eof()) {
        std::cout << "== [GETDecoder] End of the file! (last frame: " << fCurrentFrameID << ")" << std::endl;

        if (fIsAutoReload)
          if (SetNextFile())
            return GetFrame(0);

        return 0;
      }

      if (fEndianness == kBig)
        frameSize = (htonl(frameSize) >> 8);

      frameSize *= fUnitBlock;

      fData.seekg((ULong64_t)fData.tellg() - 4 + frameSize);

      fCurrentFrameID++;
    }

    if (frameNo < fCurrentFrameID) {
      fCurrentFrameID = -1;
      fData.clear();
      fData.seekg(0);

      return GetFrame(frameNo);
    }

    UShort_t metaType = 0;
    UShort_t frameType = 0;
    UShort_t itemSize = 0;
    fData.read(reinterpret_cast<Char_t *>(&metaType), 1);
    fData.read(reinterpret_cast<Char_t *>(&frameSize), 3);
    fData.ignore(1);
    fData.read(reinterpret_cast<Char_t *>(&frameType), 2);
    fData.ignore(1);
    fData.read(reinterpret_cast<Char_t *>(&headerSize), 2);
    fData.read(reinterpret_cast<Char_t *>(&itemSize), 2);
    fData.read(reinterpret_cast<Char_t *>(&nItems), 4);
    fData.ignore(6);
    fData.read(reinterpret_cast<Char_t *>(&eventIdx), 4);
    fData.read(reinterpret_cast<Char_t *>(&coboIdx), 1);
    fData.read(reinterpret_cast<Char_t *>(&asadIdx), 1);

    if (fData.eof()) {
      std::cout << "== [GETDecoder] End of the file! (last frame: " << fCurrentFrameID << ")" << std::endl;

      if (fIsAutoReload)
        if (SetNextFile())
          return GetFrame(0);

      return 0;
    }

    fEndianness = ((metaType&0x80) >> 7);
    fUnitBlock = pow(2, metaType&0xf);
    if (fEndianness == kBig) {
      frameType = htons(frameType);
      frameSize = (htonl(frameSize) >> 8);
      headerSize = htons(headerSize);
      itemSize = htons(itemSize);
      nItems = htonl(nItems);
      eventIdx = htonl(eventIdx);
      coboIdx = (htons(coboIdx) >> 8);
      asadIdx = (htons(asadIdx) >> 8);
    }

    frameSize *= fUnitBlock;
    headerSize *= fUnitBlock;

    if (fDebugMode) {
      PrintFrameInfo(frameNo, eventIdx, coboIdx, asadIdx);
      std::cout << "  frameType: " << frameType << std::endl;
      std::cout << "  frameSize: " << frameSize << std::endl;
      std::cout << " headerSize: " << headerSize << std::endl;
      std::cout << "   itemSize: " << itemSize << std::endl;
      std::cout << "   numItems: " << nItems << std::endl;
      std::cout << "   eventIdx: " << eventIdx << std::endl;
      std::cout << " fUnitBlock: " << fUnitBlock << std::endl;
      std::cout << "fEndianness: " << fEndianness << std::endl;
    }

    if (fFrame != 0)
      delete fFrame;

    fFrame = new GETFrame();
    fFrame -> SetEventID(eventIdx);
    fFrame -> SetCoboID(coboIdx);
    fFrame -> SetAsadID(asadIdx);
    fFrame -> SetFrameID(frameNo);
    fFrame -> SetPolarity((fIsPositivePolarity ? +1 : -1));

    fData.seekg((ULong64_t) fData.tellg() - 28 + headerSize);

    if (fDebugMode) {
      std::cout << " currentFrameStart: " << (ULong64_t)fData.tellg() - headerSize << std::endl;
    }

    if (frameType == 1) {
      UInt_t data;
      for (Int_t iItem = 0; iItem < nItems; iItem++) {
        fData.read(reinterpret_cast<Char_t *>(&data), itemSize);

        if (fEndianness == kBig)
          data = htonl(data);

        UShort_t agetIdx = ((data & 0xc0000000) >> 30);
        UShort_t chanIdx = ((data & 0x3f800000) >> 23);
        UShort_t buckIdx = ((data & 0x007fc000) >> 14);
        UShort_t sample = (data & 0x00000fff);         

        if (chanIdx >= 68 || agetIdx >= 4 || buckIdx >= 512)
          continue; 
                                                                       
        fFrame -> SetRawADC(agetIdx, chanIdx, buckIdx, sample); 
      }
    } else if (frameType == 2) {
      UShort_t data;
      for (Int_t iItem = 0; iItem < nItems; iItem++) {
        fData.read(reinterpret_cast<Char_t *>(&data), itemSize);

        if (fEndianness == kBig)
          data = htons(data);

        UShort_t agetIdx = ((data & 0xc000) >> 14);
        UShort_t chanIdx = ((iItem/8)*2 + iItem%2)%68;
        UShort_t buckIdx = iItem/(68*4);
        UShort_t sample = data & 0x0fff;

        if (chanIdx >= 68 || agetIdx >= 4 || buckIdx >= 512)
          continue; 
                                                                       
        fFrame -> SetRawADC(agetIdx, chanIdx, buckIdx, sample); 
      }
    }

    fCurrentFrameID = frameNo;

    if (fDebugMode) {
      std::cout << " currentFrameEnd: " << (ULong64_t)fData.tellg() << std::endl;
    }

    return fFrame;
  }
}

GETFrame *GETDecoder::GetFrame(Int_t frameNo, Int_t innerFrameNo)
{
  if (fFrameType == kNormal)
    return GetFrame(frameNo);

  ReadMergedFrameInfo();

  if (frameNo == -1 && innerFrameNo == -1) {
    if (fEOF) {
      std::cout << "== [GETDecoder] End of the file! (last frame: " << fCurrentFrameID << ")" << std::endl;

      if (fIsAutoReload)
        if (SetNextFile())
          return GetFrame(0, 0);

      return 0;
    } else if (fCurrentFrameID == -1 && fCurrentInnerFrameID == -1) {
      frameNo = 0;
      innerFrameNo = 0;
    } else if (fCurrentInnerFrameID + 1 == fNumMergedFrames) {
      frameNo = fCurrentFrameID + 1;
      innerFrameNo = 0;
      fCurrentInnerFrameID = -1;
    } else {
      frameNo = fCurrentFrameID;
      innerFrameNo = fCurrentInnerFrameID + 1;
    }
  } else if (frameNo == -1 && innerFrameNo != -1) {
    frameNo = fCurrentFrameID + 1;
  } else if (frameNo != -1 && innerFrameNo == -1) {
    innerFrameNo = fCurrentInnerFrameID + 1;

    if (frameNo == fCurrentFrameID && fCurrentInnerFrameID + 1 == fNumMergedFrames) {
      std::cout << "== [GETDecoder] Reached the end of the merged frame!" << std::endl;
      
      return 0;
    } else if (frameNo != fCurrentFrameID) {
      fCurrentInnerFrameID = -1;
      innerFrameNo = 0;
    }
  }

  if (fCurrentFrameID == frameNo && fCurrentInnerFrameID == innerFrameNo) {
    if (fDebugMode)
      PrintFrameInfo(frameNo, fFrame -> GetEventID(), fFrame -> GetCoboID(), fFrame -> GetAsadID());

    return fFrame;
  } else if (frameNo < -1 || innerFrameNo < -1) {
    std::cout << "== [GETDecoder] Frame number or inner frame number should be a positive integer!" << std::endl;

    return 0;
  } else if (innerFrameNo >= fNumMergedFrames) {
    std::cout << "== [GETDecoder] Inner frame number should be smaller than " << fNumMergedFrames << std::endl;

    return 0;
  }

  if (frameNo < fCurrentFrameID || innerFrameNo < fCurrentInnerFrameID) {
    fCurrentFrameID = -1;
    fCurrentInnerFrameID = -1;
    fData.clear();
    fData.seekg(0);
    ReadMergedFrameInfo();
    CheckEOF();

    return GetFrame(frameNo, innerFrameNo);
  }

  // Skip the frames until it reaches the given frame number, frameNo.
  while ((frameNo > fCurrentFrameID) && (frameNo > 0)) {
    if (fCurrentFrameID == -1) {
      fCurrentFrameID++;
      continue;
    }

    fData.clear();

    if (fDebugMode)
      std::cout << "== [GETDecoder] Skipping Frame No. " << fCurrentFrameID << std::endl;

    SkipMergedFrame();
    CheckEOF();
    ReadMergedFrameInfo();

    if (fEOF) {
      std::cout << "== [GETDecoder] End of the file! (last frame: " << fCurrentFrameID << ")" << std::endl;
      fCurrentInnerFrameID = fNumMergedFrames - 1;

      if (fIsAutoReload)
        if (SetNextFile())
          return GetFrame(0, 0);

      return 0;
    }

    fCurrentFrameID++;
  }

  if (fEOF) {
    std::cout << "== [GETDecoder] End of the file! (last frame: " << fCurrentFrameID << ")" << std::endl;

    if (fIsAutoReload)
      if (SetNextFile())
        return GetFrame(0, 0);

    return 0;
  }

  UInt_t frameSize;
  UShort_t headerSize;
  UInt_t nItems;
  UInt_t eventIdx;
  UShort_t coboIdx;
  UShort_t asadIdx;

  fData.ignore(fMergedHeaderSize);

  for (Int_t iSkip = 0; iSkip < innerFrameNo; iSkip++) {
    ReadInnerFrameInfo();
    SkipInnerFrame();
  }

  UShort_t metaType = 0;
  UShort_t frameType = 0;
  UShort_t itemSize = 0;
  fData.read(reinterpret_cast<Char_t *>(&metaType), 1);
  fData.read(reinterpret_cast<Char_t *>(&frameSize), 3);
  fData.ignore(1);
  fData.read(reinterpret_cast<Char_t *>(&frameType), 2);
  fData.ignore(1);
  fData.read(reinterpret_cast<Char_t *>(&headerSize), 2);
  fData.read(reinterpret_cast<Char_t *>(&itemSize), 2);
  fData.read(reinterpret_cast<Char_t *>(&nItems), 4);
  fData.ignore(6);
  fData.read(reinterpret_cast<Char_t *>(&eventIdx), 4);
  fData.read(reinterpret_cast<Char_t *>(&coboIdx), 1);
  fData.read(reinterpret_cast<Char_t *>(&asadIdx), 1);

  fEndianness = ((metaType&0x80) >> 7);
  fUnitBlock = pow(2, metaType&0xf);

  if (fEndianness == kBig) {
    frameType = htons(frameType);
    frameSize = (htonl(frameSize) >> 8);
    headerSize = htons(headerSize);
    itemSize = htons(itemSize);
    nItems = htonl(nItems);
    eventIdx = htonl(eventIdx);
    coboIdx = (htons(coboIdx) >> 8);
    asadIdx = (htons(asadIdx) >> 8);
  }

  frameSize *= fUnitBlock;
  headerSize *= fUnitBlock;

  if (fDebugMode)
    PrintFrameInfo(frameNo, eventIdx, coboIdx, asadIdx);

  if (fFrame != 0)
    delete fFrame;

  fFrame = new GETFrame();
  fFrame -> SetEventID(eventIdx);
  fFrame -> SetCoboID(coboIdx);
  fFrame -> SetAsadID(asadIdx);
  fFrame -> SetFrameID(frameNo);
  fFrame -> SetPolarity((fIsPositivePolarity ? +1 : -1));

  fData.seekg((ULong64_t) fData.tellg() - 28 + headerSize);

  if (frameType == 1) {
    UInt_t data;
    for (Int_t iItem = 0; iItem < nItems; iItem++) {
      fData.read(reinterpret_cast<Char_t *>(&data), itemSize);

      if (fEndianness == kBig)
        data = htonl(data);

      UShort_t agetIdx = ((data & 0xc0000000) >> 30);
      UShort_t chanIdx = ((data & 0x3f800000) >> 23);
      UShort_t buckIdx = ((data & 0x007fc000) >> 14);
      UShort_t sample = (data & 0x00000fff);         

      if (chanIdx >= 68 || agetIdx >= 4 || buckIdx >= 512)
        continue; 
                                                                     
      fFrame -> SetRawADC(agetIdx, chanIdx, buckIdx, sample); 
    }
  } else if (frameType == 2) {
    UShort_t data;
    for (Int_t iItem = 0; iItem < nItems; iItem++) {
      fData.read(reinterpret_cast<Char_t *>(&data), itemSize);

      if (fEndianness == kBig)
        data = htons(data);

      UShort_t agetIdx = ((data & 0xc000) >> 14);
      UShort_t chanIdx = ((iItem/8)*2 + iItem%2)%68;
      UShort_t buckIdx = iItem/(68*4);
      UShort_t sample = data & 0x0fff;

      if (chanIdx >= 68 || agetIdx >= 4 || buckIdx >= 512)
        continue; 
                                                                     
      fFrame -> SetRawADC(agetIdx, chanIdx, buckIdx, sample); 
    }
  }

  CheckEOF();

  // Return to merged frame head
  fData.seekg(fMergedFrameStartPoint);

  fCurrentFrameID = frameNo;
  fCurrentInnerFrameID = innerFrameNo;

  if (fDebugMode) {
    std::cout << "frameNo: " << frameNo << std::endl;
    std::cout << "innerFrameNo: " << innerFrameNo << std::endl;
    std::cout << "fCurrentFrameID: " << fCurrentFrameID << std::endl;
    std::cout << "fCurrentInnerFrameID: " << fCurrentInnerFrameID << std::endl;
    std::cout << "fMergedHeaderSize: " << fMergedHeaderSize << std::endl;
    std::cout << "fCurrentMergedFrameSize: " << fCurrentMergedFrameSize << std::endl;
    std::cout << "fNumMergedFrames: " << fNumMergedFrames << std::endl;
    std::cout << "fMergedFrameStartPoint: " << fMergedFrameStartPoint << std::endl;
  }

  return fFrame;
}

Int_t GETDecoder::GetNumMergedFrames()
{
  return fNumMergedFrames;
}

void GETDecoder::PrintFrameInfo(Int_t frameNo, Int_t eventID, Int_t coboID, Int_t asadID)
{
  std::cout << "== Frame Info -";
  std::cout << " Frame:" << frameNo;
  std::cout << " Event:" << eventID;
  std::cout << " CoBo:" << coboID;
  std::cout << " AsAd:" << asadID << std::endl;
}

void GETDecoder::SkipInnerFrame()
{
  fData.ignore(fCurrentInnerFrameSize);
}

void GETDecoder::SkipMergedFrame()
{
  fData.ignore(fCurrentMergedFrameSize);
}

void GETDecoder::ReadMergedFrameInfo()
{
  fMergedFrameStartPoint = fData.tellg();
  UShort_t metaType = 0;
  fData.read(reinterpret_cast<Char_t *>(&metaType), 1);
  fData.read(reinterpret_cast<Char_t *>(&fCurrentMergedFrameSize), 3);
  fData.ignore(8);
  fData.read(reinterpret_cast<Char_t *>(&fNumMergedFrames), 4);
  fData.seekg((ULong64_t)fData.tellg() - 16);

  fEndianness = ((metaType&0x80) >> 7);
  fMergedUnitBlock = pow(2, metaType&0xf);
  if (fEndianness == kBig) {
    fCurrentMergedFrameSize = htonl(fCurrentMergedFrameSize) >> 8;
    fNumMergedFrames = htonl(fNumMergedFrames);
  }

  fCurrentMergedFrameSize *= fMergedUnitBlock;
}

void GETDecoder::ReadInnerFrameInfo()
{
  UShort_t metaType = 0;
  fData.read(reinterpret_cast<Char_t *>(&metaType), 1);
  fData.read(reinterpret_cast<Char_t *>(&fCurrentInnerFrameSize), 3);
  fData.seekg((ULong64_t)fData.tellg() - 4);

  fEndianness = ((metaType&0x80) >> 7);
  fUnitBlock = pow(2, metaType&0xf);
  if (fEndianness == kBig)
    fCurrentInnerFrameSize = (htonl(fCurrentInnerFrameSize) >> 8);

  fCurrentInnerFrameSize *= fUnitBlock;
}

void GETDecoder::CheckEOF() {
  if (fData.tellg() >= fFileSize || fData.fail())
    fEOF = 1;
  else
    fEOF = 0;
}
