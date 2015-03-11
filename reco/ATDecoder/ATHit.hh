
#ifndef ATHIT_H
#define ATHIT_H

#include "TROOT.h"
#include "TObject.h"
#include "TVector3.h"


class ATHit : public TObject {
  public:
    ATHit();
    ATHit(ATHit *hit);
    ATHit(Int_t hitID, TVector3 vec, Double_t charge);
    ATHit(Int_t hitID, Double_t x, Double_t y, Double_t z, Double_t charge);
    ~ATHit();

    //!< Track ID setter
    void SetTrackID(Int_t trackID);
    //!< Hit ID setter
    void SetHitID(Int_t hitID);
    //!< Hit setter
    void SetHit(Int_t hitID, TVector3 vec, Double_t charge);
    void SetHit(Int_t hitID, Double_t x, Double_t y, Double_t z, Double_t charge);
    //!< Position setter
    void SetPosition(TVector3 vec);
    void SetPosition(Double_t x, Double_t y, Double_t z);
    //!< Position sigma setter
    void SetPosSigma(TVector3 vec);
    void SetPosSigma(Double_t dx, Double_t dy, Double_t dz);
    //!< Charge setter
    void SetCharge(Double_t charge);
    //!< Clustered flag setter
    void SetIsClustered(Bool_t value = kTRUE);
    //!< Cluster stter
    void SetClusterID(Int_t clusterID);

    //!< Track ID getter
    Int_t GetTrackID();
    //!< Hit ID getter
    Int_t GetHitID();
    //!< Position getter
    TVector3 GetPosition();
    //!< Position sigma getter
    TVector3 GetPosSigma();
    //!< Charge getter
    Double_t GetCharge();
    //!< Clustered flag getter
    Bool_t IsClustered();
    //!< Cluster ID getter
    Int_t GetClusterID();

  private:
    //!< Track ID having this hit
    Int_t fTrackID;
    //!< Hit ID
    Int_t fHitID;
    //!< Position
    TVector3 fPosition;
    //!< Position error
    TVector3 fPositionSigma;
    //!< Charge
    Double_t fCharge;
    //!< Clustered flag
    Bool_t fIsClustered;
    //!< Cluster ID having this hit
    Int_t fClusterID;

  ClassDef(ATHit, 1);
};

#endif
