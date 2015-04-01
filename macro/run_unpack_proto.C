void run_unpack_proto(){


    // -----   Timer   --------------------------------------------------------
	TStopwatch timer;
	timer.Start();
  // ------------------------------------------------------------------------


   gSystem->Load("libXMLParser.so");

   TString scriptfile = "LookupProto20150331.xml";
   TString dir = getenv("VMCWORKDIR");
   TString scriptdir = dir + "/scripts/"+ scriptfile;

   FairLogger *logger = FairLogger::GetLogger();
  logger -> SetLogFileName("ATTPCLog.log");
  logger -> SetLogToFile(kTRUE);
  logger -> SetLogToScreen(kTRUE);
  logger -> SetLogVerbosityLevel("MEDIUM");
 
   AtTpcMap *c = new AtTpcProtoMap();
   //c->SetDebugMode();
   TString geo = "proto_geo_hires.root";
   c->SetGeoFile(geo);   
   //c->GenerateATTPC(); // These two methods generate the pad plane from TMultiGraphs
   //c->GetATTPCPlane(); //

   c->GetATTPCPlane("ATTPC_Proto"); // This overloaded method extract the TH2Poly from the geomtry file previously created. Name of the TObject must be provided here (To Be changed)
   c->ParseXMLMap(scriptdir.Data());

 // -----   Finish   -------------------------------------------------------
	timer.Stop();
	Double_t rtime = timer.RealTime();
	Double_t ctime = timer.CpuTime();
	cout << endl << endl;
	cout << "Macro finished succesfully." << endl;
	cout << "Real time " << rtime << " s, CPU time " << ctime << " s" << endl;
	cout << endl;
  // ------------------------------------------------------------------------


}
