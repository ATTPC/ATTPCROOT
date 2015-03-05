/*********************************************************************
*   ATTPC Pad Class	ATPad                                        *	
*   Author: Y. Ayyad            				     *
*   Log: 05-03-2015 19:24 JST					     *
*                                                                    *
*								     *	
*********************************************************************/

#ifndef ATPAD_H
#define ATPAD_H

#include "TObject.h"
#include "TROOT.h"

class ATPad : public TObject  {

   public:
    ATPad();
    ATPad(Int_t PadNum);
    ~ATPad();

   private:
    Int_t fPadNum;

};

#endif
