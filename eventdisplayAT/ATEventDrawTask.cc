/**
 * @brief Event display task
 * @author JungWoo Lee (Korea Univ.)
 *         Adapted for ATTPCROOT by Yassid Ayyad (NSCL)
 */

#include "FairRootManager.h"

#include "ATEventDrawTask.hh"


#include "TEveManager.h"
#include "TEveGeoShape.h"
#include "TGeoSphere.h"
#include "TEveTrans.h"
#include "TPaletteAxis.h"
#include "TStyle.h"
#include "TRandom.h"

#include "AtTpcMap.h"
#include "AtTpcProtoMap.h"
#include "TH2Poly.h"

#ifndef __CINT__ // Boost 
#include <boost/multi_array.hpp>
#endif //__CINT__

#include <iostream>

using namespace std;

ClassImp(ATEventDrawTask);

ATEventDrawTask::ATEventDrawTask()
: fIs2DPlotRange(kFALSE),
  fUnpackHough(kFALSE),
  fHitArray(0),
  //fHitClusterArray(0),
  //fRiemannTrackArray(0),
  //fKalmanArray(0),
  fEventManager(0),
  fRawevent(0),
  fHoughSpaceArray(0),
  fDetmap(0),
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
  fCvsPadAll(0),
  fCvsQEvent(0),
  fQEventHist(0),
  fQEventHist_H(0),
  fCvsHoughSpace(0),
  fHoughSpace(0),
  fCvsRhoVariance(0),
  fRhoVariance(0),
  fAtMapPtr(0),
  fMinZ(0),
  fMaxZ(1344),
  fMinX(432),
  fMaxX(-432)
{

  //fAtMapPtr = new AtTpcMap(); 
  fGeoOption="ATTPC";
  
    
    Char_t padhistname[256];
    
    
    for(Int_t i=0;i<300;i++){
        sprintf(padhistname,"pad_%d",i);
          fPadAll[i] = new TH1I(padhistname,padhistname,512,0,511);
        
       // fPadAll[i] = NULL;
    }

  

}

ATEventDrawTask::~ATEventDrawTask()
{
    
    //TODO Destroy pointers
    for(Int_t i=0;i<hitSphereArray.size();i++) delete hitSphereArray[i];
    delete x;
    hitSphereArray.clear();
}

InitStatus 
ATEventDrawTask::Init()
{

  TString option = fGeoOption;
  std::cout<<" =====  ATEventDrawTask::Init ====="<<std::endl;
  std::cout<<" =====  Current detector : "<<option.Data()<<std::endl;
  gROOT->Reset();
  FairRootManager* ioMan = FairRootManager::Instance();
  fEventManager = ATEventManager::Instance();

    if(option=="Prototype"){
      
      fDetmap  =  new AtTpcProtoMap();
      //TString fMap = "/Users/yassidayyad/fair_install/ATTPCROOT_v2_06042015/scripts/proto.map"; //TODO Put it as input of the run macro
      fDetmap->SetProtoMap(fMap.Data());
    }else{
      fDetmap  =  new AtTpcMap();
     }

     fDetmap->SetName("fMap");
     gROOT->GetListOfSpecials()->Add(fDetmap);

  fHitArray = (TClonesArray*) ioMan->GetObject("ATEventH"); // TODO: Why this confusing name? It should be fEventArray
  if(fHitArray) LOG(INFO)<<"Hit Array Found."<<FairLogger::endl;
 
     
  fRawEventArray = (TClonesArray*) ioMan->GetObject("ATRawEvent");
  if(fRawEventArray) LOG(INFO)<<"Raw Event Array  Found."<<FairLogger::endl;
 
  
  fHoughSpaceArray =  (TClonesArray*) ioMan->GetObject("ATHough");
  if(fHoughSpaceArray) LOG(INFO)<<"Hough Array Found."<<FairLogger::endl;
  

  //fHitClusterArray = (TClonesArray*) ioMan->GetObject("STEventHC");
  //if(fHitClusterArray) LOG(INFO)<<"Hit Cluster Found."<<FairLogger::endl;

  //fRiemannTrackArray = (TClonesArray*) ioMan->GetObject("STRiemannTrack");
  //if(fRiemannTrackArray) LOG(INFO)<<"Riemann Track Found."<<FairLogger::endl;

  //fKalmanArray = (TClonesArray*) ioMan->GetObject("STKalmanTrack");
  //if(fKalmanArray) LOG(INFO)<<"Kalman Track Found."<<FairLogger::endl;

 // gROOT->GetListOfSpecials()->Add(fRawEventArray);
  //fRawEventArray->SetName("ATRawEvent");

  gStyle -> SetPalette(55);
  fCvsPadWave = fEventManager->GetCvsPadWave();
  fCvsPadWave->SetName("fCvsPadWave");
  gROOT->GetListOfSpecials()->Add(fCvsPadWave);
  DrawPadWave();
  fCvsPadPlane = fEventManager->GetCvsPadPlane();// There is a problem if the pad plane is drawn first
  fCvsPadPlane -> ToggleEventStatus();
  fCvsPadPlane->AddExec("ex","ATEventDrawTask::SelectPad(\"fRawEvent\")");
  DrawPadPlane();
  fCvsPadAll = fEventManager->GetCvsPadAll();
  DrawPadAll();
  fCvsRhoVariance = new TCanvas("fCvsRhoVariance","fCvsRhoVariance");
  DrawRhoVariance();
  fCvsQEvent = new TCanvas("fCvsQEvent","fCvsQEvent");
  DrawQEvent();
  //******* NO CALLS TO TCANVAS BELOW HOUGHSPACE ONE
  fCvsHoughSpace = fEventManager->GetCvsHoughSpace();
  DrawHoughSpace();
 
  
}

