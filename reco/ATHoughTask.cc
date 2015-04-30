#include "ATHoughSpace.hh"
#include "ATHoughSpaceLine.hh"
//#include "STPSALayer.hh" //TODO???

// FAIRROOT classes
#include "FairRootManager.h"
#include "FairRun.h"
#include "FairRuntimeDb.h"

#include <iostream>

ClassImp(ATHoughTask);

ATHoughTask::ATHoughTask()
{
  fLogger = FairLogger::GetLogger();
  fPar = NULL;

  fIsPersistence = kFALSE;
  
  fHoughArray = new TClonesArray("ATHough");
}

ATHoughTask::~ATHoughTask()
{
}


void ATHoughTask::SetPersistence(Bool_t value)     { fIsPersistence = value; }
void ATHoughTask::SetThreshold(Double_t threshold) { fThreshold = threshold; }

InitStatus
ATHoughTask::Init()
{
  FairRootManager *ioMan = FairRootManager::Instance();
  if (ioMan == 0) {
    fLogger -> Error(MESSAGE_ORIGIN, "Cannot find RootManager!");
    return kERROR;
  }

  fEventArray = (TClonesArray *) ioMan -> GetObject("ATEventH");
  if (fRawEventArray == 0) {
    fLogger -> Error(MESSAGE_ORIGIN, "Cannot find ATRawEvent array!");
    return kERROR;
  }

   //fPSA -> SetThreshold((Int_t)fThreshold);

  ioMan -> Register("ATHoughH", "ATTPC_Hough", fHoughArray, fIsPersistence);

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
  fHoughArray -> Delete();

  if (fEventArray -> GetEntriesFast() == 0)
    return;

  ATEvent *Event = (ATEvent *) fEventArray -> At(0);
  std::cout << "  Event Number :  " << Event -> GetEventID() << std::endl;

  /*ATEvent *event = (ATEvent *) new ((*fEventHArray)[0]) ATEvent();
  //event -> SetEventID(event -> GetEventID());
    event -> SetEventID(rawEvent -> GetEventID());

  if (!(rawEvent -> IsGood()))
    event -> SetIsGood(kFALSE);
  else {
    fPSA -> Analyze(rawEvent, event);
    event -> SetIsGood(kTRUE);
  }*/
}
