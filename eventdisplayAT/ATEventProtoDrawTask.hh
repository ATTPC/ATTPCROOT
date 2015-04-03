#pragma once
#include "ATEventDrawTask.hh"

class ATEventProtoDrawTask : public ATEventDrawTask
{
  public :

   ATEventProtoDrawTask();
   ~ATEventProtoDrawTask();

   void DrawPadPlane();

   ClassDef(ATEventProtoDrawTask,1);

};
