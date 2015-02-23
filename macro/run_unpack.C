void run_unpack(){

  AtTpcMap *newmap = new AtTpcMap();
  newmap->GenerateATTPC();
  newmap->GetATTPCPlane();
  //newmap->Dump();


}
