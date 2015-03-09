void run_unpack(){
  
   gSystem->Load("libXMLParser.so");

  /*std::vector<int> PadRef;

  		PadRef.resize(4);
                PadRef[0] = 0;
                PadRef[1] = 0;
                PadRef[2] = 0;
                PadRef[3] = 0;*/

  FairLogger *logger = FairLogger::GetLogger();
  logger -> SetLogFileName("genieLog.log");
  logger -> SetLogToFile(kTRUE);
  logger -> SetLogToScreen(kTRUE);
  logger -> SetLogVerbosityLevel("MEDIUM");

  FairRunAna* run = new FairRunAna();
  //run -> SetInputFile("mc.dummy.root");
  run -> SetOutputFile("output.root");

   FairRuntimeDb* rtdb = run->GetRuntimeDb();
 // FairParAsciiFileIo* parIo1 = new FairParAsciiFileIo();
 // parIo1 -> open(file.Data(), "in");
 // FairParRootFileIo* parIo2 = new FairParRootFileIo();
 // parIo2 -> open("param.dummy.root");
 // rtdb -> setFirstInput(parIo2);
 // rtdb -> setSecondInput(parIo1);

  ATDecoderTask *decoderTask = new ATDecoderTask();
  decoderTask ->SetMap("/home/daq/fair_install_2015/ATTPCROOT_09032015/scripts/Lookup20141208.xml");
  decoderTask -> AddData("/home/daq/Desktop/Yassid/ATTPC/run_0225/test");
  decoderTask -> SetData(0);
  //decoderTask -> SetInternalPedestal(5, 20);
  decoderTask -> SetNumTbs(512);
  decoderTask -> SetPersistence();
  run -> AddTask(decoderTask);

  
  //AtTpcMap *newmap = new AtTpcMap();
 // ATCore *unpacker = new ATCore();
  //unpacker->SetDebugMode(kTRUE);
  //unpacker->SetATTPCMap("/Users/yassidayyad/fair_install/ATTPCROOT_Mar/scripts/Lookup20141208.xml");
 // unpacker->SetATTPCMap("/home/daq/fair_install_2015/ATTPCROOT_09032015/scripts/Lookup20141208.xml");
 
  //newmap->SetGUIMode();
  //newmap->SetDebugMode();
  //newmap->GenerateATTPC();
 // newmap->GetATTPCPlane();
  //newmap->ParseXMLMap("/home/daq/fair_install_2015/ATTPCROOT_Feb/scripts/Lookup20141208.xml");
  //Int_t padnum = newmap->GetPadNum(PadRef);
  //cout<<padnum<<endl;
  //newmap->DumpATTPCMap();
  //newmap->Dump();

  // GETDecoder *decoder = new GETDecoder("/home/daq/Desktop/Yassid/ATTPC/run_0225/test");
  //unpacker->AddData("/Users/yassidayyad/Desktop/ATTPC/Data/run_0225/test");
  
  /*unpacker->AddData("/home/daq/Desktop/Yassid/ATTPC/run_0225/test");
  unpacker->SetData(0);
  unpacker->GetRawEvent();
  unpacker->GetRawEvent();*/

  run->Init();

  run->Run(0, 10);

}
