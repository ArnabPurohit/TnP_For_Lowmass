#define Rewighting2D_cxx
#include "Rewighting2D.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TH1.h>
void Rewighting2D::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Rewighting2D.C
//      root> Rewighting2D t
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
   const Int_t XBINS = 25; const Int_t YBINS = 18;
   Double_t xEdges[XBINS + 1] = {0.,0.5,0.55,0.6,0.65,0.7,0.74,0.76,0.78,0.8,0.82,0.84,0.86,0.88,0.9,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99,1.05,2.};
   Double_t yEdges[YBINS + 1] = {-3,-2.5,-2.,-1.566,-1.4442,-1.3,-1.2,-1.,-0.8,0.,0.8,1.,1.2,1.3,1.4442,1.566,2.,2.5,3.};
   TH2F *probePhotonHiggs = new TH2F("probePhotonHiggs","probePhotonHiggs",XBINS, xEdges, YBINS, yEdges);
   //TH2F *probePhotonmc = new TH2F("probePhotonmc","probePhotonmc",300,0.,300.,100,0.,1.05);
   TH2F *probePhotonZee = new TH2F("probePhotonZee","probePhotonZee",XBINS, xEdges, YBINS, yEdges);
   TH1F *probePhotonHiggsr91d = new TH1F("probePhotonHiggsr91d","probePhotonHiggsr91d",100,0.,1.05);
   TH1F *probePhotonZeer91d = new TH1F("probePhotonZeer91d","probePhotonZeer91d",100,0.,1.05);
   TH1F *probePhotonHiggsabseta1d = new TH1F("probePhotonHiggsabseta1d","probePhotonHiggsabseta1d",300,0.,300.);
   TH1F *probePhotonZeeabseta1d = new TH1F("probePhotonZeeabseta1d","probePhotonZeeabseta1d",300,0.,300.);

   TH1F *probePhotonHiggsr91dUn = new TH1F("probePhotonHiggsr91dUn","probePhotonHiggsr91dUn",100,0.,1.05);
   TH1F *probePhotonZeer91dUn = new TH1F("probePhotonZeer91dUn","probePhotonZeer91dUn",100,0.,1.05);
   TH1F *probePhotonHiggsabseta1dUn = new TH1F("probePhotonHiggsabseta1dUn","probePhotonHiggsabseta1dUn",300,0.,300.);
   TH1F *probePhotonZeeabseta1dUn = new TH1F("probePhotonZeeabseta1dUn","probePhotonZeeabseta1dUn",300,0.,300.);
   Long64_t nentries = fChain->GetEntriesFast();
   std::cout<< fCurrent << "th tree" << std::endl;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;

      if (fCurrent==0){
	//if (probe_Pho_r9>1.0){
	probePhotonHiggs->Fill(probe_Pho_r9,probe_Pho_eta);//}

        //r9data->Fill(leadr9);
	//if(ientry==1)std::cout<< fChain->GetTreeNumber() << "th tree" << std::endl; 
	//if (ientry%200==0)std::cout<< fCurrent << "th tree" << std::endl;
	probePhotonHiggsr91d->Fill(probe_Pho_r9);
	probePhotonHiggsabseta1d->Fill(probe_Pho_abseta);
	probePhotonHiggsr91dUn->Fill(probe_Pho_r9);
	probePhotonHiggsabseta1dUn->Fill(probe_Pho_abseta);
}
      if (fCurrent==1){
	//if (probe_Pho_r9>1.0){
	probePhotonZee->Fill(probe_Pho_r9,probe_Pho_eta);//}
	//std::cout<<"Hello"<<std::endl;
	//    probePhotonmc->Fill(probe_Pho_abseta,probe_Pho_r9);
	probePhotonZeer91d->Fill(probe_Pho_r9);
	probePhotonZeeabseta1d->Fill(probe_Pho_abseta);
	probePhotonZeer91dUn->Fill(probe_Pho_r9);
	probePhotonZeeabseta1dUn->Fill(probe_Pho_abseta);
      }
      //if (ientry%200000==0)std::cout<< fCurrent << "th tree" << std::endl;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
   probePhotonZee->Sumw2();
   probePhotonHiggs->Sumw2();
   std::cout<<probePhotonZee->Integral() << std::endl;
   double norm = 1/probePhotonHiggs->Integral(); 
   double norm1 = 1/probePhotonZee->Integral();

   double norm2 = 1/probePhotonHiggsr91d->Integral(); 
   double norm3 = 1/probePhotonZeer91d->Integral();

   double norm4 = 1/probePhotonHiggsabseta1d->Integral(); 
   double norm5 = 1/probePhotonZeeabseta1d->Integral();

   probePhotonHiggs->Scale(norm);
   probePhotonZee->Scale(norm1);

   probePhotonHiggsr91d->Scale(norm2);
   probePhotonZeer91d->Scale(norm3);

   probePhotonHiggsabseta1d->Scale(norm4);
   probePhotonZeeabseta1d->Scale(norm5);
   std::cout<<"After normalization"<<probePhotonZee->Integral() << std::endl; 
   TH2F *PhotonratioHtodata = (TH2F*)probePhotonHiggs->Clone("r9etaratio");
   TH1F *PhotonR9ratioHtodata = (TH1F*)probePhotonHiggsr91d->Clone("r9ratio");
   TH1F *PhotonABSETAratioHtodata = (TH1F*)probePhotonHiggsabseta1d->Clone("ABSETAratio");
   //TH1F *r9ratio = (TH1F*)r9data->Clone("r9ratio");                                                                                
   // int num_of_binx=probePhotonHiggs->GetNbinsX();
   // int num_of_biny=probePhotonHiggs->GetNbinsY();
   // int counter =0;
   // for (int i=1; i <= num_of_binx; i++){
   //   for (int j=1; j <= num_of_biny; j++){
   //     if ((probePhotonHiggs->GetBinContent(i,j)) == 0) {counter++;}  
   //   }   
   // }
   // std::cout << counter << " and nbins ="<< num_of_binx << "," << num_of_biny << std::endl;
   PhotonR9ratioHtodata->Divide(probePhotonZeer91d);

   PhotonABSETAratioHtodata->Divide(probePhotonZeeabseta1d);
   PhotonratioHtodata->Divide(probePhotonZee);
   //r9ratio->Divide(r9mc);                  
   
   TFile f("MC_Rewieghting2d_05_06_2017_NewLowmassCorrection_toseer9absetacorrel.root","RECREATE");
   probePhotonHiggs->Write();
   probePhotonZee->Write();
   //r9data->Write();  
   PhotonR9ratioHtodata->Write();
   probePhotonHiggsr91d->Write();
   probePhotonZeer91d->Write();
   probePhotonHiggsr91dUn->Write();
   probePhotonZeer91dUn->Write();

   PhotonABSETAratioHtodata->Write();
   probePhotonHiggsabseta1d->Write();
   probePhotonZeeabseta1d->Write();
   probePhotonHiggsabseta1dUn->Write();
   probePhotonZeeabseta1dUn->Write();

   //r9mc->Write();                                                                                                                   
   PhotonratioHtodata->Write();
   //r9ratio->Write();                                                                                                                
   f.Write();
}
