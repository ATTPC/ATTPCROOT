#ifndef ATGAS_H
#define ATGAS_H

// ROOT classes
#include "TString.h"
#include "TSystem.h"

//#include "Rtypes.h"

class ATGas
{
  public:
    // Constructor and Destructor
    ATGas(TString);
    ~ATGas();

    void operator=(const ATGas& GasToCopy);

    // Getter
    Double_t GetEIonize();
    Double_t GetDriftVelocity();
    Double_t GetCoefAttachment();
    Double_t GetCoefDiffusionLong();
    Double_t GetCoefDiffusionTrans();
    Int_t    GetGain();
    UInt_t   GetRandomCS();

    // Setter

  private:
    TString fGasFileName;
    void InitializeParameters();

    Double_t fEIonize;                  //!< effective ionization energy [eV]
    Double_t fDriftVelocity;            //!< drift velocity [cm/ns]
    Double_t fCoefAttachment;           //!< attachment coefficient
    Double_t fCoefDiffusionLong;        //!< longitudinal diffusion coefficient
    Double_t fCoefDiffusionTrans;       //!< transversal diffusion coefficient
    Double_t fGain;                     //!< gain factor from wire plane

  ClassDef(ATGas, 1)
};

#endif
