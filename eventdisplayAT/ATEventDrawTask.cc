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
  fRawevent(0),
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
  fCvsPadWave(0),
  fPadWave(0),
  fAtMapPtr(0),
  fMinZ(0),
  fMaxZ(1344),
  fMinX(432),
  fMaxX(-432)
{

  //fAtMapPtr = new AtTpcMap(); 

}

ATEventDrawTask::~ATEventDrawTask()
{
    
    //TODO Destroy pointers
}

InitStatus 
ATEventDrawTask::Init()
{
  FairRootManager* ioMan = FairRootManager::Instance();
  fEventManager = ATEventManager::Instance();

  fHitArray = (TClonesArray*) ioMan->GetObject("ATEventH");
  if(fHitArray) LOG(INFO)<<"Hit Array Found."<<FairLogger::endl;
    
   fRawEventArray = (TClonesArray*) ioMan->GetObject("ATRawEvent");
   if(fRawEventArray) LOG(INFO)<<"Raw Event Array  Found."<<FairLogger::endl;

  //fHitClusterArray = (TClonesArray*) ioMan->GetObject("STEventHC");
  //if(fHitClusterArray) LOG(INFO)<<"Hit Cluster Found."<<FairLogger::endl;

  //fRiemannTrackArray = (TClonesArray*) ioMan->GetObject("STRiemannTrack");
  //if(fRiemannTrackArray) LOG(INFO)<<"Riemann Track Found."<<FairLogger::endl;

  //fKalmanArray = (TClonesArray*) ioMan->GetObject("STKalmanTrack");
  //if(fKalmanArray) LOG(INFO)<<"Kalman Track Found."<<FairLogger::endl;

  gStyle -> SetPalette(55);
  fCvsPadWave = fEventManager->GetCvsPadWave();
  DrawPadWave();
  fCvsPadPlane = fEventManager->GetCvsPadPlane();// There is a problem if the pad plane is drawn first
  fCvsPadPlane->AddExec("ex","ATEventDrawTask::SelectPad()");
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
  UpdateCvsPadWave();
}

void 
ATEventDrawTask::DrawHitPoints()
{
  ATEvent* event = (ATEvent*) fHitArray->At(0);
  fRawevent = (ATRawEvent*) fRawEventArray->At(0);
    //Bool_t IsValidPad = kFALSE;
    //std::cout<<std::endl;
    //std::cout<<" ATHit Event ID : "<<event->GetEventID()<<std::endl;
    //std::cout<<" ATRawEvent Event ID : "<<rawevent->GetEventID()<<std::endl;
    //if(event->GetEventID()!=rawevent->GetEventID()) std::cout<<" = ATEventDrawTask::DrawHitPoints : Warning, EventID mismatch."<<std::endl;
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
    Int_t PadNumHit = hit.GetHitPadNum();
    
    //std::cout<<" Hit : "<<iHit<<" ATHit Pad Number :  "<<PadNumHit<<std::endl;
      
    if(hit.GetCharge()<fThreshold) continue;
    TVector3 position = hit.GetPosition();
    //std::cout<<"  Hit number : "<<iHit<<" Position X : "<<position.X()<<" Position Y : "<<position.Y()<<" Position Z : "<<position.Z()<<std::endl;
    fHitSet->SetNextPoint(position.X()/10.,position.Y()/10.,position.Z()/10.); // Convert into cm
    fHitSet->SetPointId(new TNamed(Form("Hit %d",iHit),""));
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
  fAtMapPtr = new AtTpcMap();
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
ATEventDrawTask::DrawPadWave()
{
 
    
   /*  if(fPadWave)
    {
        fPadWave->Reset(0);
        return;
    }
    **/
      fPadWave = new TH1I("PadWave","PadWave",512,0,511);
      fCvsPadWave->cd();
     fPadWave -> Draw();
    
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
ATEventDrawTask::UpdateCvsPadWave()
{
    fCvsPadWave -> Modified();
    fCvsPadWave -> Update();
    
    TPaletteAxis *paxis
    = (TPaletteAxis *) fPadPlane->GetListOfFunctions()->FindObject("palette");

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

void
ATEventDrawTask::SelectPad()
{
    int event = gPad->GetEvent();
    if (event != 11) return; //may be comment this line
    TObject *select = gPad->GetSelected();
    if (!select) return;
    if (select->InheritsFrom(TH2Poly::Class())) {
        TH2Poly *h = (TH2Poly*)select;
        gPad->GetCanvas()->FeedbackMode(kTRUE);
        // Char_t *bin_name = h->GetBinName();
        
        int pyold = gPad->GetUniqueID();
        int px = gPad->GetEventX();
        int py = gPad->GetEventY();
        float uxmin = gPad->GetUxmin();
        float uxmax = gPad->GetUxmax();
        int pxmin = gPad->XtoAbsPixel(uxmin);
        int pxmax = gPad->XtoAbsPixel(uxmax);
        if(pyold) gVirtualX->DrawLine(pxmin,pyold,pxmax,pyold);
        gVirtualX->DrawLine(pxmin,py,pxmax,py);
        gPad->SetUniqueID(py);
        Float_t upx = gPad->AbsPixeltoX(px);
        Float_t upy = gPad->AbsPixeltoY(py);
        Double_t x = gPad->PadtoX(upx);
        Double_t y = gPad->PadtoY(upy);
        Int_t bin = h->FindBin(x,y);
        const char *bin_name = h->GetBinName(bin);
        //std::cout<<" X : "<<x<<"  Y: "<<y<<std::endl;
        //std::cout<<bin_name<<std::endl;
        std::cout<<" Bin number selected : "<<bin<<" Bin name :"<<bin_name<<std::endl;
        //ATEventDrawTask test;
        //test.DrawWave(bin);
        //ATEventDrawTask::DrawWave(bin);
       
    }
    
    
    
    /*int event = gPad->GetEvent();
     if (event != 11) return; //may be comment this line
     TObject *select = gPad->GetSelected();
     if (!select) return;
     if (select->InheritsFrom("TObject")) {
     TH2PolyBin *h = (TH2PolyBin*)select;
     gPad->GetCanvas()->FeedbackMode(kTRUE);
     Int_t bin = h->GetBinNumber();
     std::cout<<" Clicked on bin : "<<bin<<std::endl;
     }*/
    
}



void
ATEventDrawTask::DrawWave(Int_t PadNum)
{
    
    //Bool_t IsValid=kFALSE;
    //ATPad *pad = fRawevent->GetPad(0);
    //ATPad *pad= fRawevent->GetPad(PadNum,IsValid);
    //std::cout<<" Raw Event Pad Num "<<pad->GetPadNum()<<" Is Valid? : "<<IsValidPad<<std::endl;

    
}
