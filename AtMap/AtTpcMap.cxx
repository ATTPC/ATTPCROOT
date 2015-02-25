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

  
  //delete cATTPCPlane;
  //delete hPlane;


}

void AtTpcMap::Initialize()
{
 
  kGUIMode=0;
  kDebug=0;
  std::fill( AtPadCoord.data(), AtPadCoord.data()+AtPadCoord.num_elements() , 0);
  std::cout<<" ATTPC Pad Coordinates container initialized "<<endl;
  fPadInd = 0;
  PadKey.clear();
}

void AtTpcMap::Dump(){
	
    int values = 0;
  	 for(index i = 0; i != 10240; ++i) 
   	   for(index j = 0; j != 3; ++j)
     	     for(index k = 0; k != 2; ++k)
             	std::cout<<" ATTPC Triangular pad coordinates - Pad Index : "<<i<<"   X("<<j<<")  -  Y("<<k<<") :"<<AtPadCoord[i][j][k]<<endl;

}

void AtTpcMap::GenerateATTPC(){

    // Local variables
    Float_t pads_in_half_hex;
    Float_t pads_in_hex;
    Float_t row_length = 0;
    Float_t pads_in_half_row = 0;
    Int_t pads_out_half_hex = 0 ;
    Int_t pads_in_row = 0;
    Int_t ort = 0;
    Float_t pad_x_off = 0;
    Float_t pad_y_off = 0;
    Float_t tmp_pad_x_off = 0;
    Float_t tmp_pad_y_off = 0;

    Float_t small_z_spacing = 2*25.4/1000.;
    Float_t small_tri_side = 184.*25.4/1000.;
    Double_t umega_radius = 10826.772*25.4/1000.;
    Float_t beam_image_radius = 4842.52*25.4/1000.;
    Int_t pad_index = 0;
    Int_t pad_index_aux=0;

    Float_t small_x_spacing = 2. * small_z_spacing / TMath::Sqrt(3.);
    Float_t small_y_spacing = small_x_spacing * TMath::Sqrt(3.);
    Float_t dotted_s_tri_side = 4. * small_x_spacing + small_tri_side;
    Float_t dotted_s_tri_hi = dotted_s_tri_side * TMath::Sqrt(3.)/2.;
    Float_t dotted_l_tri_side = 2. * dotted_s_tri_side;
    Float_t dotted_l_tri_hi = dotted_l_tri_side * TMath::Sqrt(3.)/2.;
    Float_t large_x_spacing = small_x_spacing;
    Float_t large_y_spacing = small_y_spacing;
    Float_t large_tri_side = dotted_l_tri_side - 4.*large_x_spacing;
    Float_t large_tri_hi = dotted_l_tri_side * TMath::Sqrt(3.)/2.;
    //Float_t row_len_s = 2**TMath::Ceil(TMath::Log(beam_image_radius/dotted_s_tri_side)/TMath::Log(2.0));
    Float_t row_len_s = pow(2,TMath::Ceil(TMath::Log(beam_image_radius/dotted_s_tri_side)/TMath::Log(2.0)));
    Float_t row_len_l = TMath::Floor(umega_radius/dotted_l_tri_hi);
     
    Float_t xoff = 0.;
    Float_t yoff = 0.;

      
    for(Int_t j =0;j<row_len_l;j++){
         
        pads_in_half_hex = 0;
        pads_in_hex = 0;
        //row_length = TMath::Abs(sqrt(umega_radius**2 - (j*dotted_l_tri_hi + dotted_l_tri_hi/2.)**2));
        row_length = TMath::Abs(sqrt(pow(umega_radius,2) - pow((j*dotted_l_tri_hi + dotted_l_tri_hi/2.),2)));

        if(j<row_len_s/2.){
             
            pads_in_half_hex = (2*row_len_s - 2*j)/4.;
            pads_in_hex = 2*row_len_s - 1. - 2.*j;
             
             
        }//if row_len_s

        pads_in_half_row = row_length /dotted_l_tri_side;
        pads_out_half_hex = static_cast<Int_t> (TMath::Nint(2*(pads_in_half_row-pads_in_half_hex)));
        pads_in_row = 2 * pads_out_half_hex + 4 * pads_in_half_hex - 1;

	ort = 1;
 
            for(Int_t i =0;i<pads_in_row;i++){
             
                if(i==0){
                 
                    if(j%2==0) ort = -1;
                    if(( (pads_in_row-1)/2)%2 == 1) ort = -ort;
                 
                }//i==0
                else ort = -ort;
                 
                 
                 
                pad_x_off = -(pads_in_half_hex + pads_out_half_hex/2.)*dotted_l_tri_side + i*dotted_l_tri_side/2. + 2.*large_x_spacing + xoff;
                 
                if(i<pads_out_half_hex || i> (pads_in_hex + pads_out_half_hex - 1) || j> (row_len_s/2. -1)){
                     
                    pad_y_off = j*dotted_l_tri_hi + large_y_spacing + yoff;
                    if(ort==-1) pad_y_off+=large_tri_hi;
                    fill_coord(pad_index,pad_x_off,pad_y_off,large_tri_side,ort);
                    pad_index+=1;  
                     
                }//if
                else{
                     
                    pad_y_off = j*dotted_l_tri_hi + large_y_spacing + yoff;
                    if(ort==-1) pad_y_off = j*dotted_l_tri_hi + 2*dotted_s_tri_hi - small_y_spacing+yoff;
                    fill_coord(pad_index,pad_x_off, pad_y_off, small_tri_side, ort);
                    pad_index += 1;
                    tmp_pad_x_off = pad_x_off + dotted_s_tri_side/2.;
                    tmp_pad_y_off = pad_y_off + ort*dotted_s_tri_hi - 2*ort*small_y_spacing;
                    fill_coord(pad_index,tmp_pad_x_off, tmp_pad_y_off, small_tri_side, -ort);
                    pad_index += 1;
                    tmp_pad_y_off = pad_y_off+ort*dotted_s_tri_hi;
                    fill_coord(pad_index,tmp_pad_x_off, tmp_pad_y_off, small_tri_side, ort);
                    pad_index += 1;
                    tmp_pad_x_off = pad_x_off + dotted_s_tri_side;
                    fill_coord(pad_index,tmp_pad_x_off, pad_y_off, small_tri_side, ort);
                    pad_index += 1;
                     
                     
                }
             
             
        }//pads_in_row loop


    }//row_len_l

	   for(Int_t i =0;i<pad_index;i++){
        	for(Int_t j=0;j<3;j++){
           		 AtPadCoord[i+pad_index][j][0]=-AtPadCoord[i][j][0];
           		 AtPadCoord[i+pad_index][j][1]=-AtPadCoord[i][j][1];
            
             
       		 }
      		  pad_index_aux++;
   	 }

       fPadInd = pad_index + pad_index_aux;

}

