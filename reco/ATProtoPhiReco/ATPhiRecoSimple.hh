#pragma once

#include "ATPhiReco.hh"

class ATPhiRecoSimple : public ATPhiReco
{
  public:
    ATPhiRecoSimple();
    ~ATPhiRecoSimple();
   
    void PhiAnalyze(ATEvent *event);
    //void PhiAnalyze(ATEvent *event, ATHoughSpace *HSpace);

   private:
   void PhiCalc(ATProtoQuadrant *quadrant);

  ClassDef(ATPhiRecoSimple, 1)
};
