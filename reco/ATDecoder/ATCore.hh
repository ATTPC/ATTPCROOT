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
#include "ATRawEvent.hh"


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
     ATRawEvent *GetRawEvent(Int_t eventID = -1);// TO DO It returns a pointer to ATRawEvent
     void SetNumTbs(Int_t value);
     inline void SetDebugMode(Bool_t Debug){kDebug=Debug;}
     void SetInternalPedestal(Int_t startTb = 10, Int_t averageTbs = 20);
     void SetFPNPedestal(Double_t sigmaThreshold = 5);

     AtTpcMap *fAtMapPtr;
    
     Bool_t kDebug;

     enum EPedestalMode { kNoPedestal, kPedestalInternal, kPedestalExternal, kPedestalFPN, kPedestalBothIE };

 private:
    GETDecoder* fGETDecoderPtr;
    Bool_t fIsData;
    Bool_t fIsInternalPedestal;
    Bool_t fIsFPNPedestal;
    Int_t fNumTbs;
    Int_t fStartTb;
    Int_t fAverageTbs;
    
    ATRawEvent *fRawEventPtr;
    EPedestalMode fPedestalMode;    
    Double_t fFPNSigmaThreshold;
    Double_t fPedestalRMSFactor;
    UInt_t fPrevEventNo;
    UInt_t fCurrEventNo;
    
    Int_t fCurrFrameNo;



    ClassDef(ATCore, 1);

    
};

#endif
