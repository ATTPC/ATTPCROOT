void run_sim_proto(Int_t nEvents = 10, TString mcEngine = "TGeant4")
{
    
  TString dir = getenv("VMCWORKDIR");

  // Output file name
  TString outFile ="attpcsim_proto.root";
    
  // Parameter file name
  TString parFile="attpcpar_proto.root";
  
  // -----   Timer   --------------------------------------------------------
  TStopwatch timer;
  timer.Start();
  // ------------------------------------------------------------------------

  //gSystem->Load("libAtGen.so");

  ATVertexPropagator* vertex_prop = new ATVertexPropagator();
  

  // -----   Create simulation run   ----------------------------------------
  FairRunSim* run = new FairRunSim();
  run->SetName(mcEngine);              // Transport engine
  run->SetOutputFile(outFile);          // Output file
  FairRuntimeDb* rtdb = run->GetRuntimeDb();
  // ------------------------------------------------------------------------
  

  // -----   Create media   -------------------------------------------------
  run->SetMaterials("media.geo");       // Materials
  // ------------------------------------------------------------------------
  
  // -----   Create geometry   ----------------------------------------------

  FairModule* cave= new AtCave("CAVE");
  cave->SetGeometryFileName("cave.geo");
  run->AddModule(cave);

  /*FairModule* magnet = new AtMagnet("Magnet");
  run->AddModule(magnet);*/

  FairModule* pipe = new AtPipe("Pipe");
  run->AddModule(pipe);
    
  FairDetector* ATTPC = new AtTpc("ATTPC_Proto", kTRUE);
  ATTPC->SetGeometryFileName("ATTPC_Proto_v1.0.root");
  //ATTPC->SetModifyGeometry(kTRUE);
  run->AddModule(ATTPC);

 // ------------------------------------------------------------------------


    // -----   Magnetic field   -------------------------------------------
    // Constant Field
   /* AtConstField  *fMagField = new AtConstField();
    fMagField->SetField(0., 0. ,20. ); // values are in kG
    fMagField->SetFieldRegion(-50, 50,-50, 50, -10,230); // values are in cm
                          //  (xmin,xmax,ymin,ymax,zmin,zmax)
    run->SetField(fMagField);*/
    // --------------------------------------------------------------------

    
    
  // -----   Create PrimaryGenerator   --------------------------------------
  FairPrimaryGenerator* primGen = new FairPrimaryGenerator();
  

    // Pythia8
    /* Pythia8Generator* P8gen = new Pythia8Generator();
    P8gen->UseRandom3(); //# TRandom1 or TRandom3 ?
    P8gen->SetParameters("SoftQCD:inelastic = on");
    P8gen->SetParameters("PhotonCollision:gmgm2mumu = on");
    P8gen->SetParameters("PromptPhoton:all = on");
    P8gen->SetParameters("WeakBosonExchange:all = on");
    P8gen->SetMom(40);  //# beam momentum in GeV
    primGen->AddGenerator(P8gen);*/

 
    // Add a box generator also to the run
   /* FairBoxGenerator* boxGen = new FairBoxGenerator(13, 5); // 13 = muon; 1 = multipl.
    boxGen->SetPRange(20,25); // GeV/c
    boxGen->SetPhiRange(0., 360.); // Azimuth angle range [degree]
    boxGen->SetThetaRange(0., 90.); // Polar angle in lab system range [degree]
    boxGen->SetXYZ(0., 0., 0.); // cm
    primGen->AddGenerator(boxGen);*/

  


                /*  Int_t z = 18;  // Atomic number
	          Int_t a = 34; // Mass number
	          Int_t q = 0;   // Charge State
	          Int_t m = 1;   // Multiplicity
	          Double_t px = 0.01/a;  // X-Momentum / per nucleon!!!!!!
	          Double_t py = 0.01/a;  // Y-Momentum / per nucleon!!!!!!
	          Double_t pz = 4./a;  // Z-Momentum / per nucleon!!!!!!
	          ATTPCIonGenerator* ionGen = new ATTPCIonGenerator(z,a,q,m,px,py,pz);
	          ionGen->SetSpotRadius(1,1,0);
	          // add the ion generator
	          primGen->AddGenerator(ionGen);*/

		 
                  // Beam Information
                  Int_t z = 4;  // Atomic number
	          Int_t a = 10; // Mass number
	          Int_t q = 0;   // Charge State
	          Int_t m = 1;   // Multiplicity
	          Double_t px = 0.001/a;  // X-Momentum / per nucleon!!!!!!
	          Double_t py = 0.001/a;  // Y-Momentum / per nucleon!!!!!!
	          Double_t pz = 0.809/a;  // Z-Momentum / per nucleon!!!!!!


	          ATTPCIonGenerator* ionGen = new ATTPCIonGenerator("Ion",z,a,q,m,px,py,pz);
	          ionGen->SetSpotRadius(1,-20,0);
	          // add the ion generator
		 
	          primGen->AddGenerator(ionGen);
		  
  		  //primGen->SetBeam(1,1,0,0); //These parameters change the position of the vertex of every track added to the Primary Generator
		  // primGen->SetTarget(30,0);
 
                 


		 // Variable definition for Phase Space Calculation
                  std::vector<Int_t> Zp; // Zp of the reaction products      
		  std::vector<Int_t> Ap; // Ap of the reaction products
                  std::vector<Int_t> Qp;//Electric charge of gthe reaction products
                  Int_t mult;  //Number of decaying particles        
 		  std::vector<Double_t> Pxp; //Px momentum X
		  std::vector<Double_t> Pyp; //Py momentum Y
		  std::vector<Double_t> Pzp; //Pz momentum Z
		  Double_t ResEner; // Residual energy of the beam
		  // Note: Momentum will be calculated from the phase Space according to the residual energy of the beam

                  //Initialization of variables for physic case (10Be + 4He -> 6He + 4He + 4He)
	          mult = 3; //THIS DEFINITION IS MANDATORY (and the number of particles must be the same)
                  ResEner = 35.0;

                   //--- Particle 1 -----
		  Zp.push_back(2); // 6He 
		  Ap.push_back(6); // 		  
		  Qp.push_back(0); // 
		  Pxp.push_back(0.0);
	          Pyp.push_back(0.0);
		  Pzp.push_back(0.0);
		 
		  // ---- Particle 2 -----
		  Zp.push_back(2); // 4He 
		  Ap.push_back(4); // 
		  Qp.push_back(0); 
		  Pxp.push_back(0.0);
		  Pyp.push_back(0.0);
		  Pzp.push_back(0.0);

		  // ----- Particle 3 -----
		  Zp.push_back(2); // 4He 
		  Ap.push_back(4); // 
		  Qp.push_back(0); // 
		  Pxp.push_back(0.0);
		  Pyp.push_back(0.0);
		  Pzp.push_back(0.0);

		 
		 
                  
        ATTPCIonPhaseSpace* ReacDecay = new ATTPCIonPhaseSpace("Phase",&Zp,&Ap,&Qp,mult,&Pxp,&Pyp,&Pzp,ResEner,z,a,px,py,pz); 
        primGen->AddGenerator(ReacDecay);

    
	run->SetGenerator(primGen);

// ------------------------------------------------------------------------
 
  //---Store the visualiztion info of the tracks, this make the output file very large!!
  //--- Use it only to display but not for production!
  run->SetStoreTraj(kTRUE);

    
    
  // -----   Initialize simulation run   ------------------------------------
  run->Init();
  // ------------------------------------------------------------------------

  // -----   Runtime database   ---------------------------------------------

  Bool_t kParameterMerged = kTRUE;
  FairParRootFileIo* parOut = new FairParRootFileIo(kParameterMerged);
  parOut->open(parFile.Data());
  rtdb->setOutput(parOut);
  rtdb->saveOutput();
  rtdb->print();
  // ------------------------------------------------------------------------
   
  // -----   Start run   ----------------------------------------------------
   run->Run(nEvents);
    
  //You can export your ROOT geometry ot a separate file
  run->CreateGeometryFile("geofile_proto_full.root");
  // ------------------------------------------------------------------------
  
  // -----   Finish   -------------------------------------------------------
  timer.Stop();
  Double_t rtime = timer.RealTime();
  Double_t ctime = timer.CpuTime();
  cout << endl << endl;
  cout << "Macro finished succesfully." << endl;
  cout << "Output file is "    << outFile << endl;
  cout << "Parameter file is " << parFile << endl;
  cout << "Real time " << rtime << " s, CPU time " << ctime 
       << "s" << endl << endl;
  // ------------------------------------------------------------------------
}


