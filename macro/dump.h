//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jul  2 15:18:49 2015 by ROOT version 5.34/25
// from TTree cbmsim//cbmout
// found on file: output_proto.root
//////////////////////////////////////////////////////////

#ifndef dump_h
#define dump_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "/home/ayyadlim/fair_install/FairRoot_mar15/base/event/FairEventHeader.h"
#include <TObject.h>
#include <TNamed.h>
#include <TClonesArray.h>
#include "/home/ayyadlim/fair_install/ATTPCROOT_Jun15/reco/ATDecoder/ATRawEvent.hh"
#include "/home/ayyadlim/fair_install/ATTPCROOT_Jun15/reco/ATDecoder/ATEvent.hh"
#include "/home/ayyadlim/fair_install/ATTPCROOT_Jun15/reco/ATDecoder/ATProtoEvent.hh"

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxcbmout_EvtHeader_EventHeader = 1;
   const Int_t kMaxcbmout_ATTPC_ATRawEvent = 1;
   const Int_t kMaxcbmout_ATTPC_ATEventH = 1;
   const Int_t kMaxcbmout_ATTPC_ATProtoEvent = 1;

class dump {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   FairEventHeader *EventHeader_;
   UInt_t          EventHeader_TNamed_fUniqueID;
   UInt_t          EventHeader_TNamed_fBits;
   TString         EventHeader_TNamed_fName;
   TString         EventHeader_TNamed_fTitle;
   UInt_t          EventHeader_fRunId;
   Double_t        EventHeader_fEventTime;
   Int_t           EventHeader_fInputFileId;
   Int_t           EventHeader_fMCEntryNo;
   Int_t           ATRawEvent_;
   UInt_t          ATRawEvent_fUniqueID[kMaxcbmout_ATTPC_ATRawEvent];   //[cbmout.ATTPC.ATRawEvent_]
   UInt_t          ATRawEvent_fBits[kMaxcbmout_ATTPC_ATRawEvent];   //[cbmout.ATTPC.ATRawEvent_]
   TString         ATRawEvent_fName[kMaxcbmout_ATTPC_ATRawEvent];
   TString         ATRawEvent_fTitle[kMaxcbmout_ATTPC_ATRawEvent];
   Int_t           ATRawEvent_fEventID[kMaxcbmout_ATTPC_ATRawEvent];   //[cbmout.ATTPC.ATRawEvent_]
 //vector<ATPad>   ATRawEvent_fPadArray[kMaxcbmout_ATTPC_ATRawEvent];
   Bool_t          ATRawEvent_fIsGood[kMaxcbmout_ATTPC_ATRawEvent];   //[cbmout.ATTPC.ATRawEvent_]
   Int_t           ATEventH_;
   UInt_t          ATEventH_fUniqueID[kMaxcbmout_ATTPC_ATEventH];   //[cbmout.ATTPC.ATEventH_]
   UInt_t          ATEventH_fBits[kMaxcbmout_ATTPC_ATEventH];   //[cbmout.ATTPC.ATEventH_]
   TString         ATEventH_fName[kMaxcbmout_ATTPC_ATEventH];
   TString         ATEventH_fTitle[kMaxcbmout_ATTPC_ATEventH];
   Bool_t          ATEventH_fIsClustered[kMaxcbmout_ATTPC_ATEventH];   //[cbmout.ATTPC.ATEventH_]
   Bool_t          ATEventH_fIsTracked[kMaxcbmout_ATTPC_ATEventH];   //[cbmout.ATTPC.ATEventH_]
   Bool_t          ATEventH_fIsChanged[kMaxcbmout_ATTPC_ATEventH];   //[cbmout.ATTPC.ATEventH_]
   Bool_t          ATEventH_fIsGood[kMaxcbmout_ATTPC_ATEventH];   //[cbmout.ATTPC.ATEventH_]
   Int_t           ATEventH_fEventID[kMaxcbmout_ATTPC_ATEventH];   //[cbmout.ATTPC.ATEventH_]
 //vector<ATHit>   ATEventH_fHitArray[kMaxcbmout_ATTPC_ATEventH];
   Double_t        ATEventH_fQevent[kMaxcbmout_ATTPC_ATEventH];   //[cbmout.ATTPC.ATEventH_]
   Double_t        ATEventH_fRhoVariance[kMaxcbmout_ATTPC_ATEventH];   //[cbmout.ATTPC.ATEventH_]
   map<Int_t,Int_t> ATEventH_fMultiMap[kMaxcbmout_ATTPC_ATEventH];
   Float_t         ATEventH_fMeshSig[kMaxcbmout_ATTPC_ATEventH][512];   //[cbmout.ATTPC.ATEventH_]
   Int_t           ATProtoEvent_;
   UInt_t          ATProtoEvent_fUniqueID[kMaxcbmout_ATTPC_ATProtoEvent];   //[cbmout.ATTPC.ATProtoEvent_]
   UInt_t          ATProtoEvent_fBits[kMaxcbmout_ATTPC_ATProtoEvent];   //[cbmout.ATTPC.ATProtoEvent_]
   TString         ATProtoEvent_fName[kMaxcbmout_ATTPC_ATProtoEvent];
   TString         ATProtoEvent_fTitle[kMaxcbmout_ATTPC_ATProtoEvent];
   Int_t           ATProtoEvent_fEventID[kMaxcbmout_ATTPC_ATProtoEvent];   //[cbmout.ATTPC.ATProtoEvent_]
 //vector<ATProtoQuadrant> ATProtoEvent_fQuadrantArray[kMaxcbmout_ATTPC_ATProtoEvent];

