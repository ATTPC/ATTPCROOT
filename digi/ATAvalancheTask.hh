/*****************************************************************/
/*    ATAvalancheTask: Simulates the ionized electrons which are */ 
/*    drifted and amplified by avalanche when reaching the mesh. */ 
/*    Log: Created in 23-07-2015     				 */
/*    Author: Yassid Ayyad (NSCL)				 */
/*    ayyadlim@nscl.msu.edu                                      */
/*****************************************************************/

#pragma once

#include "FairTask.h"

#include "TClonesArray.h"
#include "ATDigiPar.hh"
#include "ATGas.hh"


class ATAvalancheTask : public FairTask 
{
  public:
     ATAvalancheTask();
     ~ATAvalancheTask();

    virtual InitStatus Init();        //!< Initiliazation of task at the beginning of a run.
    virtual void Exec(Option_t* opt); //!< Executed for each event.
    virtual void SetParContainers();  //!< Load the parameter container from the runtime database.

   private:

    Int_t fEventID; //!< EventID

    TClonesArray* fMCPointArray;     
    //STMCPoint* fMCPoint;            

    //TClonesArray* fElectronArray;    

    ATDigiPar* fPar; //!< Base parameter container.
    ATGas*     fGas; //!< Gas parameter container.
 


     ClassDef(ATAvalancheTask,1);
    
};


