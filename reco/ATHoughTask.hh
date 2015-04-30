#ifndef ATHOUGHTASK_H
#define ATHOUGHTASK_H

// FAIRROOT classes
#include "FairTask.h"
#include "FairLogger.h"

// SPiRITROOT classes
#include "ATEvent.hh"
#include "ATDigiPar.hh"
#include "ATHoughSpaceLine.hh"

// ROOT classes
#include "TClonesArray.h" 

class ATHoughTask : public FairTask {
  public:
    ATHoughTask();
    ~ATHoughTask();

   
    void SetPersistence(Bool_t value = kTRUE);
    void SetThreshold(Double_t threshold);

    virtual InitStatus Init();
    virtual void SetParContainers();
    virtual void Exec(Option_t *opt);

  private:
    FairLogger *fLogger;
    
    ATDigiPar *fPar;
    
    TClonesArray *fEventHArray;
    TClonesArray *fHoughArray;

    ATHoughSpace *fHoughSpace;

    Bool_t fIsPersistence;
    
    Double_t fThreshold;

  ClassDef(ATHoughTask, 1);
};

#endif
