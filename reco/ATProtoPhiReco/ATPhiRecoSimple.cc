#include "ATPhiRecoSimple.hh"
#include "ATEvent.hh"


ClassImp(ATPhiRecoSimple)

ATPhiRecoSimple::ATPhiRecoSimple()
{
  
}

ATPhiRecoSimple::~ATPhiRecoSimple()
{
}

void ATPhiRecoSimple::PhiAnalyze(ATEvent *event){
 
                    event->SortHitArray();
                    Int_t nHits = event->GetNumHits();
                    Double_t PhiQ1 = 0.0;
                    
                    ATProtoQuadrant *ProtoQuad1 = new ATProtoQuadrant(1); // Quadrant ID : 1 
                    ProtoQuad1->SetEventID(event->GetEventID());
                    ATProtoQuadrant *ProtoQuad2 = new ATProtoQuadrant(2); // Quadrant ID : 1 
                    ProtoQuad2->SetEventID(event->GetEventID());

			 for(Int_t iHit=0; iHit<nHits; iHit++){
				ATHit hit = event->GetHitArray()->at(iHit);
                                ATHit *phit = &hit;  
    			        Int_t PadNum = hit.GetHitPadNum();
                                //std::cout<<" Hit : "<<iHit<<" ATHit Pad Number :  "<<PadNum<<std::endl;
                                
                                 //Dividing into quadrants
                                    if(PadNum>0 && PadNum<64){
					 
                                          //std::cout<<" Quadrant 1 "<<std::endl;
                                         // std::cout<<" Hit : "<<iHit<<" ATHit Pad Number :  "<<PadNum<<std::endl;
  					 ProtoQuad1 ->AddHit(phit);
                                         

                                            

				    }else if(PadNum>63 && PadNum<127){

					  // std::cout<<" Quadrant 2 "<<std::endl;
                                          // std::cout<<" Hit : "<<iHit<<" ATHit Pad Number :  "<<PadNum<<std::endl;
					  ProtoQuad2 ->AddHit(phit);

				    }else if(PadNum>126 && PadNum<190){

					   //std::cout<<" Quadrant 3 "<<std::endl;
                                          // std::cout<<" Hit : "<<iHit<<" ATHit Pad Number :  "<<PadNum<<std::endl;


				    }else if(PadNum>189 && PadNum<253){

					   //std::cout<<" Quadrant 4 "<<std::endl;
                                           //std::cout<<" Hit : "<<iHit<<" ATHit Pad Number :  "<<PadNum<<std::endl;


				    }else if(PadNum==0){

				
                                    }
                                  
				    

			}
			
			//PhiCalc(ProtoQuad1);
			PhiCalc(ProtoQuad2);
			ProtoQuad1->SetPhiQ(PhiQ1);
			fQuadArray.push_back(*ProtoQuad1);
                        delete ProtoQuad1;


}

void ATPhiRecoSimple::PhiCalc(ATProtoQuadrant *quadrant)
{


}


