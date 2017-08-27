#define TotWeightCheck_cxx
#include "TotWeightCheck.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void TotWeightCheck::Loop()
{
//   In a ROOT session, you can do:
//      root> .L TotWeightCheck.C
//      root> TotWeightCheck t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;
   
   Long64_t nentries = fChain->GetEntriesFast();
     //For EB
   TH1D* Lowr9_Pass = new TH1D ("hMass_0.0To0.85_0.0To1.479_Pass","hMass_0.0To0.85_0.0To1.479_Pass",120,60,120);
   TH1D* Lowr9_Fail = new TH1D ("hMass_0.0To0.85_0.0To1.479_Fail","hMass_0.0To0.85_0.0To1.479_Fail",120,60,120);
   TH1D* Highr9_Pass = new TH1D ("hMass_0.85To1.0_0.0To1.479_Pass","hMass_0.85To1.0_0.0To1.479_Pass",120,60,120);
   TH1D* Highr9_Fail = new TH1D ("hMass_0.85To1.0_0.0To1.479_Fail","hMass_0.85To1.0_0.0To1.479_Fail",120,60,120);
   
   //   TH1D* npv = new TH1D ("npv","npv",100,0,100);
   // TH1D* true_PU = new TH1D ("true_PU","true_PU",100,0,100);
   // TH1D* pu_weight = new TH1D ("pu_weight","pu_weight",100,0,100);
   //   TH1D* ratio = new TH1D ("ratio","ratio",100,0,100);
   
   /*   //For EE
   TH1D* Lowr9_Pass = new TH1D ("hMass_0.0To0.90_1.479To2.5_Pass","hMass_0.0To0.90_1.479To2.5_Pass",120,60,120);
   TH1D* Lowr9_Fail = new TH1D ("hMass_0.0To0.90_1.479To2.5_Fail","hMass_0.0To0.90_1.479To2.5_Fail",120,60,120);
   TH1D* Highr9_Pass = new TH1D ("hMass_0.90To1.0_1.479To2.5_Pass","hMass_0.90To1.0_1.479To2.5_Pass",120,60,120);
   TH1D* Highr9_Fail = new TH1D ("hMass_0.90To1.0_1.479To2.5_Fail","hMass_0.90To1.0_1.479To2.5_Fail",120,60,120);
   */
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
      if (Cut(ientry) < 0) continue;
              //For EB 
       if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.0 && probe_Pho_r9<0.85 && probe_sc_abseta>0.0 && probe_sc_abseta<1.479 && passingPresel==1) Lowr9_Pass->Fill(mass,totWeight);
       if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.0 && probe_Pho_r9<0.85 && probe_sc_abseta>0.0 && probe_sc_abseta<1.479 && passingPresel==0) Lowr9_Fail->Fill(mass,totWeight);
       if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.85 && probe_Pho_r9<1.0 && probe_sc_abseta>0.0 && probe_sc_abseta<1.479 && passingPresel==1) Highr9_Pass->Fill(mass,totWeight);
       if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.85 && probe_Pho_r9<1.0 && probe_sc_abseta>0.0 && probe_sc_abseta<1.479 && passingPresel==0) Highr9_Fail->Fill(mass,totWeight);
      
      /*     //For EE
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.0 && probe_Pho_r9<0.90 && probe_sc_abseta>1.479 && probe_sc_abseta<2.5 && passingPresel==1) Lowr9_Pass->Fill(mass,totWeight);
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.0 && probe_Pho_r9<0.90 && probe_sc_abseta>1.479 && probe_sc_abseta<2.5 && passingPresel==0) Lowr9_Fail->Fill(mass,totWeight);
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.90 && probe_Pho_r9<1.0 && probe_sc_abseta>1.479 && probe_sc_abseta<2.5 && passingPresel==1) Highr9_Pass->Fill(mass,totWeight);
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.90 && probe_Pho_r9<1.0 && probe_sc_abseta>1.479 && probe_sc_abseta<2.5 && passingPresel==0) Highr9_Fail->Fill(mass,totWeight);
      */
      //For Photon IDMVA
      /*   //In EB

      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.0 && probe_Pho_r9<0.85 && probe_sc_abseta>0.0 && probe_sc_abseta<1.479 && passingPresel==1 && passingIDMVA==1) Lowr9_Pass->Fill(mass,totWeight);
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.0 && probe_Pho_r9<0.85 && probe_sc_abseta>0.0 && probe_sc_abseta<1.479 && passingPresel==1 && passingIDMVA==0) Lowr9_Fail->Fill(mass,totWeight);
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.85 && probe_Pho_r9<1.0 && probe_sc_abseta>0.0 && probe_sc_abseta<1.479 && passingPresel==1 && passingIDMVA==1) Highr9_Pass->Fill(mass,totWeight);
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.85 && probe_Pho_r9<1.0 && probe_sc_abseta>0.0 && probe_sc_abseta<1.479 && passingPresel==1 && passingIDMVA==0) Highr9_Fail->Fill(mass,totWeight);
      */  
     //npv->Fill(event_nPV);
     //true_PU->Fill(truePU);
     //pu_weight->Fill(PUweight);
     //ratio->Fill();
       /*   //In EE
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.0 && probe_Pho_r9<0.90 && probe_sc_abseta>1.479 && probe_sc_abseta<2.5 && passingPresel==1 && passingIDMVA==1) Lowr9_Pass->Fill(mass,totWeight);
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.0 && probe_Pho_r9<0.90 && probe_sc_abseta>1.479 && probe_sc_abseta<2.5 && passingPresel==1 && passingIDMVA==0) Lowr9_Fail->Fill(mass,totWeight);
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.90 && probe_Pho_r9<1.0 && probe_sc_abseta>1.479 && probe_sc_abseta<2.5 && passingPresel==1 && passingIDMVA==1) Highr9_Pass->Fill(mass,totWeight);
      if(totWeight<100000 && mcTrue == 1 && pair_mass60to120 && probe_Pho_r9>0.90 && probe_Pho_r9<1.0 && probe_sc_abseta>1.479 && probe_sc_abseta<2.5 && passingPresel==1 && passingIDMVA==0) Highr9_Fail->Fill(mass,totWeight);
       */
   }
   for (int i=0;i<Lowr9_Pass->GetNbinsX();i++){
     if(Lowr9_Pass->GetBinContent(i)<0) Lowr9_Pass->SetBinContent(i,0);
   }
   for (int i=0;i<Lowr9_Fail->GetNbinsX();i++){
     if(Lowr9_Fail->GetBinContent(i)<0) Lowr9_Fail->SetBinContent(i,0);
   }
   for (int i=0;i<Highr9_Pass->GetNbinsX();i++){
     if(Highr9_Pass->GetBinContent(i)<0) Highr9_Pass->SetBinContent(i,0);
   }
   for (int i=0;i<Highr9_Fail->GetNbinsX();i++){
     if(Highr9_Fail->GetBinContent(i)<0) Highr9_Fail->SetBinContent(i,0);
   }
   
   double Lowr9hpassInt=0.0;
   double Lowr9hfailInt=0.0;
   double Lowr9spError=0.0;
   double Lowr9sfError=0.0;
   double Lowr9StErEff=0.0;
   Lowr9hpassInt = Lowr9_Pass->IntegralAndError(1, Lowr9_Pass->GetNbinsX(), Lowr9spError);
   Lowr9hfailInt = Lowr9_Fail->IntegralAndError(1, Lowr9_Fail->GetNbinsX(), Lowr9sfError);
   Lowr9StErEff = std::sqrt(std::pow(Lowr9spError/Lowr9hpassInt,2)+std::pow(((Lowr9spError+Lowr9sfError)/(Lowr9hpassInt+Lowr9hfailInt)),2));
   std::cout << std::setprecision(8) <<Lowr9hpassInt << " " << Lowr9spError << " "<< Lowr9hfailInt << " "<< Lowr9sfError << " " << Lowr9hpassInt/(Lowr9hpassInt+Lowr9hfailInt)<< " " << Lowr9StErEff << std::endl;
   double Highr9hpassInt=0.0;
   double Highr9hfailInt=0.0;
   double Highr9spError=0.0;
   double Highr9sfError=0.0;
   double Highr9StErEff=0.0;
   Highr9hpassInt = Highr9_Pass->IntegralAndError(1, Highr9_Pass->GetNbinsX(), Highr9spError);
   Highr9hfailInt = Highr9_Fail->IntegralAndError(1, Highr9_Fail->GetNbinsX(), Highr9sfError);
   Highr9StErEff = std::sqrt(std::pow(Highr9spError/Highr9hpassInt,2)+std::pow(((Highr9spError+Highr9sfError)/(Highr9hpassInt+Highr9hfailInt)),2));
   std::cout << std::setprecision(8) <<Highr9hpassInt << " " << Highr9spError << " "<< Highr9hfailInt << " "<< Highr9sfError << " " << Highr9hpassInt/(Highr9hpassInt+Highr9hfailInt)<< " " << Highr9StErEff << std::endl;
   //For EE
     TFile f("templatePreselEB.root","RECREATE");
   //For EB
   // TFile f("templateIDMVAEE_TagpT40.root","RECREATE");
   Lowr9_Pass->Write();
   Lowr9_Fail->Write();
   Highr9_Pass->Write();
   Highr9_Fail->Write();
   f.Write();
   /*
   TH1D *ratio = (TH1D*)npv->Clone("ratio");
   ratio->Divide(true_PU);
   TFile f("npv.root","RECREATE");
   npv->Write();
   true_PU->Write();
   pu_weight->Write();
   ratio->Write();
   f.Write();
   */
}
