#include "TString.h"
#include "TFile.h"
#include "TTree.h"
#include "TClonesArray.h"

#include <iostream>
#include <fstream>

void run_sim_ana()
{
    
    TString mcFileNameHead = "data/attpcsim";
    TString mcFileNameTail = ".root";
    TString mcFileName     = mcFileNameHead + mcFileNameTail;
    std:cout << " Analysis of simulation file  " << mcFileName << endl;
    
    AtTpcPoint* point;
    TClonesArray *pointArray;
    
    TFile* file = new TFile(mcFileName.Data(),"READ");
    TTree* tree = (TTree*) file -> Get("cbmsim");
    tree -> SetBranchAddress("AtTpcPoint", &pointArray);
    
    
    Int_t nEvents = tree -> GetEntriesFast();
    for(Int_t iEvent=0; iEvent<nEvents; iEvent++)
    {
        tree -> GetEntry(iEvent);
        Int_t n = pointArray -> GetEntries();
        std::cout<<" Event Number : "<<iEvent<<std::endl;
        for(Int_t i=0; i<n; i++) {
            point = (AtTpcPoint*) pointArray -> At(i);
            
            std::cout<<" Track ID : "<<point -> GetTrackID()<<std::endl;
            
        }
    }
    
}