#include "ATHoughSpaceCircle.hh"
#include "ATMCMinimization.hh"
#ifdef _OPENMP
#include <omp.h>
#endif

#include "TH1.h"
#include "TH2.h"

// FairRoot classes
#include "FairRuntimeDb.h"
#include "FairRun.h"

ClassImp(ATHoughSpaceCircle)

ATHoughSpaceCircle::ATHoughSpaceCircle()
{
    HoughPar.clear();
    fXCenter=-10000.0;
    fYCenter=-10000.0;
    HistHoughXY = new TH2F("HistHoughXY","HistHoughXY",50,0,3.15,100,-1000,1000);
    HistHoughAux = new TH2F("HistHoughAux","HistHoughAux",500,0,3.15,1000,-500,500);
    fRadius = new std::vector<Double_t>;
    fTimeStamp = new std::vector<Int_t>;
    fPhi = new std::vector<Double_t>;
    fDl = new std::vector<Double_t>;
    fTheta = new std::vector<Double_t>;
    fIniHit = new ATHit();
    fClusteredHits = new std::vector<ATHit>;



    fIniTS = 0;
    fIniRadius = 0.0;
    fIniPhi = 0.0;
    fIniHitID =0;


    FairLogger *fLogger=FairLogger::GetLogger();
    ATDigiPar *fPar;

    FairRun *run = FairRun::Instance();
    if (!run)
      fLogger -> Fatal(MESSAGE_ORIGIN, "No analysis run!");

    FairRuntimeDb *db = run -> GetRuntimeDb();
    if (!db)
      fLogger -> Fatal(MESSAGE_ORIGIN, "No runtime database!");

    fPar = (ATDigiPar *) db -> getContainer("ATDigiPar");
    if (!fPar)
      fLogger -> Fatal(MESSAGE_ORIGIN, "ATDigiPar not found!!");

      fDriftVelocity = fPar -> GetDriftVelocity();
      fTBTime = fPar -> GetTBTime();
}

ATHoughSpaceCircle::~ATHoughSpaceCircle()
{
	delete HistHoughXY;
  delete HistHoughAux;
}


//void ATHoughSpaceCircle::SetThreshold(Double_t value) {fThreshold = value;}

std::pair<Double_t,Double_t> ATHoughSpaceCircle::GetHoughPar() {return fHoughLinePar;}

TH2F* ATHoughSpaceCircle::GetHoughSpace(TString ProjPlane)   {return HistHoughXY;}

