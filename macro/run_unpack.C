void run_unpack(){


  gSystem->Load("libXMLParser.so");
  AtTpcMap *newmap = new AtTpcMap();
  newmap->SetGUIMode();
  newmap->GenerateATTPC();
  newmap->GetATTPCPlane();
  newmap->ParseXMLMap("/home/daq/fair_install_2015/ATTPCROOT_Feb/scripts/Lookup20141208.xml");
  //newmap->Dump();

  // GETDecoder *decoder = new GETDecoder("/home/daq/Desktop/Yassid/ATTPC/run_0225/test");

}