void AtTpcMap::GenerateProto(){

}

Int_t AtTpcMap::fill_coord(int pindex, float padxoff, float padyoff, float triside, float fort){

    AtPadCoord[pindex][0][0] = padxoff;
    AtPadCoord[pindex][0][1] = padyoff;
    AtPadCoord[pindex][1][0] = padxoff + triside/2.;
    AtPadCoord[pindex][1][1] = padyoff + fort*triside*TMath::Sqrt(3.)/2.;
    AtPadCoord[pindex][2][0] = padxoff + triside;
    AtPadCoord[pindex][2][1] = padyoff;


}

TH2Poly* AtTpcMap::GetATTPCPlane(){

      if(fPadInd == 0){
               
	std::cout<<" ATTPC Error : Pad plane has not been generated - Exiting... "<<std::endl;

	return 0;

      }


 
        hPlane->SetName("ATTPC_Plane");
    	hPlane->SetTitle("ATTPC_Plane");

		 for(Int_t i=0;i<fPadInd;i++){
    
      			  Double_t px[]={AtPadCoord[i][0][0],AtPadCoord[i][1][0],AtPadCoord[i][2][0]};
      			  Double_t py[]={AtPadCoord[i][0][1],AtPadCoord[i][1][1],AtPadCoord[i][2][1]};
       			  hPlane->AddBin(3,px,py);
            
       		 }

       if(kGUIMode){
        cATTPCPlane = new TCanvas("cATTPCPlane","cATTPCPlane",1000,1000);
        gStyle->SetPalette(1);
    	hPlane->Draw("Lcol");
       }	

       return hPlane;
}

Bool_t AtTpcMap::ParseXMLMap(char *xmlfile){


	    TDOMParser *domParser = new TDOMParser();
	    domParser->SetValidate(false);
	    Int_t parsecode = domParser->ParseFile(xmlfile);	
	    if(parsecode<0){
		std::cerr<< domParser->GetParseCodeMessage(parsecode) <<std::endl;
	    }
	    TXMLNode * node = domParser->GetXMLDocument()->GetRootNode();
	    ParseMapList(node->GetChildren());
	    //itrEnd = pmap.end();
	    delete domParser;

	   return true;

}