void 
ATEventDrawTask::Exec(Option_t* option)
{
  Reset();
  ResetPadAll();
  
  
  if(fHitArray) DrawHitPoints();
  if(fHoughSpaceArray && fUnpackHough) DrawHSpace();
  
  //if(fHitClusterArray) DrawHitClusterPoints();
  //if(fRiemannTrackArray) DrawRiemannHits();

  gEve -> Redraw3D(kFALSE);
    
  UpdateCvsPadPlane();
  UpdateCvsPadWave();
  UpdateCvsPadAll();
  UpdateCvsQEvent();
  UpdateCvsRhoVariance();
  if(fUnpackHough) UpdateCvsHoughSpace();
}

void 
ATEventDrawTask::DrawHitPoints()
{
  hitSphereArray.clear();
  fQEventHist_H->Reset(0);
  ATEvent* event = (ATEvent*) fHitArray->At(0); // TODO: Why this confusing name? It should be fEventArray
  Double_t Qevent=event->GetEventCharge();
  Double_t RhoVariance=event->GetRhoVariance();
  if(fEventManager->GetEraseQEvent()){ 
	fQEventHist->Reset();
        fRhoVariance->Reset();
   
  }
  
  fQEventHist->Fill(Qevent);
  fQEventHist_H->Fill(Qevent);
  fRhoVariance->Fill(RhoVariance);
  fRawevent = (ATRawEvent*) fRawEventArray->At(0);
  fRawevent->SetName("fRawEvent");
  gROOT->GetListOfSpecials()->Add(fRawevent);
 
  
  
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
    //std::cout<<"  Hit number : "<<iHit<<" - ATHit Pad Number :  "<<PadNumHit<<" - Hit Charge : "<<hit.GetCharge()<<std::endl;
    if(hit.GetCharge()<fThreshold) continue;
    TVector3 position = hit.GetPosition();
    
    fHitSet->SetNextPoint(position.X()/10.,position.Y()/10.,position.Z()/10.); // Convert into cm
    fHitSet->SetPointId(new TNamed(Form("Hit %d",iHit),""));
    Int_t Atbin = fPadPlane->Fill(position.X(), position.Y(), hit.GetCharge());
    //std::cout<<"  Hit number : "<<iHit<<" - Position X : "<<position.X()<<" - Position Y : "<<position.Y()<<" - Position Z : "<<position.Z()<<" - ATHit Pad Number :  "<<PadNumHit<<" - Pad bin :"<<Atbin<<" - Hit Charge : "<<hit.GetCharge()<<std::endl;
      
   
     /*x = new TEveGeoShape("SS"); 
     x->SetShape(new TGeoSphere(0, 0.1*hit.GetCharge()/300.));
     x->RefMainTrans().SetPos(position.X()/10.,
                             position.Y()/10.,
                             position.Z()/10.);
     x->SetMainColor(TColor::GetColorPalette
                    (gRandom->Integer(TColor::GetNumberOfColors()))); 
     hitSphereArray.push_back(x);*/
     
    
     
  }
    
    
    //for(Int_t i=0;i<hitSphereArray.size();i++) gEve->AddElement(hitSphereArray[i]);
    
    
    Int_t nPads = fRawevent->GetNumPads();
    std::cout<<"Num of pads : "<<nPads<<std::endl;
  
    if(fEventManager->GetDrawAllPad()){
    
        for(Int_t iPad = 0;iPad<nPads;iPad++){
    
        
            ATPad *fPad = fRawevent->GetPad(iPad);
            //std::cout<<"Pad num : "<<iPad<<" Is Valid? : "<<fPad->GetValidPad()<<" Pad num in pad object :"<<fPad->GetPadNum()<<std::endl;
            Int_t *rawadc = fPad->GetRawADC();
            Double_t *adc = fPad->GetADC();
        
            for(Int_t j=0;j<512;j++){ // TODO: This is limited to 256 pads only. Increment the size of the array and put another option for ATTPC
            
                if (fPad->GetValidPad() && iPad<256){
                    
                    
                    fPadAll[iPad]->SetBinContent(j,rawadc[j]);
                    
                }
            
               
                
            }

            
            
            //delete fPad;
            //fPad= NULL;
        
        }
        
       
    }
    
    
    gEve -> AddElement(fHitSet);
}

