#include "ATPhiRecoSimple.hh"



ClassImp(ATPhiRecoSimple)

ATPhiRecoSimple::ATPhiRecoSimple()
{
  PhiDist = new TH1D("PhiDist","PhiDist",90.0,0.0,90.0);
}

ATPhiRecoSimple::~ATPhiRecoSimple()
{
}

void ATPhiRecoSimple::PhiAnalyze(ATEvent *event,ATProtoEvent *protoevent){
 
                    event->SortHitArray();
                    Int_t nHits = event->GetNumHits();
                    Double_t PhiQ1 = 0.0;
                    
                    ATProtoQuadrant *ProtoQuad1 = new ATProtoQuadrant(1); // Quadrant ID : 1 
                    ProtoQuad1->SetEventID(event->GetEventID());
                    ATProtoQuadrant *ProtoQuad2 = new ATProtoQuadrant(2); // Quadrant ID : 2 
                    ProtoQuad2->SetEventID(event->GetEventID());
		    ATProtoQuadrant *ProtoQuad3 = new ATProtoQuadrant(3); // Quadrant ID : 3 
                    ProtoQuad3->SetEventID(event->GetEventID());
		    ATProtoQuadrant *ProtoQuad4 = new ATProtoQuadrant(4); // Quadrant ID : 4 
                    ProtoQuad4->SetEventID(event->GetEventID());

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
					     ProtoQuad3 ->AddHit(phit);

				    }else if(PadNum>189 && PadNum<253){

					   //std::cout<<" Quadrant 4 "<<std::endl;
                                           //std::cout<<" Hit : "<<iHit<<" ATHit Pad Number :  "<<PadNum<<std::endl;
				             ProtoQuad4 ->AddHit(phit);

				    }else if(PadNum==0){

						//TODO: Central Pad

				
                                    }
                                  
				    

			}
			
			PhiCalc(ProtoQuad1);
			PhiCalc(ProtoQuad2);
                        PhiCalc(ProtoQuad3);
			PhiCalc(ProtoQuad4);
			ProtoQuad1->SetPhiQ(20);
			fQuadArray.push_back(*ProtoQuad1);
			fQuadArray.push_back(*ProtoQuad2);
			fQuadArray.push_back(*ProtoQuad3);
			fQuadArray.push_back(*ProtoQuad4);
                        
			protoevent->SetQuadrantArray(&fQuadArray);			
                        delete ProtoQuad1;
                        delete ProtoQuad2;
			delete ProtoQuad3;
			delete ProtoQuad4;


}

void ATPhiRecoSimple::PhiCalc(ATProtoQuadrant *quadrant)
{

     PhiDist->Reset();
     Double_t a=0.5+0.125; //Small size of the strip plus half the dead area between strips
     Double_t da; //
  
     // type A: a + da - Phi/90
     // type B: a + Phi/90
  
     // TODO This function is tuned for prototype micromegas, 
       Int_t nHits = quadrant->GetNumHits();
		if(nHits>1){
		      //std::cout<<" Number of hits in quadrant  : "<<nHits<<std::endl;
		       for(Int_t iHit=0; iHit<nHits-1; iHit++){
                          
			  Double_t phi=0.0;
			  ATHit qhit_f = quadrant->GetHitArray()->at(iHit); //First strip
			  ATHit qhit_s = quadrant->GetHitArray()->at(iHit+1); //Second strip
			  Int_t PadNum_qf = qhit_f.GetHitPadNum();
			  Int_t PadNum_qs = qhit_s.GetHitPadNum();
			  Double_t Q_f = qhit_f.GetCharge(); //TODO: For the moment we asume the charge to be the amplitude
			  Double_t Q_s = qhit_s.GetCharge(); 
                         	 if(PadNum_qf<11) da=1.0-a;
			  	 else da=3.2-a;
                                 if(PadNum_qs<11) da=1.0-a;
			  	 else da=3.2-a;
                             

			        if(PadNum_qs==PadNum_qf+1){


					if(quadrant->GetQuadrantID()%2==1){ 
						//std::cout<<" "<<std::endl;
						//std::cout<<" Inside an odd quadrant ID : "<<quadrant->GetQuadrantID()<<std::endl;
						phi= (1.0 - (Q_f-Q_s)/(Q_f+Q_s)*2.0*a/da - (Q_f-Q_s)/(Q_f+Q_s) )*45 ;
						if(PadNum_qf%2==1 && PadNum_qs%2==0) phi= (1.0 - (Q_f-Q_s)/(Q_f+Q_s)*2.0*a/da - (Q_f-Q_s)/(Q_f+Q_s) )*45 ;
						else if(PadNum_qf%2==0 && PadNum_qs%2==1) phi = 90.0-phi;
						else{ std::cout<<" ======================================================================= "<<std::endl;
						      std::cout<<" Warning, even-odd sttagering not found. "<<std::endl;
						}


					}

					else if(quadrant->GetQuadrantID()%2==0){

						//std::cout<<" Inside an even quadrant ID : "<<quadrant->GetQuadrantID()<<std::endl;
                                                phi= (1.0 - (Q_f-Q_s)/(Q_f+Q_s)*2.0*a/da - (Q_f-Q_s)/(Q_f+Q_s) )*45 ;
						if(PadNum_qf%2==0 && PadNum_qs%2==1) phi= (1.0 - (Q_f-Q_s)/(Q_f+Q_s)*2.0*a/da - (Q_f-Q_s)/(Q_f+Q_s) )*45 ;
						else if(PadNum_qf%2==1 && PadNum_qs%2==0) phi = 90.0-phi;
						else{ std::cout<<" ======================================================================= "<<std::endl;
						      std::cout<<" Warning, even-odd sttagering not found. "<<std::endl;
						}
						

					}else std::cout<<" Invalid Quadrant ID : "<<quadrant->GetQuadrantID()<<std::endl;


				}else{
					//std::cout<<" ======================================================================= "<<std::endl;
					//std::cout<<" Warning, Pads are not adjacent. "<<std::endl;
					phi=0.0;

				 } //Adjacent strips


				PhiDist->Fill(phi);
                                
	                               
			        // std::cout<<" ======================================================================= "<<std::endl;
				 //std::cout<<" Prototype quadrant : "<<quadrant->GetQuadrantID()<<std::endl;
                     		// std::cout<<" First Hit Pad : "<<PadNum_qf<<" First Pad Charge : "<<Q_f<<std::endl;
                                // std::cout<<" Second Hit Pad : "<<PadNum_qs<<" Second Pad Charge : "<<Q_s<<std::endl;
				// std::cout<<" Phi : "<<phi<<std::endl;
 
		       }
                 }//nHits>1
                PhiDist->Draw();

		//quadrant->SetPhiDistribution(PhiDist);

}