void AtTpcMap::ParseMapList(TXMLNode *node){

		std::vector<int> test;
                test.resize(4);
                test[0] = 8;
                test[1] = 0;
                test[2] = 1;
                test[3] = 10;
                Int_t aux=0;
		for(int i=0;i<4;i++) std::cout<<test[i]<<endl;
		for(; node;node=node->GetNextNode()){
			if(node->GetNodeType()==TXMLNode::kXMLElementNode){ //Element node
			   if(strcmp(node->GetNodeName(),"Lookup20141208") == 0){
				//cout<<node->GetNodeName()<<endl;
				ParseATTPCMap(node->GetChildren());
			   }
			}

		}

    
		//Option 1: Int key - vector<int> value
		/*	std::map<int,std::vector<int>>::iterator it;
               		std::ostream_iterator<int> ii (std::cout,", ");

				for(it=this->ATTPCPadMap.begin(); it!=this->ATTPCPadMap.end(); ++it){ 
					std::cout<<" [ "<<(*it).first<<", ";
					std::copy ((*it).second.begin(), (*it).second.end(), ii );
					std::cout<<"]"<<std::endl;;
					
				}
			
			std::map<int, std::vector<int>>::const_iterator ite = ATTPCPadMap.find(1);
                        std::string value = it->second;
			*/

		 //Option 2: vector<int> key - int value
			std::map<std::vector<int>,int>::iterator it;
               		std::ostream_iterator<int> ii (std::cout,", ");

				/*for(it=this->ATTPCPadMap.begin(); it!=this->ATTPCPadMap.end(); ++it){ 
					std::cout<<" [ "<<(*it).second<<", ";
					std::copy ((*it).first.begin(), (*it).first.end(), ii );
					std::cout<<"]"<<std::endl;;
					
				}*/
		
	//Option 1: Int key - vector<int> value
			//std::map<int, std::vector<int>>::const_iterator ite = ATTPCPadMap.find(1);
                        //std::string value = it->second;
			 //Option 2: vector<int> key - int value
			 std::map<std::vector<int>,int>::const_iterator its =ATTPCPadMap.find(test);
			 int value = (*its).second;
			 std::cout<<value<<std::endl;
			 //std::map<std::vector<int>,int>::const_iterator its;
			 //std::cout<<ATTPCPadMap.find(test)->second<<std::endl;
			// auto its = ATTPCPadMap.find(test);
			// std::cout << "x: " << (int)its->second << "\n";
			
			



		/*for (auto& m : ATTPCPadMap){ //C+11 style
			    
			for(auto& kv : m.second){
				std::cout<<m.first<<'\n';
			}		
		}*/

		


}


void AtTpcMap::ParseATTPCMap(TXMLNode *node){

		Int_t fCoboID;
                Int_t fAsadID;
		Int_t fAgetID;
		Int_t fChannelID;
                Int_t fPadID;
	        
                 

		for ( ; node; node = node->GetNextNode()) {
   		 	 if (node->GetNodeType() == TXMLNode::kXMLElementNode) { // Element Node
				if (strcmp(node->GetNodeName(), "CoboID") == 0)
				fCoboID = atoi(node->GetText());
				if (strcmp(node->GetNodeName(), "AsadID") == 0)
				fAsadID = atoi(node->GetText());
				if (strcmp(node->GetNodeName(), "AgetID") == 0)
				fAgetID = atoi(node->GetText());
                                if (strcmp(node->GetNodeName(), "ChannelID") == 0)
				fChannelID = atoi(node->GetText());
				if (strcmp(node->GetNodeName(), "PadID") == 0)
				fPadID = atoi(node->GetText());
				
				
			}

			
				
		}

		PadKey.push_back(fCoboID);
                PadKey.push_back(fAsadID);
                PadKey.push_back(fAgetID);
		PadKey.push_back(fChannelID);
                
		ATTPCPadMap.insert(std::pair<std::vector<int>,int>(PadKey,fPadID));
                //ATTPCPadMap.insert(std::pair<int,std::vector<int>>(fPadID,PadKey));
                //  for(Int_t i=0;i<4;i++) cout<<PadKey[i]<<endl;
		PadKey.clear();
		if(kDebug) cout<<"PadID : "<<fPadID<<" - CoboID : "<<fCoboID<<"  - AsadID : "<<fAsadID<<"  - AgetID : "<<fAgetID<<"  - ChannelID : "<<fChannelID<<endl;


}

ClassImp(AtTpcMap)
