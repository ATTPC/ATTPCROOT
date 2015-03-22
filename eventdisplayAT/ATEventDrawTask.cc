/**
 * @brief Event display task
 * @author JungWoo Lee (Korea Univ.)
 *         Adapted for ATTPCROOT by Yassid Ayyad (NSCL)
 */

#include "FairRootManager.h"

#include "ATEventDrawTask.hh"

#include "TEveManager.h"
#include "TPaletteAxis.h"
#include "TStyle.h"

#include "AtTpcMap.h"
#include "TH2Poly.h"

#ifndef __CINT__ // Boost 
#include <boost/multi_array.hpp>
#endif //__CINT__

#include <iostream>

using namespace std;

ClassImp(ATEventDrawTask);

ATEventDrawTask::ATEventDrawTask()
: fIs2DPlotRange(kFALSE),
  fHitArray(0),
  //fHitClusterArray(0),
  //fRiemannTrackArray(0),
  //fKalmanArray(0),
  fEventManager(0),
  fThreshold(0),
  fHitSet(0),
  fHitColor(kPink),
  fHitSize(1),
  fHitStyle(kFullDotMedium),
  //fHitClusterSet(0),
  //fHitClusterColor(kAzure-5),
  //fHitClusterColor(kYellow-5),
  //fHitClusterSize(1),
  //fHitClusterStyle(kOpenCircle),
  //fRiemannSetArray(0),
  //fRiemannColor(kBlue),
  //fRiemannSize(1.5),
  //fRiemannStyle(kOpenCircle),
  fCvsPadPlane(0),
  fPadPlane(0),
  fAtMapPtr(0),
  fMinZ(0),
  fMaxZ(1344),
  fMinX(432),
  fMaxX(-432)
{

  fAtMapPtr = new AtTpcMap(); 

}

ATEventDrawTask::~ATEventDrawTask()
{
}

InitStatus 
ATEventDrawTask::Init()
{
  FairRootManager* ioMan = FairRootManager::Instance();
  fEventManager = ATEventManager::Instance();

  fHitArray = (TClonesArray*) ioMan->GetObject("ATEventH");
  if(fHitArray) LOG(INFO)<<"Hit Found."<<FairLogger::endl;

  //fHitClusterArray = (TClonesArray*) ioMan->GetObject("STEventHC");
  //if(fHitClusterArray) LOG(INFO)<<"Hit Cluster Found."<<FairLogger::endl;

  //fRiemannTrackArray = (TClonesArray*) ioMan->GetObject("STRiemannTrack");
  //if(fRiemannTrackArray) LOG(INFO)<<"Riemann Track Found."<<FairLogger::endl;

  //fKalmanArray = (TClonesArray*) ioMan->GetObject("STKalmanTrack");
  //if(fKalmanArray) LOG(INFO)<<"Kalman Track Found."<<FairLogger::endl;

  gStyle -> SetPalette(55);
  fCvsPadPlane = fEventManager->GetCvsPadPlane();
  DrawPadPlane(); 
}

void 
ATEventDrawTask::Exec(Option_t* option)
{
  Reset();
  
  if(fHitArray) DrawHitPoints();
  //if(fHitClusterArray) DrawHitClusterPoints();
  //if(fRiemannTrackArray) DrawRiemannHits();

  gEve -> Redraw3D(kFALSE);
  UpdateCvsPadPlane();
}

void 
ATEventDrawTask::DrawHitPoints()
{
  ATEvent* event = (ATEvent*) fHitArray->At(0);
  Int_t nHits = event->GetNumHits();
  fHitSet = new TEvePointSet("Hit",nHits, TEvePointSelectorConsumer::kTVT_XYZ);
  fHitSet->SetOwnIds(kTRUE);
  fHitSet->SetMarkerColor(fHitColor);
  fHitSet->SetMarkerSize(fHitSize);
  fHitSet->SetMarkerStyle(fHitStyle);
    std::cout<<" Number of hits : "<<nHits<<std::endl;

  for(Int_t iHit=0; iHit<nHits; iHit++)
  {
     
    ATHit hit = event->GetHitArray()->at(iHit);
      
    if(hit.GetCharge()<fThreshold) continue;
    TVector3 position = hit.GetPosition();
    fHitSet->SetNextPoint(position.X()/10.,position.Y()/10.,position.Z()/10.);
    fHitSet->SetPointId(new TNamed(Form("Hit %d",iHit),""));
      
      std::cout<<position.X()<<std::endl;
    fPadPlane->Fill(position.X(), position.Y(), hit.GetCharge());
  }
  gEve -> AddElement(fHitSet);
}

/*void 
ATEventDrawTask::DrawHitClusterPoints()
{
  STEvent* event = (STEvent*) fHitClusterArray->At(0);
  Int_t nClusters = event->GetNumClusters();

  fHitClusterSet = new TEvePointSet("HitCluster",nClusters, TEvePointSelectorConsumer::kTVT_XYZ);
  fHitClusterSet->SetOwnIds(kTRUE);
  fHitClusterSet->SetMarkerColor(fHitClusterColor);
  fHitClusterSet->SetMarkerSize(fHitClusterSize);
  fHitClusterSet->SetMarkerStyle(fHitClusterStyle);

  for(Int_t iCluster; iCluster<nClusters; iCluster++)
  {
    STHitCluster cluster = event->GetClusterArray()->at(iCluster);
    if(cluster.GetCharge()<fThreshold) continue;
    TVector3 position = cluster.GetPosition();
    fHitClusterSet -> SetNextPoint(position.X()/10.,position.Y()/10.,position.Z()/10.);
    //cout << "cluster : " << cluster.GetClusterID() << " " << position.X()/10. << " " << position.Y()/10. << " " << position.Z()/10. << endl;
    fHitClusterSet -> SetPointId(new TNamed(Form("HitCluster %d",iCluster),""));
  }
  gEve -> AddElement(fHitClusterSet);
}*/

