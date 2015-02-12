/////////////////////////////////////////////////////////////////
//*-- AUTHOR : Hector Alvarez-Pol     hapol@fpddux.usc.es
//*-- Date: 03/2006
//*-- Last Update: 06/03/06 by Hector Alvarez Pol
// --------------------------------------------------------------
// Description:
//   Physics List Messenger
//
// --------------------------------------------------------------
// Comments:
//
//  06/03/06 Included after full physics revision. Migrated to geant4.8
//           Based on examples/extended/medical/GammaTherapy
//
// --------------------------------------------------------------
/////////////////////////////////////////////////////////////////

#ifndef AtTpcPhysicsListMessenger_h
#define AtTpcPhysicsListMessenger_h 1

#include "globals.hh"
#include "G4UImessenger.hh"

class AtTpcPhysicsList;
class G4UIdirectory;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithAString;
class G4UIcmdWithAnInteger;


class AtTpcPhysicsListMessenger: public G4UImessenger {
private:
  
  AtTpcPhysicsList*               pPhysicsList;
    
  G4UIdirectory*             physDir;    
  G4UIcmdWithADoubleAndUnit* gammaCutCmd;
  G4UIcmdWithADoubleAndUnit* electCutCmd;
  G4UIcmdWithADoubleAndUnit* protoCutCmd;    
  G4UIcmdWithADoubleAndUnit* allCutCmd;    
  G4UIcmdWithAnInteger*      verbCmd;
  G4UIcmdWithAString*        pListCmd;
   
public:
  
  AtTpcPhysicsListMessenger(AtTpcPhysicsList* );
  ~AtTpcPhysicsListMessenger();
    
  void SetNewValue(G4UIcommand*, G4String);
};
#endif

