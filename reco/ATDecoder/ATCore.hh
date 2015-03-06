/*********************************************************************
*   ATTPC Unpacker and Decoder Core Class	ATCore                   *
*   Author: Y. Ayyad            				                     *
*   Log: 04-03-2015 17:16 JST					                     *
*   Adapted from STCore from SPiRITROOT by G. Jhang                  *
*								                                     *
*********************************************************************/

#ifndef ATCORE_H
#define ATCORE_H

#include "TObject.h"
#include "TString.h"
#include "GETDecoder.hh"
#include "GETFrame.hh"
#include "AtTpcMap.h"
#include "ATPad.hh"


class ATCore : public TObject  {

 public:
    ATCore();
    ATCore(TString filename, Int_t numTbs);

    ~ATCore();

     void Initialize();
     Bool_t AddData(TString filename);
     Bool_t SetData(Int_t value);
     Bool_t SetATTPCMap(char *lookup);
     void SetPositivePolarity(Bool_t value = kTRUE);
     Int_t *GetRawEvent(Int_t eventID = -1);// TO DO It returns a pointer to ATRawEvent
     void SetNumTbs(Int_t value);
     inline void SetDebugMode(Bool_t Debug){kDebug=Debug;}

     AtTpcMap *fAtMapPtr;
    
     Bool_t kDebug;


 private:
    GETDecoder* fGETDecoderPtr;
    Bool_t fIsData;
    Int_t fNumTbs;

    UInt_t fPrevEventNo;
    UInt_t fCurrEventNo;

    Int_t fCurrFrameNo;
    
    ClassDef(ATCore, 1);

    
};

#endif