void ATHoughSpaceCircle::CalcHoughSpace(ATEvent* event,Bool_t YZplane,Bool_t XYplane, Bool_t XZplane){

	Int_t nHits = event->GetNumHits();
  Int_t nstep = 10;
  //Double_t drift_cal = 4.16;//mm
  Double_t drift_cal = fDriftVelocity*fTBTime/100.0;//mm


  ATMinimization *min = new ATMCMinimization();

  //TH2F *RadVSTb = new TH2F("RadVSTb","RadVSTb",100,0,500,100,0,500);
  //TH1F *Phi = new TH1F("Phi","Phi",512,0,512);
  //TH1F *hdist = new TH1F("hdist","hdist",100,0,1000);
  //TH2F *distVSTb = new TH2F("DistVSTb","DistVSTb",1000,0,1000,100,0,2000);

    #pragma omp parallel for ordered schedule(dynamic)
		for(Int_t iHit=0; iHit<(nHits-nstep); iHit++){
      //#pragma omp parallel for collapse(1) ordered schedule(dynamic)

          			ATHit hit = event->GetHitArray()->at(iHit);
                ATHit hit_forw = event->GetHitArray()->at(iHit+nstep);
                ATHit hit_next = event->GetHitArray()->at(iHit+1);
              	Int_t PadNumHit = hit.GetHitPadNum();
                Int_t PadNumHit_forw = hit_forw.GetHitPadNum();

          			if(hit.GetCharge()<fThreshold) continue;
             		TVector3 position = hit.GetPosition();
                TVector3 position_forw = hit_forw.GetPosition();
                TVector3 position_next = hit_next.GetPosition();

                //if(position.X()<130.0) continue;
                //if(position_forw.X()<130.0)

                Double_t hitdist = TMath::Sqrt( TMath::Power(position.X()-position_next.X(),2) + TMath::Power(position.Y()-position_next.Y(),2) + TMath::Power(position.Z()-position_next.Z(),2)   );
                //std::cout<<" Hit Coordinates - X : "<<position.X()<<" Y : "<<position.Y()<<" - Hit Coordinates Forward - X : "<<position_forw.X()<<" Y : "<<position_forw.Y()<<std::endl;
                //std::cout<<" Distance : "<<hitdist<<std::endl;
                //std::cout<<" Position Z : "<<position.Z()<<std::endl;
                //hdist->Fill(hitdist);

                //if(hitdist<4.0) continue;
                //distVSTb->Fill(hitdist,position.Z());

                //if(hitdist>5.0) continue;

          			for(Int_t itheta = 0; itheta <1023; itheta++){
          	 				Float_t angle = TMath::Pi()*(static_cast<Float_t>(itheta)/1023);
                    Float_t d0_XY_inv = 2.0* ( (position.Y()-position_forw.Y())*TMath::Sin(angle) + (position.X()-position_forw.X())*TMath::Cos(angle)  )
                    / ( (TMath::Power(position.Y(),2)-TMath::Power(position_forw.Y(),2) ) +   (TMath::Power(position.X(),2)-TMath::Power(position_forw.X(),2) )        );
                    HistHoughXY->Fill(angle,1.0/d0_XY_inv);
                }
      }//Hit loop

                    Int_t locmaxx,locmaxy,locmaxz;
                    HistHoughXY->GetMaximumBin(locmaxx,locmaxy,locmaxz);
                    Double_t xpos = HistHoughXY->GetXaxis()->GetBinCenter(locmaxx);
                    Double_t ypos = HistHoughXY->GetYaxis()->GetBinCenter(locmaxy);

                    fXCenter =  ypos*TMath::Cos(xpos);
                    fYCenter =  ypos*TMath::Sin(xpos);

                        //std::cout<<" yPos"<<ypos<<std::endl;
                        //std::cout<<" XCenter"<<fXCenter<<std::endl;
                        //std::cout<<" YCenter"<<fYCenter<<std::endl;
                      /// Radius, Phi, Theta, B, x0,y0,z0

                      fIniRadius=0.0;
                      fIniPhi=0.0;
                      fIniTheta=0.0;

                      
                      for(Int_t iHit=0; iHit<nHits-1; iHit++){

                             ATHit hit = event->GetHitArray()->at(iHit);
                             TVector3 position = hit.GetPosition();
                             ATHit hit_forw = event->GetHitArray()->at(iHit+1);
                             TVector3 position_forw = hit_forw.GetPosition();

                             fRadius->push_back(TMath::Sqrt(  TMath::Power((fXCenter-position.X()),2)   +  TMath::Power((fYCenter-position.Y()),2)    ));
                             fTimeStamp->push_back(hit.GetTimeStamp());
                             fPhi->push_back(TMath::ATan2(fXCenter-position.X(),fYCenter-position.Y()));
                             Double_t dl = TMath::Sqrt( TMath::Power(position_forw.X()-position.X(),2) + TMath::Power(position_forw.Y()-position.Y(),2)  );
                             Double_t dz = (hit_forw.GetTimeStamp()-hit.GetTimeStamp())*drift_cal;
                             //fTheta->push_back(TMath::ATan2(dl,dz)); // Obsolete


                                //Second Hough Space Calculation for PhixRadius

                                   for(Int_t itheta = 0; itheta <1023; itheta++){
                                        Float_t angle = TMath::Pi()*(static_cast<Float_t>(itheta)/1023);
                                        Float_t d0_XY = (TMath::Cos(angle)*fPhi->at(iHit)*fRadius->at(iHit))  +  (TMath::Sin(angle)*hit.GetTimeStamp());
                                        HistHoughAux->Fill(angle,d0_XY);
                                        //FillHoughMap(angle,d0_XY);

                                  }

                             //Phi->SetBinContent(hit.GetTimeStamp(),fTheta->at(iHit));
                             //RadVSTb->Fill(hit.GetTimeStamp(),fRadius->at(iHit));
                             //std::cout<<" Hit Time Stamp : "<<hit.GetTimeStamp()<<std::endl;
                             //std::cout<<" Phi "<<fPhi->at(iHit)<<std::endl;
                      }

                    fHoughLinePar =  CalHoughParameters(HistHoughAux);//Histo
                    //std::pair<Double_t,Double_t> HoughLinePar = CalHoughParameters();//std
                    Double_t IniPosZ =0.0;


                    Int_t IniTSBuff=0;
                    Double_t IniRadiusBuff =0.0;
                    Double_t IniPhiBuff =0.0;


                    for(Int_t iHit=0; iHit<nHits-1; iHit++)
                    {
                      ATHit hit = event->GetHitArray()->at(iHit);
                      TVector3 position = hit.GetPosition();
                      Double_t geo_dist = TMath::Abs (TMath::Cos(fHoughLinePar.first)*fPhi->at(iHit)*fRadius->at(iHit)  + TMath::Sin(fHoughLinePar.first)*hit.GetTimeStamp()  - fHoughLinePar.second);
                      Double_t hit_dist = TMath::Sqrt( TMath::Power( (fPhi->at(iHit)*fRadius->at(iHit) - IniPhiBuff*IniRadiusBuff),2) + TMath::Power(hit.GetTimeStamp()-IniTSBuff ,2) );
                      //if(hit_dist<50) std::cout<<" Hist Dist pre :"<<hit_dist<<" Geo Dist : "<<geo_dist<<std::endl;



                              if(geo_dist<10.0){
                                        //fIniHit->SetHit(hit.GetHitPadNum(),hit.GetHitID(),position.X(),position.Y(),position.Z(),hit.GetCharge());
                                        //IniPosZ = position.Z();
                                        //fIniHit->SetTimeStamp(hit.GetTimeStamp());
                                        IniTSBuff = hit.GetTimeStamp();
                                        IniRadiusBuff = fRadius->at(iHit);
                                        IniPhiBuff = fPhi->at(iHit);

                                          if(hit_dist<10.0){


                                            fClusteredHits->push_back(&hit);
                                            fIniHit->SetHit(hit.GetHitPadNum(),hit.GetHitID(),position.X(),position.Y(),position.Z(),hit.GetCharge());
                                            IniPosZ = position.Z();
                                            fIniHit->SetTimeStamp(hit.GetTimeStamp());
                                            fIniTS = IniTSBuff;
                                            fIniRadius = IniRadiusBuff;
                                            fIniPhi = IniPhiBuff;
                                            fIniHitID = iHit; // Easier and faster to use the position of the hit in the vector
                                            //fIniHitID = hit.GetHitID();
                                            //std::cout<<" Position Z : "<<position.Z()<<std::endl;
                                            //std::cout<<" Hit : "<<iHit<<" Timebucket : "<<hit.GetTimeStamp()<<" Geometrical distance : "<<geo_dist<< " Hit Dist : "<<hit_dist<<std::endl;


                                          }




                                  }


                     }// End of clustering algorithm

                    //std::cout<<" ==========================================="<<std::endl;

                      Double_t dl_theta=0.0;
                      Double_t theta_avg=0.0;
                      Int_t clusterSize=fClusteredHits->size();
                      /*for(Int_t i=0;i<clusterSize;i++){
                         ATHit hittest = fClusteredHits->at(i);
                         std::cout<<" Clustered Hit num : "<<i<<" Time Stamp : "<<hittest.GetTimeStamp()<<std::endl;
                       }*/

                      //More precise determination of the scattering angle
                      //std::cout<<" ++++++++ Event Angle calculation ++++++++++"<<std::endl;
                      Int_t TB_Scan = 0;
                      for(Int_t iHitTB=0;iHitTB<clusterSize-1;iHitTB++){

                        Double_t posx=0.0;
                        Double_t posy=0.0;
                        Double_t posz=0.0;
                        Double_t totCharge=0.0;
                        Double_t cmsHits_X =0.0;
                        Double_t cmsHits_Y =0.0;
                        Int_t TB =0;
                        Double_t posx_forw=0.0;
                        Double_t posy_forw=0.0;
                        Double_t posz_forw=0.0;
                        Double_t totCharge_forw=0.0;
                        Double_t cmsHits_X_forw =0.0;
                        Double_t cmsHits_Y_forw =0.0;
                        Int_t TB_forw = 0;


                        // TODO: Only neighboring TB are taken into account
                        std::vector<ATHit>  fClusteredTBHits;
                        std::vector<ATHit>  fClusteredTBHits_forw;


                        fClusteredTBHits=min->GetTBHitArray(fIniTS-iHitTB-TB_Scan,fClusteredHits);

                      if(fClusteredTBHits.size()>0){ //Found at least 1 clustered hit in that time bucket, if not go to the next loop iteration
                              //std::cout<<" ================================ "<<std::endl;
                              //std::cout<<"  Starting cluster with TB : "<<fIniTS-iHitTB<<std::endl;
                              fClusteredTBHits_forw=min->GetTBHitArray(fIniTS-iHitTB-1-TB_Scan,fClusteredHits);

                       if(fClusteredTBHits_forw.size()==0){// If forward hit is empty scan until the end of the vector or until the next non-zero solution


                            while(fClusteredTBHits_forw.size()==0  &&  fIniTS-iHitTB-1-TB_Scan>0){ //TODO: Use a lambda function for this mess
                                TB_Scan++;
                                fClusteredTBHits_forw=min->GetTBHitArray(fIniTS-iHitTB-1-TB_Scan,fClusteredHits);
                                //std::cout<<TB_Scan<<std::endl;
                                //std::cout<<fClusteredTBHits_forw.size()<<std::endl;
                            }

                        }

                        if(fClusteredTBHits_forw.size()>0){




                                      if( fClusteredTBHits.size()>0  && fClusteredTBHits_forw.size()>0 ){

                                            for(Int_t iHit=0;iHit<fClusteredTBHits.size();iHit++){
                                              ATHit hitTB = fClusteredTBHits.at(iHit);
                                              TVector3 positionTB = hitTB.GetPosition();
                                              TB = hitTB.GetTimeStamp();
                                              cmsHits_X+= positionTB.X()*hitTB.GetCharge();
                                              cmsHits_Y+= positionTB.Y()*hitTB.GetCharge();
                                              totCharge+=hitTB.GetCharge();
                                              //std::cout<<" Hit TB : "<<TB<<" Position X : "<<positionTB.X()<<" Position Y : "<<positionTB.Y()<<std::endl;
                                            }

                                            for(Int_t iHit=0;iHit<fClusteredTBHits_forw.size();iHit++){
                                              ATHit hitTB_forw = fClusteredTBHits_forw.at(iHit);
                                              TVector3 positionTB_forw = hitTB_forw.GetPosition();
                                              TB_forw = hitTB_forw.GetTimeStamp();
                                              cmsHits_X_forw+= positionTB_forw.X()*hitTB_forw.GetCharge();
                                              cmsHits_Y_forw+= positionTB_forw.Y()*hitTB_forw.GetCharge();
                                              totCharge_forw+=hitTB_forw.GetCharge();
                                              //std::cout<<" Hit TB forw : "<<TB_forw<<" Position forw X : "<<positionTB_forw.X()<<" Position forw Y : "<<positionTB_forw.Y()<<std::endl;
                                            }

                                      }

                                      posx=cmsHits_X/totCharge;
                                      posy=cmsHits_Y/totCharge;
                                      posx_forw=cmsHits_X_forw/totCharge_forw;
                                      posy_forw=cmsHits_Y_forw/totCharge_forw;
                                      //std::cout<<" Average Pos X : "<<posx<<" Average Pos Y : "<<posy<<std::endl;
                                      //std::cout<<" Average Pos Forward X : "<<posx_forw<<" Average Pos Forward Y : "<<posy_forw<<std::endl;

                            }//Hit forward if>0
                          }//Hit if>0

                          Double_t distXY = TMath::Sqrt( TMath::Power(posx-posx_forw,2) + TMath::Power(posy-posy_forw,2) );
                          Double_t dl = (TB-TB_forw)*drift_cal;
                          theta_avg=TMath::ATan2(distXY,dl);
                          fTheta->push_back(theta_avg);
                          fDl->push_back(TB);
                          //std::cout<<TB<<std::endl;


                     }// Loop over clusterSize


                       // Path integration
                       /*for(Int_t iHitT=0; iHitT<clusterSize-1;iHitT++ ){
                          //std::cout<<" iHit : "<<iHitT<<" Cluster Size - Hit : "<<clusterSize-iHitT<<std::endl;

                        // ATHit hitT = event->GetHitArray()->at(nHits-iHitT);
                        // ATHit hitT_forw = event->GetHitArray()->at(nHits-1-iHitT);
                         ATHit hitT = fClusteredHits->at(clusterSize-iHitT-1);
                         ATHit hitT_forw = fClusteredHits->at(clusterSize-iHitT-2);
                         TVector3 positionT = hitT.GetPosition();
                         TVector3 positionT_forw = hitT_forw.GetPosition();


                               //if(positionT_forw.Z()-IniPosZ>=0){
                               dl_theta+= TMath::Sqrt( TMath::Power(positionT_forw.X()-positionT.X(),2) + TMath::Power(positionT_forw.Y()-positionT.Y(),2)  );
                               fDl->push_back(dl_theta);
                               fTheta->push_back( TMath::ATan2(dl_theta,(positionT_forw.Z() - IniPosZ ) ) ); // Distance in time between origin and Hit point (not HitT)
                               //std::cout<<" Hit : "<<iHitT<<" Position Forw : "<<positionT_forw.Z()-IniPosZ<<" dl : "<<dl_theta<<" Time Stamp : "<<hitT.GetTimeStamp()<<std::endl;

                              //}


                       }*/

                    //RadVSTb->Draw();
                    //Phi->Draw();
                    //HistHoughAux->Draw("zcol");

                    Double_t fThetaVal=0.0;
                    Int_t thetacnt=0; //Needed to remove theta values with 0

                    if(!fTheta->empty()){

                        for(Int_t i=0;i<fTheta->size();++i){
                            if(fTheta->at(i)>0){
                             fThetaVal+= fTheta->at(i);
                             thetacnt++;
                           }
                        }
                        fIniTheta = fThetaVal/thetacnt;
                        //std::cout<<" Theta Size : "<<fTheta->size()<<std::endl;
                        //std::cout<<" fIniTheta  : "<<fIniTheta<<" thetacnt : "<<thetacnt<<std::endl;
                        //fIniTheta = fTheta->back();
                    }


                    TVector3 IniHitPos = fIniHit->GetPosition();
                    Double_t* parameter = new Double_t[8];
                    parameter[0]=IniHitPos.X();
                    parameter[1]=IniHitPos.Y();
                    parameter[2]=IniHitPos.Z();
                    parameter[3]=fIniTS;
                    parameter[4]=fIniPhi;
                    parameter[5]=fIniRadius;
                    parameter[6]=fIniTheta;
                    parameter[7]=fIniHitID;





                   min->Minimize(parameter,event);
                   fPosXmin = min->GetPosXMin();
                   fPosYmin = min->GetPosYMin();
                   fPosZmin = min->GetPosZMin();
                   fPosXexp = min->GetPosXExp();
                   fPosYexp = min->GetPosYExp();
                   fPosZexp = min->GetPosZExp();
                   fPosXinter = min->GetPosXInt();
                   fPosYinter = min->GetPosYInt();
                   fPosZinter = min->GetPosZInt();
                   ATHoughSpaceCircle::FitParameters.sThetaMin = min->FitParameters.sThetaMin;
                   ATHoughSpaceCircle::FitParameters.sThetaMin = min->FitParameters.sThetaMin;
                   ATHoughSpaceCircle::FitParameters.sEnerMin  = min->FitParameters.sEnerMin;
                   ATHoughSpaceCircle::FitParameters.sPosMin   = min->FitParameters.sPosMin;
                   ATHoughSpaceCircle::FitParameters.sBrhoMin  = min->FitParameters.sBrhoMin;
                   ATHoughSpaceCircle::FitParameters.sBMin     = min->FitParameters.sBMin;
                   ATHoughSpaceCircle::FitParameters.sPhiMin   = min->FitParameters.sPhiMin;
                   ATHoughSpaceCircle::FitParameters.sChi2Min   = min->FitParameters.sChi2Min;
                   delete min;

                    //hdist->Draw();
                    //distVSTb->Draw("zcol");

}


