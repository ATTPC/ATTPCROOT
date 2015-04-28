/*******************************************************************
* Daughter class for Linear Hough Space transformation             *
* Log: Class started 28-04-2015                                    *
* Author: Y. Ayyad (NSCL ayyadlim@nscl.msu.edu)                    *
********************************************************************/ 

#pragma once

#include "ATHoughSpace.hh"

class ATHoughSpaceLine : public ATHoughSpace{

      public:
	ATHoughSpaceLine();
        ~ATHoughSpaceLine();

	TH2F* GetHoughSpace(TString ProjPlane);
        void CalcHoughSpace(ATEvent* event,Bool_t YZplane,Bool_t XYplane, Bool_t XZplane);

      private:
        Int_t fThreshold;
        std::map<Float_t,Float_t> HoughMap_XZ;

	ClassDef(ATHoughSpaceLine, 1);

};



