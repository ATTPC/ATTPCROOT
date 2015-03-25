
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
  fCvsPadPlane(0)
{
  fInstance=this;
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
  pack->SetElementName("Overview");
  pack->SetHorizontal();
  pack->SetShowTitleBar(kFALSE);

  pack->NewSlot()->MakeCurrent();
  TEveViewer* view3D = gEve->SpawnNewViewer("3D View", "");
  view3D->AddScene(gEve->GetGlobalScene());
  view3D->AddScene(gEve->GetEventScene());


  slot = pack->NewSlotWithWeight(1.5);
  TRootEmbeddedCanvas* ecvs = new TRootEmbeddedCanvas();
  TEveWindowFrame* frame = slot->MakeFrame(ecvs);
  frame->SetElementName("ATTPC Pad Plane");
  pack->GetEveFrame()->SetShowTitleBar(kFALSE);
  fCvsPadPlane = ecvs->GetCanvas();

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
    
    TGHorizontalFrame* hf = new TGHorizontalFrame(frmMain);
    {
        
        TString icondir( Form("%s/icons/", gSystem->Getenv("VMCWORKDIR")) );
        TGPictureButton* b = 0;
        //EvNavHandler    *fh = new EvNavHandler;
        //ATEventManager *fh = new ATEventManager; //Wrong!! Another instance produces different events
        
        
        b = new TGPictureButton(hf, gClient->GetPicture(icondir+"arrow_left.gif"));
        hf->AddFrame(b);
        b->Connect("Clicked()", "ATEventManager", fInstance, "PrevEvent()");
      
        b = new TGPictureButton(hf, gClient->GetPicture(icondir+"arrow_right.gif"));
        hf->AddFrame(b);
        b->Connect("Clicked()", "ATEventManager", fInstance, "NextEvent()");
        
        
       // b = new TGPictureButton(hf, gClient->GetPicture(icondir+"goto.gif"));
       // hf->AddFrame(b);
       // b->Connect("Clicked()", "ATEventManager", fInstance, "GotoEvent(Int_t)");
    }
    
    frmMain->AddFrame(hf);
    
    
   /* TString Infile= "Input file : ";
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
    frmMain->AddFrame(TEvent);*/


    
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
