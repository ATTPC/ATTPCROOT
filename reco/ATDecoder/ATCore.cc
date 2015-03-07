/*********************************************************************
*   ATTPC Unpacker and Decoder Core Class	ATCore               *	
*   Author: Y. Ayyad            				     *
*   Log: 04-03-2015 17:16 JST					     *
*   Adapted from STCore from SPiRITROOT by G. Jhang		     *	
*********************************************************************/


#include <iostream>
#include <fstream>
#include <cmath>

#include "ATCore.hh"
#include "GETDecoder.hh"
#include "GETFrame.hh"

ClassImp(ATCore);

ATCore::ATCore()
{
  Initialize();
  kDebug=kFALSE;
}

ATCore::ATCore(TString filename, Int_t numTbs)
{
  
  Initialize();
  AddData(filename);
  SetNumTbs(numTbs);
  kDebug=kFALSE;
  
}

ATCore::~ATCore()
{
  delete fGETDecoderPtr;
  delete fAtMapPtr;
  //delete fPedestalPtr;
  //delete fMapPtr;
}

void ATCore::Initialize(){

  fGETDecoderPtr = new GETDecoder();
  fNumTbs = 512;
  fIsData = kFALSE;
  fAtMapPtr = new AtTpcMap();
  fRawEventPtr = NULL;

}

Bool_t ATCore::AddData(TString filename)
{
  return fGETDecoderPtr -> AddData(filename);
}

Bool_t ATCore::SetData(Int_t value)
{
  fIsData = fGETDecoderPtr -> SetData(value);

  fPrevEventNo = -1;
  fCurrEventNo = -1;
  fCurrFrameNo = 0;

  return fIsData;
}

Bool_t ATCore::SetATTPCMap(char *lookup){

  fAtMapPtr->GenerateATTPC();
  fAtMapPtr->ParseXMLMap(lookup);
  //**** For debugging purposes only! ******//
  //fAtMapPtr->SetGUIMode();
  //fAtMapPtr->GetATTPCPlane();
  return 1;

}

void ATCore::SetPositivePolarity(Bool_t value)
{
  fGETDecoderPtr -> SetPositivePolarity(value);
}

void ATCore::SetNumTbs(Int_t value)
{
  fNumTbs = value;
  fGETDecoderPtr -> SetNumTbs(value);
}

ATRawEvent *ATCore::GetRawEvent(Int_t eventID){

      if(kDebug) fAtMapPtr->SetDebugMode();
    
  	  if (!fIsData) {
  		  std::cout << "== ATCore -  Data file is not set" << std::endl;
		  return NULL;
  	  }

    fPrevEventNo = eventID;
    
    if (fRawEventPtr != NULL)
        delete fRawEventPtr;

        fRawEventPtr = new ATRawEvent();
        GETFrame *frame = NULL;

		
		while ((frame = fGETDecoderPtr -> GetFrame(fCurrFrameNo))) {
            if (fPrevEventNo == -1)
                fPrevEventNo = frame -> GetEventID();
            
            fCurrEventNo = frame -> GetEventID();
            
            if (fCurrEventNo == fPrevEventNo + 1) {
                fPrevEventNo = fCurrEventNo;
                return fRawEventPtr;
            } else if (fCurrEventNo > fPrevEventNo + 1) {
                fCurrFrameNo = 0;
                continue;
            } else if (fCurrEventNo < fPrevEventNo) {
                fCurrFrameNo++;
                continue;
            }

            

			Int_t frameType = fGETDecoderPtr -> GetFrameType();
            
        if ((frameType == GETDecoder::kMergedID || frameType == GETDecoder::kMergedTime) && !(fRawEventPtr -> IsGood())) {
                Int_t currentInnerFrameID = fGETDecoderPtr -> GetCurrentInnerFrameID();
                Int_t numInnerFrames = fGETDecoderPtr -> GetNumMergedFrames();
                
                while (!(currentInnerFrameID + 1 == numInnerFrames)) {
                    fGETDecoderPtr -> GetFrame(fCurrFrameNo);
                    
                    currentInnerFrameID = fGETDecoderPtr -> GetCurrentInnerFrameID();
                    numInnerFrames = fGETDecoderPtr -> GetNumMergedFrames();
                }
                
                fCurrFrameNo++;
                fPrevEventNo = fCurrEventNo;
                return fRawEventPtr;
            }
          
            fRawEventPtr -> SetEventID(fCurrEventNo);



				 eventID = frame -> GetEventID();
				 Int_t iCobo = frame -> GetCoboID();
				 Int_t iAsad = frame -> GetAsadID();


                 std::cout<<" Event ID : "<<eventID<<" coboID : "<<iCobo<<" asadID : "<<iAsad<<std::endl;

 					for (Int_t iAget = 0; iAget < 4; iAget++) {
                        for (Int_t iCh = 0; iCh < 68; iCh++) {
							//std::cout<<" Event ID : "<<eventID<<" coboID : "<<iCobo<<" asadID : "<<iAsad<<std::endl;
							//std::cout<<" AgetID : "<<iAget<<" ChannelID : "<<iCh<<std::endl;
							std::vector<int> PadRef={iCobo,iAsad,iAget,iCh};
                            Int_t PadRefNum = fAtMapPtr->GetPadNum(PadRef);
                            ATPad *pad = new ATPad(PadRefNum); // TODO Return all pads with a flag??????
                            if(PadRefNum!=-1) pad->SetValidPad(kFALSE);
                            else pad->SetValidPad(kTRUE);
                            //else continue;
                            
                                Int_t *rawadc = frame -> GetRawADC(iAget, iCh);
                                for (Int_t iTb = 0; iTb < fGETDecoderPtr -> GetNumTbs(); iTb++){
                                    //std::cout<<" AGet "<<iAget<<" Channel : "<<iCh<<" ADC : "<<*rawadc<<" Time Bucket : "<<iTb<<std::endl;
                                    pad -> SetRawADC(iTb, rawadc[iTb]);

                                }
							    //std::cout<<" Pad Number : "<<fAtMapPtr->GetPadNum(PadRef)<<std::endl;
        						//Int_t maxTb = fGETDecoderPtr-> GetNumTbs();
							    //for (Int_t iTb = 0; iTb < maxTb; iTb++) {
         						// Int_t rawadc = frame -> GetRawADC(iAget, iCh, iTb);
                                //std::cout<<" AGet "<<iAget<<" Channel : "<<iCh<<" ADC : "<<rawadc<<" Time Bucket : "<<iTb<<std::endl;
        						//}
                            
                                fRawEventPtr -> SetPad(pad);
                                delete pad;
						 }
                    }
           
             if (frameType == GETDecoder::kMergedID || frameType == GETDecoder::kMergedTime) {
                Int_t currentInnerFrameID = fGETDecoderPtr -> GetCurrentInnerFrameID();
                Int_t numInnerFrames = fGETDecoderPtr -> GetNumMergedFrames();
                
                if (currentInnerFrameID + 1 == numInnerFrames) {
                    fCurrFrameNo++;
                    fPrevEventNo = fCurrEventNo;
                    return fRawEventPtr;
                }
              } else
                fCurrFrameNo++;


			

		}

	

	return NULL;

}













