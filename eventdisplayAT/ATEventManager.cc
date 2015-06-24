
#include "ATEventManager.hh"
#include "FairEventManagerEditor.h"

#include "TEveGeoNode.h"
#include "TEveManager.h"
#include "TEveProjectionManager.h"
#include "TEveScene.h"
#include "TEveViewer.h"
#include "TEveWindow.h"
#include "TEveBrowser.h"

#include "TRootEmbeddedCanvas.h"

#include "TGTab.h"
#include "TGLViewer.h"
#include "TGeoManager.h"
#include "TVirtualX.h"
#include "TGWindow.h"
#include "TGButton.h"
#include "TGLabel.h"
#include "TGWidget.h"




#include "TEveGedEditor.h"
#include "TGLEmbeddedViewer.h"
#include "TCanvas.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TObject.h"
#include "TH2.h"
#include "TH2Poly.h"
#include "TMultiGraph.h"
#include "TPolyLine.h"





#include <iostream>

class TGeoNode;


using namespace std;

ClassImp(ATEventManager);

ATEventManager* ATEventManager::fInstance=0;
ATEventManager* ATEventManager::Instance()
{
  return fInstance;
}

ATEventManager::ATEventManager()
: TEveEventManager("ATEventManager",""),
  fRootManager(FairRootManager::Instance()),
  fRunAna(FairRunAna::Instance()),
  fEntry(0),
  fEvent(0),
  fCurrentEvent(0),
  fCvsPadPlane(0),
  fPadWave(0),
  fPadAll(0),
  fCvsQEvent(0),
  fCvsHough(0),
  drawallpad(0),
  eraseQevent(0),
  drawHoughSpace(0),
  kDrawAllOn(0),
  kDrawAllOff(0),
  kEraseQ(0),
  kDrawHoughOn(0)

{
  fInstance=this;
   kEraseQ = kFALSE;
}

ATEventManager::~ATEventManager()
{
}

/*void
ATEventManager::InitRiemann(Int_t option, Int_t level, Int_t nNodes)
{
  TEveManager::Create();
  fRunAna->Init();
  fEvent= gEve->AddEvent(this);
}*/

