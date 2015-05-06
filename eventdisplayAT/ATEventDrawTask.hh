/**
 * @brief Event display task
 * @author JungWoo Lee (Korea Univ.)
 *         Adapted for ATTPCROOT by Yassid Ayyad (NSCL)
 */

#pragma once

// FairRoot classes
#include "FairTask.h"
#include "FairLogger.h"

// ROOT classes
#include "TEvePointSet.h"
#include "TClonesArray.h"
#include "TVector3.h"

#include "TCanvas.h"
#include "TH2.h"
#include "TH1.h"
#include "TGraph.h"
#include "TH2Poly.h"

#include "ATEventManager.hh"
//#include "ATRiemannTrack.hh"
//#include "ATRiemannHit.hh"
#include "ATRawEvent.hh"
#include "ATEvent.hh"
#include "ATHoughSpaceLine.hh"
#include "ATHoughSpace.hh"
#include "ATHit.hh"
#include "AtTpcMap.h"

#ifndef __CINT__ // Boost 
#include <boost/multi_array.hpp>
#endif //__CINT__

class ATEventDrawTask : public FairTask
{
  public :
    ATEventDrawTask();
    ATEventDrawTask(TString modes);

    virtual ~ATEventDrawTask();

    virtual InitStatus Init();
    virtual void Exec(Option_t* option);
    void Reset();

    //void Set2DPlotRange(Int_t uaIdx);
    void SetThreshold(Int_t val) { fThreshold=val; }
    void UnpackHoughSpace()      { fUnpackHough=kTRUE; }
    void SetHitAttributes(Color_t, Size_t, Style_t);
    //void SetHitClusterAttributes(Color_t, Size_t, Style_t);
    //void SetRiemannAttributes(Color_t, Size_t, Style_t);
    
    static void SelectPad(const char *rawevt);
    void DrawWave(Int_t PadNum);
    
    void SetGeoOption(Option_t *option) {fGeoOption = option;}

    void SetProtoMap(TString map) {fMap = map;}
    

  protected :
    virtual void DrawPadPlane();
    virtual void DrawPadWave();
    virtual void DrawPadAll();
    virtual void DrawQEvent();
    virtual void DrawRhoVariance();
    virtual void DrawHoughSpace();
    
    AtTpcMap *fAtMapPtr;
    void UpdateCvsPadPlane();
    void UpdateCvsPadWave();
    void UpdateCvsPadAll();
    void UpdateCvsQEvent();
    void UpdateCvsRhoVariance();
    void UpdateCvsHoughSpace();
    
    void ResetPadAll();


    void DrawHitPoints();
    void DrawHSpace();
    //void DrawHitClusterPoints();
    //void DrawRiemannHits();


    Bool_t fIs2DPlotRange;
    Bool_t fUnpackHough;

    TClonesArray* fHitArray;
    //TClonesArray* fHitClusterArray;
    //TClonesArray* fRiemannTrackArray;
    //TClonesArray* fKalmanArray;
    TClonesArray* fRawEventArray;
    TClonesArray* fHoughSpaceArray;

    ATEventManager* fEventManager;
    ATRawEvent* fRawevent;
    
    AtTpcMap *fDetmap;

    Int_t fThreshold;
    Option_t* fGeoOption; //Chose Geometry of the detector: ATTPC (Default)-  Prototype 
    TString fMap;

    TEvePointSet* fHitSet;
    Color_t fHitColor;
    Size_t  fHitSize;
    Style_t fHitStyle;

    /*TEvePointSet* fHitClusterSet;
    Color_t fHitClusterColor;
    Size_t  fHitClusterSize;
    Style_t fHitClusterStyle;*/

    /*vector<TEvePointSet*> fRiemannSetArray;
    Color_t fRiemannColor;
    Size_t  fRiemannSize;
    Style_t fRiemannStyle;*/

    TCanvas* fCvsPadPlane;
    TH2Poly* fPadPlane;
    TCanvas* fCvsPadWave;
    TH1I*  fPadWave;
    TCanvas* fCvsPadAll;
    TH1I*  fPadAll[300];
    TCanvas* fCvsQEvent;
    TH1D* fQEventHist;
    TH1D* fQEventHist_H;
    TCanvas* fCvsHoughSpace;
    TH2F* fHoughSpace;
    TCanvas* fCvsRhoVariance;
    TH1D* fRhoVariance;
  
    
    
    Int_t fMinZ;
    Int_t fMaxZ;
    Int_t fMinX;
    Int_t fMaxX;

    ClassDef(ATEventDrawTask,1);
};
