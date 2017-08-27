//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Aug 12 22:09:28 2016 by ROOT version 6.04/02
// from TTree fitter_tree/fitter_tree
// found on file: TnPTree_data_newID_norm1.root
//////////////////////////////////////////////////////////

#ifndef makereweight_h
#define makereweight_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class makereweight {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         probe_Pho_ESsigma;
   Float_t         probe_Pho_ZSr9;
   Float_t         probe_Pho_abseta;
   Float_t         probe_Pho_chIso;
   Float_t         probe_Pho_chIso2;
   Float_t         probe_Pho_chIsoPresel;
   Float_t         probe_Pho_chWorIso;
   Float_t         probe_Pho_e;
   Float_t         probe_Pho_e1x5;
   Float_t         probe_Pho_e2x5;
   Float_t         probe_Pho_e3x3;
   Float_t         probe_Pho_e5x5;
   Float_t         probe_Pho_et;
   Float_t         probe_Pho_eta;
   Float_t         probe_Pho_etawidth;
   Float_t         probe_Pho_full5x5_e1x5;
   Float_t         probe_Pho_full5x5_e2x5;
   Float_t         probe_Pho_full5x5_e3x3;
   Float_t         probe_Pho_full5x5_e5x5;
   Float_t         probe_Pho_hoe;
   Float_t         probe_Pho_neuIso03;
   Float_t         probe_Pho_neuIso04;
   Float_t         probe_Pho_phiwidth;
   Float_t         probe_Pho_phoIso03;
   Float_t         probe_Pho_phoIso04;
   Float_t         probe_Pho_pt;
   Float_t         probe_Pho_r9;
   Float_t         probe_Pho_s4;
   Float_t         probe_Pho_sieie;
   Float_t         probe_Pho_sieip;
   Float_t         probe_Pho_sigmaEoE;
   Float_t         probe_Pho_sipip;
   Float_t         probe_Pho_tkIso;
   Float_t         probe_sc_abseta;
   Float_t         probe_sc_energy;
   Float_t         probe_sc_et;
   Float_t         probe_sc_eta;
   Float_t         probe_sc_rawe;
   Float_t         probe_Pho_mva;
   Int_t           passingIDMVA;
   Int_t           passingPresel;
   UInt_t          run;
   UInt_t          lumi;
   ULong64_t       event;
   Int_t           truePU;
   Float_t         event_PrimaryVertex_x;
   Float_t         event_PrimaryVertex_y;
   Float_t         event_PrimaryVertex_z;
   Int_t           event_nPV;
   Float_t         event_BeamSpot_x;
   Float_t         event_BeamSpot_y;
   Float_t         event_BeamSpot_z;
   Float_t         event_rho;
   Float_t         mass;
   Float_t         tag_Pho_abseta;
   Float_t         tag_Pho_e;
   Float_t         tag_Pho_et;
   Float_t         tag_Pho_eta;
   Float_t         tag_Pho_full5x5_r9;
   Float_t         tag_Pho_pt;
   Float_t         tag_Pho_r9;
   Float_t         tag_sc_abseta;
   Float_t         tag_sc_energy;
   Float_t         tag_sc_et;
   Float_t         tag_sc_eta;
   Float_t         tag_Pho_mva;
   Float_t         pair_abseta;
   Float_t         pair_eta;
   Float_t         pair_mass;
   Float_t         pair_pt;
   Int_t           pair_mass60to120;
   Float_t         totWeight;
   Float_t         PUweight;

   // List of branches
   TBranch        *b_probe_Pho_ESsigma;   //!
   TBranch        *b_probe_Pho_ZSr9;   //!
   TBranch        *b_probe_Pho_abseta;   //!
   TBranch        *b_probe_Pho_chIso;   //!
   TBranch        *b_probe_Pho_chIso2;   //!
   TBranch        *b_probe_Pho_chIsoPresel;   //!
   TBranch        *b_probe_Pho_chWorIso;   //!
   TBranch        *b_probe_Pho_e;   //!
   TBranch        *b_probe_Pho_e1x5;   //!
   TBranch        *b_probe_Pho_e2x5;   //!
   TBranch        *b_probe_Pho_e3x3;   //!
   TBranch        *b_probe_Pho_e5x5;   //!
   TBranch        *b_probe_Pho_et;   //!
   TBranch        *b_probe_Pho_eta;   //!
   TBranch        *b_probe_Pho_etawidth;   //!
   TBranch        *b_probe_Pho_full5x5_e1x5;   //!
   TBranch        *b_probe_Pho_full5x5_e2x5;   //!
   TBranch        *b_probe_Pho_full5x5_e3x3;   //!
   TBranch        *b_probe_Pho_full5x5_e5x5;   //!
   TBranch        *b_probe_Pho_hoe;   //!
   TBranch        *b_probe_Pho_neuIso03;   //!
   TBranch        *b_probe_Pho_neuIso04;   //!
   TBranch        *b_probe_Pho_phiwidth;   //!
   TBranch        *b_probe_Pho_phoIso03;   //!
   TBranch        *b_probe_Pho_phoIso04;   //!
   TBranch        *b_probe_Pho_pt;   //!
   TBranch        *b_probe_Pho_r9;   //!
   TBranch        *b_probe_Pho_s4;   //!
   TBranch        *b_probe_Pho_sieie;   //!
   TBranch        *b_probe_Pho_sieip;   //!
   TBranch        *b_probe_Pho_sigmaEoE;   //!
   TBranch        *b_probe_Pho_sipip;   //!
   TBranch        *b_probe_Pho_tkIso;   //!
   TBranch        *b_probe_sc_abseta;   //!
   TBranch        *b_probe_sc_energy;   //!
   TBranch        *b_probe_sc_et;   //!
   TBranch        *b_probe_sc_eta;   //!
   TBranch        *b_probe_sc_rawe;   //!
   TBranch        *b_probe_Pho_mva;   //!
   TBranch        *b_passingIDMVA;   //!
   TBranch        *b_passingPresel;   //!
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_truePU;   //!
   TBranch        *b_mPVx;   //!
   TBranch        *b_mPVy;   //!
   TBranch        *b_mPVz;   //!
   TBranch        *b_mNPV;   //!
   TBranch        *b_mBSx;   //!
   TBranch        *b_mBSy;   //!
   TBranch        *b_mBSz;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_mass;   //!
   TBranch        *b_tag_Pho_abseta;   //!
   TBranch        *b_tag_Pho_e;   //!
   TBranch        *b_tag_Pho_et;   //!
   TBranch        *b_tag_Pho_eta;   //!
   TBranch        *b_tag_Pho_full5x5_r9;   //!
   TBranch        *b_tag_Pho_pt;   //!
   TBranch        *b_tag_Pho_r9;   //!
   TBranch        *b_tag_sc_abseta;   //!
   TBranch        *b_tag_sc_energy;   //!
   TBranch        *b_tag_sc_et;   //!
   TBranch        *b_tag_sc_eta;   //!
   TBranch        *b_tag_Pho_mva;   //!
   TBranch        *b_pair_abseta;   //!
   TBranch        *b_pair_eta;   //!
   TBranch        *b_pair_mass;   //!
   TBranch        *b_pair_pt;   //!
   TBranch        *b_pair_mass60to120;   //!
   TBranch        *b_totWeight;   //!
   TBranch        *b_PUweight;   //!

   makereweight(TTree *tree=0);
   virtual ~makereweight();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef makereweight_cxx
