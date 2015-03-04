void run_unpack(){
  
  std::vector<int> PadRef;

  		PadRef.resize(4);
                PadRef[0] = 0;
                PadRef[1] = 0;
                PadRef[2] = 0;
                PadRef[3] = 0;


  gSystem->Load("libXMLParser.so");
  AtTpcMap *newmap = new AtTpcMap();
  ATCore *unpacker = new ATCore();
  
 
  //newmap->SetGUIMode();
  //newmap->SetDebugMode();
  newmap->GenerateATTPC();
  newmap->GetATTPCPlane();
  newmap->ParseXMLMap("/home/daq/fair_install_2015/ATTPCROOT_Feb/scripts/Lookup20141208.xml");
  Int_t padnum = newmap->GetPadNum(PadRef);
  cout<<padnum<<endl;
  //newmap->DumpATTPCMap();
  //newmap->Dump();

  // GETDecoder *decoder = new GETDecoder("/home/daq/Desktop/Yassid/ATTPC/run_0225/test");
  unpacker->AddData("/home/daq/Desktop/Yassid/ATTPC/run_0225/test");
  unpacker->SetData(0);
  unpacker->GetRawEvent(0);

}
