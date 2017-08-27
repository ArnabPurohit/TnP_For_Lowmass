#define makereweight_cxx
#include "makereweight.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <math.h>
void makereweight::Loop()
{
//   In a ROOT session, you can do:
//      root> .L makereweight.C
//      root> makereweight t
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
   //TH1F *r9before = new TH1F("r9before","r9before",100,0.,1.05);
   //TH1F *r9after = new TH1F("r9after","r9after",100,0.,1.05);
   TH1F *etabefore = new TH1F("etabefore","etabefore",100,-5.,5.);
   TH1F *etaafter = new TH1F("etaafter","etaafter",100,-5.,5.);
   TH1F *r9before = new TH1F("r9before","r9before",100,0.,1.05);
   TH1F *r9after = new TH1F("r9after","r9after",100,0.,1.05);
   Long64_t nbytes = 0, nb = 0;
   //double weightedr9=0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      if(totWeight==-nan) continue;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      //std::cout<< tag_Pho_r9 << " * " << totWeight << " = " << tag_Pho_r9*totWeight << std::endl;    
      etabefore->Fill(probe_Pho_eta);
      r9before->Fill(probe_Pho_r9);
      // if(totWeight==0){
      // 	totWeight=1.0;
      // 	std::cout<<"Hiiiiiii" << std::endl;      }
      etaafter->Fill(probe_Pho_eta,totWeight);
      r9after->Fill(probe_Pho_r9,totWeight);
     //if(jentry>1000) break;
     // ratio->Fill(totWeight);
     std::cout << totWeight << "= weight" << std::endl;
   }
  
   // r9before->Scale(1/r9before->Integral());
   //r9after->Scale(1/r9after->Integral());
   //etabefore->Scale(1/etabefore->Integral());
   // etaafter->Scale(1/etaafter->Integral());
   //   TH1F * ratio = (TH1F*)r9before->Clone("r9ratio");
   //TH1F * ratio = (TH1F*)etaafter->Clone("etaratio");
   // r9ratio->Divide(r9after);
    
     // r9after->SetLineColor(kRed);
     // r9after->Draw();
     // r9before->Draw("same");   
   // ratio->Draw();
   TFile file("etar9reweight.root","RECREATE");
    etabefore->Write();
    etaafter->SetLineColor(kRed);
    etaafter->Write();
    r9before->Write();
    r9after->Write();
    file.Write();   
   //ratio->Draw();  
 // TFile* file = TFile::Open("Rewieghting2d_16_08_toseer9ptcorrel.root");
   /// TH1F * TagPhotonHiggspT1dptr = (TH1F*) file->Get("Rewieghting2d_16_08_toseer9ptcorrel.root:/TagPhotonHiggspT1d");
   //TH1F * TagPhotonHiggsr91dptr = (TH1F*) file->Get("Rewieghting2d_16_08_toseer9ptcorrel.root:/TagPhotonHiggsr91d");
   //   TagPhotondatapT1dUn->Scale(1/pTafter->Integral());   
   // TagPhotondatapT1dUn->SetLineColor(kGreen);   

   //ratio->Divide(TagPhotonHiggspT1dptr);
   
   //TagPhotonHiggspT1dptr->SetLineColor(kGreen);
   //TagPhotonHiggspT1dptr->Draw("same");
   //TagPhotonHiggsr91dptr->SetLineColor(kGreen);
   //TagPhotonHiggsr91dptr->Draw("same");
   //f->cd();
   // ratio->Draw();
   
   
   //   file->Close();
   //pTratio->Divide(pTafter);
   
   //ratio->Draw();

   //TO GET THE BIN BY BIN DIFFERENCE**********************************************
   /*
     float diff=0;
     TH1F * bindiff = new TH1F("bindiff","bindiff",100,-0.1,0.1);
     for (int a=1;a<301;a++){
       
       diff=(pTafter->GetBinContent(a)-TagPhotonHiggspT1dptr->GetBinContent(a));
       bindiff->Fill(diff);
     }
     bindiff->Draw();
   */
}

