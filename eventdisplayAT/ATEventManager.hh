#pragma once

#include "TEveEventManager.h"
#include "FairEventManager.h"
#include "TGNumberEntry.h"

#include "FairRunAna.h"
#include "FairRootManager.h"
#include "FairTask.h"

#include "TCanvas.h"

#ifndef __CINT__ // Boost
#include <boost/multi_array.hpp>
#endif //__CINT__

class TGListTreeItem;

class ATEventManager : public TEveEventManager
{
  public : 
    static ATEventManager* Instance();
    ATEventManager();
    virtual ~ATEventManager();

    virtual void GotoEvent(Int_t event); ///< *MENU*
    virtual void NextEvent();            ///< *MENU*
    virtual void PrevEvent();            ///< *MENU*
    virtual void make_gui();
    virtual void SelectEvent();
    static void DrawWave();
    void ChangeDrawAllPads();
    void EnableDrawHoughSpace();
    void EraseQEvent();

    void AddTask(FairTask* task) { fRunAna->AddTask(task); }
    //virtual void InitRiemann(Int_t option=1, Int_t level=3, Int_t nNodes=10000);
    virtual void Init(Int_t option=1, Int_t level=3, Int_t nNodes=10000);

    virtual Int_t GetCurrentEvent() {return fEntry;}

    TCanvas* GetCvsPadPlane() { return fCvsPadPlane; }
    TCanvas* GetCvsPadWave() { return fPadWave; }
    TCanvas* GetCvsPadAll() { return fPadAll; }
    TCanvas* GetCvsQEvent() { return fCvsQEvent; }
    TCanvas* GetCvsHoughSpace() { return fCvsHough; }
    Bool_t GetDrawAllPad() { return kDrawAllOn; }
    Bool_t GetDrawHoughSpace() { return kDrawHoughOn; }
    Bool_t GetEraseQEvent() {Bool_t EraseBuff = kEraseQ; kEraseQ=kFALSE; return EraseBuff; }

    void RunEvent();
    

  private :
    FairRootManager* fRootManager;
    FairRunAna* fRunAna;
    
    
    Int_t fEntry;
    TGListTreeItem* fEvent;
    TGNumberEntry*  fCurrentEvent;
    TCanvas* fCvsPadPlane;
    TCanvas* fPadWave;
    TCanvas* fPadAll;
    TCanvas* fCvsQEvent;
    TCanvas* fCvsHough;

    TGTextButton *drawallpad;
    TGTextButton *eraseQevent;
    TGTextButton *drawHoughSpace;
    Bool_t kDrawAllOn;
    Bool_t kDrawAllOff;
    Bool_t kEraseQ;
    Bool_t kDrawHoughOn;

    static ATEventManager* fInstance;

    ATEventManager(const ATEventManager&);
    ATEventManager& operator=(const ATEventManager&);
    


  ClassDef(ATEventManager,1);
};


