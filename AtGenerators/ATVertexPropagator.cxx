#include "ATVertexPropagator.h"

ATVertexPropagator *gATVP = (ATVertexPropagator *)0;

// -----   Default constructor   -------------------------------------------
ATVertexPropagator::ATVertexPropagator()
{

   if(gATVP)
    delete gATVP;
  gATVP = this;

}

// -------------------------------------------------------------------------



// -----   Destructor   ----------------------------------------------------
ATVertexPropagator::~ATVertexPropagator()
{

}

Bool_t ATVertexPropagator::Test(){

   std::cout<<" Hodor "<<std::endl;
   return kTRUE;

}


ClassImp(ATVertexPropagator)
