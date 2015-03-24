#include "ATPSATask.hh"
#include "ATPSA.hh"
#include "ATPSASimple.hh"
#include "ATPSASimple2.hh"
//#include "STPSALayer.hh" //TODO???

// FAIRROOT classes
#include "FairRootManager.h"
#include "FairRun.h"
#include "FairRuntimeDb.h"

#include <iostream>

ClassImp(ATPSATask);

ATPSATask::ATPSATask()
{
  fLogger = FairLogger::GetLogger();
  fPar = NULL;

  fIsPersistence = kFALSE;
  
  fEventHArray = new TClonesArray("ATEvent");

  fPSAMode = 1;
}

ATPSATask::~ATPSATask()
{
}

void ATPSATask::SetPSAMode(Int_t value)          { fPSAMode = value; }
void ATPSATask::SetPersistence(Bool_t value)     { fIsPersistence = value; }
void ATPSATask::SetThreshold(Double_t threshold) { fThreshold = threshold; }

InitStatus
ATPSATask::Init()
{
  FairRootManager *ioMan = FairRootManager::Instance();
  if (ioMan == 0) {
    fLogger -> Error(MESSAGE_ORIGIN, "Cannot find RootManager!");
    return kERROR;
  }

  fRawEventArray = (TClonesArray *) ioMan -> GetObject("ATRawEvent");
  if (fRawEventArray == 0) {
    fLogger -> Error(MESSAGE_ORIGIN, "Cannot find ATRawEvent array!");
    return kERROR;
  }

  if (fPSAMode == 0) {
    fLogger -> Info(MESSAGE_ORIGIN, "Use ATPSASimple!");

    fPSA = new ATPSASimple();
  } else if (fPSAMode == 1) {
    fLogger -> Info(MESSAGE_ORIGIN, "Use ATPSASimple2!");

    fPSA = new ATPSASimple2();
  /*} else if (fPSAMode == 2) {
    fLogger -> Info(MESSAGE_ORIGIN, "Use STPSALayer!");

    fPSA = new STPSALayer();*/
  }

  fPSA -> SetThreshold((Int_t)fThreshold);

  ioMan -> Register("ATEventH", "ATTPC", fEventHArray, fIsPersistence);

  return kSUCCESS;
}

void
ATPSATask::SetParContainers()
{
  FairRun *run = FairRun::Instance();
  if (!run)
    fLogger -> Fatal(MESSAGE_ORIGIN, "No analysis run!");

  FairRuntimeDb *db = run -> GetRuntimeDb();
  if (!db)
    fLogger -> Fatal(MESSAGE_ORIGIN, "No runtime database!");

  fPar = (ATDigiPar *) db -> getContainer("ATDigiPar");
  if (!fPar)
    fLogger -> Fatal(MESSAGE_ORIGIN, "ATDigiPar not found!!");
}

void
ATPSATask::Exec(Option_t *opt)
{
  fEventHArray -> Delete();

  if (fRawEventArray -> GetEntriesFast() == 0)
    return;

  ATRawEvent *rawEvent = (ATRawEvent *) fRawEventArray -> At(0);
  std::cout << "  Event Number :  " << rawEvent -> GetEventID() << " Valid pads : " << rawEvent -> GetNumPads() << std::endl;

  ATEvent *event = (ATEvent *) new ((*fEventHArray)[0]) ATEvent();
  event -> SetEventID(event -> GetEventID());

  if (!(rawEvent -> IsGood()))
    event -> SetIsGood(kFALSE);
  else {
    fPSA -> Analyze(rawEvent, event);
    event -> SetIsGood(kTRUE);
  }
}
