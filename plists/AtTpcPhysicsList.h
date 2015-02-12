/////////////////////////////////////////////////////////////////
//*-- AUTHOR : Hector Alvarez-Pol     hapol@fpddux.usc.es
//*-- Date: 11/2004
//*-- Last Update: 04/03/06 by Hector Alvarez Pol
// --------------------------------------------------------------
// Description:
//   Physics List
//
// --------------------------------------------------------------
// Comments:
//
//  04/03/06 Full physics revision. Migrated to geant4.8
//           Based on examples/extended/medical/GammaTherapy
//
// --------------------------------------------------------------
/////////////////////////////////////////////////////////////////

#ifndef AtTpcPhysicsList_h
#define AtTpcPhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "globals.hh"

class AtTpcPhysicsListMessenger;
class G4StepLimiterBuilder;

class AtTpcPhysicsList: public G4VModularPhysicsList {
private:
  G4double cutForGamma;
  G4double cutForElectron;
  G4double cutForPositron;
  G4int    verbose;
  G4bool   emBuilderIsRegisted;
  G4bool   decayIsRegisted;
  G4bool   stepLimiterIsRegisted;
  G4bool   helIsRegisted;
  G4bool   bicIsRegisted;
  G4bool   ionIsRegisted;
  G4bool   gnucIsRegisted;
  
  AtTpcPhysicsListMessenger* pMessenger;
  G4StepLimiterBuilder* steplimiter;
  
public:
  AtTpcPhysicsList();
  ~AtTpcPhysicsList();
  
  // SetCuts()   
  void ConstructParticle();
  void ConstructProcess();
  void SetCuts();

  void SetCutForGamma(G4double);
  void SetCutForElectron(G4double);
  void SetCutForPositron(G4double);

  void AddPhysicsList(const G4String&);
  void SetVerbose(G4int val);
};
#endif



