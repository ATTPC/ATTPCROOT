#include "ATVertexPropagator.h"

ATVertexPropagator *gATVP = (ATVertexPropagator *)0;
//ATVertexPropagator *gATVP = new ATVertexPropagator();

// -----   Default constructor   -------------------------------------------
ATVertexPropagator::ATVertexPropagator():fGlobalEvtCnt(0),fBeamEvtCnt(0),fDecayEvtCnt(0),
fVx(0.),fVy(0.),fVz(0.),fPx(0.),fPy(0.),fPz(0.),fE(0.),fBeamMass(0),fRndELoss(0),fBeamNomE(0)
{

   if(gATVP)
    delete gATVP;
   gATVP = this;

}

// -------------------------------------------------------------------------



// -----   Destructor   ----------------------------------------------------
ATVertexPropagator::~ATVertexPropagator()
{

  delete gATVP;
  std::cout<<" ATVertexPropagator: Global pointer ATVertexPropagator succesfully deleted "<<std::endl;

}

Bool_t ATVertexPropagator::Test(){

 
   return kTRUE;

}


void ATVertexPropagator::SetVertex(Double_t vx,Double_t vy,Double_t vz,Double_t px,Double_t py, Double_t pz, Double_t E)
{
    fVx=vx;
    fVy=vy;
    fVz=vz;
    fPx=px;
    fPy=py;
    fPz=pz;
    fE=E;
}

void ATVertexPropagator::SetRndELoss(Double_t eloss)
{
    fRndELoss=eloss;
}

void ATVertexPropagator::SetBeamNomE(Double_t nome)
{
    fBeamNomE=nome;
}

void ATVertexPropagator::ResetVertex()
{

    fVx=0.0;
    fVy=0.0;
    fVz=0.0;
    fPx=0.0;
    fPy=0.0;
    fPz=0.0;
    fE=0.0;

}

void ATVertexPropagator::SetBeamMass(Double_t m)                { fBeamMass = m;}          
Int_t ATVertexPropagator::GetGlobalEvtCnt()    			{ return fGlobalEvtCnt;}
Int_t ATVertexPropagator::GetBeamEvtCnt()    			{ return fBeamEvtCnt;}
Int_t ATVertexPropagator::GetDecayEvtCnt()    			{ return fDecayEvtCnt;}
Double_t ATVertexPropagator::GetVx()				{ return fVx;}
Double_t ATVertexPropagator::GetVy()				{ return fVy;}
Double_t ATVertexPropagator::GetVz()				{ return fVz;}
Double_t ATVertexPropagator::GetPx()				{ return fPx;}
Double_t ATVertexPropagator::GetPy()				{ return fPy;}
Double_t ATVertexPropagator::GetPz()				{ return fPz;}
Double_t ATVertexPropagator::GetEnergy()			{ return fE;}
Double_t ATVertexPropagator::GetBeamMass()                      { return fBeamMass;}  
Double_t ATVertexPropagator::GetRndELoss()                      { return fRndELoss; } 
Double_t ATVertexPropagator::GetBeamNomE()                      { return fBeamNomE; }    

void ATVertexPropagator::IncGlobalEvtCnt()                      {  fGlobalEvtCnt++;    }
void ATVertexPropagator::IncBeamEvtCnt()                        {  fBeamEvtCnt++;    }
void ATVertexPropagator::IncDecayEvtCnt()                       {  fDecayEvtCnt++;    }


ClassImp(ATVertexPropagator)
