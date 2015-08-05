#include "ATTPC2Body.h"

#include "FairPrimaryGenerator.h"
#include "FairRootManager.h"
#include "FairLogger.h"
#include "FairMCEventHeader.h"

#include "FairIon.h"
#include "FairRunSim.h"
#include "FairRunAna.h"

#include "TDatabasePDG.h"
#include "TParticlePDG.h"
#include "TObjArray.h"
                    
#include "TRandom.h"
#include "TMath.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TGenPhaseSpace.h"
#include "TVirtualMC.h"
#include "TParticle.h"
#include "TClonesArray.h"

  
#include "FairRunSim.h"
#include "FairIon.h"
#include <iostream>
#include "TParticle.h"

#include "AtStack.h"
#include "AtTpcPoint.h"
#include "ATVertexPropagator.h"

Int_t ATTPC2Body::fgNIon = 0;


ATTPC2Body::ATTPC2Body()
  : fMult(0),          
    fPx(0.), fPy(0.), fPz(0.),
    fVx(0.), fVy(0.), fVz(0.),
    fIon(0),  fQ(0)
{
//  cout << "-W- ATTPCIonGenerator: "
//      << " Please do not use the default constructor! " << endl;
}

// -----   Default constructor   ------------------------------------------
ATTPC2Body::ATTPC2Body(const char* name,std::vector<Int_t> *z,std::vector<Int_t> *a,std::vector<Int_t> *q, Int_t mult, std::vector<Double_t> *px, 
	std::vector<Double_t>* py,std::vector<Double_t> *pz, std::vector<Double_t> *mass, std::vector<Double_t> *Ex,Double_t ResEner)
  : fMult(0),          
    fPx(0.), fPy(0.), fPz(0.),
    fVx(0.), fVy(0.), fVz(0.),
    fIon(0),  fQ(0)
{

   
  fgNIon++;
  fMult = mult;
  fIon.reserve(fMult);
  fThetaCmsMax = 45;
  fThetaCmsMin = 0;
  
  fNoSolution = kFALSE;

  char buffer[20];
  
 /* fBeamEnergy_buff = ResEner;
  fBeamMass = BMass;
  fTargetMass = TMass;
  fZBeam = ZB;
  fABeam = AB;
  fPxBeam = PxB;
  fPyBeam = PyB;
  fPzBeam = PzB;*/
  
  
      for(Int_t i=0;i<fMult;i++){

             
  	fPx.push_back( Double_t(a->at(i)) * px->at(i) );
	fPy.push_back( Double_t(a->at(i)) * py->at(i) );
	fPz.push_back( Double_t(a->at(i)) * pz->at(i) );
	Masses.push_back(mass->at(i)*1000.0);
        fExEnergy.push_back(Ex->at(i));
        fWm.push_back( mass->at(i)*1000.0 + Ex->at(i));
         
        
        sprintf(buffer, "Product_Ion%d", i); 
        FairIon *IonBuff = new FairIon(buffer, z->at(i), a->at(i), q->at(i),0.0,mass->at(i));
	//std::cout<<" Z "<<z->at(i)<<" A "<<a->at(i)<<std::endl;
	//std::cout<<buffer<<std::endl;
        fIon.push_back(IonBuff);

        
       }
 
  FairRunSim* run = FairRunSim::Instance();
  if ( ! run ) {
    std::cout << "-E- FairIonGenerator: No FairRun instantised!" << std::endl;
    Fatal("FairIonGenerator", "No FairRun instantised!");
  }

   for(Int_t i=0;i<fMult;i++){
       
  	run->AddNewIon(fIon.at(i));
	std::cout<<" Z "<<z->at(i)<<" A "<<a->at(i)<<std::endl;
	std::cout<<fIon.at(i)->GetName()<<std::endl;
       
    }

  

}

// -----   Destructor   ---------------------------------------------------
ATTPC2Body::~ATTPC2Body()
{
 // if (fIon) delete fIon;
}