   // List of branches
   TBranch        *b_cbmout_EvtHeader_EventHeader_;   //!
   TBranch        *b_EventHeader_cbmout_EvtHeader_EventHeader_TNamed_fUniqueID;   //!
   TBranch        *b_EventHeader_cbmout_EvtHeader_EventHeader_TNamed_fBits;   //!
   TBranch        *b_EventHeader_cbmout_EvtHeader_EventHeader_TNamed_fName;   //!
   TBranch        *b_EventHeader_cbmout_EvtHeader_EventHeader_TNamed_fTitle;   //!
   TBranch        *b_EventHeader_cbmout_EvtHeader_EventHeader_fRunId;   //!
   TBranch        *b_EventHeader_cbmout_EvtHeader_EventHeader_fEventTime;   //!
   TBranch        *b_EventHeader_cbmout_EvtHeader_EventHeader_fInputFileId;   //!
   TBranch        *b_EventHeader_cbmout_EvtHeader_EventHeader_fMCEntryNo;   //!
   TBranch        *b_cbmout_ATTPC_ATRawEvent_;   //!
   TBranch        *b_ATRawEvent_fUniqueID;   //!
   TBranch        *b_ATRawEvent_fBits;   //!
   TBranch        *b_ATRawEvent_fName;   //!
   TBranch        *b_ATRawEvent_fTitle;   //!
   TBranch        *b_ATRawEvent_fEventID;   //!
   TBranch        *b_ATRawEvent_fIsGood;   //!
   TBranch        *b_cbmout_ATTPC_ATEventH_;   //!
   TBranch        *b_ATEventH_fUniqueID;   //!
   TBranch        *b_ATEventH_fBits;   //!
   TBranch        *b_ATEventH_fName;   //!
   TBranch        *b_ATEventH_fTitle;   //!
   TBranch        *b_ATEventH_fIsClustered;   //!
   TBranch        *b_ATEventH_fIsTracked;   //!
   TBranch        *b_ATEventH_fIsChanged;   //!
   TBranch        *b_ATEventH_fIsGood;   //!
   TBranch        *b_ATEventH_fEventID;   //!
   TBranch        *b_ATEventH_fQevent;   //!
   TBranch        *b_ATEventH_fRhoVariance;   //!
   TBranch        *b_ATEventH_fMultiMap;   //!
   TBranch        *b_ATEventH_fMeshSig;   //!
   TBranch        *b_cbmout_ATTPC_ATProtoEvent_;   //!
   TBranch        *b_ATProtoEvent_fUniqueID;   //!
   TBranch        *b_ATProtoEvent_fBits;   //!
   TBranch        *b_ATProtoEvent_fName;   //!
   TBranch        *b_ATProtoEvent_fTitle;   //!
   TBranch        *b_ATProtoEvent_fEventID;   //!

   dump(TTree *tree=0);
   virtual ~dump();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef dump_cxx
dump::dump(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("output_proto.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("output_proto.root");
      }
      f->GetObject("cbmsim",tree);

   }
   Init(tree);
}

