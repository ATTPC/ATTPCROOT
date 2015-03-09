/*********************************************************************
*   ATTPC Pad Class	ATPad                                            *
*   Author: Y. Ayyad                                                 *
*   Log: 05-03-2015 19:24 JST                                        *
*                                                                    *
*                                                                    *
*********************************************************************/

#include <iostream>
#include "ATPad.hh"

ClassImp(ATPad);

ATPad::ATPad()
{
    fPadNum = -1;
}

ATPad::ATPad(Int_t PadNum)
{
    Initialize();
	fPadNum = PadNum;
    
}


ATPad::~ATPad()
{
 
}

void ATPad::Initialize(){
    
    memset(fRawAdc, 0, sizeof(fRawAdc));
  
}

void ATPad::SetValidPad(Bool_t val)               { kIsValid = val; }
void ATPad::SetPad(Int_t val)                     { fPadNum = val; }
void ATPad::SetRawADC(Int_t *val)                 { memcpy(val, fRawAdc, sizeof(fRawAdc)); }
void ATPad::SetRawADC(Int_t idx, Int_t val)       { fRawAdc[idx] = val; memset(fRawAdc, 0, sizeof(fRawAdc));}