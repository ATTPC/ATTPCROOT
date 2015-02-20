/*********************************************************************
*   ATTPC Mapping Class	AtTpcMap.h			             *	
*   Author: Y. Ayyad            				     *
*   Log: 13-02-2014 17:16 JST					     *
*								     *	
*********************************************************************/

#ifndef ATTPCMAP_H
#define ATTPCMAP_H

#ifndef __CINT__ // Boost 
#include <boost/multi_array.hpp>
#endif //__CINT__

#include <cassert>
#include "TObject.h"



class AtTpcMap : public TObject
{

  public:
    
     AtTpcMap();
     ~AtTpcMap();

     #ifndef __CINT__
     typedef boost::multi_array<double,3> multiarray;
     typedef multiarray::index index;
     multiarray AtPadCoord;
     #endif //__CINT__


     void Initialize();
     void Dump();
     void CalCoord();


     ClassDef(AtTpcMap,1);

     

};

#endif




