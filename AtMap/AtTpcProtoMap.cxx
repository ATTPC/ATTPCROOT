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
  kIsFileSet= kFALSE;
  kIsGenerated = kFALSE;
  kIsProtoMapSet = kFALSE;
  hProto = new TH2Poly();
  hProto->SetName("ATTPC_Proto");
  hProto->SetTitle("ATTPC_Proto");
  

}

Bool_t AtTpcProtoMap::SetGeoFile(TString geofile){

  TString dir = getenv("VMCWORKDIR");
  TString geodir = dir + "/geometry/"+ geofile;
  f = new TFile(geodir.Data());
  
 	 if(f->IsZombie()){
   		std::cout<<" ATTPC Proto Map : No geometry file found! Check VMCWORKDIR variable. Exiting... "<<std::endl;//TODO Not working!!!
		delete f;
                return kFALSE;
	 }
               	std::cout<<" ATTPC Proto Map : Prototype geometry found in : "<<geodir.Data()<<std::endl;
		kIsFileSet=kTRUE;
                return kTRUE;
	 


}

void AtTpcProtoMap::GenerateATTPC(){

    if(f->IsZombie()){
   	std::cout<<" ATTPC Proto Map : No geometry file found! Please set the geometry file first via SetGeoFile method "<<std::endl;
                return;
    }

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
 
    kIsGenerated = kTRUE;

}

TH2Poly* AtTpcProtoMap::GetATTPCPlane(){
	// This method must be called after GenerateATTPC()
     
        if(!kIsFileSet){
   	std::cout<<" ATTPC Proto Map : No geometry file found! Please set the geometry file first via the SetGeoFile method "<<std::endl;
                return NULL;
	}
            
        if(!kIsGenerated){
	std::cout<<"  ATTPC Proto Map : Pad plane has not been generated. Please generate it via the GenerateATTPC method "<<std::endl;
	return NULL;
	}
  
       if(kGUIMode){
        cATTPCPlane = new TCanvas("cATTPCPlane","cATTPCPlane",1000,1000);
        gStyle->SetPalette(1);
    	hProto->Draw("Lcol");
       }	

       return hProto;
}

TH2Poly* AtTpcProtoMap::GetATTPCPlane(TString TH2Poly_name){
       // This is a stand alone method
       if(f->IsZombie()){
   	std::cout<<" ATTPC Proto Map : No geometry file found! Please set the geometry file first via SetGeoFile method "<<std::endl;
                return NULL;
	}
       hProto = (TH2Poly*)f->Get(TH2Poly_name.Data());
       cATTPCPlane = new TCanvas("cATTPCPlane","cATTPCPlane",1000,1000);
       gStyle->SetPalette(1);
       hProto->Draw("Lcol");
       return hProto;
}

std::vector<Float_t> AtTpcProtoMap::CalcPadCenter(Int_t PadRef){



             std::vector<Float_t> PadCenter={-9999,-9999};
             PadCenter.reserve(2);
	     
              if(!kIsProtoMapSet){
   		std::cout<<" ATTPC Proto Map : No map file for prototype found! Please set the geometry file first via the SetProtoMap method "<<std::endl;
		 return PadCenter;

      	      }           

	      
	      if(f->IsZombie()){
   		std::cout<<" ATTPC Proto Map : No geometry file found! Please set the geometry file first via the SetGeoFile method "<<std::endl;
		return PadCenter;

      	      }

             

   	   if(PadRef!=-1){ //Boost multi_array crashes with a negative index
                return PadCenter; //TODO We return this dummy coordinates for the moment	       	    

              

	   }else{

		if(kDebug) std::cout<<" AtTpcMap::CalcPadCenter Error : Pad not found"<<std::endl;
		return PadCenter;

	   }

}

Bool_t AtTpcProtoMap::SetProtoMap(TString file){


	TString PadName;
	Int_t PadNum;
	InProtoMap = new ifstream(file.Data());
        if(InProtoMap->fail()){
		 std::cout<<" ATTPC Proto Map : No Prototype Map file found! "<<std::endl;
		 return kFALSE;
	}


		    while(!InProtoMap->eof()){
         
     			   *InProtoMap>>PadNum>>PadName;
			   if(kDebug)
		             if(!PadName.IsNull()) std::cout<<" PadNum : "<<PadNum<<" PadName "<<PadName.Data()<<std::endl;
         
   		     }
 
        kIsProtoMapSet=kTRUE;
        return kTRUE;

}




