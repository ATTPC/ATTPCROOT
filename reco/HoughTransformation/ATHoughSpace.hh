/*******************************************************************
* Base class for Hough Space transformation for the ATTPCROOT      *
* Log: Class started 28-04-2015                                    *
* Author: Y. Ayyad (NSCL ayyadlim@nscl.msu.edu)                    *
********************************************************************/ 


#ifndef ATHOUGHSPACE_H
#define ATHOUGHSPACE_H


#include "ATHit.hh"
#include "ATEvent.hh"
#include "ATDigiPar.hh"

// FairRoot classes
#include "FairRootManager.h"
#include "FairLogger.h"

//ROOT classes
#include "TClonesArray.h"
#include "TH2F.h"
#include "TMath.h"

class ATHoughSpace{

	public:

		ATHoughSpace();
		~ATHoughSpace();

               virtual TH2F* GetHoughSpace(TString ProjPlane)=0;
	       virtual void CalcHoughSpace(ATEvent* event,Bool_t YZplane,Bool_t XYplane, Bool_t XZplane)=0;

		ClassDef(ATHoughSpace, 1);

};

#endif
