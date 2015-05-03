#include "ATHoughSpace.hh"
#include "ATHoughSpaceLine.hh"
//#include "STPSALayer.hh" //TODO???

// FAIRROOT classes
#include "FairRootManager.h"
#include "FairRun.h"
#include "FairRuntimeDb.h"

#include <iostream>

#include "ATHoughTask.hh"

ClassImp(ATHoughTask);

ATHoughTask::ATHoughTask()
{
  fLogger = FairLogger::GetLogger();
  fPar = NULL;

  fIsPersistence = kFALSE;
  
  fHoughArray = new TClonesArray("ATHoughSpaceLine");
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

  fEventHArray = (TClonesArray *) ioMan -> GetObject("ATEventH");
  if (fEventHArray == 0) {
    fLogger -> Error(MESSAGE_ORIGIN, "Cannot find ATEvent array!");
    return kERROR;
  }

   //fPSA -> SetThreshold((Int_t)fThreshold);

    ioMan -> Register("ATHough", "ATTPC", fHoughArray, fIsPersistence);

   

  return kSUCCESS;
}

void
ATHoughTask::SetParContainers()
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
ATHoughTask::Exec(Option_t *opt)
{
   fHoughArray -> Delete();

 

  if (fEventHArray -> GetEntriesFast() == 0)
     return;

     ATEvent *Event = (ATEvent *) fEventHArray -> At(0);
     //std::cout << "  Event Number :  " << Event -> GetEventID() << std::endl;

    ATHoughSpaceLine *HoughSpace = (ATHoughSpaceLine *) new ((*fHoughArray)[0]) ATHoughSpaceLine();
    HoughSpace ->CalcHoughSpace(Event,kTRUE,kTRUE,kTRUE);

  //(ATHoughSpaceLine *) new ((*fHoughArray)[0]) ATHoughSpaceLine();
  //event -> SetEventID(event -> GetEventID());
   /* event -> SetEventID(rawEvent -> GetEventID());

  if (!(rawEvent -> IsGood()))
    event -> SetIsGood(kFALSE);
  else {
    fPSA -> Analyze(rawEvent, event);
    event -> SetIsGood(kTRUE);
  }*/
}
