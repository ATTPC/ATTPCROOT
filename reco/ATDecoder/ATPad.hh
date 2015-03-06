/*********************************************************************
*   ATTPC Pad Class	ATPad                                            *
*   Author: Y. Ayyad            				                     *
*   Log: 05-03-2015 19:24 JST					                     *
*   Adapted from SPiRITROOT STPad by G. Jhang                        *
*								                                     *	
*********************************************************************/

#ifndef ATPAD_H
#define ATPAD_H

#include "TObject.h"
#include "TROOT.h"

class ATPad : public TObject  {

   public:
    ATPad();
    ATPad(Int_t PadNum);
    ~ATPad();

    void Initialize();
    void SetValidPad(Bool_t val=kTRUE);
    void SetPad(Int_t val);
    void SetRawADC(Int_t *val);
    void SetRawADC(Int_t idx, Int_t val);
    
    
   private:
    
    Int_t fPadNum;
    Bool_t kIsValid;
    Int_t fRawAdc[512];
    
    ClassDef(ATPad, 1);

};

#endif
