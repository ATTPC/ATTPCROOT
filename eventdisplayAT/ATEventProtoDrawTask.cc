#include "ATEventProtoDrawTask.hh"
#include "AtTpcProtoMap.h"

ClassImp(ATEventProtoDrawTask)

ATEventProtoDrawTask::ATEventProtoDrawTask()
{

  
}

ATEventProtoDrawTask::~ATEventProtoDrawTask()
{

  
}

void
ATEventProtoDrawTask::DrawPadPlane()
{

  fAtMapPtr = new AtTpcProtoMap();
  if(fPadPlane) 
  {
    fPadPlane->Reset(0);
    return;
  }

    fAtMapPtr->SetGeoFile("proto_geo_hires.root");
    fPadPlane = fAtMapPtr->GetATTPCPlane("ATTPC_Proto");
    fCvsPadPlane -> cd();
    fPadPlane -> Draw("col");
  
}
