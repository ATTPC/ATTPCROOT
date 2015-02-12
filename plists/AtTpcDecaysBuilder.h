/////////////////////////////////////////////////////////////////
//*-- AUTHOR : Hector Alvarez-Pol     hapol@fpddux.usc.es
//*-- Date: 03/2006
//*-- Last Update: 06/03/06 by Hector Alvarez Pol
//*-- Adapted for ATTPCROOT by Yassid Ayyad 
// --------------------------------------------------------------
// Description:
//   Physics List -- Decays builder
//
// --------------------------------------------------------------
// Comments:
//
//  06/03/06 Included after full physics revision. Migrated to geant4.8
//           Based on examples/extended/medical/GammaTherapy
//
// --------------------------------------------------------------
/////////////////////////////////////////////////////////////////

#ifndef AtTpcDecaysBuilder_h
#define AtTpcDecaysBuilder_h 1

#include "G4VPhysicsConstructor.hh"
#include "globals.hh"


class AtTpcDecaysBuilder : public G4VPhysicsConstructor {
private:

   // hide assignment operator
  AtTpcDecaysBuilder & operator=(const AtTpcDecaysBuilder &right);
  AtTpcDecaysBuilder(const AtTpcDecaysBuilder&);

public:

  AtTpcDecaysBuilder(const G4String& name = "decays");
  virtual ~AtTpcDecaysBuilder();

  // This method is dummy for physics
  virtual void ConstructParticle();

  // This method will be invoked in the Construct() method.
  // each physics process will be instantiated and
  // registered to the process manager of each particle type
  virtual void ConstructProcess();

};
#endif