/*void 
STEventDrawTask::DrawRiemannHits()
{
  STRiemannTrack* track = 0;
  STHitCluster* rCluster = 0;
  TEvePointSet* riemannClusterSet = 0;

  STEvent* event = (STEvent*) fHitClusterArray->At(0);

  Int_t nTracks = fRiemannTrackArray -> GetEntries();
  //cout << "number of rieman tracks : " << nTracks << endl;
  for(Int_t iTrack=0; iTrack<nTracks; iTrack++) 
  {
    track = (STRiemannTrack*) fRiemannTrackArray -> At(iTrack);

    Int_t nClusters = track -> GetNumHits();
    riemannClusterSet = new TEvePointSet(Form("RiemannTrack_%d",iTrack),nClusters,TEvePointSelectorConsumer::kTVT_XYZ);
    riemannClusterSet -> SetMarkerColor(fRiemannColor+iTrack);
    riemannClusterSet -> SetMarkerSize(fRiemannSize);
    riemannClusterSet -> SetMarkerStyle(fRiemannStyle);
    for(Int_t iCluster=0; iCluster<nClusters; iCluster++)
    {
      rCluster = track -> GetHit(iCluster) -> GetCluster();
      if((rCluster->GetCharge())<fThreshold) continue;
      Int_t id = rCluster -> GetClusterID();
      //cout << id << endl;
      STHitCluster oCluster = event->GetClusterArray()->at(id);

      TVector3 position = oCluster.GetPosition();
      riemannClusterSet -> SetNextPoint(position.X()/10.,position.Y()/10.,position.Z()/10.);
      //cout << "riemann cluster: " << oCluster.GetClusterID() << " " << position.X()/10. << " " << position.Y()/10. << " " << position.Z()/10. << endl;
      riemannClusterSet -> SetPointId(new TNamed(Form("RiemanCluster %d",iCluster),""));
    }
    gEve -> AddElement(riemannClusterSet);
    fRiemannSetArray.push_back(riemannClusterSet);
  }
}*/

void
ATEventDrawTask::Reset()
{
  if(fHitSet) {
    fHitSet->Reset();
    gEve->RemoveElement(fHitSet, fEventManager);
  }

  /*if(fHitClusterSet) {
    fHitClusterSet->Reset();
    gEve->RemoveElement(fHitClusterSet, fEventManager);
  }*/

 /* Int_t nRiemannTracks = fRiemannSetArray.size();
  TEvePointSet* pointSet;
  if(nRiemannTracks!=0) {
    for(Int_t i=0; i<nRiemannTracks; i++){
      pointSet = fRiemannSetArray[i];
      gEve->RemoveElement(pointSet, fEventManager);
    }
    fRiemannSetArray.clear();
  }*/

  if(fPadPlane!=NULL)
    fPadPlane->Reset(0);
}

/*void
ATEventDrawTask::Set2DPlotRange(Int_t uaIdx)
{
  if(uaIdx%100<0 || uaIdx%100>11 || uaIdx/100<0 || uaIdx/100>3) 
  {
    fLogger->Error(MESSAGE_ORIGIN, 
      "2DPlotRange should be ABB ( A = [0, 3], BB = [00, 11] )!");
    return;
  }

  fMinZ = (uaIdx/100)*12*7*4;
  fMaxZ = (uaIdx/100 + 1)*12*7*4;
  fMinX = (uaIdx%100)*8*9 - 432;
  fMaxX = (uaIdx%100 + 1)*8*9 - 432;

  fIs2DPlotRange = kTRUE;
}*/

void
ATEventDrawTask::DrawPadPlane()
{
  if(fPadPlane) 
  {
    fPadPlane->Reset(0);
    return;
  }

   
    
    fAtMapPtr->GenerateATTPC();
 // fAtMapPtr->SetGUIMode();// This method does not need to be called since it generates the Canvas we do not want
    fPadPlane = fAtMapPtr->GetATTPCPlane();
    fCvsPadPlane -> cd();
    fPadPlane -> Draw("col");
  
}

void 
ATEventDrawTask::UpdateCvsPadPlane()
{
  fCvsPadPlane -> Modified();
  fCvsPadPlane -> Update();

  TPaletteAxis *paxis 
    = (TPaletteAxis *) fPadPlane->GetListOfFunctions()->FindObject("palette");

  /*if (paxis) {
    if(fIs2DPlotRange) {
      paxis -> SetX1NDC(0.940);
      paxis -> SetX2NDC(0.955);
      paxis -> SetLabelSize(0.08);
      paxis -> GetAxis() -> SetTickSize(0.01);
    } else {
      paxis -> SetX1NDC(0.905);
      paxis -> SetX2NDC(0.94);
    }

    fCvsPadPlane -> Modified();
    fCvsPadPlane -> Update();
  }*/
}

void 
ATEventDrawTask::SetHitAttributes(Color_t color, Size_t size, Style_t style)
{
  fHitColor = color;
  fHitSize = size;
  fHitStyle = style;
}

/*void 
ATEventDrawTask::SetHitClusterAttributes(Color_t color, Size_t size, Style_t style)
{
  fHitClusterColor = color;
  fHitClusterSize = size;
  fHitClusterStyle = style;
}*/

/*void 
ATEventDrawTask::SetRiemannAttributes(Color_t color, Size_t size, Style_t style)
{
  fRiemannColor = color;
  fRiemannSize = size;
  fRiemannStyle = style;
}*/