makereweight::makereweight(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TnP_mc_Moriond17_norm_pTandr9reweight.root");
      if (!f || !f->IsOpen()) {
	f = new TFile("TnP_mc_Moriond17_norm_pTandr9reweight.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("TnP_mc_Moriond17_norm_pTandr9reweight.root:/PhotonToRECO");
      dir->GetObject("fitter_tree",tree);

   }
   Init(tree);
}

makereweight::~makereweight()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t makereweight::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t makereweight::LoadTree(Long64_t entry)
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

void makereweight::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("probe_Pho_ESsigma", &probe_Pho_ESsigma, &b_probe_Pho_ESsigma);
   fChain->SetBranchAddress("probe_Pho_ZSr9", &probe_Pho_ZSr9, &b_probe_Pho_ZSr9);
   fChain->SetBranchAddress("probe_Pho_abseta", &probe_Pho_abseta, &b_probe_Pho_abseta);
   fChain->SetBranchAddress("probe_Pho_chIso", &probe_Pho_chIso, &b_probe_Pho_chIso);
   fChain->SetBranchAddress("probe_Pho_chIso2", &probe_Pho_chIso2, &b_probe_Pho_chIso2);
   fChain->SetBranchAddress("probe_Pho_chIsoPresel", &probe_Pho_chIsoPresel, &b_probe_Pho_chIsoPresel);
   fChain->SetBranchAddress("probe_Pho_chWorIso", &probe_Pho_chWorIso, &b_probe_Pho_chWorIso);
   fChain->SetBranchAddress("probe_Pho_e", &probe_Pho_e, &b_probe_Pho_e);
   fChain->SetBranchAddress("probe_Pho_e1x5", &probe_Pho_e1x5, &b_probe_Pho_e1x5);
   fChain->SetBranchAddress("probe_Pho_e2x5", &probe_Pho_e2x5, &b_probe_Pho_e2x5);
   fChain->SetBranchAddress("probe_Pho_e3x3", &probe_Pho_e3x3, &b_probe_Pho_e3x3);
   fChain->SetBranchAddress("probe_Pho_e5x5", &probe_Pho_e5x5, &b_probe_Pho_e5x5);
   fChain->SetBranchAddress("probe_Pho_et", &probe_Pho_et, &b_probe_Pho_et);
   fChain->SetBranchAddress("probe_Pho_eta", &probe_Pho_eta, &b_probe_Pho_eta);
   fChain->SetBranchAddress("probe_Pho_etawidth", &probe_Pho_etawidth, &b_probe_Pho_etawidth);
   fChain->SetBranchAddress("probe_Pho_full5x5_e1x5", &probe_Pho_full5x5_e1x5, &b_probe_Pho_full5x5_e1x5);
   fChain->SetBranchAddress("probe_Pho_full5x5_e2x5", &probe_Pho_full5x5_e2x5, &b_probe_Pho_full5x5_e2x5);
   fChain->SetBranchAddress("probe_Pho_full5x5_e3x3", &probe_Pho_full5x5_e3x3, &b_probe_Pho_full5x5_e3x3);
   fChain->SetBranchAddress("probe_Pho_full5x5_e5x5", &probe_Pho_full5x5_e5x5, &b_probe_Pho_full5x5_e5x5);
   fChain->SetBranchAddress("probe_Pho_hoe", &probe_Pho_hoe, &b_probe_Pho_hoe);
   fChain->SetBranchAddress("probe_Pho_neuIso03", &probe_Pho_neuIso03, &b_probe_Pho_neuIso03);
   fChain->SetBranchAddress("probe_Pho_neuIso04", &probe_Pho_neuIso04, &b_probe_Pho_neuIso04);
   fChain->SetBranchAddress("probe_Pho_phiwidth", &probe_Pho_phiwidth, &b_probe_Pho_phiwidth);
   fChain->SetBranchAddress("probe_Pho_phoIso03", &probe_Pho_phoIso03, &b_probe_Pho_phoIso03);
   fChain->SetBranchAddress("probe_Pho_phoIso04", &probe_Pho_phoIso04, &b_probe_Pho_phoIso04);
   fChain->SetBranchAddress("probe_Pho_pt", &probe_Pho_pt, &b_probe_Pho_pt);
   fChain->SetBranchAddress("probe_Pho_r9", &probe_Pho_r9, &b_probe_Pho_r9);
   fChain->SetBranchAddress("probe_Pho_s4", &probe_Pho_s4, &b_probe_Pho_s4);
   fChain->SetBranchAddress("probe_Pho_sieie", &probe_Pho_sieie, &b_probe_Pho_sieie);
   fChain->SetBranchAddress("probe_Pho_sieip", &probe_Pho_sieip, &b_probe_Pho_sieip);
   fChain->SetBranchAddress("probe_Pho_sigmaEoE", &probe_Pho_sigmaEoE, &b_probe_Pho_sigmaEoE);
   fChain->SetBranchAddress("probe_Pho_sipip", &probe_Pho_sipip, &b_probe_Pho_sipip);
   fChain->SetBranchAddress("probe_Pho_tkIso", &probe_Pho_tkIso, &b_probe_Pho_tkIso);
   fChain->SetBranchAddress("probe_sc_abseta", &probe_sc_abseta, &b_probe_sc_abseta);
   fChain->SetBranchAddress("probe_sc_energy", &probe_sc_energy, &b_probe_sc_energy);
   fChain->SetBranchAddress("probe_sc_et", &probe_sc_et, &b_probe_sc_et);
   fChain->SetBranchAddress("probe_sc_eta", &probe_sc_eta, &b_probe_sc_eta);
   fChain->SetBranchAddress("probe_sc_rawe", &probe_sc_rawe, &b_probe_sc_rawe);
   fChain->SetBranchAddress("probe_Pho_mva", &probe_Pho_mva, &b_probe_Pho_mva);
   fChain->SetBranchAddress("passingIDMVA", &passingIDMVA, &b_passingIDMVA);
   fChain->SetBranchAddress("passingPresel", &passingPresel, &b_passingPresel);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("truePU", &truePU, &b_truePU);
   fChain->SetBranchAddress("event_PrimaryVertex_x", &event_PrimaryVertex_x, &b_mPVx);
   fChain->SetBranchAddress("event_PrimaryVertex_y", &event_PrimaryVertex_y, &b_mPVy);
   fChain->SetBranchAddress("event_PrimaryVertex_z", &event_PrimaryVertex_z, &b_mPVz);
   fChain->SetBranchAddress("event_nPV", &event_nPV, &b_mNPV);
   fChain->SetBranchAddress("event_BeamSpot_x", &event_BeamSpot_x, &b_mBSx);
   fChain->SetBranchAddress("event_BeamSpot_y", &event_BeamSpot_y, &b_mBSy);
   fChain->SetBranchAddress("event_BeamSpot_z", &event_BeamSpot_z, &b_mBSz);
   fChain->SetBranchAddress("event_rho", &event_rho, &b_rho);
   fChain->SetBranchAddress("mass", &mass, &b_mass);
   fChain->SetBranchAddress("tag_Pho_abseta", &tag_Pho_abseta, &b_tag_Pho_abseta);
   fChain->SetBranchAddress("tag_Pho_e", &tag_Pho_e, &b_tag_Pho_e);
   fChain->SetBranchAddress("tag_Pho_et", &tag_Pho_et, &b_tag_Pho_et);
   fChain->SetBranchAddress("tag_Pho_eta", &tag_Pho_eta, &b_tag_Pho_eta);
   fChain->SetBranchAddress("tag_Pho_full5x5_r9", &tag_Pho_full5x5_r9, &b_tag_Pho_full5x5_r9);
   fChain->SetBranchAddress("tag_Pho_pt", &tag_Pho_pt, &b_tag_Pho_pt);
   fChain->SetBranchAddress("tag_Pho_r9", &tag_Pho_r9, &b_tag_Pho_r9);
   fChain->SetBranchAddress("tag_sc_abseta", &tag_sc_abseta, &b_tag_sc_abseta);
   fChain->SetBranchAddress("tag_sc_energy", &tag_sc_energy, &b_tag_sc_energy);
   fChain->SetBranchAddress("tag_sc_et", &tag_sc_et, &b_tag_sc_et);
   fChain->SetBranchAddress("tag_sc_eta", &tag_sc_eta, &b_tag_sc_eta);
   fChain->SetBranchAddress("tag_Pho_mva", &tag_Pho_mva, &b_tag_Pho_mva);
   fChain->SetBranchAddress("pair_abseta", &pair_abseta, &b_pair_abseta);
   fChain->SetBranchAddress("pair_eta", &pair_eta, &b_pair_eta);
   fChain->SetBranchAddress("pair_mass", &pair_mass, &b_pair_mass);
   fChain->SetBranchAddress("pair_pt", &pair_pt, &b_pair_pt);
   fChain->SetBranchAddress("pair_mass60to120", &pair_mass60to120, &b_pair_mass60to120);
   fChain->SetBranchAddress("totWeight", &totWeight, &b_totWeight);
   fChain->SetBranchAddress("PUweight", &PUweight, &b_PUweight);
   Notify();
}

Bool_t makereweight::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void makereweight::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t makereweight::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef makereweight_cxx
