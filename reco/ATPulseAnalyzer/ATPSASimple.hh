
#pragma once

#include "ATPSA.hh"

class ATPSASimple : public ATPSA
{
  public:
    ATPSASimple();
    ~ATPSASimple();

    void Analyze(ATRawEvent *rawEvent, ATEvent *event);

  ClassDef(ATPSASimple, 1)
};
