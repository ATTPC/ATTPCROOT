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
    
    fIsPedestalSubtracted = 0;
    fMaxAdcIdx = 0;

    memset(fRawAdc, 0, sizeof(fRawAdc));
    memset(fAdc, 0, sizeof(fAdc));
  
}

void ATPad::SetValidPad(Bool_t val)               { kIsValid = val; }
void ATPad::SetPad(Int_t val)                     { fPadNum = val; }
void ATPad::SetRawADC(Int_t *val)                 { memcpy(val, fRawAdc, sizeof(fRawAdc)); }
void ATPad::SetRawADC(Int_t idx, Int_t val)       { fRawAdc[idx] = val; memset(fRawAdc, 0, sizeof(fRawAdc));}
void ATPad::SetPedestalSubtracted(Bool_t val) { fIsPedestalSubtracted = val; }
//void ATPad::SetGainCalibrated(Bool_t val)     { fIsGainCalibrated = val; }//TODO
void ATPad::SetMaxADCIdx(Int_t val)           { fMaxAdcIdx = val; }
void ATPad::SetADC(Double_t *val)             { memcpy(fAdc, val, sizeof(fAdc)); }
void ATPad::SetADC(Int_t idx, Double_t val)   { fAdc[idx] = val; }

ATPad &ATPad::operator= (ATPad right)
{
  Initialize();

  fPadNum = right.GetPadNum();
  

  memcpy(fRawAdc, right.GetRawADC(), sizeof(fRawAdc));
  memcpy(fAdc, right.GetADC(), sizeof(fAdc));

  fMaxAdcIdx = right.GetMaxADCIdx();

  fIsPedestalSubtracted = right.IsPedestalSubtracted();
  //fIsGainCalibrated = right.IsGainCalibrated();//todo

  return *this;
}

 Int_t  ATPad::GetPadNum()             { return fPadNum; }
 Int_t *ATPad::GetRawADC()            { return fRawAdc; }
 Int_t  ATPad::GetRawADC(Int_t idx)   { return fRawAdc[idx]; }
 Int_t  ATPad::GetMaxADCIdx()         { return fMaxAdcIdx; }
Bool_t  ATPad::IsPedestalSubtracted() { return fIsPedestalSubtracted; }
//Bool_t  ATPad::IsGainCalibrated()     { return fIsGainCalibrated; }//TODO

Double_t *ATPad::GetADC()
{
  if (!fIsPedestalSubtracted) {
    std::cout << "== Pedestal subtraction is not done!" << std::endl;

    return 0;
  }

  return fAdc;
}

Double_t ATPad::GetADC(Int_t idx)
{
  if (!fIsPedestalSubtracted) {
    std::cout << "== Pedestal subtraction is not done!" << std::endl;

    return -4;
  }

  return fAdc[idx];
}




