void run_eve_proto() 
{
  FairLogger *fLogger = FairLogger::GetLogger();
  fLogger -> SetLogToScreen(kTRUE);
  fLogger->SetLogVerbosityLevel("MEDIUM");

  FairRunAna *fRun= new FairRunAna();
  fRun -> SetInputFile("output_proto.root");
  fRun -> SetOutputFile("output_proto.reco_display.root");

  FairRuntimeDb* rtdb = fRun->GetRuntimeDb();
  FairParRootFileIo* parIo1 = new FairParRootFileIo();
  parIo1->open("param.dummy.root");
  rtdb->setFirstInput(parIo1);

  FairRootManager* ioman = FairRootManager::Instance();

  ATEventManager *eveMan = new ATEventManager();
  ATEventDrawTask* eve = new ATEventProtoDrawTask();
  eve->SetGeoOption("Prototype"); // Options: "ATTPC" - "Prototype"

  eveMan->AddTask(eve);
  eveMan->Init();                    
}