// -----   Public method ReadEvent   --------------------------------------
Bool_t ATTPC2Body::ReadEvent(FairPrimaryGenerator* primGen) {


    std::vector<Double_t> Ang;				     // Lab Angle of the products
    std::vector<Double_t> Ene;                                // Lab Energy of the products
    Ang.reserve(2);
    Ang.reserve(2); 
    fPx.clear();
    fPy.clear();
    fPx.clear();
   
    fPx.resize(fMult);
    fPy.resize(fMult);
    fPx.resize(fMult);
  

   
   Double_t thetacmsInput = fThetaCmsMin + ((fThetaCmsMax-fThetaCmsMin)*gRandom->Uniform());
   std::cout<<" Random CMS Theta angle in degrees : "<<thetacmsInput<<std::endl;
   const Double_t rad2deg = 0.0174532925;
   
   AtStack* stack = (AtStack*) gMC->GetStack();

   fIsDecay = kFALSE;
   

   fBeamEnergy = gATVP->GetEnergy(); 
   std::cout<<" Residual energy in ATTPC2Body : "<<gATVP->GetEnergy()<<std::endl;
   
   fPxBeam = gATVP->GetPx();
   fPyBeam = gATVP->GetPy();
   fPzBeam = gATVP->GetPz();

   Double_t eb=fBeamEnergy+fWm.at(0);
   Double_t pb2=fBeamEnergy*fBeamEnergy+2.0*fBeamEnergy*fWm.at(0);
   Double_t pb=TMath::Sqrt(pb2);
   Double_t beta=pb/(eb+fWm.at(1));
   Double_t gamma=1.0/sqrt(1.0-beta*beta);
 

   
   Double_t thetacms=thetacmsInput*rad2deg;  // degree to radian

  
   Double_t thetacmr=TMath::Pi()-thetacms;
   Double_t e=fBeamEnergy+fWm.at(0)+fWm.at(1);
   Double_t e_cm2 = e*e-pb2;
   Double_t e_cm  = TMath::Sqrt(e_cm2);
   Double_t t_cm  = e_cm-fWm.at(2)-fWm.at(3);


  if(t_cm<0.0){
    std::cout << "-I- ATTPC2Body : No solution!"<<std::endl;
    fNoSolution=kTRUE;
   // return kFALSE;
  }

   Double_t t_cm2=t_cm*t_cm;
   Double_t t3_cm=(t_cm2+2.*fWm.at(3)*t_cm)/(t_cm+fWm.at(2)+fWm.at(3))/2.0; 
   Double_t t4_cm=(t_cm2+2.*fWm.at(2)*t_cm)/(t_cm+fWm.at(2)+fWm.at(3))/2.0;
   Double_t p3_cm2=t3_cm*t3_cm+2.0*t3_cm*fWm.at(2);
   Double_t p3_cm =TMath::Sqrt(p3_cm2);
   Double_t tg_thetalabs=p3_cm*TMath::Sin(thetacms)/(gamma*(p3_cm*TMath::Cos(thetacms)+beta*TMath::Sqrt(p3_cm*p3_cm+fWm.at(2)*fWm.at(2))));

  if(tg_thetalabs>=1.0e6){
    Ang.push_back(TMath::Pi()/2.0);
  }
  else{
    Ang.push_back(TMath::ATan(tg_thetalabs));
  }

  if(Ang.at(0)<0.0) Ang.at(0)=TMath::Pi()+Ang.at(0);

  Double_t p4_cm2=t4_cm*t4_cm+2.*t4_cm*fWm.at(3);
  Double_t p4_cm =TMath::Sqrt(p4_cm2);
  Double_t tg_thetalabr=p4_cm*TMath::Sin(thetacmr)/(gamma*(p4_cm*TMath::Cos(thetacmr)+beta*TMath::Sqrt(p4_cm*p4_cm+fWm.at(3)*fWm.at(3))));
  //std::cout<<" tg_thetalabr : "<<tg_thetalabr<<std::endl;

  if(tg_thetalabr>1.0e6){
    Ang.push_back(TMath::Pi()/2.0);
  }
  else{
    Ang.push_back(TMath::ATan(tg_thetalabr));
  }

  if(Ang.at(1)<0.0) Ang.at(1)=TMath::Pi()+Ang.at(1);
  

// Lorentz transformations to lab -----

  Double_t p3_cmx = p3_cm*sin(thetacms);
  Double_t p3_cmz = p3_cm*cos(thetacms);
  Double_t p3_labx = p3_cmx;
  Double_t p3_labz = gamma*(p3_cmz+beta*(t3_cm+fWm.at(2)));
  Double_t p3_lab = TMath::Sqrt(p3_labx*p3_labx+p3_labz*p3_labz);
  Ene.push_back(TMath::Sqrt(p3_lab*p3_lab+fWm.at(2)*fWm.at(2))-fWm.at(2));

  Double_t p4_cmx = p4_cm*sin(thetacmr);
  Double_t p4_cmz = p4_cm*cos(thetacmr);
  Double_t p4_labx = p4_cmx;
  Double_t p4_labz = gamma*(p4_cmz+beta*(t4_cm+fWm.at(3)));
  Double_t p4_lab = TMath::Sqrt(p4_labx*p4_labx+p4_labz*p4_labz);
  Ene.push_back(TMath::Sqrt(p4_lab*p4_lab+fWm.at(3)*fWm.at(3))-fWm.at(3));

        std::cout << " Recoil energy:" << Ene.at(1) << " MeV" << std::endl;
        std::cout << " Scattered energy:" << Ene.at(0)  << " MeV" << std::endl;
        std::cout << " Recoiled angle:"  << Ang.at(1)*180.0/TMath::Pi() << " deg" << std::endl;
        std::cout << " Scattered  angle:"  << Ang.at(0)*180/TMath::Pi() << " deg" << std::endl;
    

		fPx.at(0) = 0.0;
                fPy.at(0) = 0.0; 
	        fPz.at(0) = 0.0;

                fPx.at(1) = 0.0;
                fPy.at(1) = 0.0; 
	        fPz.at(1) = 0.0;


           
	        fPx.at(2) = p3_labx/1000.0;
                fPy.at(2) = 0.0; 
	        fPz.at(2) = p3_labz/1000.0;

                fPx.at(3) = p4_labx/1000.0;
                fPy.at(3) = 0.0; 
	        fPz.at(3) = p4_labz/1000.0;

	      



  

	
         
	
          
    for(Int_t i=0; i<fMult; i++){


 TParticlePDG* thisPart = 
     TDatabasePDG::Instance()->GetParticle(fIon.at(i)->GetName());


  if ( ! thisPart ) {
    std::cout << "-W- FairIonGenerator: Ion " << fIon.at(i)->GetName()
	 << " not found in database!" << std::endl;
    return kFALSE;
  }

     int pdgType = thisPart->PdgCode(); 

     // Propagate the vertex of the previous event

         fVx = gATVP->GetVx();
         fVy = gATVP->GetVy();
         fVz = gATVP->GetVz();

       

   
      if(i>1 && gATVP->GetDecayEvtCnt()){

	 std::cout << "-I- FairIonGenerator: Generating " << fMult << " ions of type "
       << fIon.at(i)->GetName() << " (PDG code " << pdgType << ")" << std::endl;
        std::cout << "    Momentum (" << fPx.at(i) << ", " << fPy.at(i) << ", " << fPz.at(i) 
       << ") Gev from vertex (" << fVx << ", " << fVy
       << ", " << fVz << ") cm" << std::endl; 
        primGen->AddTrack(pdgType, fPx.at(i), fPy.at(i), fPz.at(i), fVx, fVy, fVz);
      }


  }      
        

  gATVP->IncDecayEvtCnt();  //TODO: Okay someone should put a more suitable name but we are on a hurry...

  
  return kTRUE;

}


ClassImp(ATTPC2Body)
