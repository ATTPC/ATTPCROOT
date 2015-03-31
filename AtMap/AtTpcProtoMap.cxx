/*********************************************************************
*   ATTPC Mapping Class	AtTpcProtoMap.cxx			             *	
*   Author: Y. Ayyad            				     *
*   Log: 31-03-2015 11:56 JST					     *
*								     *	
*********************************************************************/

#include "AtTpcProtoMap.h"
#include "TMultiGraph.h"
#include "TKey.h"

ClassImp(AtTpcProtoMap)

AtTpcProtoMap::AtTpcProtoMap()
{

Initialize();

}

AtTpcProtoMap::~AtTpcProtoMap()
{

}

void AtTpcProtoMap::Initialize()
{
  IsFileSet= kFALSE;
  hProto = new TH2Poly();
  hProto->SetName("ATTPC_Proto");
  hProto->SetTitle("ATTPC_Proto");

}

Bool_t AtTpcProtoMap::SetGeoFile(TString geofile){

  TString dir = getenv("VMCWORKDIR");
  TString geodir = dir + "/geometry/"+ geofile;
  f = new TFile(geodir.Data());
 	 if(!f){
   		std::cout<<" ATTPC Proto Map : No geometry file found! Check VMCWORKDIR variable. Exiting... "<<std::endl;
                return kFALSE;
	 }else{
               	std::cout<<" ATTPC Proto Map : Prototype geometry found in : "<<geodir.Data()<<std::endl;
		IsFileSet=kTRUE;
                return kTRUE;
	 }


}

void AtTpcProtoMap::GenerateATTPC(){

    std::cout<<" ATTPC Proto Map : Generating the map geometry of the ATTPC Prototype "<<std::endl;
    TMultiGraph *mg;
    TKey *key;
    TIter nextkey(gDirectory->GetListOfKeys());
    while (key = (TKey*)nextkey()) {
      TMultiGraph *obj =(TMultiGraph*)key->ReadObj();
      if (obj->InheritsFrom("TMultiGraph")) {
         mg = (TMultiGraph*)obj;
         bin = hProto->AddBin(mg);
         std::cout<<bin<<std::endl;
      }
   }

}

TH2Poly* AtTpcProtoMap::GetATTPCPlane(){

     
               
	//std::cout<<" AtTpcMap::GetATTPCPlane Error : Pad plane has not been generated - Exiting... "<<std::endl;

	//return 0;

      
      // if(kGUIMode){
        cATTPCPlane = new TCanvas("cATTPCPlane","cATTPCPlane",1000,1000);
        gStyle->SetPalette(1);
    	hProto->Draw("Lcol");
      // }	

       return hProto;
}

TH2Poly* AtTpcProtoMap::GetATTPCPlane(TString TH2Poly_name){

       if(!f){
   	std::cout<<" ATTPC Proto Map : No geometry file found! Please set the geometry file first via SetGeoFile method "<<std::endl;
                return NULL;
	}
       hProto = (TH2Poly*)f->Get(TH2Poly_name.Data());
       cATTPCPlane = new TCanvas("cATTPCPlane","cATTPCPlane",1000,1000);
       gStyle->SetPalette(1);
       hProto->Draw("Lcol");
       return hProto;
}




