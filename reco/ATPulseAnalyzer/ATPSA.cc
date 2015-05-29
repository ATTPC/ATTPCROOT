#include "ATPSA.hh"

// FairRoot classes
#include "FairRuntimeDb.h"
#include "FairRun.h"

// STL
#include <algorithm>

using std::max_element;
using std::min_element;
using std::distance;

ClassImp(ATPSA)

ATPSA::ATPSA()
{
  fLogger = FairLogger::GetLogger();

  FairRun *run = FairRun::Instance();
  if (!run)
    fLogger -> Fatal(MESSAGE_ORIGIN, "No analysis run!");

  FairRuntimeDb *db = run -> GetRuntimeDb();
  if (!db)
    fLogger -> Fatal(MESSAGE_ORIGIN, "No runtime database!");

  fPar = (ATDigiPar *) db -> getContainer("ATDigiPar");
  if (!fPar)
    fLogger -> Fatal(MESSAGE_ORIGIN, "ATDigiPar not found!!");

  fPadPlaneX = fPar -> GetPadPlaneX();
  fPadSizeX = fPar -> GetPadSizeX();
  fPadSizeZ = fPar -> GetPadSizeZ();
  fPadRows = fPar -> GetPadRows();
  fPadLayers = fPar -> GetPadLayers();

  fNumTbs = fPar -> GetNumTbs();
  fTBTime = fPar -> GetTBTime();
  fDriftVelocity = fPar -> GetDriftVelocity();
  fMaxDriftLength = fPar -> GetDriftLength();
  
  fBackGroundSuppression = kFALSE;

  fThreshold = -1;
}

ATPSA::~ATPSA()
{
}

void
ATPSA::SetThreshold(Int_t threshold)
{
  fThreshold = threshold;
}

Double_t
ATPSA::CalculateX(Double_t row)
{
  return (row + 0.5)*fPadSizeX - fPadPlaneX/2.;
}

Double_t
ATPSA::CalculateZ(Double_t peakIdx)
{
  //return -peakIdx*fTBTime*fDriftVelocity/100.;
   // std::cout<<fNumTbs<<"    "<<fTBTime<<"	"<<fDriftVelocity<<std::endl;
    return (fNumTbs - peakIdx)*fTBTime*fDriftVelocity/100.;
}

Double_t
ATPSA::CalculateY(Double_t layer)
{
  return (layer + 0.5)*fPadSizeZ;
}

void
ATPSA::SetBackGroundSuppression(){
  fBackGroundSuppression = kTRUE; 
}