std::pair<Double_t,Double_t> ATHoughSpaceCircle::CalHoughParameters(TH2F* hist){

		std::pair<Double_t,Double_t> HoughParBuff;
		Int_t locmaxx,locmaxy,locmaxz;
    hist->GetMaximumBin(locmaxx,locmaxy,locmaxz);
    Double_t xpos = hist->GetXaxis()->GetBinCenter(locmaxx);
    Double_t ypos = hist->GetYaxis()->GetBinCenter(locmaxy);
		//std::cout<<" X Hough Position : "<<180-xpos*180/TMath::Pi()<<std::endl;
    //std::cout<<" X Hough Position : "<<xpos<<std::endl;
	  //std::cout<<" Y Hough Position : "<<ypos<<std::endl;
		HoughParBuff.first= xpos;
		HoughParBuff.second= ypos;
		return HoughParBuff;

}

void ATHoughSpaceCircle::FillHoughMap(Double_t ang, Double_t dist)
{


      ULong64_t MapKey;

      //if(ang<0 || dist<0)  std::cout<<" -I- ATHougSpaceLine : Negative values for Hough Space parameters "<<std::endl;

      if(ang>0 || dist>0){
      Int_t dist_enc = static_cast<Int_t>(round(dist*1.5));
      Int_t ang_enc = static_cast<Int_t>(round(ang*160.0));
      /*std::cout<<" Filling std::map for the Hough Space "<<std::endl;
      std::cout<<" Hough Angle : "<<ang<<" Hough Dist : "<<dist<<std::endl;
      std::cout<<" Encoded Hough Angle : "<<ang_enc<<" Encoded Hough Dist : "<<dist_enc<<std::endl;*/

      MapKey = dist_enc&0xFFFFFFFF;
      MapKey = (MapKey<<32) + (ang_enc&0xFFFFFFFF);
      HoughMap[MapKey]++;

    /*  std::cout<<" Map Key : "<<MapKey<<std::endl;
      std::cout<<" Map Key Dist "<<(MapKey&0xFFFFFFFF)<<std::endl;
      std::cout<<" Map Key Ang "<<((MapKey>>32)&(0xFFFFFFFF))<<std::endl;*/

      }


}

