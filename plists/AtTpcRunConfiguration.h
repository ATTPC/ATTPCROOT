#ifndef AtTpcRUNCONFIGURATION_H
#define AtTpcRUNCONFIGURATION_H


#include "TG4RunConfiguration.h"


class AtTpcRunConfiguration : public TG4RunConfiguration
{
  public:
    AtTpcRunConfiguration(const TString& userGeometry,
                          const TString& specialProcess = "stepLimiter" );
    virtual ~AtTpcRunConfiguration();

    // methods
    virtual G4VUserPhysicsList*  CreatePhysicsList();


};

#endif //AtTpcRUNCONFIGURATION_H

