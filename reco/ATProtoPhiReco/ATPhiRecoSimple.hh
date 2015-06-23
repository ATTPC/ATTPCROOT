#pragma once

#include "ATPhiReco.hh"
#include "ATProtoEvent.hh"

class ATPhiRecoSimple : public ATPhiReco
{
  public:
    ATPhiRecoSimple();
    ~ATPhiRecoSimple();
   
    void PhiAnalyze(ATEvent *event,ATProtoEvent *protoevent);
    //void PhiAnalyze(ATEvent *event, ATHoughSpace *HSpace);

   private:
   void PhiCalc(ATProtoQuadrant *quadrant);
   TH1D* PhiDist; 

  ClassDef(ATPhiRecoSimple, 1)
};
