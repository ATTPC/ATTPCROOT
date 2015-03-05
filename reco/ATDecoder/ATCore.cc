/*********************************************************************
*   ATTPC Unpacker and Decoder Core Class	ATCore               *	
*   Author: Y. Ayyad            				     *
*   Log: 04-03-2015 17:16 JST					     *
*   Adapted from STCore from SPiRITROOT by G. Jhang		     *	
*********************************************************************/


#include <iostream>
#include <fstream>
#include <cmath>

#include "ATCore.hh"
#include "GETDecoder.hh"
#include "GETFrame.hh"

ClassImp(ATCore);

ATCore::ATCore()
{
  Initialize();
}

ATCore::ATCore(TString filename, Int_t numTbs)
{
  
  Initialize();
  AddData(filename);
  SetNumTbs(numTbs);

  
}

ATCore::~ATCore()
{
  delete fGETDecoderPtr;
  delete fAtMapPtr;
  //delete fPedestalPtr;
  //delete fMapPtr;
}

void ATCore::Initialize(){

  fGETDecoderPtr = new GETDecoder();
  fNumTbs = 512;
  fIsData = kFALSE;
  fAtMapPtr = new AtTpcMap();

}

Bool_t ATCore::AddData(TString filename)
{
  return fGETDecoderPtr -> AddData(filename);
}

Bool_t ATCore::SetData(Int_t value)
{
  fIsData = fGETDecoderPtr -> SetData(value);

  fPrevEventNo = -1;
  fCurrEventNo = -1;
  fCurrFrameNo = 0;

  return fIsData;
}

Bool_t ATCore::SetATTPCMap(char *lookup){

  fAtMapPtr->GenerateATTPC();
  fAtMapPtr->ParseXMLMap(lookup);
  //**** For debugging purposes only! ******//
  fAtMapPtr->SetGUIMode();
  fAtMapPtr->GetATTPCPlane();
  return 1;

}

void ATCore::SetPositivePolarity(Bool_t value)
{
  fGETDecoderPtr -> SetPositivePolarity(value);
}

void ATCore::SetNumTbs(Int_t value)
{
  fNumTbs = value;
  fGETDecoderPtr -> SetNumTbs(value);
}

Int_t *ATCore::GetRawEvent(Int_t eventID){

  	  if (!fIsData) {
  		  std::cout << "== ATCore -  Data file is not set" << std::endl;
		  return NULL;
  	  }

	fPrevEventNo = eventID;

        GETFrame *frame = NULL;

		//while ((frame = fGETDecoderPtr -> GetFrame())) {
		while ((frame = fGETDecoderPtr -> GetFrame(fCurrFrameNo))) {

			Int_t frameType = fGETDecoderPtr -> GetFrameType();



				 eventID = frame -> GetEventID();
				 Int_t iCobo = frame -> GetCoboID();
				 Int_t iAsad = frame -> GetAsadID();


			          std::cout<<" Event ID : "<<eventID<<" coboID : "<<iCobo<<" asadID : "<<iAsad<<std::endl;

 					for (Int_t iAget = 0; iAget < 4; iAget++) {
                                		 for (Int_t iCh = 0; iCh < 68; iCh++) {
							//std::cout<<" Event ID : "<<eventID<<" coboID : "<<iCobo<<" asadID : "<<iAsad<<std::endl;
							//std::cout<<" AgetID : "<<iAget<<" ChannelID : "<<iCh<<std::endl;
							std::vector<int> PadRef={iCobo,iAsad,iAget,iCh};
							ATPad *pad = new ATPad(fAtMapPtr->GetPadNum(PadRef));
							//std::cout<<" Pad Number : "<<fAtMapPtr->GetPadNum(PadRef)<<std::endl;
        						Int_t maxTb = fGETDecoderPtr-> GetNumTbs();
							for (Int_t iTb = 0; iTb < maxTb; iTb++) {
         						 Int_t rawadc = frame -> GetRawADC(iAget, iCh, iTb);
                                        		 //std::cout<<" AGet "<<iAget<<" Channel : "<<iCh<<" ADC : "<<rawadc<<" Time Bucket : "<<iTb<<std::endl;
        						}
						 }
    					}


			

		}

	

	return NULL;

}













