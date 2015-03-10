
#ifndef ATDIGIPAR_H
#define ATDIGIPAR_H

// FAIRROOT classes
#include "FairParGenericSet.h"
#include "FairParamList.h"
#include "FairLogger.h"

// SPiRITROOT classes
#include "ATGas.hh"

// ROOT classes
#include "TString.h"
#include "TSystem.h"

class ATDigiPar : public FairParGenericSet
{
  public:
    // Constructors and Destructors
    ATDigiPar(const Char_t *name, const Char_t *title, const Char_t *context);
    ~ATDigiPar();

    // Operators
    
    // Getters
    Int_t GetPadPlaneX();
    Int_t GetPadPlaneZ();
    Int_t GetPadSizeX();
    Int_t GetPadSizeZ();
    Int_t GetPadRows();
    Int_t GetPadLayers();
    Double_t GetAnodeWirePlaneY();
    Double_t GetGroundWirePlaneY();
    Double_t GetGatingWirePlaneY();
    ATGas *GetGas();
    Int_t GetNumTbs();
    Int_t GetTBTime();              ///< returns the time duration of a time bucket in given sampling time in ns.
    Double_t GetDriftVelocity();    ///< returns the drift velocity in cm/us.
    Double_t GetDriftLength();      ///< returns the drift length in mm
    Int_t GetYDivider();            ///< returns the slice divider
    virtual Bool_t getParams(FairParamList *paramList);

    TString GetFile(Int_t fileNum);

    // Setters
    virtual void putParams(FairParamList *paramList);

    // Main methods

  private:
    FairLogger *fLogger;

    ATGas *fGas;
    TString fGasFileName;

    Bool_t fInitialized;

    Int_t fPadPlaneX;
    Int_t fPadPlaneZ;
    Int_t fPadSizeX;
    Int_t fPadSizeZ;
    Int_t fPadRows;
    Int_t fPadLayers;
    Double_t fAnodeWirePlaneY;
    Double_t fGroundWirePlaneY;
    Double_t fGatingWirePlaneY;
    Double_t fEField;
    Int_t fNumTbs;
    Int_t fSamplingRate;
    Double_t fDriftVelocity;
    Double_t fDriftLength;
    Int_t fYDivider;
    Int_t fGasFile;
    Int_t fPadPlaneFile;
    Int_t fPadShapeFile;

  ClassDef(ATDigiPar, 1);
};

#endif