void 
ATEventDrawTask::DrawHSpace()
{

   
    ATHoughSpaceLine* HoughSpace = (ATHoughSpaceLine*) fHoughSpaceArray->At(0);
    fHoughSpace = HoughSpace->GetHoughSpace("XZ");

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

   for(Int_t i=0;i<hitSphereArray.size();i++)  gEve->RemoveElement(hitSphereArray[i],fEventManager);
		// delete hitSphereArray[i];
		
   


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
      fPadWave = new TH1I("fPadWave","fPadWave",512,0,511);
      gROOT->GetListOfSpecials()->Add(fPadWave);
      fCvsPadWave->cd();
      fPadWave -> Draw();
    
}


void
ATEventDrawTask::DrawPadAll()
{

    fCvsPadAll->cd();
    
    for(Int_t i=0;i<300;i++){
    //fPadAll[i]->Reset(0);
    //fPadAll[i] = new TH1I("fPadAll","fPadAll",512,0,511);
    fPadAll[i]->GetYaxis()->SetRangeUser(0,2500);
    fPadAll[i] -> Draw("SAME");
    
    }
    
}


void
ATEventDrawTask::DrawQEvent()
{

   
   
   fQEventHist = new TH1D("fQEventHist","fQEventHist",300,0.,2000000.);
   fQEventHist_H = new TH1D("fQEventHist_H","fQEventHist_H",300,0.,2000000.);
   fQEventHist_H -> SetLineColor(kRed);
   fQEventHist_H -> SetFillStyle(1);
   fCvsQEvent->cd();
   fQEventHist -> Draw();
   fQEventHist_H -> Draw("SAMES");

}


void
ATEventDrawTask::DrawRhoVariance()
{
  
   fCvsRhoVariance->cd();
   fRhoVariance = new TH1D("fRhoVariance","fRhoVariance",4000,0.,1000000.);
   fRhoVariance -> Draw();
   fRhoVariance -> SetLineColor(kRed);
   
}


void
ATEventDrawTask::DrawHoughSpace()
{
   fCvsHoughSpace->cd();
   fHoughSpace = new TH2F();
   fHoughSpace->Draw("zcol");
}

void
ATEventDrawTask::UpdateCvsPadPlane()
{
  fHoughSpace->Draw("zcol");
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
    
  //  TPaletteAxis *paxis
  //  = (TPaletteAxis *) fPadPlane->GetListOfFunctions()->FindObject("palette");

}


void
ATEventDrawTask::UpdateCvsPadAll()
{
    fCvsPadAll -> Modified();
    fCvsPadAll -> Update();
    
  //  TPaletteAxis *paxis
   // = (TPaletteAxis *) fPadPlane->GetListOfFunctions()->FindObject("palette");
    
}


void
ATEventDrawTask::UpdateCvsQEvent()
{
    fCvsQEvent -> Modified();
    fCvsQEvent -> Update();
 
    
}