void 
ATEventManager::Init(Int_t option, Int_t level, Int_t nNodes)
{

  gStyle->SetOptTitle(0);
  TEveManager::Create();
    
  Int_t  dummy;
  UInt_t width, height;
  UInt_t widthMax = 1400, heightMax = 650;
  Double_t ratio = (Double_t)widthMax/heightMax;
  gVirtualX->GetWindowSize(gClient->GetRoot()->GetId(), dummy, dummy, width, height);
  // Assume that width of screen is always larger than the height of screen
  if(width>widthMax){ width = widthMax; height = heightMax; } 
  else height = (Int_t)(width/ratio);
  //gEve->GetMainWindow()->Resize(width,height);

  /**************************************************************************/

  TEveWindowSlot* slot = 0;
  TEveWindowPack* pack = 0;

  // 3D
  slot = TEveWindow::CreateWindowInTab(gEve->GetBrowser()->GetTabRight());
  pack = slot->MakePack();
  pack->SetElementName("ATTPC 3D/Pad plane views");
  pack->SetHorizontal();
  //pack->SetVertical();
  pack->SetShowTitleBar(kFALSE);

  pack->NewSlot()->MakeCurrent();
  TEveViewer* view3D = gEve->SpawnNewViewer("3D View", "");
  view3D->AddScene(gEve->GetGlobalScene());
  view3D->AddScene(gEve->GetEventScene());
 
  

    // Old arrangement

 /* slot = pack->NewSlotWithWeight(1.5);
  TRootEmbeddedCanvas* ecvs = new TRootEmbeddedCanvas();
  TEveWindowFrame* frame = slot->MakeFrame(ecvs);
  frame->SetElementName("ATTPC Pad Plane");
  pack->GetEveFrame()->SetShowTitleBar(kFALSE);
  fCvsPadPlane = ecvs->GetCanvas();*/
    
    //New arrangement
    
    slot = pack->NewSlot();
    TEveWindowPack* pack2 = slot->MakePack();
    pack2->SetShowTitleBar(kFALSE);
    pack2->SetVertical();
    slot = pack2->NewSlot();
    slot->StartEmbedding();
    fPadWave = new TCanvas("ATPad Canvas");
    fPadWave->ToggleEditor();
    slot->StopEmbedding();
    
    /*slot = pack2->NewSlot();
    slot->StartEmbedding();
    fCvsPadPlane = new TCanvas("ATPoly");
    fPadWave->ToggleEditor();
    slot->StopEmbedding();
    fCvsPadPlane->AddExec("ex","ATEventManager::DrawWave()");*/
    
    
    // Pad Plane
    slot = pack2->NewSlotWithWeight(1.5);
    TRootEmbeddedCanvas* ecvs = new TRootEmbeddedCanvas();
    TEveWindowFrame* frame = slot->MakeFrame(ecvs);
    frame->SetElementName("ATTPC Pad Plane");
    pack->GetEveFrame()->SetShowTitleBar(kFALSE);
    fCvsPadPlane = ecvs->GetCanvas();
    //fCvsPadPlane->AddExec("ex","ATEventManager::DrawWave()"); //OBSOLETE DO NOT USE

    //A test
    /*slot = pack2->NewSlotWithWeight(1.5);
    TRootEmbeddedCanvas* ecvs2 = new TRootEmbeddedCanvas();
    TEveWindowFrame* frame2 = slot->MakeFrame(ecvs2);
    frame2->SetElementName("ATTPC Pad Plane All");
    fPadAll = ecvs2->GetCanvas();*/
    
    
    //Third tab
    TEveWindowSlot* slot2 =
    TEveWindow::CreateWindowInTab(gEve->GetBrowser()->GetTabRight());
    TEveWindowPack* pack3 = slot2->MakePack();
    pack3->SetShowTitleBar(kFALSE);
    pack3->SetElementName("Pad plane raw signals");
    
    slot2 = pack3->NewSlotWithWeight(1.5);
    TRootEmbeddedCanvas* ecvs3 = new TRootEmbeddedCanvas();
    TEveWindowFrame* frame3 = slot2->MakeFrame(ecvs3);
    frame3->SetElementName("ATTPC Pad Plane All");
    fPadAll = ecvs3->GetCanvas();
   /* TEveWindowSlot* slot2 =
    TEveWindow::CreateWindowInTab(gEve->GetBrowser()->GetTabRight());
    TEveWindowPack* pack3;
    pack3 = slot2->MakePack();
    //pack3->SetShowTitleBar(kFALSE);
    pack3->SetHorizontal();
    pack3->SetElementName("Pad Plane Raw Signals");
    TRootEmbeddedCanvas* ecvs2 = new TRootEmbeddedCanvas();
    
    
    //TEveWindowFrame* frame2 = slot2->MakeFrame(ecvs2);
    
    
    
    fPadAll = ecvs2->GetCanvas();*/
    
    //fPadAll = new TCanvas();
   
    
     //Forth tab Reconstruction
    TEveWindowSlot* slot3 =
    TEveWindow::CreateWindowInTab(gEve->GetBrowser()->GetTabRight());
    TEveWindowPack* pack4 = slot3->MakePack();
    pack4->SetShowTitleBar(kFALSE);
    pack4->SetElementName("Reconstruction");
    slot3 = pack4->NewSlotWithWeight(1.5);
    TRootEmbeddedCanvas* ecvs4 = new TRootEmbeddedCanvas();
    TEveWindowFrame* frame4 = slot3->MakeFrame(ecvs4);
    frame4->SetElementName("Hough Space");
    fCvsHough = ecvs4->GetCanvas();


       //Fifth tab Phi Reconstruction
    TEveWindowSlot* slot4 =
    TEveWindow::CreateWindowInTab(gEve->GetBrowser()->GetTabRight());
    TEveWindowPack* pack5 = slot4->MakePack();
    pack5->SetShowTitleBar(kFALSE);
    pack5->SetElementName("Prototype Phi Recons.");
    slot4 = pack5->NewSlotWithWeight(1.5);
    TRootEmbeddedCanvas* ecvs5 = new TRootEmbeddedCanvas();
    TEveWindowFrame* frame5 = slot4->MakeFrame(ecvs5);
    frame5->SetElementName("Phi Reconstruction");
    fCvsPhi = ecvs5->GetCanvas();
   
 
  /**************************************************************************/

  fRunAna->Init();

  if(gGeoManager) {
    TGeoNode* geoNode = gGeoManager->GetTopNode();
    TEveGeoTopNode* topNode
      = new TEveGeoTopNode(gGeoManager, geoNode, option, level, nNodes);
    gEve->AddGlobalElement(topNode);

    Int_t transparency = 80;
     
    //gGeoManager -> DefaultColors();
    //gGeoManager -> GetVolume("field_cage_in")     -> SetVisibility(kFALSE); //active
    gGeoManager -> GetVolume("drift_volume")         -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("cageSide")          -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("cageCorner")        -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("frontWindow")       -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("frontWindowFrame")  -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("frontWindowCradle") -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("bottomPlate")       -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("backWindowFrame")   -> SetTransparency(transparency);
    ////gGeoManager -> GetVolume("backWindow")        -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("topFrame")          -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("ribmain")           -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("wirePlane")         -> SetTransparency(transparency);
    //gGeoManager -> GetVolume("padPlane")          -> SetTransparency(transparency);

    gEve->FullRedraw3D(kTRUE);
    fEvent= gEve->AddEvent(this);
  }

  /**************************************************************************/

  gEve->GetBrowser()->GetTabRight()->SetTab(1);
   make_gui();
    
  gEve->Redraw3D(kTRUE, kTRUE);

  TGLViewer *dfViewer = gEve->GetDefaultGLViewer(); //Is this doing anything?
  dfViewer->CurrentCamera().RotateRad(-.7, 0.5);
  dfViewer->DoDraw();

  //RunEvent();
}