dump::~dump()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t dump::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t dump::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void dump::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   EventHeader_ = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventHeader.", &EventHeader_, &b_cbmout_EvtHeader_EventHeader_);
   fChain->SetBranchAddress("EventHeader.TNamed.fUniqueID", &EventHeader_TNamed_fUniqueID, &b_EventHeader_cbmout_EvtHeader_EventHeader_TNamed_fUniqueID);
   fChain->SetBranchAddress("EventHeader.TNamed.fBits", &EventHeader_TNamed_fBits, &b_EventHeader_cbmout_EvtHeader_EventHeader_TNamed_fBits);
   fChain->SetBranchAddress("EventHeader.TNamed.fName", &EventHeader_TNamed_fName, &b_EventHeader_cbmout_EvtHeader_EventHeader_TNamed_fName);
   fChain->SetBranchAddress("EventHeader.TNamed.fTitle", &EventHeader_TNamed_fTitle, &b_EventHeader_cbmout_EvtHeader_EventHeader_TNamed_fTitle);
   fChain->SetBranchAddress("EventHeader.fRunId", &EventHeader_fRunId, &b_EventHeader_cbmout_EvtHeader_EventHeader_fRunId);
   fChain->SetBranchAddress("EventHeader.fEventTime", &EventHeader_fEventTime, &b_EventHeader_cbmout_EvtHeader_EventHeader_fEventTime);
   fChain->SetBranchAddress("EventHeader.fInputFileId", &EventHeader_fInputFileId, &b_EventHeader_cbmout_EvtHeader_EventHeader_fInputFileId);
   fChain->SetBranchAddress("EventHeader.fMCEntryNo", &EventHeader_fMCEntryNo, &b_EventHeader_cbmout_EvtHeader_EventHeader_fMCEntryNo);
   fChain->SetBranchAddress("ATRawEvent", &ATRawEvent_, &b_cbmout_ATTPC_ATRawEvent_);
   fChain->SetBranchAddress("ATRawEvent.fUniqueID", ATRawEvent_fUniqueID, &b_ATRawEvent_fUniqueID);
   fChain->SetBranchAddress("ATRawEvent.fBits", ATRawEvent_fBits, &b_ATRawEvent_fBits);
   fChain->SetBranchAddress("ATRawEvent.fName", ATRawEvent_fName, &b_ATRawEvent_fName);
   fChain->SetBranchAddress("ATRawEvent.fTitle", ATRawEvent_fTitle, &b_ATRawEvent_fTitle);
   fChain->SetBranchAddress("ATRawEvent.fEventID", ATRawEvent_fEventID, &b_ATRawEvent_fEventID);
   fChain->SetBranchAddress("ATRawEvent.fIsGood", ATRawEvent_fIsGood, &b_ATRawEvent_fIsGood);
   fChain->SetBranchAddress("ATEventH", &ATEventH_, &b_cbmout_ATTPC_ATEventH_);
   fChain->SetBranchAddress("ATEventH.fUniqueID", ATEventH_fUniqueID, &b_ATEventH_fUniqueID);
   fChain->SetBranchAddress("ATEventH.fBits", ATEventH_fBits, &b_ATEventH_fBits);
   fChain->SetBranchAddress("ATEventH.fName", ATEventH_fName, &b_ATEventH_fName);
   fChain->SetBranchAddress("ATEventH.fTitle", ATEventH_fTitle, &b_ATEventH_fTitle);
   fChain->SetBranchAddress("ATEventH.fIsClustered", ATEventH_fIsClustered, &b_ATEventH_fIsClustered);
   fChain->SetBranchAddress("ATEventH.fIsTracked", ATEventH_fIsTracked, &b_ATEventH_fIsTracked);
   fChain->SetBranchAddress("ATEventH.fIsChanged", ATEventH_fIsChanged, &b_ATEventH_fIsChanged);
   fChain->SetBranchAddress("ATEventH.fIsGood", ATEventH_fIsGood, &b_ATEventH_fIsGood);
   fChain->SetBranchAddress("ATEventH.fEventID", ATEventH_fEventID, &b_ATEventH_fEventID);
   fChain->SetBranchAddress("ATEventH.fQevent", ATEventH_fQevent, &b_ATEventH_fQevent);
   fChain->SetBranchAddress("ATEventH.fRhoVariance", ATEventH_fRhoVariance, &b_ATEventH_fRhoVariance);
   fChain->SetBranchAddress("ATEventH.fMultiMap", ATEventH_fMultiMap, &b_ATEventH_fMultiMap);
   fChain->SetBranchAddress("ATEventH.fMeshSig[512]", ATEventH_fMeshSig, &b_ATEventH_fMeshSig);
   fChain->SetBranchAddress("ATProtoEvent", &ATProtoEvent_, &b_cbmout_ATTPC_ATProtoEvent_);
   fChain->SetBranchAddress("ATProtoEvent.fUniqueID", ATProtoEvent_fUniqueID, &b_ATProtoEvent_fUniqueID);
   fChain->SetBranchAddress("ATProtoEvent.fBits", ATProtoEvent_fBits, &b_ATProtoEvent_fBits);
   fChain->SetBranchAddress("ATProtoEvent.fName", ATProtoEvent_fName, &b_ATProtoEvent_fName);
   fChain->SetBranchAddress("ATProtoEvent.fTitle", ATProtoEvent_fTitle, &b_ATProtoEvent_fTitle);
   fChain->SetBranchAddress("ATProtoEvent.fEventID", ATProtoEvent_fEventID, &b_ATProtoEvent_fEventID);
   Notify();
}

Bool_t dump::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void dump::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t dump::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef dump_cxx
