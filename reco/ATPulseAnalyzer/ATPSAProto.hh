#pragma once

#include "ATPSA.hh"

// ROOT classes
#include "TSpectrum.h"

class ATPSAProto : public ATPSA
{
  public:
    ATPSAProto();
    ~ATPSAProto();

    void Analyze(ATRawEvent *rawEvent, ATEvent *event);

  private:
    TSpectrum *fPeakFinder;  /// TSpectrum object
    

  ClassDef(ATPSAProto, 1)
};
