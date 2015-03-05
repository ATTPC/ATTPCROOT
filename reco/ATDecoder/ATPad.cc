/*********************************************************************
*   ATTPC Pad Class	ATPad                                        *	
*   Author: Y. Ayyad            				     *
*   Log: 05-03-2015 19:24 JST					     *
*                                                                    *
*								     *	
*********************************************************************/

#include <iostream>
#include "ATPad.hh"

ClassImp(ATPad);

ATPad::ATPad()
{
  
}

ATPad::ATPad(Int_t PadNum)
{  
	fPadNum = PadNum;
}


ATPad::~ATPad()
{
 
}
