#include "ATHoughSpaceLine.hh"

ClassImp(ATHoughSpaceLine)

ATHoughSpaceLine::ATHoughSpaceLine()
{
    HoughPar.clear();
    HistHoughXZ = new TH2F("HistHoughXZ","HistHoughXZ",500,0,3.15,500,0,300);
}

ATHoughSpaceLine::~ATHoughSpaceLine()
{
	delete HistHoughXZ;
}

TH2F* ATHoughSpaceLine::GetHoughSpace(TString ProjPlane)
{

       
       return HistHoughXZ;

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
               	    		 if(XZplane){
                      	 		 Float_t d0_XZ = (TMath::Cos(angle)*position.X())  +  (TMath::Sin(angle)*position.Z());
                      			 HistHoughXZ->Fill(angle,d0_XZ);
                       			 HoughPar.push_back(angle);
                        		 HoughPar.push_back(d0_XZ);
                       			 //HoughMap_XZ.insert(std::pair<std::vector<Float_t>,Int_t>(HoughPar,0));
                      		         HoughMap_XZ[HoughPar]++;
                                         HoughPar.clear();

                   		 }
                
			}
	
		  

	        }

         
		

}
