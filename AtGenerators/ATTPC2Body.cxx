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
	std::vector<Double_t>* py,std::vector<Double_t> *pz, std::vector<Double_t> *mass,Double_t ResEner,Int_t ZB, Int_t AB, Double_t PxB, Double_t PyB, Double_t PzB, Double_t BMass, Double_t TMass)
  : fMult(0),          
    fPx(0.), fPy(0.), fPz(0.),
    fVx(0.), fVy(0.), fVz(0.),
    fIon(0),  fQ(0)
{

  fgNIon++;
  fMult = mult;
  fIon.reserve(fMult);
  


  char buffer[20];
  
  fBeamEnergy_buff = ResEner;
  fBeamMass = BMass;
  fTargetMass = TMass;
  fZBeam = ZB;
  fABeam = AB;
  fPxBeam = PxB;
  fPyBeam = PyB;
  fPzBeam = PzB;
  
  
      for(Int_t i=0;i<fMult;i++){

             
  	fPx.push_back( Double_t(a->at(i)) * px->at(i) );
	fPy.push_back( Double_t(a->at(i)) * py->at(i) );
	fPz.push_back( Double_t(a->at(i)) * pz->at(i) );
	Masses.push_back(mass->at(i));
         
        
        sprintf(buffer, "Product_Ion%d", i); 
        FairIon *IonBuff = new FairIon(buffer, z->at(i), a->at(i), q->at(i));
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



  

   // === Phase Space Calculation
   TLorentzVector fEnergyImpulsionLab_beam;
   TLorentzVector fEnergyImpulsionLab_target;
   TLorentzVector fEnergyImpulsionLab_Total;
   TLorentzVector fEnergyImpulsionFinal;
   TVector3 fImpulsionLab_beam;
   TVector3 fImpulsionLab_target;
   TLorentzVector *p1;
   TLorentzVector *p2;
   TLorentzVector *p3;
   std::vector<TLorentzVector*> p_vector;
   TGenPhaseSpace event1;
   
   AtStack* stack = (AtStack*) gMC->GetStack();

    fIsDecay = kFALSE;
   

   fBeamEnergy = gATVP->GetEnergy()/1000.0;
   std::cout<<" Residual energy in ATTPCIonPhaseSpace : "<<gATVP->GetEnergy()<<std::endl;
   
   fPxBeam = gATVP->GetPx();
   fPyBeam = gATVP->GetPy();
   fPzBeam = gATVP->GetPz();

   Double_t beta;
   Double_t s=0.0;
   Double_t mass_1[10]={0.0};
   Double_t* pMass;

   Double_t M_tot=0;



   //std::cout<<" Beam Z momentum : "<<fABeam*fPzBeam<<std::endl;

   //fImpulsionLab_beam = TVector3(fABeam*fPxBeam,fABeam*fPyBeam,fABeam*fPzBeam);
   fImpulsionLab_beam = TVector3(fPxBeam,fPyBeam,fPzBeam);
  // fEnergyImpulsionLab_beam = TLorentzVector(fImpulsionLab_beam,9327.55/1000.0+fBeamEnergy);
    fEnergyImpulsionLab_beam = TLorentzVector(fImpulsionLab_beam,fBeamMass+fBeamEnergy);
  
   //fEnergyImpulsionLab_target = TLorentzVector(TVector3(0,0,0),3728.40/1000.0);
   fEnergyImpulsionLab_target = TLorentzVector(TVector3(0,0,0),fTargetMass);

   fEnergyImpulsionLab_Total = fEnergyImpulsionLab_beam + fEnergyImpulsionLab_target;
   s = fEnergyImpulsionLab_Total.M2();
   beta = fEnergyImpulsionLab_Total.Beta();

   std::cout<<" fABeam : "<<fABeam<<" fPzBeam : "<<fPzBeam<<" fBeamEnergy : "<<fBeamEnergy<<std::endl;

   for(Int_t i=0;i<fMult;i++){

        M_tot+=Masses.at(i)/1000.0;     
        mass_1[i] = Masses.at(i)/1000.0;
    }

    

        
       /* mass_1[1] = Masses.at(1)/1000.0;
        mass_1[2] = Masses.at(2)/1000.0;*/



	//std::cout<<" Mass 1 : "<<mass_1[0]<<" Mass 2 : "<<mass_1[1]<<"  Mass 3 : "<<mass_1[2]<<std::endl;

	

  // std::cout<<" S : "<<s<<" Pow(M) "<<pow(mass_1[0]+mass_1[1]+mass_1[2],2)<<std::endl;
    std::cout<<" S : "<<s<<" Pow(M) "<<pow(M_tot,2)<<std::endl;

         if(s>pow(M_tot,2)){
            
               fIsDecay=kTRUE;            

               event1.SetDecay(fEnergyImpulsionLab_Total,fMult, mass_1);
               Double_t weight1 = event1.Generate();
            
              /* p1  = event1.GetDecay(0);
               p2  = event1.GetDecay(1);
	       p3  = event1.GetDecay(2);*/

		std::vector<Double_t> KineticEnergy;
                std::vector<Double_t> ThetaLab;

             std::cout<<"  ==== Phase Space Information ==== "<<std::endl;
	      for(Int_t i=0;i<fMult;i++){


		      p_vector.push_back(event1.GetDecay(i));
	              fPx.at(i) = p_vector.at(i)->Px();
 	              fPy.at(i) = p_vector.at(i)->Py();
 	              fPz.at(i) = p_vector.at(i)->Pz();
		      KineticEnergy.push_back((p_vector.at(i)->E() - mass_1[i])*1000);
		      ThetaLab.push_back(p_vector.at(i)->Theta()*180./TMath::Pi());
		      std::cout<<" Particle "<<i<<" - TKE (MeV) : "<<KineticEnergy.at(i)<<" - Lab Angle (deg) : "<<ThetaLab.at(i)<<std::endl;
                      

              }

              
		



	      /*  fPx.at(0) = p1->Px();
                fPy.at(0) = p1->Py(); 
	        fPz.at(0) = p1->Pz(); 

                fPx.at(1) = p2->Px();
                fPy.at(1) = p2->Py(); 
	        fPz.at(1) = p2->Pz(); 

	        fPx.at(2) = p3->Px();
                fPy.at(2) = p3->Py(); 
	        fPz.at(2) = p3->Pz(); 

		 Double_t  KineticEnergy_P1  = (p1->E() - mass_1[0])*1000; //MeV
		  Double_t  ThetaLab_P1     = p1->Theta()*180./TMath::Pi();

		  Double_t  KineticEnergy_P2  = (p2->E() - mass_1[1])*1000; //MeV
		  Double_t  ThetaLab_P2     = p2->Theta()*180./TMath::Pi();

		  Double_t  KineticEnergy_P3  = (p3->E() - mass_1[2])*1000; //MeV
		  Double_t  ThetaLab_P3     = p3->Theta()*180./TMath::Pi();

		   std::cout<<"  ==== Phase Space Information ==== "<<std::endl;
            std::cout<<" Particle 1 - TKE : "<<KineticEnergy_P1<<"  Angle (Lab) : "<<ThetaLab_P1<<std::endl;
	    std::cout<<" Particle 2 - TKE : "<<KineticEnergy_P2<<"  Angle (Lab) : "<<ThetaLab_P2<<std::endl;
	    std::cout<<" Particle 3 - TKE : "<<KineticEnergy_P3<<"  Angle (Lab) : "<<ThetaLab_P3<<std::endl;*/


        
       }// if kinematics condition

	
         
	
          
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
 

  std::cout << "-I- FairIonGenerator: Generating " << fMult << " ions of type "
       << fIon.at(i)->GetName() << " (PDG code " << pdgType << ")" << std::endl;
  std::cout << "    Momentum (" << fPx.at(i) << ", " << fPy.at(i) << ", " << fPz.at(i) 
       << ") Gev from vertex (" << fVx << ", " << fVy
       << ", " << fVz << ") cm" << std::endl; 

   
      if(fIsDecay){
        primGen->AddTrack(pdgType, fPx.at(i), fPy.at(i), fPz.at(i), fVx, fVy, fVz);
      }


  }       
        

  gATVP->IncDecayEvtCnt();  

  
  return kTRUE;

}


ClassImp(ATTPC2Body)
