/*********************************************************************
*   ATTPC Mapping Class	AtTpcMap.cxx			             *	
*   Author: Y. Ayyad            				     *
*   Log: 13-02-2014 17:16 JST					     *
*								     *	
*********************************************************************/

#include "AtTpcMap.h"

#include <iostream>
#include <cassert>

using std::cout;
using std::endl;


AtTpcMap::AtTpcMap():AtPadCoord(boost::extents[10240][3][2])
{
 Initialize();
}

AtTpcMap::~AtTpcMap()
{
}

void AtTpcMap::Initialize()
{
 
  std::fill( AtPadCoord.data(), AtPadCoord.data()+AtPadCoord.num_elements() , 0);
  std::cout<<" ATTPC Pad Coordinates container initialized "<<endl;
}

void AtTpcMap::Dump(){
	
    int values = 0;
  	 for(index i = 0; i != 10240; ++i) 
   	   for(index j = 0; j != 3; ++j)
     	     for(index k = 0; k != 2; ++k)
             	std::cout<<AtPadCoord[i][j][k]<<endl;

}


ClassImp(AtTpcMap)