void ATEventManager::SelectEvent()
{
   GotoEvent(fCurrentEvent->GetIntNumber());
   // cout<<fCurrentEvent->GetIntNumber()<<endl;

}

void 
ATEventManager::GotoEvent(Int_t event)
{
    
  fEntry=event;
  std::cout<<" Event number : "<<fEntry<<std::endl;
  fRunAna->Run((Long64_t)event);
  
}

void 
ATEventManager::NextEvent()
{
  fEntry+=1;
  std::cout<<" Event number : "<<fEntry<<std::endl;
  fRunAna->Run((Long64_t)fEntry);
    
}

void 
ATEventManager::PrevEvent()
{
  fEntry-=1;
  std::cout<<" Event number : "<<fEntry<<std::endl;
  fRunAna->Run((Long64_t)fEntry);
  
}

void
ATEventManager::DrawWave()
{
    int event = gPad->GetEvent();
    if (event != 11) return; //may be comment this line
    TObject *select = gPad->GetSelected();
    if (!select) return;
    if (select->InheritsFrom(TH2::Class())) {
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
ATEventManager::RunEvent()
{
  fRunAna->Run((Long64_t)fEntry);
}




void
ATEventManager::make_gui()
{
    // Create minimal GUI for event navigation.
    
       TChain* chain =FairRootManager::Instance()->GetInChain();
       Int_t Entries= chain->GetEntriesFast();
    
    TEveBrowser* browser = gEve->GetBrowser();
    browser->StartEmbedding(TRootBrowser::kLeft);
    
    TGMainFrame* frmMain = new TGMainFrame(gClient->GetRoot(), 1000, 600);
    frmMain->SetWindowName("XX GUI");
    frmMain->SetCleanup(kDeepCleanup);
    
    TGVerticalFrame* hf = new TGVerticalFrame(frmMain);
    {
        
       // TString icondir( Form("%s/icons/", gSystem->Getenv("VMCWORKDIR")) );
      //  TGPictureButton* b = 0;
       
           //EvNavHandler    *fh = new EvNavHandler;
        //ATEventManager *fh = new ATEventManager; //Wrong!! Another instance produces different events
        
        
     
        
        drawallpad = new TGTextButton(hf, "&Enable Draw All Pads");
        drawallpad -> SetToolTipText("Press to Enable/Disble drawing of all pads signal\n (Display on ATTPC Pad Plane Raw Signals tab) ",400);
        drawallpad->Connect("Clicked()", "ATEventManager", fInstance, "ChangeDrawAllPads()");
        hf->AddFrame(drawallpad, new TGLayoutHints(kLHintsCenterX, 5, 5, 3, 4));

        eraseQevent = new TGTextButton(hf, "&Erase Q Event Pad");
        eraseQevent -> SetToolTipText("Press to erase Event Q histogram upon calling the next event",400);
        eraseQevent->Connect("Clicked()", "ATEventManager", fInstance, "EraseQEvent()");
        hf->AddFrame(eraseQevent, new TGLayoutHints(kLHintsCenterX, 5, 5, 3, 4));

        drawHoughSpace = new TGTextButton(hf, "&Enable Hough Space");
        drawHoughSpace -> SetToolTipText("Press to enable Hough Space visualization",400);
        drawHoughSpace ->Connect("Clicked()", "ATEventManager", fInstance, "EnableDrawHoughSpace()");
        hf->AddFrame(drawHoughSpace, new TGLayoutHints(kLHintsCenterX, 5, 5, 3, 4));


      /*  b = new TGPictureButton(hf, gClient->GetPicture(icondir+"arrow_left.gif"));
        hf->AddFrame(b);
        b->Connect("Clicked()", "ATEventManager", fInstance, "PrevEvent()");
      
        b = new TGPictureButton(hf, gClient->GetPicture(icondir+"arrow_right.gif"));
        hf->AddFrame(b);
        b->Connect("Clicked()", "ATEventManager", fInstance, "NextEvent()");*/
        
       // b = new TGPictureButton(hf, gClient->GetPicture(icondir+"goto.gif"));
       // hf->AddFrame(b);
       // b->Connect("Clicked()", "ATEventManager", fInstance, "GotoEvent(Int_t)");
    }

    TGHorizontalFrame* hf_2 = new TGHorizontalFrame(frmMain);
    {

	 TString icondir( Form("%s/icons/", gSystem->Getenv("VMCWORKDIR")) );
         TGPictureButton* b = 0;

         b = new TGPictureButton(hf_2, gClient->GetPicture(icondir+"arrow_left.gif"));
        hf_2->AddFrame(b);
        b->Connect("Clicked()", "ATEventManager", fInstance, "PrevEvent()");
      
        b = new TGPictureButton(hf_2, gClient->GetPicture(icondir+"arrow_right.gif"));
        hf_2->AddFrame(b);
        b->Connect("Clicked()", "ATEventManager", fInstance, "NextEvent()");

    }
    
    frmMain->AddFrame(hf);
    frmMain->AddFrame(hf_2);
    


    TString Infile= "Input file : ";
    //  TFile* file =FairRunAna::Instance()->GetInputFile();
    TFile* file =FairRootManager::Instance()->GetInChain()->GetFile();
    Infile+=file->GetName();
    TGLabel* TFName=new TGLabel(frmMain, Infile.Data());
    frmMain->AddFrame(TFName);
    
    UInt_t RunId= FairRunAna::Instance()->getRunId();
    TString run= "Run Id : ";
    run += RunId;
    TGLabel* TRunId=new TGLabel(frmMain, run.Data());
    frmMain->AddFrame( TRunId);
    
    TString nevent= "No of events : ";
    nevent +=Entries ;
    TGLabel* TEvent=new TGLabel(frmMain, nevent.Data());
    frmMain->AddFrame(TEvent);


    
    TGHorizontalFrame* f = new TGHorizontalFrame(frmMain);
    TGLabel* l = new TGLabel(f, "Current Event:");
    f->AddFrame(l, new TGLayoutHints(kLHintsLeft | kLHintsCenterY, 1, 2, 1, 1));
    
    
    
      fCurrentEvent = new TGNumberEntry(f, 0., 6, -1,
                                      TGNumberFormat::kNESInteger, TGNumberFormat::kNEANonNegative,
                                      TGNumberFormat::kNELLimitMinMax, 0, Entries);
      f->AddFrame(fCurrentEvent, new TGLayoutHints(kLHintsLeft, 1, 1, 1, 1));
      fCurrentEvent->Connect("ValueSet(Long_t)","ATEventManager",fInstance, "SelectEvent()");
      frmMain->AddFrame(f);

    
    
    
    frmMain->MapSubwindows();
    frmMain->Resize();
    frmMain->MapWindow();
    
    browser->StopEmbedding();
    browser->SetTabTitle("ATTPC Event Control", 0);
}

void
ATEventManager::ChangeDrawAllPads()
{
    drawallpad->SetState(kButtonDown);
    if (!kDrawAllOn) {
        drawallpad->SetText("&Disable Draw All Pads");
        kDrawAllOn = kTRUE;
    } else {
        drawallpad->SetText("&Enable Draw All Pads");
        kDrawAllOn = kFALSE;
    }
    drawallpad->SetState(kButtonUp);
}

void
ATEventManager::EnableDrawHoughSpace(){

     drawHoughSpace->SetState(kButtonDown);
     if (!kDrawHoughOn){
	 drawHoughSpace->SetText("&Disable Hough Space");
         kDrawHoughOn = kTRUE;
    } else {
        drawHoughSpace->SetText("&Enable Hough Space");
        kDrawHoughOn = kFALSE;
    }
       drawHoughSpace->SetState(kButtonUp);

}

void
ATEventManager::EraseQEvent()
{
   
    kEraseQ=kTRUE;

}














