#include "ATPhiReco.hh"

// FairRoot classes
#include "FairRuntimeDb.h"
#include "FairRun.h"

// STL
#include <algorithm>


ClassImp(ATPhiReco)

ATPhiReco::ATPhiReco()
{
  
    //TODO: IS THIS NEEDED??? 
 /* fLogger = FairLogger::GetLogger();

  FairRun *run = FairRun::Instance();
  if (!run)
    fLogger -> Fatal(MESSAGE_ORIGIN, "No analysis run!");

  FairRuntimeDb *db = run -> GetRuntimeDb();
  if (!db)
    fLogger -> Fatal(MESSAGE_ORIGIN, "No runtime database!");

  fPar = (ATDigiPar *) db -> getContainer("ATDigiPar");
  if (!fPar)
    fLogger -> Fatal(MESSAGE_ORIGIN, "ATDigiPar not found!!");*/

 
}

ATPhiReco::~ATPhiReco()
{
}

Double_t ATPhiReco::PhiCalc(ATProtoQuadrant *quadrant)
{

     Double_t phi=0.0;
     Double_t a=0.5; //Small size of the strip
     Double_t da; //
 
  
     // TODO This function is tuned for prototype micromegas, 
       Int_t nHits = quadrant->GetNumHits();
		if(nHits>1){
		      std::cout<<" Number of hits in quadrant  : "<<nHits<<std::endl;
		       for(Int_t iHit=0; iHit<nHits-1; iHit++){
			  ATHit qhit_f = quadrant->GetHitArray()->at(iHit); //First strip
			  ATHit qhit_s = quadrant->GetHitArray()->at(iHit+1); //Second strip
			  Int_t PadNum_qf = qhit_f.GetHitPadNum();
			  Int_t PadNum_qs = qhit_s.GetHitPadNum();
			  Double_t Q_f = qhit_f.GetCharge(); //TODO: For the moment we asume the charge to be the amplitude
			  Double_t Q_s = qhit_s.GetCharge(); 
                         	 if(PadNum_qf<11) da=1.0-a;
			  	 else da=3.2-a;
                                 if(PadNum_qs<11) da=1.0-a;
			  	 else da=3.2-a;
                                 phi= ( 1 - (((Q_f-Q_s)/(Q_f+Q_s))*2.0*a/da) - (Q_f-Q_s)/(Q_f+Q_s) )*45.0;
                     		 std::cout<<" First Hit Pad : "<<PadNum_qf<<" First Pad Charge : "<<Q_f<<std::endl;
                                 std::cout<<" Second Hit Pad : "<<PadNum_qs<<" Second Pad Charge : "<<Q_s<<std::endl;
				 std::cout<<" Phi : "<<phi<<std::endl;
 
		       }
                 }//nHits>1

}
















