#ifndef ATEVENT_H
#define ATEVENT_H

#include "TROOT.h"
#include "TObject.h"

#include <vector>

#include "ATHit.hh"
//#include "STHitCluster.hh"
//#include "STTrack.hh"

using std::vector;

class ATEvent : public TNamed {
  public:
    ATEvent(Bool_t isClustered = kFALSE, Bool_t isTracked = kFALSE, Bool_t isChanged = kFALSE);
    ATEvent(ATEvent *object);
    ~ATEvent();

    // setters
    void SetEventID(Int_t evtid);
    void AddHit(ATHit *hit);
    void SetHitArray(vector<ATHit> *hitArray);
    //void AddCluster(ATHitCluster *cluster); //TODO Implement clustering
    //void SetClusterArray(vector<ATHitCluster> *clusterArray);
//    void AddTrack(STTrack *track);
//    void SetTrackArray(vector<STTrack> &trackArray);

    void SetIsClustered(Bool_t value);
    void SetIsTracked(Bool_t value);
    void SetIsChanged(Bool_t value);

    void SetIsGood(Bool_t value);

    // getters
    Int_t GetEventID();

    Int_t GetNumHits();
    ATHit *GetHit(Int_t hitNo);
    void RemoveHit(Int_t hitNo);
    vector<ATHit> *GetHitArray();

    Int_t GetNumClusters();
    //ATHitCluster *GetCluster(Int_t clusterNo);
    //void RemoveCluster(Int_t clusterNo);
    //vector<ATHitCluster> *GetClusterArray();

//    Int_t GetNumTracks();
//    STTrack *GetTrack(Int_t trackNo);
//    STTrack *RemoveTrack(Int_t trackNo);
//    vector<STTrack> *GetTrackArray();

    Bool_t IsClustered();
    Bool_t IsTracked();
    Bool_t IsChanged();

    Bool_t IsGood();

  private:
    Bool_t fIsClustered;
    Bool_t fIsTracked;
    Bool_t fIsChanged;

    Bool_t fIsGood;

    Int_t fEventID;

    vector<ATHit> fHitArray;
    //vector<ATHitCluster> fClusterArray;
//    vector<STTrack> fTrackArray;

  ClassDef(ATEvent, 2);
};

#endif
