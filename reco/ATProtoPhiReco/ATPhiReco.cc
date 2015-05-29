#include "ATPhiReco.hh"

// FairRoot classes
#include "FairRuntimeDb.h"
#include "FairRun.h"

// STL
#include <algorithm>


ClassImp(ATPhiReco)

ATPhiReco::ATPhiReco()
{
  
    //TODO: IS THIS NEEDED??? 
 /* fLogger = FairLogger::GetLogger();

  FairRun *run = FairRun::Instance();
  if (!run)
    fLogger -> Fatal(MESSAGE_ORIGIN, "No analysis run!");

  FairRuntimeDb *db = run -> GetRuntimeDb();
  if (!db)
    fLogger -> Fatal(MESSAGE_ORIGIN, "No runtime database!");

  fPar = (ATDigiPar *) db -> getContainer("ATDigiPar");
  if (!fPar)
    fLogger -> Fatal(MESSAGE_ORIGIN, "ATDigiPar not found!!");*/

 
}

ATPhiReco::~ATPhiReco()
{
}

