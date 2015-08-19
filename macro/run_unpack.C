void run_unpack(){
  
   // -----   Timer   --------------------------------------------------------
	TStopwatch timer;
	timer.Start();
  // ------------------------------------------------------------------------

   gSystem->Load("libXMLParser.so");

   TString scriptfile = "Lookup20150611.xml";
   TString dir = getenv("VMCWORKDIR");
   TString scriptdir = dir + "/scripts/"+ scriptfile;

  /*std::vector<int> PadRef;

  		PadRef.resize(4);
                PadRef[0] = 0;
                PadRef[1] = 0;
                PadRef[2] = 0;
                PadRef[3] = 0;*/

  FairLogger *logger = FairLogger::GetLogger();
  logger -> SetLogFileName("ATTPCLog.log");
  logger -> SetLogToFile(kTRUE);
  logger -> SetLogToScreen(kTRUE);
  logger -> SetLogVerbosityLevel("MEDIUM");

  FairRunAna* run = new FairRunAna();
  run -> SetInputFile("mc.dummy.root");
  run -> SetOutputFile("output.root");
    
    TString file = "../parameters/AT.parameters.par";

   FairRuntimeDb* rtdb = run->GetRuntimeDb();
   FairParAsciiFileIo* parIo1 = new FairParAsciiFileIo();
   parIo1 -> open(file.Data(), "in");
   FairParRootFileIo* parIo2 = new FairParRootFileIo();
   parIo2 -> open("param.dummy.root");
   rtdb -> setFirstInput(parIo2);
   rtdb -> setSecondInput(parIo1);

  

  ATDecoderTask *decoderTask = new ATDecoderTask();
  decoderTask ->SetMap(scriptdir.Data());
  decoderTask ->SetMapOpt(0); // ATTPC : 0  - Prototype: 1 |||| Default value = 0 
 // decoderTask ->SetMap("/home/daq/fair_install_2015/ATTPCROOT_09032015/scripts/Lookup20141208.xml");
  //decoderTask -> AddData("/home/daq/Desktop/Yassid/ATTPC/run_0225/test");
  //decoderTask ->SetMap("/Users/yassidayyad/fair_install/ATTPCROOT_Apr/scripts/Lookup20141208.xml");
  //decoderTask -> AddData("/Users/yassidayyad/Desktop/ATTPC/Data/run_0225/test");
 // decoderTask -> AddData("/home/ayyadlim/Desktop/Yassid/ATTPC/Data/run_0141/run_0141.graw");
  //decoderTask -> AddData("/home/ayyadlim/Desktop/Yassid/ATTPC/Data/ar40/run_0089/run_0089.graw");
  decoderTask -> AddData("/data/ar40/run_0122/run_0122.graw");
  decoderTask -> SetPositivePolarity(kTRUE);
  
  //decoderTask -> SetData(0);
  //decoderTask -> SetInternalPedestal(5, 20);
  decoderTask -> SetFPNPedestal(100);
  decoderTask -> SetFPNPedestal();
  decoderTask -> SetNumTbs(512);
  decoderTask -> SetPersistence();
  run -> AddTask(decoderTask);



  ATPSATask *psaTask = new ATPSATask();
  psaTask -> SetPersistence();
  psaTask -> SetThreshold(20);
  psaTask -> SetPSAMode(2); //NB: 1 is ATTPC - 2 is pATTPC
  run -> AddTask(psaTask);

  run->Init();

  run->Run(0,10); // Number must be lower than the number of events in dummy

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
