/*********************************************************************
*   ATTPC Mapping Class	AtTpcMap.h			             *	
*   Author: Y. Ayyad            				     *
*   Log: 13-02-2014 17:16 JST					     *
*								     *	
*********************************************************************/

#ifndef ATTPCMAP_H
#define ATTPCMAP_H

#ifndef __CINT__ // Boost 
#include <boost/multi_array.hpp>
#endif //__CINT__

#include <cassert>
#include "TObject.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TH2Poly.h"
#include "TMath.h"
#include "TROOT.h"
#include "TStyle.h"
#include <map>
#include <vector>
#include "TDOMParser.h"
#include "TXMLNode.h"



class AtTpcMap : public TObject
{

  public:
    
     AtTpcMap();
     ~AtTpcMap();

     #ifndef __CINT__
     typedef boost::multi_array<double,3> multiarray;
     typedef multiarray::index index;
     multiarray AtPadCoord;
     #endif //__CINT__


     void Initialize();
     void Dump();
     
     void GenerateATTPC();
     void GenerateProto();
     Int_t  fill_coord(int pindex, float padxoff, float padyoff, float triside, float fort);
     inline void SetGUIMode(){kGUIMode=1;}
     inline void SetDebugMode(){kDebug=1;}
     Bool_t ParseXMLMap(char *xmlfile);
     void ParseMapList(TXMLNode *node);
     void ParseATTPCMap(TXMLNode *node);

     TH2Poly* GetATTPCPlane();
     Int_t fPadInd;
     Bool_t kGUIMode;
     Bool_t kDebug;
     

     std::map<std::vector<int>,int> ATTPCPadMap;
     //std::map<int,std::vector<int>> ATTPCPadMap;
     std::vector<int> PadKey; 
     
 
     TCanvas *cATTPCPlane; 
     TH2Poly *hPlane = new TH2Poly();

        friend ostream & operator << (ostream& out, const AtTpcMap& p){

		std::vector<int>::iterator it;

                for(auto it=p.PadKey.begin();it!=p.PadKey.end();it++){

                             out<<"  This "<<p.PadKey[0]<<std::endl;
		}

		/*out<<" EN Node ID :"<<p.id<<" , ";
		out<<" EN detector segment name :"<<p.detname<<" , ";
		out<<" EN module ID :"<<p.modid<<" , "; 
		out<<" EN detector ID :"<<p.detID<<" , ";     
		out<<" EN VME module :"<<p.vme<<" , ";
		out<<" EN Module status :"<<p.stat<<endl;*/
	}



     ClassDef(AtTpcMap,1);

};

#endif




