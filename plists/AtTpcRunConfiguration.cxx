#include "G4Version.hh"
#include "AtTpcRunConfiguration.h"

#include "TG4ComposedPhysicsList.h"
#include "TG4SpecialPhysicsList.h"

#if G4VERSION_NUMBER > 922
#include <QGSP_BERT.hh>
#else
#include <LHEP_BERT.hh>
#endif
#include "AtTpcPhysicsList.h"

//_____________________________________________________________________________
AtTpcRunConfiguration::AtTpcRunConfiguration(const TString& userGeometry,
                                             const TString& specialProcess)
  : TG4RunConfiguration(userGeometry, "emStandard", specialProcess) 
{


}

//_____________________________________________________________________________
AtTpcRunConfiguration::~AtTpcRunConfiguration()
{
/// Destructor
}

//
// protected methods
//


//_____________________________________________________________________________
G4VUserPhysicsList*  AtTpcRunConfiguration::CreatePhysicsList()
{
/// Override the default physics list with user defined physics list;
/// LHEP_BERT physics list should be replaced with user own physics list

  TG4ComposedPhysicsList* builder = new TG4ComposedPhysicsList();
  
  // User physics list
  G4cout << G4endl;
  G4cout << "-I- AtTpcRunConfiguration Adding -AtTpc- SpecialPhysicsList ...  " << G4endl;
  builder->AddPhysicsList(new AtTpcPhysicsList());
    
//  G4cout << "Adding SpecialPhysicsList " << G4endl;
//  builder->AddPhysicsList(new TG4SpecialPhysicsList(
//                                 fSpecialProcessSelection.Data()));
  
  return builder;  
}  


