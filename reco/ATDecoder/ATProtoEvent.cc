#include "ATProtoEvent.hh"

ClassImp(ATProtoEvent);

ATProtoEvent::ATProtoEvent()
:TNamed("ATProtoEvent", "Proto Event container")
{
  
}

ATProtoEvent::~ATProtoEvent()
{

}

void ATProtoEvent::SetEventID(Int_t evtid)                                        { fEventID = evtid; }
void ATProtoEvent::AddQuadrant(ATProtoQuadrant *quadrant)                         { fQuadrantArray.push_back(*quadrant); } 
void ATProtoEvent::SetQuadrantArray(std::vector<ATProtoQuadrant> *quadrantArray)  { fQuadrantArray = *quadrantArray; }

