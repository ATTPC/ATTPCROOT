#include "ATHoughSpaceLine.hh"

ClassImp(ATHoughSpaceLine)

ATHoughSpaceLine::ATHoughSpaceLine()
{
}

ATHoughSpaceLine::~ATHoughSpaceLine()
{
}

TH2F* ATHoughSpaceLine::GetHoughSpace(TString ProjPlane)
{
}

void ATHoughSpaceLine::CalcHoughSpace(ATEvent* event,Bool_t YZplane,Bool_t XYplane, Bool_t XZplane){

	Int_t nHits = event->GetNumHits();


		for(Int_t iHit=0; iHit<nHits; iHit++){
			ATHit hit = event->GetHitArray()->at(iHit);
    			Int_t PadNumHit = hit.GetHitPadNum();
			if(hit.GetCharge()<fThreshold) continue;
   		        TVector3 position = hit.GetPosition();  			

			for(Int_t itheta = 0; itheta <1023; itheta++){
	 			Float_t angle = TMath::Pi()*(static_cast<Float_t>(itheta)/1023);
  	     			if(XZplane) Float_t d0 = (TMath::Cos(angle)*position.X())  +  (TMath::Sin(angle)*position.Z());	
			}
	
		  

		}

		

}
