#ifndef ATVertexPropagator_H
#define ATVertexPropagator_H

#include "TObject.h"

#include <iostream>
#include <map>

class ATVertexPropagator;
extern ATVertexPropagator *gATVP; // global

class ATVertexPropagator : public TObject
{

  public:

    
    ATVertexPropagator();
    virtual ~ATVertexPropagator();

    Bool_t Test();

    ClassDef(ATVertexPropagator,1)


};




#endif