std::pair<Double_t,Double_t> ATHoughSpaceCircle::CalHoughParameters()
{

    std::pair<Double_t,Double_t> HoughParBuff;
    // Method 1:
    /*  using pair_type = decltype(HoughMap)::value_type;

       auto pr = std::max_element
        (
            std::begin(HoughMap), std::end(HoughMap),
            [] (const pair_type & p1, const pair_type & p2) {
              return p1.second < p2.second;
            }
         );

          std::cout << "pr->first : " << pr->first<< '\n';
          std::cout << "pr->second : " << pr->second<< '\n';
          std::cout << " pr->first&0xFFFFFFFF " << (pr->first&0xFFFFFFFF) << '\n';
          std::cout << " ((pr->first>>32)&0xFFFFFFFF) " << ((pr->first>>32)&0xFFFFFFFF) << '\n';*/


     //Method 2:
           std::map<ULong64_t,Int_t>::iterator maximum = std::max_element(HoughMap.begin(), HoughMap.end(), maxpersecond());
           HoughParBuff.first=(maximum->first&0xFFFFFFFF)/160.0; //Binning of the associated histogram
           HoughParBuff.second=((maximum->first&0xFFFFFFFF00000000)>>32)/1.5;
          // std::cout<<" Size of First Element in Hough Map (byte) :"<<sizeof(maximum->first)<<std::endl;
          // std::cout<<" Size of Second Element of Houg Map (byte) :"<<sizeof(maximum->second)<<std::endl;
          // std::cout<<" Angle : "<<(maximum->first&0xFFFFFFFF)/160.0<<std::endl;
          // std::cout<<" Distance : "<<((maximum->first&0xFFFFFFFF00000000)>>32)/1.5<<std::endl;
          // std::cout<<" Number of Maximum Votes : "<<maximum->second<<std::endl;
          return HoughParBuff;

}

void ATHoughSpaceCircle::CalcHoughSpace(ATProtoEvent* protoevent,Bool_t q1,Bool_t q2, Bool_t q3, Bool_t q4){



}