void
ATEventDrawTask::UpdateCvsRhoVariance()
{
    fCvsRhoVariance -> Modified();
    fCvsRhoVariance -> Update();
 
    
}


void
ATEventDrawTask::UpdateCvsHoughSpace()
{
    fCvsHoughSpace -> Modified();
    fCvsHoughSpace -> Update();
 
    
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
ATEventDrawTask::SelectPad(const char *rawevt)
{
    int event = gPad->GetEvent();
    if (event != 11) return; //may be comment this line
    TObject *select = gPad->GetSelected();
    if (!select) return;
    if (select->InheritsFrom(TH2Poly::Class())) {
        TH2Poly *h = (TH2Poly*)select;
        gPad->GetCanvas()->FeedbackMode(kTRUE);
         ATRawEvent* tRawEvent = NULL;
         tRawEvent = (ATRawEvent*)gROOT->GetListOfSpecials()->FindObject(rawevt);
         if(tRawEvent == NULL){ 
		std::cout<<" = ATEventDrawTask::SelectPad NULL pointer for the ATRawEvent! Please select an event first "<<std::endl;
		return;
	}

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
        std::cout<<" =========================="<<std::endl;
        std::cout<<" Bin number selected : "<<bin<<" Bin name :"<<bin_name<<std::endl;
        Bool_t IsValid = kFALSE;

        AtTpcMap *tmap = NULL;
        tmap = (AtTpcMap*)gROOT->GetListOfSpecials()->FindObject("fMap");
        //new AtTpcProtoMap();
        //TString map = "/Users/yassidayyad/fair_install/ATTPCROOT_v2_06042015/scripts/proto.map";
        //tmap->SetProtoMap(map.Data());
        Int_t tPadNum =tmap->BinToPad(bin);
        std::cout<<" Bin : "<<bin<<" to Pad : "<<tPadNum<<std::endl;
        ATPad *tPad = tRawEvent->GetPad(tPadNum,IsValid);
        std::cout<<" Event ID (Select Pad) : "<<tRawEvent->GetEventID()<<std::endl;
        std::cout<<" Raw Event Pad Num "<<tPad->GetPadNum()<<" Is Valid? : "<<IsValid<<std::endl;
        std::cout<<std::endl;
        //TH1D* tPadWaveSub = NULL;
        //tPadWaveSub = new TH1D("tPadWaveSub","tPadWaveSub",512.0,0.0,511.0);
        //tPadWaveSub->SetLineColor(kRed);
        TH1I* tPadWave = NULL;
        tPadWave = (TH1I*)gROOT->GetListOfSpecials()->FindObject("fPadWave");
        Int_t *rawadc = tPad->GetRawADC();
        Double_t *adc = tPad->GetADC();
        if(tPadWave == NULL){ 
            std::cout<<" = ATEventDrawTask::SelectPad NULL pointer for the TH1I! Please select an event first "<<std::endl;
            return;
	     }
         tPadWave->Reset();
         //tPadWaveSub->Reset();
        for(Int_t i=0;i<512;i++){
			
			      // tPadWave->SetBinContent(i,rawadc[i]);
                   tPadWave->SetBinContent(i,adc[i]);
         		   //tPadWaveSub->SetBinContent(i,adc[i]);

		    }
        
       
        
        TCanvas *tCvsPadWave = NULL;
        tCvsPadWave = (TCanvas*)gROOT->GetListOfSpecials()->FindObject("fCvsPadWave");
        if(tCvsPadWave == NULL){
            std::cout<<" = ATEventDrawTask::SelectPad NULL pointer for the TCanvas! Please select an event first "<<std::endl;
            return;
        }
        tCvsPadWave->cd();
        tPadWave->Draw();
        //tPadWaveSub->Draw("SAME");
        tCvsPadWave->Update();
    }
        
    
}



void
ATEventDrawTask::DrawWave(Int_t PadNum)
{
    
    //Bool_t IsValid=kFALSE;
    //ATPad *pad = fRawevent->GetPad(0);
    //ATPad *pad= fRawevent->GetPad(PadNum,IsValid);
    //std::cout<<" Raw Event Pad Num "<<pad->GetPadNum()<<" Is Valid? : "<<IsValidPad<<std::endl;

    
}

void
ATEventDrawTask::ResetPadAll()
{
    
    for(Int_t i=0;i<300;i++){
        fPadAll[i]->Reset(0);
    }

    
    
}
