#define MyExoTreeJet_cxx
#include "MyExoTreeJet.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>


#include <iostream>
#include <sstream>

#include "/afs/cern.ch/user/c/ciperez/plostyle.C"
using namespace std;


//   In a ROOT session, you can do:
//      Root > .L MyExoTreeJet.C
//      Root > MyExoTreeJet t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
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



void MyExoTreeJet::LoopSigmaIetaIeta()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();

  TCanvas *canvasDataJet = new TCanvas("canvasDataJet","canvasDataJet",900,100,500,500);
  TCanvas *canvasfakeJet = new TCanvas("canvasfakeJet","canvasfakeJet",900,100,500,500);
  TCanvas *canvasTightAndFakeDataJet = new TCanvas("canvasTightAndFakeDataJet","canvasTightAndFakeDataJet",900,100,500,500);

  TH1F *histoDataJetptbin1 = new TH1F("histoDataJetptbin1","histoDataJetptbin1",60,0.,0.03);
  TH1F *histoDataJetptbin2 = new TH1F("histoDataJetptbin2","histoDataJetptbin2",60,0.,0.03);
  TH1F *histoDataJetptbin3 = new TH1F("histoDataJetptbin3","histoDataJetptbin3",60,0.,0.03);
  TH1F *histoDataJetptbin4 = new TH1F("histoDataJetptbin4","histoDataJetptbin4",60,0.,0.03);
  TH1F *histoDataJetptbin5 = new TH1F("histoDataJetptbin5","histoDataJetptbin5",60,0.,0.03);
  TH1F *histoDataJetptbin6 = new TH1F("histoDataJetptbin6","histoDataJetptbin6",60,0.,0.03);
  TH1F *histoDataJetptbin7 = new TH1F("histoDataJetptbin7","histoDataJetptbin7",60,0.,0.03);
  TH1F *histoDataJetptbin8 = new TH1F("histoDataJetptbin8","histoDataJetptbin8",60,0.,0.03);
  TH1F *histoDataJetptbin9 = new TH1F("histoDataJetptbin9","histoDataJetptbin9",60,0.,0.03);
  TH1F *histoDataJetptbin10 = new TH1F("histoDataJetptbin10","histoDataJetptbin10",60,0.,0.03);

  TH1F *histofakeJettemplateptbin1 = new TH1F("histofakeJettemplateptbin1","histofakeJettemplateptbin1",60,0.,0.03);
  TH1F *histofakeJettemplateptbin2 = new TH1F("histofakeJettemplateptbin2","histofakeJettemplateptbin2",60,0.,0.03);
  TH1F *histofakeJettemplateptbin3 = new TH1F("histofakeJettemplateptbin3","histofakeJettemplateptbin3",60,0.,0.03);
  TH1F *histofakeJettemplateptbin4 = new TH1F("histofakeJettemplateptbin4","histofakeJettemplateptbin4",60,0.,0.03);
  TH1F *histofakeJettemplateptbin5 = new TH1F("histofakeJettemplateptbin5","histofakeJettemplateptbin5",60,0.,0.03);
  TH1F *histofakeJettemplateptbin6 = new TH1F("histofakeJettemplateptbin6","histofakeJettemplateptbin6",60,0.,0.03);
  TH1F *histofakeJettemplateptbin7 = new TH1F("histofakeJettemplateptbin7","histofakeJettemplateptbin7",60,0.,0.03);
  TH1F *histofakeJettemplateptbin8 = new TH1F("histofakeJettemplateptbin8","histofakeJettemplateptbin8",60,0.,0.03);
  TH1F *histofakeJettemplateptbin9 = new TH1F("histofakeJettemplateptbin9","histofakeJettemplateptbin9",60,0.,0.03);
  TH1F *histofakeJettemplateptbin10 = new TH1F("histofakeJettemplateptbin10","histofakeJettemplateptbin10",60,0.,0.03);

  TH1F *histoTightAndFakeDataJetptbin1 = new TH1F("histoTightAndFakeDataJetptbin1","histoTightAndFakeDataJetptbin1",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin2 = new TH1F("histoTightAndFakeDataJetptbin2","histoTightAndFakeDataJetptbin2",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin3 = new TH1F("histoTightAndFakeDataJetptbin3","histoTightAndFakeDataJetptbin3",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin4 = new TH1F("histoTightAndFakeDataJetptbin4","histoTightAndFakeDataJetptbin4",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin5 = new TH1F("histoTightAndFakeDataJetptbin5","histoTightAndFakeDataJetptbin5",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin6 = new TH1F("histoTightAndFakeDataJetptbin6","histoTightAndFakeDataJetptbin6",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin7 = new TH1F("histoTightAndFakeDataJetptbin7","histoTightAndFakeDataJetptbin7",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin8 = new TH1F("histoTightAndFakeDataJetptbin8","histoTightAndFakeDataJetptbin8",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin9 = new TH1F("histoTightAndFakeDataJetptbin9","histoTightAndFakeDataJetptbin9",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin10 = new TH1F("histoTightAndFakeDataJetptbin10","histoTightAndFakeDataJetptbin10",60,0.,0.03);


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
    //if(jentry == 500000) break;

    for(int i=0;i<10;i++) {
      Bool_t towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
      Bool_t CHisocut = (Photon_rhocorPFIsoCharged03[i] < 0.7);
      Bool_t NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 0.4 + 0.04 * Photon_pt[i]);
      Bool_t PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.5 + 0.005 * Photon_pt[i]);
      Bool_t barrelcut = (Photon_isEB[i]);
      Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
      Bool_t isfakeable = (Photon_isPFFakeable[i]);
      Bool_t haspromptelec = (Photon_hasMatchedPromptElectron[i]);

      Bool_t ptbin1 = (Photon_pt[i] > 30. && Photon_pt[i] < 40.);
      Bool_t ptbin2 = (Photon_pt[i] > 40. && Photon_pt[i] < 50.);
      Bool_t ptbin3 = (Photon_pt[i] > 50. && Photon_pt[i] < 60.);
      Bool_t ptbin4 = (Photon_pt[i] > 60. && Photon_pt[i] < 70.);
      Bool_t ptbin5 = (Photon_pt[i] > 70. && Photon_pt[i] < 80.);
      Bool_t ptbin6 = (Photon_pt[i] > 80. && Photon_pt[i] < 90.);
      Bool_t ptbin7 = (Photon_pt[i] > 90. && Photon_pt[i] < 100.);
      Bool_t ptbin8 = (Photon_pt[i] > 100. && Photon_pt[i] < 110.);
      Bool_t ptbin9 = (Photon_pt[i] > 110. && Photon_pt[i] < 120.);
      Bool_t ptbin10 = (Photon_pt[i] > 120. && Photon_pt[i] < 130.);

      Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
      Bool_t gapcut = Photon_isEBEEGap[i];
      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

      //put this to go faster but be careful
      if(!ptcut) continue;
      if(!siphiiphicut) continue;
      if(gapcut) continue;
      if(rechitflagcut) continue;

      //this is the sinin template for numerator containing both real and fake components
      //if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
      if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  if(ptbin1) histoDataJetptbin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin2) histoDataJetptbin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin3) histoDataJetptbin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin4) histoDataJetptbin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin5) histoDataJetptbin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin6) histoDataJetptbin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin7) histoDataJetptbin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin8) histoDataJetptbin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin9) histoDataJetptbin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin10) histoDataJetptbin10->Fill(Photon_sigmaIetaIeta[i]);
	}

      //this is the sinin fake template (inverting track isolation)
      //if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
      if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  if(ptbin1) histofakeJettemplateptbin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin2) histofakeJettemplateptbin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin3) histofakeJettemplateptbin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin4) histofakeJettemplateptbin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin5) histofakeJettemplateptbin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin6) histofakeJettemplateptbin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin7) histofakeJettemplateptbin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin8) histofakeJettemplateptbin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin9) histofakeJettemplateptbin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin10) histofakeJettemplateptbin10->Fill(Photon_sigmaIetaIeta[i]);
	}

      //this is the denominator, i.e. the set of fakeable objects
      if(isfakeable && barrelcut && ptcut)
	{
	  if(ptbin1) histoTightAndFakeDataJetptbin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin2) histoTightAndFakeDataJetptbin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin3) histoTightAndFakeDataJetptbin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin4) histoTightAndFakeDataJetptbin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin5) histoTightAndFakeDataJetptbin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin6) histoTightAndFakeDataJetptbin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin7) histoTightAndFakeDataJetptbin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin8) histoTightAndFakeDataJetptbin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin9) histoTightAndFakeDataJetptbin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin10) histoTightAndFakeDataJetptbin10->Fill(Photon_sigmaIetaIeta[i]);
	}

    }//end of loop over photons

  }//end of loop over entries in event

  canvasDataJet->cd();

  histoDataJetptbin1->Draw();
  canvasDataJet->Print("histoDataJetptbin1.C","cxx");
  histoDataJetptbin2->Draw();
  canvasDataJet->Print("histoDataJetptbin2.C","cxx");
  histoDataJetptbin3->Draw();
  canvasDataJet->Print("histoDataJetptbin3.C","cxx");
  histoDataJetptbin4->Draw();
  canvasDataJet->Print("histoDataJetptbin4.C","cxx");
  histoDataJetptbin5->Draw();
  canvasDataJet->Print("histoDataJetptbin5.C","cxx");
  histoDataJetptbin6->Draw();
  canvasDataJet->Print("histoDataJetptbin6.C","cxx");
  histoDataJetptbin7->Draw();
  canvasDataJet->Print("histoDataJetptbin7.C","cxx");
  histoDataJetptbin8->Draw();
  canvasDataJet->Print("histoDataJetptbin8.C","cxx");
  histoDataJetptbin9->Draw();
  canvasDataJet->Print("histoDataJetptbin9.C","cxx");
  histoDataJetptbin10->Draw();
  canvasDataJet->Print("histoDataJetptbin10.C","cxx");

  canvasfakeJet->cd();

  histofakeJettemplateptbin1->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin1.C","cxx");
  histofakeJettemplateptbin2->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin2.C","cxx");
  histofakeJettemplateptbin3->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin3.C","cxx");
  histofakeJettemplateptbin4->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin4.C","cxx");
  histofakeJettemplateptbin5->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin5.C","cxx");
  histofakeJettemplateptbin6->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin6.C","cxx");
  histofakeJettemplateptbin7->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin7.C","cxx");
  histofakeJettemplateptbin8->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin8.C","cxx");
  histofakeJettemplateptbin9->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin9.C","cxx");
  histofakeJettemplateptbin10->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin10.C","cxx");

  canvasTightAndFakeDataJet->cd();

  histoTightAndFakeDataJetptbin1->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin1.C","cxx");
  histoTightAndFakeDataJetptbin2->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin2.C","cxx");
  histoTightAndFakeDataJetptbin3->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin3.C","cxx");
  histoTightAndFakeDataJetptbin4->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin4.C","cxx");
  histoTightAndFakeDataJetptbin5->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin5.C","cxx");
  histoTightAndFakeDataJetptbin6->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin6.C","cxx");
  histoTightAndFakeDataJetptbin7->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin7.C","cxx");
  histoTightAndFakeDataJetptbin8->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin8.C","cxx");
  histoTightAndFakeDataJetptbin9->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin9.C","cxx");
  histoTightAndFakeDataJetptbin10->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin10.C","cxx");

}//end of method































void MyExoTreeJet::LoopSigmaIetaIetaEtaBins()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();

  TCanvas *canvasDataJet = new TCanvas("canvasDataJet","canvasDataJet",900,100,500,500);
  TCanvas *canvasfakeJet = new TCanvas("canvasfakeJet","canvasfakeJet",900,100,500,500);
  TCanvas *canvasTightAndFakeDataJet = new TCanvas("canvasTightAndFakeDataJet","canvasTightAndFakeDataJet",900,100,500,500);

  int nbinstemplate = 15;
  float minvaluetemplate = -1.5;
  float maxvaluetemplate = 1.5;
  float step = (maxvaluetemplate - minvaluetemplate)/nbinstemplate;

  int nbins = 60;
  float minvalue = 0.;
  float maxvalue = 0.03;

  std::vector<TH1F*> histoDataJet;
  std::vector<TH1F*> histoFakeJet;
  std::vector<TH1F*> histoTightAndFakeJet;
  std::vector<Bool_t> etabins;

  histoDataJet.resize(nbinstemplate);
  histoFakeJet.resize(nbinstemplate);
  histoTightAndFakeJet.resize(nbinstemplate);
  etabins.resize(nbinstemplate);

  for(int num=0;num<nbinstemplate;num++) 
    {
      std::stringstream Datatemplatename;
      std::stringstream Faketemplatename;
      std::stringstream TightAndFaketemplatename;

      Datatemplatename<<"histoDataJetetabin"<<(num+1);
      histoDataJet[num] = new TH1F(Datatemplatename.str().c_str(),Datatemplatename.str().c_str(),nbins,minvalue,maxvalue);

      Faketemplatename<<"histofakeJettemplateetabin"<<(num+1);
      histoFakeJet[num] = new TH1F(Faketemplatename.str().c_str(),Faketemplatename.str().c_str(),nbins,minvalue,maxvalue);

      TightAndFaketemplatename<<"histoTightAndFakeDataJetetabin"<<(num+1);
      histoTightAndFakeJet[num] = new TH1F(TightAndFaketemplatename.str().c_str(),TightAndFaketemplatename.str().c_str(),nbins,minvalue,maxvalue);
    }


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
    //if(jentry == 5000000) break;

    for(int i=0;i<10;i++) {
      Bool_t towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
      Bool_t CHisocut = (Photon_rhocorPFIsoCharged03[i] < 0.7);
      Bool_t NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 0.4 + 0.04 * Photon_pt[i]);
      Bool_t PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.5 + 0.005 * Photon_pt[i]);
      Bool_t barrelcut = (Photon_isEB[i]);
      Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
      Bool_t isfakeable = (Photon_isPFFakeable[i]);
      Bool_t haspromptelec = (Photon_hasMatchedPromptElectron[i]);

      Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
      Bool_t gapcut = Photon_isEBEEGap[i];
      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

      for(int num=0;num<nbinstemplate;num++) 
	{
	  etabins[num] = ( (Photon_eta[i] > (minvaluetemplate+num*step)) && (Photon_eta[i] < (minvaluetemplate+(num+1)*step)) );
	}

      //put this to go faster but be careful
      if(!ptcut) continue;
      if(!siphiiphicut) continue;
      if(gapcut) continue;
      if(rechitflagcut) continue;

      //this is the sinin template for numerator containing both real and fake components
      if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  for(int num=0;num<nbinstemplate;num++) {if(etabins[num]) histoDataJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}
      
      //this is the sinin fake template (inverting track isolation)
      if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  for(int num=0;num<nbinstemplate;num++) {if(etabins[num]) histoFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}
      
      //this is the denominator, i.e. the set of fakeable objects
      if(isfakeable && barrelcut && ptcut)
	{
	  for(int num=0;num<nbinstemplate;num++) {if(etabins[num]) histoTightAndFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}

    }//end of loop over photons
    
  }//end of loop over entries in event

  canvasDataJet->cd();

  for(int num=0;num<nbinstemplate;num++) 
    {
      TString Datatemplatename = TString(histoDataJet[num]->GetName())+".C";
      TString Faketemplatename = TString(histoFakeJet[num]->GetName())+".C";
      TString TightAndFaketemplatename = TString(histoTightAndFakeJet[num]->GetName())+".C";

      histoDataJet[num]->Draw();
      canvasDataJet->Print(Datatemplatename.Data());

      histoFakeJet[num]->Draw();
      canvasDataJet->Print(Faketemplatename.Data());

      histoTightAndFakeJet[num]->Draw();
      canvasDataJet->Print(TightAndFaketemplatename.Data());
    }

}//end of method




























void MyExoTreeJet::LoopSigmaIetaIetaPhiBins()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();

  TCanvas *canvasDataJet = new TCanvas("canvasDataJet","canvasDataJet",900,100,500,500);
  TCanvas *canvasfakeJet = new TCanvas("canvasfakeJet","canvasfakeJet",900,100,500,500);
  TCanvas *canvasTightAndFakeDataJet = new TCanvas("canvasTightAndFakeDataJet","canvasTightAndFakeDataJet",900,100,500,500);

  int nbinstemplate = 18;
  float minvaluetemplate = -3.14159265358979312;
  float maxvaluetemplate = 3.14159265358979312;
  float step = (maxvaluetemplate - minvaluetemplate)/nbinstemplate;

  int nbins = 60;
  float minvalue = 0.;
  float maxvalue = 0.03;



  std::vector<TH1F*> histoDataJet;
  std::vector<TH1F*> histoFakeJet;
  std::vector<TH1F*> histoTightAndFakeJet;
  std::vector<Bool_t> phibins;

  histoDataJet.resize(nbinstemplate);
  histoFakeJet.resize(nbinstemplate);
  histoTightAndFakeJet.resize(nbinstemplate);
  phibins.resize(nbinstemplate);

  for(int num=0;num<nbinstemplate;num++) 
    {
      std::stringstream Datatemplatename;
      std::stringstream Faketemplatename;
      std::stringstream TightAndFaketemplatename;

      Datatemplatename<<"histoDataJetphibin"<<(num+1);
      histoDataJet[num] = new TH1F(Datatemplatename.str().c_str(),Datatemplatename.str().c_str(),nbins,minvalue,maxvalue);

      Faketemplatename<<"histofakeJettemplatephibin"<<(num+1);
      histoFakeJet[num] = new TH1F(Faketemplatename.str().c_str(),Faketemplatename.str().c_str(),nbins,minvalue,maxvalue);

      TightAndFaketemplatename<<"histoTightAndFakeDataJetphibin"<<(num+1);
      histoTightAndFakeJet[num] = new TH1F(TightAndFaketemplatename.str().c_str(),TightAndFaketemplatename.str().c_str(),nbins,minvalue,maxvalue);
    }


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
    //if(jentry == 50000) break;

    for(int i=0;i<10;i++) {
      Bool_t towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
      Bool_t CHisocut = (Photon_rhocorPFIsoCharged03[i] < 0.7);
      Bool_t NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 0.4 + 0.04 * Photon_pt[i]);
      Bool_t PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.5 + 0.005 * Photon_pt[i]);
      Bool_t barrelcut = (Photon_isEB[i]);
      Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
      Bool_t isfakeable = (Photon_isPFFakeable[i]);
      Bool_t haspromptelec = (Photon_hasMatchedPromptElectron[i]);

      Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
      Bool_t gapcut = Photon_isEBEEGap[i];
      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

      for(int num=0;num<nbinstemplate;num++) 
	{
	  phibins[num] = ( (Photon_phi[i] > (minvaluetemplate+num*step)) && (Photon_phi[i] < (minvaluetemplate+(num+1)*step)) );
	}

      //put this to go faster but be careful
      if(!ptcut) continue;
      if(!siphiiphicut) continue;
      if(gapcut) continue;
      if(rechitflagcut) continue;

      //this is the sinin template for numerator containing both real and fake components
      if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  for(int num=0;num<nbinstemplate;num++) {if(phibins[num]) histoDataJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}
      
      //this is the sinin fake template (inverting track isolation)
      if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  for(int num=0;num<nbinstemplate;num++) {if(phibins[num]) histoFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}
      
      //this is the denominator, i.e. the set of fakeable objects
      if(isfakeable && barrelcut && ptcut)
	{
	  for(int num=0;num<nbinstemplate;num++) {if(phibins[num]) histoTightAndFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}

    }//end of loop over photons
    
  }//end of loop over entries in event

  canvasDataJet->cd();


  for(int num=0;num<nbinstemplate;num++) 
    {
      TString Datatemplatename = TString(histoDataJet[num]->GetName())+".C";
      TString Faketemplatename = TString(histoFakeJet[num]->GetName())+".C";
      TString TightAndFaketemplatename = TString(histoTightAndFakeJet[num]->GetName())+".C";

      histoDataJet[num]->Draw();
      canvasDataJet->Print(Datatemplatename.Data());

      histoFakeJet[num]->Draw();
      canvasDataJet->Print(Faketemplatename.Data());

      histoTightAndFakeJet[num]->Draw();
      canvasDataJet->Print(TightAndFaketemplatename.Data());
    }


}//end of method
















void MyExoTreeJet::LoopSigmaIetaIetaWithPixelSeed()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();

  TCanvas *canvasDataJet = new TCanvas("canvasDataJet","canvasDataJet",900,100,500,500);
  TCanvas *canvasfakeJet = new TCanvas("canvasfakeJet","canvasfakeJet",900,100,500,500);
  TCanvas *canvasTightAndFakeDataJet = new TCanvas("canvasTightAndFakeDataJet","canvasTightAndFakeDataJet",900,100,500,500);

  TH1F *histoDataJetptbin1 = new TH1F("histoDataJetptbin1","histoDataJetptbin1",60,0.,0.03);
  TH1F *histoDataJetptbin2 = new TH1F("histoDataJetptbin2","histoDataJetptbin2",60,0.,0.03);
  TH1F *histoDataJetptbin3 = new TH1F("histoDataJetptbin3","histoDataJetptbin3",60,0.,0.03);
  TH1F *histoDataJetptbin4 = new TH1F("histoDataJetptbin4","histoDataJetptbin4",60,0.,0.03);
  TH1F *histoDataJetptbin5 = new TH1F("histoDataJetptbin5","histoDataJetptbin5",60,0.,0.03);
  TH1F *histoDataJetptbin6 = new TH1F("histoDataJetptbin6","histoDataJetptbin6",60,0.,0.03);
  TH1F *histoDataJetptbin7 = new TH1F("histoDataJetptbin7","histoDataJetptbin7",60,0.,0.03);
  TH1F *histoDataJetptbin8 = new TH1F("histoDataJetptbin8","histoDataJetptbin8",60,0.,0.03);
  TH1F *histoDataJetptbin9 = new TH1F("histoDataJetptbin9","histoDataJetptbin9",60,0.,0.03);
  TH1F *histoDataJetptbin10 = new TH1F("histoDataJetptbin10","histoDataJetptbin10",60,0.,0.03);

  TH1F *histofakeJettemplateptbin1 = new TH1F("histofakeJettemplateptbin1","histofakeJettemplateptbin1",60,0.,0.03);
  TH1F *histofakeJettemplateptbin2 = new TH1F("histofakeJettemplateptbin2","histofakeJettemplateptbin2",60,0.,0.03);
  TH1F *histofakeJettemplateptbin3 = new TH1F("histofakeJettemplateptbin3","histofakeJettemplateptbin3",60,0.,0.03);
  TH1F *histofakeJettemplateptbin4 = new TH1F("histofakeJettemplateptbin4","histofakeJettemplateptbin4",60,0.,0.03);
  TH1F *histofakeJettemplateptbin5 = new TH1F("histofakeJettemplateptbin5","histofakeJettemplateptbin5",60,0.,0.03);
  TH1F *histofakeJettemplateptbin6 = new TH1F("histofakeJettemplateptbin6","histofakeJettemplateptbin6",60,0.,0.03);
  TH1F *histofakeJettemplateptbin7 = new TH1F("histofakeJettemplateptbin7","histofakeJettemplateptbin7",60,0.,0.03);
  TH1F *histofakeJettemplateptbin8 = new TH1F("histofakeJettemplateptbin8","histofakeJettemplateptbin8",60,0.,0.03);
  TH1F *histofakeJettemplateptbin9 = new TH1F("histofakeJettemplateptbin9","histofakeJettemplateptbin9",60,0.,0.03);
  TH1F *histofakeJettemplateptbin10 = new TH1F("histofakeJettemplateptbin10","histofakeJettemplateptbin10",60,0.,0.03);

  TH1F *histoTightAndFakeDataJetptbin1 = new TH1F("histoTightAndFakeDataJetptbin1","histoTightAndFakeDataJetptbin1",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin2 = new TH1F("histoTightAndFakeDataJetptbin2","histoTightAndFakeDataJetptbin2",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin3 = new TH1F("histoTightAndFakeDataJetptbin3","histoTightAndFakeDataJetptbin3",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin4 = new TH1F("histoTightAndFakeDataJetptbin4","histoTightAndFakeDataJetptbin4",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin5 = new TH1F("histoTightAndFakeDataJetptbin5","histoTightAndFakeDataJetptbin5",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin6 = new TH1F("histoTightAndFakeDataJetptbin6","histoTightAndFakeDataJetptbin6",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin7 = new TH1F("histoTightAndFakeDataJetptbin7","histoTightAndFakeDataJetptbin7",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin8 = new TH1F("histoTightAndFakeDataJetptbin8","histoTightAndFakeDataJetptbin8",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin9 = new TH1F("histoTightAndFakeDataJetptbin9","histoTightAndFakeDataJetptbin9",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetptbin10 = new TH1F("histoTightAndFakeDataJetptbin10","histoTightAndFakeDataJetptbin10",60,0.,0.03);


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
    //if(jentry == 500000) break;

    //cut on deltaphi
    //if(abs(Photon_phi[1] - Photon_phi[0]) > 2.8) continue;

    for(int i=0;i<10;i++) {
      Bool_t towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
      Bool_t CHisocut = (Photon_rhocorPFIsoCharged03[i] < 0.7);
      Bool_t NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 0.4 + 0.04 * Photon_pt[i]);
      Bool_t PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.5 + 0.005 * Photon_pt[i]);
      Bool_t barrelcut = (Photon_isEB[i]);
      Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
      Bool_t isfakeable = (Photon_isPFFakeable[i]);
      Bool_t haspromptelec = (Photon_hasMatchedPromptElectron[i]);

      Bool_t ptbin1 = (Photon_pt[i] > 30. && Photon_pt[i] < 40.);
      Bool_t ptbin2 = (Photon_pt[i] > 40. && Photon_pt[i] < 50.);
      Bool_t ptbin3 = (Photon_pt[i] > 50. && Photon_pt[i] < 60.);
      Bool_t ptbin4 = (Photon_pt[i] > 60. && Photon_pt[i] < 70.);
      Bool_t ptbin5 = (Photon_pt[i] > 70. && Photon_pt[i] < 80.);
      Bool_t ptbin6 = (Photon_pt[i] > 80. && Photon_pt[i] < 90.);
      Bool_t ptbin7 = (Photon_pt[i] > 90. && Photon_pt[i] < 100.);
      Bool_t ptbin8 = (Photon_pt[i] > 100. && Photon_pt[i] < 110.);
      Bool_t ptbin9 = (Photon_pt[i] > 110. && Photon_pt[i] < 120.);
      Bool_t ptbin10 = (Photon_pt[i] > 120. && Photon_pt[i] < 130.);

      Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
      Bool_t gapcut = Photon_isEBEEGap[i];
      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

      //put this to go faster but be careful
      if(!ptcut) continue;
      if(!siphiiphicut) continue;
      if(gapcut) continue;
      if(rechitflagcut) continue;

      /////////////
      //this is to try with the pixel seed
      //this has to be applied only on numerator
      //be careful to remove it when not needed
      ////////////

      //this is the sinin template for numerator containing both real and fake components
      //if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
      if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut && !haspromptelec)
	{
	  if(ptbin1) histoDataJetptbin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin2) histoDataJetptbin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin3) histoDataJetptbin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin4) histoDataJetptbin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin5) histoDataJetptbin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin6) histoDataJetptbin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin7) histoDataJetptbin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin8) histoDataJetptbin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin9) histoDataJetptbin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin10) histoDataJetptbin10->Fill(Photon_sigmaIetaIeta[i]);
	}

      //this is the sinin fake template (inverting track isolation)
      //if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
      if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut && !haspromptelec)
	{
	  if(ptbin1) histofakeJettemplateptbin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin2) histofakeJettemplateptbin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin3) histofakeJettemplateptbin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin4) histofakeJettemplateptbin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin5) histofakeJettemplateptbin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin6) histofakeJettemplateptbin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin7) histofakeJettemplateptbin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin8) histofakeJettemplateptbin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin9) histofakeJettemplateptbin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin10) histofakeJettemplateptbin10->Fill(Photon_sigmaIetaIeta[i]);
	}

      //this is the denominator, i.e. the set of fakeable objects
      if(isfakeable && barrelcut && ptcut)
	{
	  if(ptbin1) histoTightAndFakeDataJetptbin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin2) histoTightAndFakeDataJetptbin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin3) histoTightAndFakeDataJetptbin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin4) histoTightAndFakeDataJetptbin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin5) histoTightAndFakeDataJetptbin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin6) histoTightAndFakeDataJetptbin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin7) histoTightAndFakeDataJetptbin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin8) histoTightAndFakeDataJetptbin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin9) histoTightAndFakeDataJetptbin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(ptbin10) histoTightAndFakeDataJetptbin10->Fill(Photon_sigmaIetaIeta[i]);
	}

    }//end of loop over photons

  }//end of loop over entries in event

  canvasDataJet->cd();

  histoDataJetptbin1->Draw();
  canvasDataJet->Print("histoDataJetptbin1.C","cxx");
  histoDataJetptbin2->Draw();
  canvasDataJet->Print("histoDataJetptbin2.C","cxx");
  histoDataJetptbin3->Draw();
  canvasDataJet->Print("histoDataJetptbin3.C","cxx");
  histoDataJetptbin4->Draw();
  canvasDataJet->Print("histoDataJetptbin4.C","cxx");
  histoDataJetptbin5->Draw();
  canvasDataJet->Print("histoDataJetptbin5.C","cxx");
  histoDataJetptbin6->Draw();
  canvasDataJet->Print("histoDataJetptbin6.C","cxx");
  histoDataJetptbin7->Draw();
  canvasDataJet->Print("histoDataJetptbin7.C","cxx");
  histoDataJetptbin8->Draw();
  canvasDataJet->Print("histoDataJetptbin8.C","cxx");
  histoDataJetptbin9->Draw();
  canvasDataJet->Print("histoDataJetptbin9.C","cxx");
  histoDataJetptbin10->Draw();
  canvasDataJet->Print("histoDataJetptbin10.C","cxx");

  canvasfakeJet->cd();

  histofakeJettemplateptbin1->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin1.C","cxx");
  histofakeJettemplateptbin2->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin2.C","cxx");
  histofakeJettemplateptbin3->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin3.C","cxx");
  histofakeJettemplateptbin4->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin4.C","cxx");
  histofakeJettemplateptbin5->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin5.C","cxx");
  histofakeJettemplateptbin6->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin6.C","cxx");
  histofakeJettemplateptbin7->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin7.C","cxx");
  histofakeJettemplateptbin8->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin8.C","cxx");
  histofakeJettemplateptbin9->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin9.C","cxx");
  histofakeJettemplateptbin10->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin10.C","cxx");

  canvasTightAndFakeDataJet->cd();

  histoTightAndFakeDataJetptbin1->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin1.C","cxx");
  histoTightAndFakeDataJetptbin2->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin2.C","cxx");
  histoTightAndFakeDataJetptbin3->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin3.C","cxx");
  histoTightAndFakeDataJetptbin4->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin4.C","cxx");
  histoTightAndFakeDataJetptbin5->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin5.C","cxx");
  histoTightAndFakeDataJetptbin6->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin6.C","cxx");
  histoTightAndFakeDataJetptbin7->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin7.C","cxx");
  histoTightAndFakeDataJetptbin8->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin8.C","cxx");
  histoTightAndFakeDataJetptbin9->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin9.C","cxx");
  histoTightAndFakeDataJetptbin10->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin10.C","cxx");

}//end of method































































void MyExoTreeJet::LoopSigmaIetaIetaPileupBins()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();

  TCanvas *canvasDataJet = new TCanvas("canvasDataJet","canvasDataJet",900,100,500,500);
  TCanvas *canvasfakeJet = new TCanvas("canvasfakeJet","canvasfakeJet",900,100,500,500);
  TCanvas *canvasTightAndFakeDataJet = new TCanvas("canvasTightAndFakeDataJet","canvasTightAndFakeDataJet",900,100,500,500);

  TH1F *histoDataJetpileuprhobin1 = new TH1F("histoDataJetpileuprhobin1","histoDataJetpileuprhobin1",60,0.,0.03);
  TH1F *histoDataJetpileuprhobin2 = new TH1F("histoDataJetpileuprhobin2","histoDataJetpileuprhobin2",60,0.,0.03);
  TH1F *histoDataJetpileuprhobin3 = new TH1F("histoDataJetpileuprhobin3","histoDataJetpileuprhobin3",60,0.,0.03);
  TH1F *histoDataJetpileuprhobin4 = new TH1F("histoDataJetpileuprhobin4","histoDataJetpileuprhobin4",60,0.,0.03);
  TH1F *histoDataJetpileuprhobin5 = new TH1F("histoDataJetpileuprhobin5","histoDataJetpileuprhobin5",60,0.,0.03);
  TH1F *histoDataJetpileuprhobin6 = new TH1F("histoDataJetpileuprhobin6","histoDataJetpileuprhobin6",60,0.,0.03);
  TH1F *histoDataJetpileuprhobin7 = new TH1F("histoDataJetpileuprhobin7","histoDataJetpileuprhobin7",60,0.,0.03);
  TH1F *histoDataJetpileuprhobin8 = new TH1F("histoDataJetpileuprhobin8","histoDataJetpileuprhobin8",60,0.,0.03);
  TH1F *histoDataJetpileuprhobin9 = new TH1F("histoDataJetpileuprhobin9","histoDataJetpileuprhobin9",60,0.,0.03);
  TH1F *histoDataJetpileuprhobin10 = new TH1F("histoDataJetpileuprhobin10","histoDataJetpileuprhobin10",60,0.,0.03);

  TH1F *histofakeJettemplatepileuprhobin1 = new TH1F("histofakeJettemplatepileuprhobin1","histofakeJettemplatepileuprhobin1",60,0.,0.03);
  TH1F *histofakeJettemplatepileuprhobin2 = new TH1F("histofakeJettemplatepileuprhobin2","histofakeJettemplatepileuprhobin2",60,0.,0.03);
  TH1F *histofakeJettemplatepileuprhobin3 = new TH1F("histofakeJettemplatepileuprhobin3","histofakeJettemplatepileuprhobin3",60,0.,0.03);
  TH1F *histofakeJettemplatepileuprhobin4 = new TH1F("histofakeJettemplatepileuprhobin4","histofakeJettemplatepileuprhobin4",60,0.,0.03);
  TH1F *histofakeJettemplatepileuprhobin5 = new TH1F("histofakeJettemplatepileuprhobin5","histofakeJettemplatepileuprhobin5",60,0.,0.03);
  TH1F *histofakeJettemplatepileuprhobin6 = new TH1F("histofakeJettemplatepileuprhobin6","histofakeJettemplatepileuprhobin6",60,0.,0.03);
  TH1F *histofakeJettemplatepileuprhobin7 = new TH1F("histofakeJettemplatepileuprhobin7","histofakeJettemplatepileuprhobin7",60,0.,0.03);
  TH1F *histofakeJettemplatepileuprhobin8 = new TH1F("histofakeJettemplatepileuprhobin8","histofakeJettemplatepileuprhobin8",60,0.,0.03);
  TH1F *histofakeJettemplatepileuprhobin9 = new TH1F("histofakeJettemplatepileuprhobin9","histofakeJettemplatepileuprhobin9",60,0.,0.03);
  TH1F *histofakeJettemplatepileuprhobin10 = new TH1F("histofakeJettemplatepileuprhobin10","histofakeJettemplatepileuprhobin10",60,0.,0.03);

  TH1F *histoTightAndFakeDataJetpileuprhobin1 = new TH1F("histoTightAndFakeDataJetpileuprhobin1","histoTightAndFakeDataJetpileuprhobin1",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileuprhobin2 = new TH1F("histoTightAndFakeDataJetpileuprhobin2","histoTightAndFakeDataJetpileuprhobin2",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileuprhobin3 = new TH1F("histoTightAndFakeDataJetpileuprhobin3","histoTightAndFakeDataJetpileuprhobin3",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileuprhobin4 = new TH1F("histoTightAndFakeDataJetpileuprhobin4","histoTightAndFakeDataJetpileuprhobin4",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileuprhobin5 = new TH1F("histoTightAndFakeDataJetpileuprhobin5","histoTightAndFakeDataJetpileuprhobin5",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileuprhobin6 = new TH1F("histoTightAndFakeDataJetpileuprhobin6","histoTightAndFakeDataJetpileuprhobin6",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileuprhobin7 = new TH1F("histoTightAndFakeDataJetpileuprhobin7","histoTightAndFakeDataJetpileuprhobin7",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileuprhobin8 = new TH1F("histoTightAndFakeDataJetpileuprhobin8","histoTightAndFakeDataJetpileuprhobin8",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileuprhobin9 = new TH1F("histoTightAndFakeDataJetpileuprhobin9","histoTightAndFakeDataJetpileuprhobin9",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileuprhobin10 = new TH1F("histoTightAndFakeDataJetpileuprhobin10","histoTightAndFakeDataJetpileuprhobin10",60,0.,0.03);


  TH1F *histoDataJetpileupnvtxbin1 = new TH1F("histoDataJetpileupnvtxbin1","histoDataJetpileupnvtxbin1",60,0.,0.03);
  TH1F *histoDataJetpileupnvtxbin2 = new TH1F("histoDataJetpileupnvtxbin2","histoDataJetpileupnvtxbin2",60,0.,0.03);
  TH1F *histoDataJetpileupnvtxbin3 = new TH1F("histoDataJetpileupnvtxbin3","histoDataJetpileupnvtxbin3",60,0.,0.03);
  TH1F *histoDataJetpileupnvtxbin4 = new TH1F("histoDataJetpileupnvtxbin4","histoDataJetpileupnvtxbin4",60,0.,0.03);
  TH1F *histoDataJetpileupnvtxbin5 = new TH1F("histoDataJetpileupnvtxbin5","histoDataJetpileupnvtxbin5",60,0.,0.03);
  TH1F *histoDataJetpileupnvtxbin6 = new TH1F("histoDataJetpileupnvtxbin6","histoDataJetpileupnvtxbin6",60,0.,0.03);
  TH1F *histoDataJetpileupnvtxbin7 = new TH1F("histoDataJetpileupnvtxbin7","histoDataJetpileupnvtxbin7",60,0.,0.03);
  TH1F *histoDataJetpileupnvtxbin8 = new TH1F("histoDataJetpileupnvtxbin8","histoDataJetpileupnvtxbin8",60,0.,0.03);
  TH1F *histoDataJetpileupnvtxbin9 = new TH1F("histoDataJetpileupnvtxbin9","histoDataJetpileupnvtxbin9",60,0.,0.03);
  TH1F *histoDataJetpileupnvtxbin10 = new TH1F("histoDataJetpileupnvtxbin10","histoDataJetpileupnvtxbin10",60,0.,0.03);

  TH1F *histofakeJettemplatepileupnvtxbin1 = new TH1F("histofakeJettemplatepileupnvtxbin1","histofakeJettemplatepileupnvtxbin1",60,0.,0.03);
  TH1F *histofakeJettemplatepileupnvtxbin2 = new TH1F("histofakeJettemplatepileupnvtxbin2","histofakeJettemplatepileupnvtxbin2",60,0.,0.03);
  TH1F *histofakeJettemplatepileupnvtxbin3 = new TH1F("histofakeJettemplatepileupnvtxbin3","histofakeJettemplatepileupnvtxbin3",60,0.,0.03);
  TH1F *histofakeJettemplatepileupnvtxbin4 = new TH1F("histofakeJettemplatepileupnvtxbin4","histofakeJettemplatepileupnvtxbin4",60,0.,0.03);
  TH1F *histofakeJettemplatepileupnvtxbin5 = new TH1F("histofakeJettemplatepileupnvtxbin5","histofakeJettemplatepileupnvtxbin5",60,0.,0.03);
  TH1F *histofakeJettemplatepileupnvtxbin6 = new TH1F("histofakeJettemplatepileupnvtxbin6","histofakeJettemplatepileupnvtxbin6",60,0.,0.03);
  TH1F *histofakeJettemplatepileupnvtxbin7 = new TH1F("histofakeJettemplatepileupnvtxbin7","histofakeJettemplatepileupnvtxbin7",60,0.,0.03);
  TH1F *histofakeJettemplatepileupnvtxbin8 = new TH1F("histofakeJettemplatepileupnvtxbin8","histofakeJettemplatepileupnvtxbin8",60,0.,0.03);
  TH1F *histofakeJettemplatepileupnvtxbin9 = new TH1F("histofakeJettemplatepileupnvtxbin9","histofakeJettemplatepileupnvtxbin9",60,0.,0.03);
  TH1F *histofakeJettemplatepileupnvtxbin10 = new TH1F("histofakeJettemplatepileupnvtxbin10","histofakeJettemplatepileupnvtxbin10",60,0.,0.03);

  TH1F *histoTightAndFakeDataJetpileupnvtxbin1 = new TH1F("histoTightAndFakeDataJetpileupnvtxbin1","histoTightAndFakeDataJetpileupnvtxbin1",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileupnvtxbin2 = new TH1F("histoTightAndFakeDataJetpileupnvtxbin2","histoTightAndFakeDataJetpileupnvtxbin2",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileupnvtxbin3 = new TH1F("histoTightAndFakeDataJetpileupnvtxbin3","histoTightAndFakeDataJetpileupnvtxbin3",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileupnvtxbin4 = new TH1F("histoTightAndFakeDataJetpileupnvtxbin4","histoTightAndFakeDataJetpileupnvtxbin4",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileupnvtxbin5 = new TH1F("histoTightAndFakeDataJetpileupnvtxbin5","histoTightAndFakeDataJetpileupnvtxbin5",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileupnvtxbin6 = new TH1F("histoTightAndFakeDataJetpileupnvtxbin6","histoTightAndFakeDataJetpileupnvtxbin6",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileupnvtxbin7 = new TH1F("histoTightAndFakeDataJetpileupnvtxbin7","histoTightAndFakeDataJetpileupnvtxbin7",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileupnvtxbin8 = new TH1F("histoTightAndFakeDataJetpileupnvtxbin8","histoTightAndFakeDataJetpileupnvtxbin8",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileupnvtxbin9 = new TH1F("histoTightAndFakeDataJetpileupnvtxbin9","histoTightAndFakeDataJetpileupnvtxbin9",60,0.,0.03);
  TH1F *histoTightAndFakeDataJetpileupnvtxbin10 = new TH1F("histoTightAndFakeDataJetpileupnvtxbin10","histoTightAndFakeDataJetpileupnvtxbin10",60,0.,0.03);


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
    //if(jentry == 500000) break;

    for(int i=0;i<10;i++) {
      Bool_t towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
      Bool_t CHisocut = (Photon_rhocorPFIsoCharged03[i] < 0.7);
      Bool_t NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 0.4 + 0.04 * Photon_pt[i]);
      Bool_t PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.5 + 0.005 * Photon_pt[i]);
      Bool_t barrelcut = (Photon_isEB[i]);
      Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
      Bool_t isfakeable = (Photon_isPFFakeable[i]);
      Bool_t haspromptelec = (Photon_hasMatchedPromptElectron[i]);

      Bool_t pileuprhobin1 = (rho25 > 0. && rho25 < 5.);
      Bool_t pileuprhobin2 = (rho25 > 5. && rho25 < 10.);
      Bool_t pileuprhobin3 = (rho25 > 10. && rho25 < 15.);
      Bool_t pileuprhobin4 = (rho25 > 15. && rho25 < 20.);
      Bool_t pileuprhobin5 = (rho25 > 20. && rho25 < 25.);
      Bool_t pileuprhobin6 = (rho25 > 25. && rho25 < 30.);
      Bool_t pileuprhobin7 = (rho25 > 30. && rho25 < 35.);
      Bool_t pileuprhobin8 = (rho25 > 35. && rho25 < 40.);
      Bool_t pileuprhobin9 = (rho25 > 40. && rho25 < 45.);
      Bool_t pileuprhobin10 = (rho25 > 45. && rho25 < 50.);

      Bool_t pileupnvtxbin1 = ((Vtx_Nvtx*1.) > 0. && (Vtx_Nvtx*1.) < 5.);
      Bool_t pileupnvtxbin2 = ((Vtx_Nvtx*1.) > 5. && (Vtx_Nvtx*1.) < 10.);
      Bool_t pileupnvtxbin3 = ((Vtx_Nvtx*1.) > 10. && (Vtx_Nvtx*1.) < 15.);
      Bool_t pileupnvtxbin4 = ((Vtx_Nvtx*1.) > 15. && (Vtx_Nvtx*1.) < 20.);
      Bool_t pileupnvtxbin5 = ((Vtx_Nvtx*1.) > 20. && (Vtx_Nvtx*1.) < 25.);
      Bool_t pileupnvtxbin6 = ((Vtx_Nvtx*1.) > 25. && (Vtx_Nvtx*1.) < 30.);
      Bool_t pileupnvtxbin7 = ((Vtx_Nvtx*1.) > 30. && (Vtx_Nvtx*1.) < 35.);
      Bool_t pileupnvtxbin8 = ((Vtx_Nvtx*1.) > 35. && (Vtx_Nvtx*1.) < 40.);
      Bool_t pileupnvtxbin9 = ((Vtx_Nvtx*1.) > 40. && (Vtx_Nvtx*1.) < 45.);
      Bool_t pileupnvtxbin10 = ((Vtx_Nvtx*1.) > 45. && (Vtx_Nvtx*1.) < 50.);

      Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
      Bool_t gapcut = Photon_isEBEEGap[i];
      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

      //put this to go faster but be careful
      if(!ptcut) continue;
      if(!siphiiphicut) continue;
      if(gapcut) continue;
      if(rechitflagcut) continue;

      //if(abs(Photon_eta[i]) > 0.9) continue;
      //if(abs(Photon_eta[i]) < 0.9) continue;

      //this is the sinin template for numerator containing both real and fake components
      //if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
      if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  if(pileuprhobin1) histoDataJetpileuprhobin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin2) histoDataJetpileuprhobin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin3) histoDataJetpileuprhobin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin4) histoDataJetpileuprhobin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin5) histoDataJetpileuprhobin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin6) histoDataJetpileuprhobin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin7) histoDataJetpileuprhobin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin8) histoDataJetpileuprhobin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin9) histoDataJetpileuprhobin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin10) histoDataJetpileuprhobin10->Fill(Photon_sigmaIetaIeta[i]);

	  if(pileupnvtxbin1) histoDataJetpileupnvtxbin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin2) histoDataJetpileupnvtxbin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin3) histoDataJetpileupnvtxbin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin4) histoDataJetpileupnvtxbin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin5) histoDataJetpileupnvtxbin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin6) histoDataJetpileupnvtxbin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin7) histoDataJetpileupnvtxbin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin8) histoDataJetpileupnvtxbin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin9) histoDataJetpileupnvtxbin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin10) histoDataJetpileupnvtxbin10->Fill(Photon_sigmaIetaIeta[i]);
	}

      //this is the sinin fake template (inverting track isolation)
      //if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
      if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  if(pileuprhobin1) histofakeJettemplatepileuprhobin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin2) histofakeJettemplatepileuprhobin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin3) histofakeJettemplatepileuprhobin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin4) histofakeJettemplatepileuprhobin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin5) histofakeJettemplatepileuprhobin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin6) histofakeJettemplatepileuprhobin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin7) histofakeJettemplatepileuprhobin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin8) histofakeJettemplatepileuprhobin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin9) histofakeJettemplatepileuprhobin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin10) histofakeJettemplatepileuprhobin10->Fill(Photon_sigmaIetaIeta[i]);

	  if(pileupnvtxbin1) histofakeJettemplatepileupnvtxbin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin2) histofakeJettemplatepileupnvtxbin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin3) histofakeJettemplatepileupnvtxbin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin4) histofakeJettemplatepileupnvtxbin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin5) histofakeJettemplatepileupnvtxbin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin6) histofakeJettemplatepileupnvtxbin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin7) histofakeJettemplatepileupnvtxbin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin8) histofakeJettemplatepileupnvtxbin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin9) histofakeJettemplatepileupnvtxbin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin10) histofakeJettemplatepileupnvtxbin10->Fill(Photon_sigmaIetaIeta[i]);
	}

      //this is the denominator, i.e. the set of fakeable objects
      if(isfakeable && barrelcut && ptcut)
	{
	  if(pileuprhobin1) histoTightAndFakeDataJetpileuprhobin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin2) histoTightAndFakeDataJetpileuprhobin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin3) histoTightAndFakeDataJetpileuprhobin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin4) histoTightAndFakeDataJetpileuprhobin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin5) histoTightAndFakeDataJetpileuprhobin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin6) histoTightAndFakeDataJetpileuprhobin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin7) histoTightAndFakeDataJetpileuprhobin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin8) histoTightAndFakeDataJetpileuprhobin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin9) histoTightAndFakeDataJetpileuprhobin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileuprhobin10) histoTightAndFakeDataJetpileuprhobin10->Fill(Photon_sigmaIetaIeta[i]);

	  if(pileupnvtxbin1) histoTightAndFakeDataJetpileupnvtxbin1->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin2) histoTightAndFakeDataJetpileupnvtxbin2->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin3) histoTightAndFakeDataJetpileupnvtxbin3->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin4) histoTightAndFakeDataJetpileupnvtxbin4->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin5) histoTightAndFakeDataJetpileupnvtxbin5->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin6) histoTightAndFakeDataJetpileupnvtxbin6->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin7) histoTightAndFakeDataJetpileupnvtxbin7->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin8) histoTightAndFakeDataJetpileupnvtxbin8->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin9) histoTightAndFakeDataJetpileupnvtxbin9->Fill(Photon_sigmaIetaIeta[i]);
	  if(pileupnvtxbin10) histoTightAndFakeDataJetpileupnvtxbin10->Fill(Photon_sigmaIetaIeta[i]);
	}

    }//end of loop over photons

  }//end of loop over entries in event

  canvasDataJet->cd();

  histoDataJetpileuprhobin1->Draw();
  canvasDataJet->Print("histoDataJetpileuprhobin1.C","cxx");
  histoDataJetpileuprhobin2->Draw();
  canvasDataJet->Print("histoDataJetpileuprhobin2.C","cxx");
  histoDataJetpileuprhobin3->Draw();
  canvasDataJet->Print("histoDataJetpileuprhobin3.C","cxx");
  histoDataJetpileuprhobin4->Draw();
  canvasDataJet->Print("histoDataJetpileuprhobin4.C","cxx");
  histoDataJetpileuprhobin5->Draw();
  canvasDataJet->Print("histoDataJetpileuprhobin5.C","cxx");
  histoDataJetpileuprhobin6->Draw();
  canvasDataJet->Print("histoDataJetpileuprhobin6.C","cxx");
  histoDataJetpileuprhobin7->Draw();
  canvasDataJet->Print("histoDataJetpileuprhobin7.C","cxx");
  histoDataJetpileuprhobin8->Draw();
  canvasDataJet->Print("histoDataJetpileuprhobin8.C","cxx");
  histoDataJetpileuprhobin9->Draw();
  canvasDataJet->Print("histoDataJetpileuprhobin9.C","cxx");
  histoDataJetpileuprhobin10->Draw();
  canvasDataJet->Print("histoDataJetpileuprhobin10.C","cxx");

  histoDataJetpileupnvtxbin1->Draw();
  canvasDataJet->Print("histoDataJetpileupnvtxbin1.C","cxx");
  histoDataJetpileupnvtxbin2->Draw();
  canvasDataJet->Print("histoDataJetpileupnvtxbin2.C","cxx");
  histoDataJetpileupnvtxbin3->Draw();
  canvasDataJet->Print("histoDataJetpileupnvtxbin3.C","cxx");
  histoDataJetpileupnvtxbin4->Draw();
  canvasDataJet->Print("histoDataJetpileupnvtxbin4.C","cxx");
  histoDataJetpileupnvtxbin5->Draw();
  canvasDataJet->Print("histoDataJetpileupnvtxbin5.C","cxx");
  histoDataJetpileupnvtxbin6->Draw();
  canvasDataJet->Print("histoDataJetpileupnvtxbin6.C","cxx");
  histoDataJetpileupnvtxbin7->Draw();
  canvasDataJet->Print("histoDataJetpileupnvtxbin7.C","cxx");
  histoDataJetpileupnvtxbin8->Draw();
  canvasDataJet->Print("histoDataJetpileupnvtxbin8.C","cxx");
  histoDataJetpileupnvtxbin9->Draw();
  canvasDataJet->Print("histoDataJetpileupnvtxbin9.C","cxx");
  histoDataJetpileupnvtxbin10->Draw();
  canvasDataJet->Print("histoDataJetpileupnvtxbin10.C","cxx");

  canvasfakeJet->cd();

  histofakeJettemplatepileuprhobin1->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileuprhobin1.C","cxx");
  histofakeJettemplatepileuprhobin2->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileuprhobin2.C","cxx");
  histofakeJettemplatepileuprhobin3->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileuprhobin3.C","cxx");
  histofakeJettemplatepileuprhobin4->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileuprhobin4.C","cxx");
  histofakeJettemplatepileuprhobin5->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileuprhobin5.C","cxx");
  histofakeJettemplatepileuprhobin6->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileuprhobin6.C","cxx");
  histofakeJettemplatepileuprhobin7->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileuprhobin7.C","cxx");
  histofakeJettemplatepileuprhobin8->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileuprhobin8.C","cxx");
  histofakeJettemplatepileuprhobin9->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileuprhobin9.C","cxx");
  histofakeJettemplatepileuprhobin10->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileuprhobin10.C","cxx");

  histofakeJettemplatepileupnvtxbin1->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileupnvtxbin1.C","cxx");
  histofakeJettemplatepileupnvtxbin2->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileupnvtxbin2.C","cxx");
  histofakeJettemplatepileupnvtxbin3->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileupnvtxbin3.C","cxx");
  histofakeJettemplatepileupnvtxbin4->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileupnvtxbin4.C","cxx");
  histofakeJettemplatepileupnvtxbin5->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileupnvtxbin5.C","cxx");
  histofakeJettemplatepileupnvtxbin6->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileupnvtxbin6.C","cxx");
  histofakeJettemplatepileupnvtxbin7->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileupnvtxbin7.C","cxx");
  histofakeJettemplatepileupnvtxbin8->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileupnvtxbin8.C","cxx");
  histofakeJettemplatepileupnvtxbin9->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileupnvtxbin9.C","cxx");
  histofakeJettemplatepileupnvtxbin10->Draw();
  canvasfakeJet->Print("histofakeJettemplatepileupnvtxbin10.C","cxx");

  canvasTightAndFakeDataJet->cd();

  histoTightAndFakeDataJetpileuprhobin1->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileuprhobin1.C","cxx");
  histoTightAndFakeDataJetpileuprhobin2->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileuprhobin2.C","cxx");
  histoTightAndFakeDataJetpileuprhobin3->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileuprhobin3.C","cxx");
  histoTightAndFakeDataJetpileuprhobin4->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileuprhobin4.C","cxx");
  histoTightAndFakeDataJetpileuprhobin5->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileuprhobin5.C","cxx");
  histoTightAndFakeDataJetpileuprhobin6->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileuprhobin6.C","cxx");
  histoTightAndFakeDataJetpileuprhobin7->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileuprhobin7.C","cxx");
  histoTightAndFakeDataJetpileuprhobin8->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileuprhobin8.C","cxx");
  histoTightAndFakeDataJetpileuprhobin9->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileuprhobin9.C","cxx");
  histoTightAndFakeDataJetpileuprhobin10->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileuprhobin10.C","cxx");

  histoTightAndFakeDataJetpileupnvtxbin1->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileupnvtxbin1.C","cxx");
  histoTightAndFakeDataJetpileupnvtxbin2->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileupnvtxbin2.C","cxx");
  histoTightAndFakeDataJetpileupnvtxbin3->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileupnvtxbin3.C","cxx");
  histoTightAndFakeDataJetpileupnvtxbin4->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileupnvtxbin4.C","cxx");
  histoTightAndFakeDataJetpileupnvtxbin5->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileupnvtxbin5.C","cxx");
  histoTightAndFakeDataJetpileupnvtxbin6->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileupnvtxbin6.C","cxx");
  histoTightAndFakeDataJetpileupnvtxbin7->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileupnvtxbin7.C","cxx");
  histoTightAndFakeDataJetpileupnvtxbin8->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileupnvtxbin8.C","cxx");
  histoTightAndFakeDataJetpileupnvtxbin9->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileupnvtxbin9.C","cxx");
  histoTightAndFakeDataJetpileupnvtxbin10->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetpileupnvtxbin10.C","cxx");

}//end of method



































































void MyExoTreeJet::LoopSigmaIetaIetaEtaPtBins()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();

  TCanvas *canvasDataJet = new TCanvas("canvasDataJet","canvasDataJet",900,100,500,500);

  Double_t ptrangevalues[21] = {30.,50.,70.,90.,110.,130.,150.,170.,190.,210.,230.,250.,270.,290.,310.,330.,350.,370.,390.,490.,590.};

  const int nbinspt = 10;
  //const int nbinspt = 20;
  float minvaluept = 30.;
  float maxvaluept = 130.;
  float steppt = (maxvaluept - minvaluept)/nbinspt;

  const int nbinseta = 15;
  float minvalueeta = -1.5;
  float maxvalueeta = 1.5;
  float stepeta = (maxvalueeta - minvalueeta)/nbinseta;

  int nbins = 60;
  float minvalue = 0.;
  float maxvalue = 0.03;

  std::vector<std::vector<TH1F*> > histoDataJet;
  std::vector<std::vector<TH1F*> > histoFakeJet;
  std::vector<std::vector<TH1F*> > histoTightAndFakeJet;
  std::vector<std::vector<Bool_t> > etaptbins;

  histoDataJet.resize(nbinseta);
  histoFakeJet.resize(nbinseta);
  histoTightAndFakeJet.resize(nbinseta);
  etaptbins.resize(nbinseta);

  for(int numeta=0;numeta<nbinseta;numeta++) 
    {
      histoDataJet[numeta].resize(nbinspt);
      histoFakeJet[numeta].resize(nbinspt);
      histoTightAndFakeJet[numeta].resize(nbinspt);
      etaptbins[numeta].resize(nbinspt);
    }

  for(int numeta=0;numeta<nbinseta;numeta++) 
    {
      for(int numpt=0;numpt<nbinspt;numpt++) 
	{

	  std::stringstream Datatemplatename;
	  std::stringstream Faketemplatename;
	  std::stringstream TightAndFaketemplatename;
	  
	  Datatemplatename<<"histoDataJetetabin"<<(numeta+1)<<"ptbin"<<(numpt+1);
	  histoDataJet[numeta][numpt] = new TH1F(Datatemplatename.str().c_str(),Datatemplatename.str().c_str(),nbins,minvalue,maxvalue);

	  Faketemplatename<<"histofakeJettemplateetabin"<<(numeta+1)<<"ptbin"<<(numpt+1);
	  histoFakeJet[numeta][numpt] = new TH1F(Faketemplatename.str().c_str(),Faketemplatename.str().c_str(),nbins,minvalue,maxvalue);

	  TightAndFaketemplatename<<"histoTightAndFakeJetetabin"<<(numeta+1)<<"ptbin"<<(numpt+1);
	  histoTightAndFakeJet[numeta][numpt] = new TH1F(TightAndFaketemplatename.str().c_str(),TightAndFaketemplatename.str().c_str(),nbins,minvalue,maxvalue);
	  
	}
    }


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
    //if(jentry == 1) break;

    for(int i=0;i<10;i++) {
      Bool_t towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
      Bool_t CHisocut = (Photon_rhocorPFIsoCharged03[i] < 0.7);
      Bool_t NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 0.4 + 0.04 * Photon_pt[i]);
      Bool_t PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.5 + 0.005 * Photon_pt[i]);
      Bool_t barrelcut = (Photon_isEB[i]);
      Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
      //Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 590.);
      Bool_t isfakeable = (Photon_isPFFakeable[i]);
      Bool_t haspromptelec = (Photon_hasMatchedPromptElectron[i]);

      for(int numeta=0;numeta<nbinseta;numeta++) 
	{
	  //cout<<"eta range ["<<(minvalueeta+numeta*stepeta)<<"-"<<(minvalueeta+(numeta+1)*stepeta)<<endl;
	  for(int numpt=0;numpt<nbinspt;numpt++) 
	    {
	      //cout<<"pt range ["<<(minvaluept+numpt*steppt)<<"-"<<(minvaluept+(numpt+1)*steppt)<<"] ";
	      //cout<<"pt range ["<<ptrangevalues[numpt]<<"-"<<ptrangevalues[numpt+1]<<"] ";
	      Bool_t etabin = ( (Photon_eta[i] > (minvalueeta+numeta*stepeta)) && (Photon_eta[i] < (minvalueeta+(numeta+1)*stepeta)) );
	      Bool_t ptbin = ( (Photon_pt[i] > (minvaluept+numpt*steppt)) && (Photon_pt[i] < (minvaluept+(numpt+1)*steppt)) );
	      //Bool_t ptbin = ( (Photon_pt[i] > ptrangevalues[numpt]) && (Photon_pt[i] < ptrangevalues[numpt+1]) );
	      etaptbins[numeta][numpt] = (etabin && ptbin);
	    }
	  // 	  cout<<""<<endl;
	  // 	  cout<<""<<endl;
	  // 	  cout<<""<<endl;
	}

      Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
      Bool_t gapcut = Photon_isEBEEGap[i];
      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

      //put this to go faster but be careful
      if(!ptcut) continue;
      if(!siphiiphicut) continue;
      if(gapcut) continue;
      if(rechitflagcut) continue;

      //this is the sinin template for numerator containing both real and fake components
      if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  for(int numeta=0;numeta<nbinseta;numeta++) 
	    {
	      for(int numpt=0;numpt<nbinspt;numpt++) 
		{
		  //if(etaptbins[numeta][numpt]) histoDataJet[numeta][numpt].Fill(Photon_sigmaIetaIeta[i]);
		  if(etaptbins[numeta][numpt]) histoDataJet[numeta][numpt]->Fill(Photon_sigmaIetaIeta[i]);
		}
	    }
	}
      
      //this is the sinin fake template (inverting track isolation)
      if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  for(int numeta=0;numeta<nbinseta;numeta++) 
	    {
	      for(int numpt=0;numpt<nbinspt;numpt++) 
		{
		  if(etaptbins[numeta][numpt]) histoFakeJet[numeta][numpt]->Fill(Photon_sigmaIetaIeta[i]);
		}
	    }
	}
      
      //this is the denominator, i.e. the set of fakeable objects
      if(isfakeable && barrelcut && ptcut)
	{
	  for(int numeta=0;numeta<nbinseta;numeta++) 
	    {
	      for(int numpt=0;numpt<nbinspt;numpt++) 
		{
		  if(etaptbins[numeta][numpt]) histoTightAndFakeJet[numeta][numpt]->Fill(Photon_sigmaIetaIeta[i]);
		}
	    }
	}

    }//end of loop over photons
    
  }//end of loop over entries in event

  canvasDataJet->cd();

  for(int numeta=0;numeta<nbinseta;numeta++) 
    {
      for(int numpt=0;numpt<nbinspt;numpt++) 
	{

	  TString Datatemplatename = TString(histoDataJet[numeta][numpt]->GetName())+".C";
	  TString Faketemplatename = TString(histoFakeJet[numeta][numpt]->GetName())+".C";
	  TString TightAndFaketemplatename = TString(histoTightAndFakeJet[numeta][numpt]->GetName())+".C";

	  histoDataJet[numeta][numpt]->Draw();
	  canvasDataJet->Print(Datatemplatename.Data());
	  
	  histoFakeJet[numeta][numpt]->Draw();
	  canvasDataJet->Print(Faketemplatename.Data());
	  
	  histoTightAndFakeJet[numeta][numpt]->Draw();
	  canvasDataJet->Print(TightAndFaketemplatename.Data());
	}
    }


}//end of method




















































void MyExoTreeJet::LoopSigmaIetaIetaPileupPtBins()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();

  TCanvas *canvasDataJet = new TCanvas("canvasDataJet","canvasDataJet",900,100,500,500);

  const int nbinspileup = 10;
  float minvaluepileup = 0.;
  float maxvaluepileup = 50.;
  float steppileup = (maxvaluepileup - minvaluepileup)/nbinspileup;

  const int nbinspt = 10;
  float minvaluept = 30.;
  float maxvaluept = 130.;
  float steppt = (maxvaluept - minvaluept)/nbinspt;

  int nbins = 60;
  float minvalue = 0.;
  float maxvalue = 0.03;

  std::vector<std::vector<TH1F*> > histoDataJet;
  std::vector<std::vector<TH1F*> > histoFakeJet;
  std::vector<std::vector<TH1F*> > histoTightAndFakeJet;
  std::vector<std::vector<Bool_t> > pileupptbins;

  histoDataJet.resize(nbinspileup);
  histoFakeJet.resize(nbinspileup);
  histoTightAndFakeJet.resize(nbinspileup);
  pileupptbins.resize(nbinspileup);

  for(int numpileup=0;numpileup<nbinspileup;numpileup++) 
    {
      histoDataJet[numpileup].resize(nbinspt);
      histoFakeJet[numpileup].resize(nbinspt);
      histoTightAndFakeJet[numpileup].resize(nbinspt);
      pileupptbins[numpileup].resize(nbinspt);
    }

  for(int numpileup=0;numpileup<nbinspileup;numpileup++) 
    {
      for(int numpt=0;numpt<nbinspt;numpt++) 
	{

	  std::stringstream Datatemplatename;
	  std::stringstream Faketemplatename;
	  std::stringstream TightAndFaketemplatename;
	  
	  Datatemplatename<<"histoDataJetpileupbin"<<(numpileup+1)<<"ptbin"<<(numpt+1);
	  histoDataJet[numpileup][numpt] = new TH1F(Datatemplatename.str().c_str(),Datatemplatename.str().c_str(),nbins,minvalue,maxvalue);

	  Faketemplatename<<"histofakeJettemplatepileupbin"<<(numpileup+1)<<"ptbin"<<(numpt+1);
	  histoFakeJet[numpileup][numpt] = new TH1F(Faketemplatename.str().c_str(),Faketemplatename.str().c_str(),nbins,minvalue,maxvalue);

	  TightAndFaketemplatename<<"histoTightAndFakeJetpileupbin"<<(numpileup+1)<<"ptbin"<<(numpt+1);
	  histoTightAndFakeJet[numpileup][numpt] = new TH1F(TightAndFaketemplatename.str().c_str(),TightAndFaketemplatename.str().c_str(),nbins,minvalue,maxvalue);
	  
	}
    }


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
    //if(jentry == 5) break;

    for(int i=0;i<10;i++) {
      Bool_t towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
      Bool_t CHisocut = (Photon_rhocorPFIsoCharged03[i] < 0.7);
      Bool_t NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 0.4 + 0.04 * Photon_pt[i]);
      Bool_t PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.5 + 0.005 * Photon_pt[i]);
      Bool_t barrelcut = (Photon_isEB[i]);
      Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
      Bool_t isfakeable = (Photon_isPFFakeable[i]);
      Bool_t haspromptelec = (Photon_hasMatchedPromptElectron[i]);

      Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
      Bool_t gapcut = Photon_isEBEEGap[i];
      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

      for(int numpileup=0;numpileup<nbinspileup;numpileup++) 
	{
	  //cout<<"pileup range ["<<(minvaluepileup+numpileup*steppileup)<<"-"<<(minvaluepileup+(numpileup+1)*steppileup)<<endl;
	  for(int numpt=0;numpt<nbinspt;numpt++) 
	    {
	      //cout<<"pt range ["<<(minvaluept+numpt*steppt)<<"-"<<(minvaluept+(numpt+1)*steppt)<<"] ";
	      Bool_t pileupbin = ( ((Vtx_Nvtx*1.) > (minvaluepileup+numpileup*steppileup)) && ((Vtx_Nvtx*1.) <= (minvaluepileup+(numpileup+1)*steppileup)) );
	      Bool_t ptbin = ( (Photon_pt[i] > (minvaluept+numpt*steppt)) && (Photon_pt[i] < (minvaluept+(numpt+1)*steppt)) );
	      pileupptbins[numpileup][numpt] = (pileupbin && ptbin);
	    }
	  //cout<<""<<endl;
	  //cout<<""<<endl;
	  //cout<<""<<endl;
	}


      //put this to go faster but be careful
      if(!ptcut) continue;
      if(!siphiiphicut) continue;
      if(gapcut) continue;
      if(rechitflagcut) continue;

      //this is the sinin template for numerator containing both real and fake components
      if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  for(int numpileup=0;numpileup<nbinspileup;numpileup++) 
	    {
	      for(int numpt=0;numpt<nbinspt;numpt++) 
		{
		  //if(pileupptbins[numpileup][numpt]) histoDataJet[numpileup][numpt].Fill(Photon_sigmaIetaIeta[i]);
		  if(pileupptbins[numpileup][numpt]) histoDataJet[numpileup][numpt]->Fill(Photon_sigmaIetaIeta[i]);
		}
	    }
	}
      
      //this is the sinin fake template (inverting track isolation)
      if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  for(int numpileup=0;numpileup<nbinspileup;numpileup++) 
	    {
	      for(int numpt=0;numpt<nbinspt;numpt++) 
		{
		  if(pileupptbins[numpileup][numpt]) histoFakeJet[numpileup][numpt]->Fill(Photon_sigmaIetaIeta[i]);
		}
	    }
	}
      
      //this is the denominator, i.e. the set of fakeable objects
      if(isfakeable && barrelcut && ptcut)
	{
	  for(int numpileup=0;numpileup<nbinspileup;numpileup++) 
	    {
	      for(int numpt=0;numpt<nbinspt;numpt++) 
		{
		  if(pileupptbins[numpileup][numpt]) histoTightAndFakeJet[numpileup][numpt]->Fill(Photon_sigmaIetaIeta[i]);
		}
	    }
	}

    }//end of loop over photons
    
  }//end of loop over entries in event

  canvasDataJet->cd();

  for(int numpileup=0;numpileup<nbinspileup;numpileup++) 
    {
      for(int numpt=0;numpt<nbinspt;numpt++) 
	{

	  TString Datatemplatename = TString(histoDataJet[numpileup][numpt]->GetName())+".C";
	  TString Faketemplatename = TString(histoFakeJet[numpileup][numpt]->GetName())+".C";
	  TString TightAndFaketemplatename = TString(histoTightAndFakeJet[numpileup][numpt]->GetName())+".C";

	  histoDataJet[numpileup][numpt]->Draw();
	  canvasDataJet->Print(Datatemplatename.Data());
	  
	  histoFakeJet[numpileup][numpt]->Draw();
	  canvasDataJet->Print(Faketemplatename.Data());
	  
	  histoTightAndFakeJet[numpileup][numpt]->Draw();
	  canvasDataJet->Print(TightAndFaketemplatename.Data());
	}
    }


}//end of method







































void MyExoTreeJet::LoopSigmaIetaIetaVsMaxRecHitTime()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();

  setPlotStyle();

  TCanvas *canvasDataJet = new TCanvas("canvasDataJet","canvasDataJet",900,100,500,500);
  TCanvas *canvasfakeJet = new TCanvas("canvasfakeJet","canvasfakeJet",900,100,500,500);
  TCanvas *canvasTightAndFakeDataJet = new TCanvas("canvasTightAndFakeDataJet","canvasTightAndFakeDataJet",900,100,500,500);

  //tseed vs sinin
  TH2F *histoTSeedVsSininDataJetptbin1 = new TH2F("histoTSeedVsSininDataJetptbin1","histoTSeedVsSininDataJetptbin1",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininDataJetptbin2 = new TH2F("histoTSeedVsSininDataJetptbin2","histoTSeedVsSininDataJetptbin2",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininDataJetptbin3 = new TH2F("histoTSeedVsSininDataJetptbin3","histoTSeedVsSininDataJetptbin3",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininDataJetptbin4 = new TH2F("histoTSeedVsSininDataJetptbin4","histoTSeedVsSininDataJetptbin4",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininDataJetptbin5 = new TH2F("histoTSeedVsSininDataJetptbin5","histoTSeedVsSininDataJetptbin5",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininDataJetptbin6 = new TH2F("histoTSeedVsSininDataJetptbin6","histoTSeedVsSininDataJetptbin6",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininDataJetptbin7 = new TH2F("histoTSeedVsSininDataJetptbin7","histoTSeedVsSininDataJetptbin7",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininDataJetptbin8 = new TH2F("histoTSeedVsSininDataJetptbin8","histoTSeedVsSininDataJetptbin8",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininDataJetptbin9 = new TH2F("histoTSeedVsSininDataJetptbin9","histoTSeedVsSininDataJetptbin9",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininDataJetptbin10 = new TH2F("histoTSeedVsSininDataJetptbin10","histoTSeedVsSininDataJetptbin10",300,0.,0.03,200,-20.,20.);

  TH2F *histoTSeedVsSininfakeJettemplateptbin1 = new TH2F("histoTSeedVsSininfakeJettemplateptbin1","histoTSeedVsSininfakeJettemplateptbin1",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininfakeJettemplateptbin2 = new TH2F("histoTSeedVsSininfakeJettemplateptbin2","histoTSeedVsSininfakeJettemplateptbin2",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininfakeJettemplateptbin3 = new TH2F("histoTSeedVsSininfakeJettemplateptbin3","histoTSeedVsSininfakeJettemplateptbin3",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininfakeJettemplateptbin4 = new TH2F("histoTSeedVsSininfakeJettemplateptbin4","histoTSeedVsSininfakeJettemplateptbin4",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininfakeJettemplateptbin5 = new TH2F("histoTSeedVsSininfakeJettemplateptbin5","histoTSeedVsSininfakeJettemplateptbin5",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininfakeJettemplateptbin6 = new TH2F("histoTSeedVsSininfakeJettemplateptbin6","histoTSeedVsSininfakeJettemplateptbin6",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininfakeJettemplateptbin7 = new TH2F("histoTSeedVsSininfakeJettemplateptbin7","histoTSeedVsSininfakeJettemplateptbin7",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininfakeJettemplateptbin8 = new TH2F("histoTSeedVsSininfakeJettemplateptbin8","histoTSeedVsSininfakeJettemplateptbin8",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininfakeJettemplateptbin9 = new TH2F("histoTSeedVsSininfakeJettemplateptbin9","histoTSeedVsSininfakeJettemplateptbin9",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininfakeJettemplateptbin10 = new TH2F("histoTSeedVsSininfakeJettemplateptbin10","histoTSeedVsSininfakeJettemplateptbin10",300,0.,0.03,200,-20.,20.);

  TH2F *histoTSeedVsSininTightAndFakeDataJetptbin1 = new TH2F("histoTSeedVsSininTightAndFakeDataJetptbin1","histoTSeedVsSininTightAndFakeDataJetptbin1",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininTightAndFakeDataJetptbin2 = new TH2F("histoTSeedVsSininTightAndFakeDataJetptbin2","histoTSeedVsSininTightAndFakeDataJetptbin2",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininTightAndFakeDataJetptbin3 = new TH2F("histoTSeedVsSininTightAndFakeDataJetptbin3","histoTSeedVsSininTightAndFakeDataJetptbin3",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininTightAndFakeDataJetptbin4 = new TH2F("histoTSeedVsSininTightAndFakeDataJetptbin4","histoTSeedVsSininTightAndFakeDataJetptbin4",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininTightAndFakeDataJetptbin5 = new TH2F("histoTSeedVsSininTightAndFakeDataJetptbin5","histoTSeedVsSininTightAndFakeDataJetptbin5",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininTightAndFakeDataJetptbin6 = new TH2F("histoTSeedVsSininTightAndFakeDataJetptbin6","histoTSeedVsSininTightAndFakeDataJetptbin6",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininTightAndFakeDataJetptbin7 = new TH2F("histoTSeedVsSininTightAndFakeDataJetptbin7","histoTSeedVsSininTightAndFakeDataJetptbin7",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininTightAndFakeDataJetptbin8 = new TH2F("histoTSeedVsSininTightAndFakeDataJetptbin8","histoTSeedVsSininTightAndFakeDataJetptbin8",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininTightAndFakeDataJetptbin9 = new TH2F("histoTSeedVsSininTightAndFakeDataJetptbin9","histoTSeedVsSininTightAndFakeDataJetptbin9",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSininTightAndFakeDataJetptbin10 = new TH2F("histoTSeedVsSininTightAndFakeDataJetptbin10","histoTSeedVsSininTightAndFakeDataJetptbin10",300,0.,0.03,200,-20.,20.);

  //tseed vs siphiphi
  TH2F *histoTSeedVsSiphiphiDataJetptbin1 = new TH2F("histoTSeedVsSiphiphiDataJetptbin1","histoTSeedVsSiphiphiDataJetptbin1",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiDataJetptbin2 = new TH2F("histoTSeedVsSiphiphiDataJetptbin2","histoTSeedVsSiphiphiDataJetptbin2",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiDataJetptbin3 = new TH2F("histoTSeedVsSiphiphiDataJetptbin3","histoTSeedVsSiphiphiDataJetptbin3",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiDataJetptbin4 = new TH2F("histoTSeedVsSiphiphiDataJetptbin4","histoTSeedVsSiphiphiDataJetptbin4",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiDataJetptbin5 = new TH2F("histoTSeedVsSiphiphiDataJetptbin5","histoTSeedVsSiphiphiDataJetptbin5",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiDataJetptbin6 = new TH2F("histoTSeedVsSiphiphiDataJetptbin6","histoTSeedVsSiphiphiDataJetptbin6",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiDataJetptbin7 = new TH2F("histoTSeedVsSiphiphiDataJetptbin7","histoTSeedVsSiphiphiDataJetptbin7",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiDataJetptbin8 = new TH2F("histoTSeedVsSiphiphiDataJetptbin8","histoTSeedVsSiphiphiDataJetptbin8",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiDataJetptbin9 = new TH2F("histoTSeedVsSiphiphiDataJetptbin9","histoTSeedVsSiphiphiDataJetptbin9",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiDataJetptbin10 = new TH2F("histoTSeedVsSiphiphiDataJetptbin10","histoTSeedVsSiphiphiDataJetptbin10",300,0.,0.03,200,-20.,20.);

  TH2F *histoTSeedVsSiphiphifakeJettemplateptbin1 = new TH2F("histoTSeedVsSiphiphifakeJettemplateptbin1","histoTSeedVsSiphiphifakeJettemplateptbin1",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphifakeJettemplateptbin2 = new TH2F("histoTSeedVsSiphiphifakeJettemplateptbin2","histoTSeedVsSiphiphifakeJettemplateptbin2",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphifakeJettemplateptbin3 = new TH2F("histoTSeedVsSiphiphifakeJettemplateptbin3","histoTSeedVsSiphiphifakeJettemplateptbin3",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphifakeJettemplateptbin4 = new TH2F("histoTSeedVsSiphiphifakeJettemplateptbin4","histoTSeedVsSiphiphifakeJettemplateptbin4",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphifakeJettemplateptbin5 = new TH2F("histoTSeedVsSiphiphifakeJettemplateptbin5","histoTSeedVsSiphiphifakeJettemplateptbin5",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphifakeJettemplateptbin6 = new TH2F("histoTSeedVsSiphiphifakeJettemplateptbin6","histoTSeedVsSiphiphifakeJettemplateptbin6",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphifakeJettemplateptbin7 = new TH2F("histoTSeedVsSiphiphifakeJettemplateptbin7","histoTSeedVsSiphiphifakeJettemplateptbin7",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphifakeJettemplateptbin8 = new TH2F("histoTSeedVsSiphiphifakeJettemplateptbin8","histoTSeedVsSiphiphifakeJettemplateptbin8",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphifakeJettemplateptbin9 = new TH2F("histoTSeedVsSiphiphifakeJettemplateptbin9","histoTSeedVsSiphiphifakeJettemplateptbin9",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphifakeJettemplateptbin10 = new TH2F("histoTSeedVsSiphiphifakeJettemplateptbin10","histoTSeedVsSiphiphifakeJettemplateptbin10",300,0.,0.03,200,-20.,20.);

  TH2F *histoTSeedVsSiphiphiTightAndFakeDataJetptbin1 = new TH2F("histoTSeedVsSiphiphiTightAndFakeDataJetptbin1","histoTSeedVsSiphiphiTightAndFakeDataJetptbin1",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiTightAndFakeDataJetptbin2 = new TH2F("histoTSeedVsSiphiphiTightAndFakeDataJetptbin2","histoTSeedVsSiphiphiTightAndFakeDataJetptbin2",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiTightAndFakeDataJetptbin3 = new TH2F("histoTSeedVsSiphiphiTightAndFakeDataJetptbin3","histoTSeedVsSiphiphiTightAndFakeDataJetptbin3",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiTightAndFakeDataJetptbin4 = new TH2F("histoTSeedVsSiphiphiTightAndFakeDataJetptbin4","histoTSeedVsSiphiphiTightAndFakeDataJetptbin4",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiTightAndFakeDataJetptbin5 = new TH2F("histoTSeedVsSiphiphiTightAndFakeDataJetptbin5","histoTSeedVsSiphiphiTightAndFakeDataJetptbin5",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiTightAndFakeDataJetptbin6 = new TH2F("histoTSeedVsSiphiphiTightAndFakeDataJetptbin6","histoTSeedVsSiphiphiTightAndFakeDataJetptbin6",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiTightAndFakeDataJetptbin7 = new TH2F("histoTSeedVsSiphiphiTightAndFakeDataJetptbin7","histoTSeedVsSiphiphiTightAndFakeDataJetptbin7",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiTightAndFakeDataJetptbin8 = new TH2F("histoTSeedVsSiphiphiTightAndFakeDataJetptbin8","histoTSeedVsSiphiphiTightAndFakeDataJetptbin8",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiTightAndFakeDataJetptbin9 = new TH2F("histoTSeedVsSiphiphiTightAndFakeDataJetptbin9","histoTSeedVsSiphiphiTightAndFakeDataJetptbin9",300,0.,0.03,200,-20.,20.);
  TH2F *histoTSeedVsSiphiphiTightAndFakeDataJetptbin10 = new TH2F("histoTSeedVsSiphiphiTightAndFakeDataJetptbin10","histoTSeedVsSiphiphiTightAndFakeDataJetptbin10",300,0.,0.03,200,-20.,20.);

  //siphiiphi vs sinin
  TH2F *histoSiphiiphiVsSininDataJetptbin1 = new TH2F("histoSiphiiphiVsSininDataJetptbin1","histoSiphiiphiVsSininDataJetptbin1",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininDataJetptbin2 = new TH2F("histoSiphiiphiVsSininDataJetptbin2","histoSiphiiphiVsSininDataJetptbin2",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininDataJetptbin3 = new TH2F("histoSiphiiphiVsSininDataJetptbin3","histoSiphiiphiVsSininDataJetptbin3",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininDataJetptbin4 = new TH2F("histoSiphiiphiVsSininDataJetptbin4","histoSiphiiphiVsSininDataJetptbin4",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininDataJetptbin5 = new TH2F("histoSiphiiphiVsSininDataJetptbin5","histoSiphiiphiVsSininDataJetptbin5",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininDataJetptbin6 = new TH2F("histoSiphiiphiVsSininDataJetptbin6","histoSiphiiphiVsSininDataJetptbin6",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininDataJetptbin7 = new TH2F("histoSiphiiphiVsSininDataJetptbin7","histoSiphiiphiVsSininDataJetptbin7",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininDataJetptbin8 = new TH2F("histoSiphiiphiVsSininDataJetptbin8","histoSiphiiphiVsSininDataJetptbin8",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininDataJetptbin9 = new TH2F("histoSiphiiphiVsSininDataJetptbin9","histoSiphiiphiVsSininDataJetptbin9",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininDataJetptbin10 = new TH2F("histoSiphiiphiVsSininDataJetptbin10","histoSiphiiphiVsSininDataJetptbin10",300,0.,0.03,300,0.,0.03);

  TH2F *histoSiphiiphiVsSininfakeJettemplateptbin1 = new TH2F("histoSiphiiphiVsSininfakeJettemplateptbin1","histoSiphiiphiVsSininfakeJettemplateptbin1",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininfakeJettemplateptbin2 = new TH2F("histoSiphiiphiVsSininfakeJettemplateptbin2","histoSiphiiphiVsSininfakeJettemplateptbin2",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininfakeJettemplateptbin3 = new TH2F("histoSiphiiphiVsSininfakeJettemplateptbin3","histoSiphiiphiVsSininfakeJettemplateptbin3",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininfakeJettemplateptbin4 = new TH2F("histoSiphiiphiVsSininfakeJettemplateptbin4","histoSiphiiphiVsSininfakeJettemplateptbin4",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininfakeJettemplateptbin5 = new TH2F("histoSiphiiphiVsSininfakeJettemplateptbin5","histoSiphiiphiVsSininfakeJettemplateptbin5",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininfakeJettemplateptbin6 = new TH2F("histoSiphiiphiVsSininfakeJettemplateptbin6","histoSiphiiphiVsSininfakeJettemplateptbin6",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininfakeJettemplateptbin7 = new TH2F("histoSiphiiphiVsSininfakeJettemplateptbin7","histoSiphiiphiVsSininfakeJettemplateptbin7",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininfakeJettemplateptbin8 = new TH2F("histoSiphiiphiVsSininfakeJettemplateptbin8","histoSiphiiphiVsSininfakeJettemplateptbin8",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininfakeJettemplateptbin9 = new TH2F("histoSiphiiphiVsSininfakeJettemplateptbin9","histoSiphiiphiVsSininfakeJettemplateptbin9",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininfakeJettemplateptbin10 = new TH2F("histoSiphiiphiVsSininfakeJettemplateptbin10","histoSiphiiphiVsSininfakeJettemplateptbin10",300,0.,0.03,300,0.,0.03);

  TH2F *histoSiphiiphiVsSininTightAndFakeDataJetptbin1 = new TH2F("histoSiphiiphiVsSininTightAndFakeDataJetptbin1","histoSiphiiphiVsSininTightAndFakeDataJetptbin1",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininTightAndFakeDataJetptbin2 = new TH2F("histoSiphiiphiVsSininTightAndFakeDataJetptbin2","histoSiphiiphiVsSininTightAndFakeDataJetptbin2",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininTightAndFakeDataJetptbin3 = new TH2F("histoSiphiiphiVsSininTightAndFakeDataJetptbin3","histoSiphiiphiVsSininTightAndFakeDataJetptbin3",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininTightAndFakeDataJetptbin4 = new TH2F("histoSiphiiphiVsSininTightAndFakeDataJetptbin4","histoSiphiiphiVsSininTightAndFakeDataJetptbin4",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininTightAndFakeDataJetptbin5 = new TH2F("histoSiphiiphiVsSininTightAndFakeDataJetptbin5","histoSiphiiphiVsSininTightAndFakeDataJetptbin5",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininTightAndFakeDataJetptbin6 = new TH2F("histoSiphiiphiVsSininTightAndFakeDataJetptbin6","histoSiphiiphiVsSininTightAndFakeDataJetptbin6",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininTightAndFakeDataJetptbin7 = new TH2F("histoSiphiiphiVsSininTightAndFakeDataJetptbin7","histoSiphiiphiVsSininTightAndFakeDataJetptbin7",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininTightAndFakeDataJetptbin8 = new TH2F("histoSiphiiphiVsSininTightAndFakeDataJetptbin8","histoSiphiiphiVsSininTightAndFakeDataJetptbin8",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininTightAndFakeDataJetptbin9 = new TH2F("histoSiphiiphiVsSininTightAndFakeDataJetptbin9","histoSiphiiphiVsSininTightAndFakeDataJetptbin9",300,0.,0.03,300,0.,0.03);
  TH2F *histoSiphiiphiVsSininTightAndFakeDataJetptbin10 = new TH2F("histoSiphiiphiVsSininTightAndFakeDataJetptbin10","histoSiphiiphiVsSininTightAndFakeDataJetptbin10",300,0.,0.03,300,0.,0.03);

  //swisscross vs sinin
  TH2F *histoSwisscrossVsSininDataJetptbin1 = new TH2F("histoSwisscrossVsSininDataJetptbin1","histoSwisscrossVsSininDataJetptbin1",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininDataJetptbin2 = new TH2F("histoSwisscrossVsSininDataJetptbin2","histoSwisscrossVsSininDataJetptbin2",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininDataJetptbin3 = new TH2F("histoSwisscrossVsSininDataJetptbin3","histoSwisscrossVsSininDataJetptbin3",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininDataJetptbin4 = new TH2F("histoSwisscrossVsSininDataJetptbin4","histoSwisscrossVsSininDataJetptbin4",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininDataJetptbin5 = new TH2F("histoSwisscrossVsSininDataJetptbin5","histoSwisscrossVsSininDataJetptbin5",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininDataJetptbin6 = new TH2F("histoSwisscrossVsSininDataJetptbin6","histoSwisscrossVsSininDataJetptbin6",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininDataJetptbin7 = new TH2F("histoSwisscrossVsSininDataJetptbin7","histoSwisscrossVsSininDataJetptbin7",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininDataJetptbin8 = new TH2F("histoSwisscrossVsSininDataJetptbin8","histoSwisscrossVsSininDataJetptbin8",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininDataJetptbin9 = new TH2F("histoSwisscrossVsSininDataJetptbin9","histoSwisscrossVsSininDataJetptbin9",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininDataJetptbin10 = new TH2F("histoSwisscrossVsSininDataJetptbin10","histoSwisscrossVsSininDataJetptbin10",300,0.,0.03,200,-10.,10.);

  TH2F *histoSwisscrossVsSininfakeJettemplateptbin1 = new TH2F("histoSwisscrossVsSininfakeJettemplateptbin1","histoSwisscrossVsSininfakeJettemplateptbin1",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininfakeJettemplateptbin2 = new TH2F("histoSwisscrossVsSininfakeJettemplateptbin2","histoSwisscrossVsSininfakeJettemplateptbin2",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininfakeJettemplateptbin3 = new TH2F("histoSwisscrossVsSininfakeJettemplateptbin3","histoSwisscrossVsSininfakeJettemplateptbin3",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininfakeJettemplateptbin4 = new TH2F("histoSwisscrossVsSininfakeJettemplateptbin4","histoSwisscrossVsSininfakeJettemplateptbin4",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininfakeJettemplateptbin5 = new TH2F("histoSwisscrossVsSininfakeJettemplateptbin5","histoSwisscrossVsSininfakeJettemplateptbin5",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininfakeJettemplateptbin6 = new TH2F("histoSwisscrossVsSininfakeJettemplateptbin6","histoSwisscrossVsSininfakeJettemplateptbin6",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininfakeJettemplateptbin7 = new TH2F("histoSwisscrossVsSininfakeJettemplateptbin7","histoSwisscrossVsSininfakeJettemplateptbin7",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininfakeJettemplateptbin8 = new TH2F("histoSwisscrossVsSininfakeJettemplateptbin8","histoSwisscrossVsSininfakeJettemplateptbin8",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininfakeJettemplateptbin9 = new TH2F("histoSwisscrossVsSininfakeJettemplateptbin9","histoSwisscrossVsSininfakeJettemplateptbin9",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininfakeJettemplateptbin10 = new TH2F("histoSwisscrossVsSininfakeJettemplateptbin10","histoSwisscrossVsSininfakeJettemplateptbin10",300,0.,0.03,200,-10.,10.);

  TH2F *histoSwisscrossVsSininTightAndFakeDataJetptbin1 = new TH2F("histoSwisscrossVsSininTightAndFakeDataJetptbin1","histoSwisscrossVsSininTightAndFakeDataJetptbin1",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininTightAndFakeDataJetptbin2 = new TH2F("histoSwisscrossVsSininTightAndFakeDataJetptbin2","histoSwisscrossVsSininTightAndFakeDataJetptbin2",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininTightAndFakeDataJetptbin3 = new TH2F("histoSwisscrossVsSininTightAndFakeDataJetptbin3","histoSwisscrossVsSininTightAndFakeDataJetptbin3",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininTightAndFakeDataJetptbin4 = new TH2F("histoSwisscrossVsSininTightAndFakeDataJetptbin4","histoSwisscrossVsSininTightAndFakeDataJetptbin4",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininTightAndFakeDataJetptbin5 = new TH2F("histoSwisscrossVsSininTightAndFakeDataJetptbin5","histoSwisscrossVsSininTightAndFakeDataJetptbin5",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininTightAndFakeDataJetptbin6 = new TH2F("histoSwisscrossVsSininTightAndFakeDataJetptbin6","histoSwisscrossVsSininTightAndFakeDataJetptbin6",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininTightAndFakeDataJetptbin7 = new TH2F("histoSwisscrossVsSininTightAndFakeDataJetptbin7","histoSwisscrossVsSininTightAndFakeDataJetptbin7",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininTightAndFakeDataJetptbin8 = new TH2F("histoSwisscrossVsSininTightAndFakeDataJetptbin8","histoSwisscrossVsSininTightAndFakeDataJetptbin8",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininTightAndFakeDataJetptbin9 = new TH2F("histoSwisscrossVsSininTightAndFakeDataJetptbin9","histoSwisscrossVsSininTightAndFakeDataJetptbin9",300,0.,0.03,200,-10.,10.);
  TH2F *histoSwisscrossVsSininTightAndFakeDataJetptbin10 = new TH2F("histoSwisscrossVsSininTightAndFakeDataJetptbin10","histoSwisscrossVsSininTightAndFakeDataJetptbin10",300,0.,0.03,200,-10.,10.);


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
    //if(jentry == 50) break;

    for(int i=0;i<10;i++) {
      Bool_t towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
      Bool_t CHisocut = (Photon_rhocorPFIsoCharged03[i] < 0.7);
      Bool_t NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 0.4 + 0.04 * Photon_pt[i]);
      Bool_t PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.5 + 0.005 * Photon_pt[i]);
      Bool_t barrelcut = (Photon_isEB[i]);
      Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
      Bool_t isfakeable = (Photon_isPFFakeable[i]);
      Bool_t haspromptelec = (Photon_hasMatchedPromptElectron[i]);

      Bool_t ptbin1 = (Photon_pt[i] > 30. && Photon_pt[i] < 40.);
      Bool_t ptbin2 = (Photon_pt[i] > 40. && Photon_pt[i] < 50.);
      Bool_t ptbin3 = (Photon_pt[i] > 50. && Photon_pt[i] < 60.);
      Bool_t ptbin4 = (Photon_pt[i] > 60. && Photon_pt[i] < 70.);
      Bool_t ptbin5 = (Photon_pt[i] > 70. && Photon_pt[i] < 80.);
      Bool_t ptbin6 = (Photon_pt[i] > 80. && Photon_pt[i] < 90.);
      Bool_t ptbin7 = (Photon_pt[i] > 90. && Photon_pt[i] < 100.);
      Bool_t ptbin8 = (Photon_pt[i] > 100. && Photon_pt[i] < 110.);
      Bool_t ptbin9 = (Photon_pt[i] > 110. && Photon_pt[i] < 120.);
      Bool_t ptbin10 = (Photon_pt[i] > 120. && Photon_pt[i] < 130.);

      Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
      Bool_t gapcut = Photon_isEBEEGap[i];
      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

      //put this to go faster but be careful
      if(!ptcut) continue;
      if(!siphiiphicut) continue;
      if(gapcut) continue;
      if(rechitflagcut) continue;

      //this is the sinin template for numerator containing both real and fake components
      //if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
      if(towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  if(ptbin1) histoTSeedVsSininDataJetptbin1->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin2) histoTSeedVsSininDataJetptbin2->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin3) histoTSeedVsSininDataJetptbin3->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin4) histoTSeedVsSininDataJetptbin4->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin5) histoTSeedVsSininDataJetptbin5->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin6) histoTSeedVsSininDataJetptbin6->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin7) histoTSeedVsSininDataJetptbin7->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin8) histoTSeedVsSininDataJetptbin8->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin9) histoTSeedVsSininDataJetptbin9->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin10) histoTSeedVsSininDataJetptbin10->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);

	  if(ptbin1) histoTSeedVsSiphiphiDataJetptbin1->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin2) histoTSeedVsSiphiphiDataJetptbin2->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin3) histoTSeedVsSiphiphiDataJetptbin3->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin4) histoTSeedVsSiphiphiDataJetptbin4->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin5) histoTSeedVsSiphiphiDataJetptbin5->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin6) histoTSeedVsSiphiphiDataJetptbin6->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin7) histoTSeedVsSiphiphiDataJetptbin7->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin8) histoTSeedVsSiphiphiDataJetptbin8->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin9) histoTSeedVsSiphiphiDataJetptbin9->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin10) histoTSeedVsSiphiphiDataJetptbin10->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);

	  if(ptbin1) histoSiphiiphiVsSininDataJetptbin1->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin2) histoSiphiiphiVsSininDataJetptbin2->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin3) histoSiphiiphiVsSininDataJetptbin3->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin4) histoSiphiiphiVsSininDataJetptbin4->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin5) histoSiphiiphiVsSininDataJetptbin5->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin6) histoSiphiiphiVsSininDataJetptbin6->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin7) histoSiphiiphiVsSininDataJetptbin7->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin8) histoSiphiiphiVsSininDataJetptbin8->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin9) histoSiphiiphiVsSininDataJetptbin9->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin10) histoSiphiiphiVsSininDataJetptbin10->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);

	  if(ptbin1) histoSwisscrossVsSininDataJetptbin1->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin2) histoSwisscrossVsSininDataJetptbin2->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin3) histoSwisscrossVsSininDataJetptbin3->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin4) histoSwisscrossVsSininDataJetptbin4->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin5) histoSwisscrossVsSininDataJetptbin5->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin6) histoSwisscrossVsSininDataJetptbin6->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin7) histoSwisscrossVsSininDataJetptbin7->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin8) histoSwisscrossVsSininDataJetptbin8->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin9) histoSwisscrossVsSininDataJetptbin9->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin10) histoSwisscrossVsSininDataJetptbin10->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);

	}

      //this is the sinin fake template (inverting track isolation)
      //if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
      if(towerhoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
	{
	  if(ptbin1) histoTSeedVsSininfakeJettemplateptbin1->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin2) histoTSeedVsSininfakeJettemplateptbin2->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin3) histoTSeedVsSininfakeJettemplateptbin3->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin4) histoTSeedVsSininfakeJettemplateptbin4->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin5) histoTSeedVsSininfakeJettemplateptbin5->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin6) histoTSeedVsSininfakeJettemplateptbin6->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin7) histoTSeedVsSininfakeJettemplateptbin7->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin8) histoTSeedVsSininfakeJettemplateptbin8->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin9) histoTSeedVsSininfakeJettemplateptbin9->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin10) histoTSeedVsSininfakeJettemplateptbin10->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);

	  if(ptbin1) histoTSeedVsSiphiphifakeJettemplateptbin1->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin2) histoTSeedVsSiphiphifakeJettemplateptbin2->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin3) histoTSeedVsSiphiphifakeJettemplateptbin3->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin4) histoTSeedVsSiphiphifakeJettemplateptbin4->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin5) histoTSeedVsSiphiphifakeJettemplateptbin5->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin6) histoTSeedVsSiphiphifakeJettemplateptbin6->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin7) histoTSeedVsSiphiphifakeJettemplateptbin7->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin8) histoTSeedVsSiphiphifakeJettemplateptbin8->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin9) histoTSeedVsSiphiphifakeJettemplateptbin9->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin10) histoTSeedVsSiphiphifakeJettemplateptbin10->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);

	  if(ptbin1) histoSiphiiphiVsSininfakeJettemplateptbin1->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin2) histoSiphiiphiVsSininfakeJettemplateptbin2->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin3) histoSiphiiphiVsSininfakeJettemplateptbin3->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin4) histoSiphiiphiVsSininfakeJettemplateptbin4->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin5) histoSiphiiphiVsSininfakeJettemplateptbin5->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin6) histoSiphiiphiVsSininfakeJettemplateptbin6->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin7) histoSiphiiphiVsSininfakeJettemplateptbin7->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin8) histoSiphiiphiVsSininfakeJettemplateptbin8->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin9) histoSiphiiphiVsSininfakeJettemplateptbin9->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin10) histoSiphiiphiVsSininfakeJettemplateptbin10->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);

	  if(ptbin1) histoSwisscrossVsSininfakeJettemplateptbin1->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin2) histoSwisscrossVsSininfakeJettemplateptbin2->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin3) histoSwisscrossVsSininfakeJettemplateptbin3->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin4) histoSwisscrossVsSininfakeJettemplateptbin4->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin5) histoSwisscrossVsSininfakeJettemplateptbin5->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin6) histoSwisscrossVsSininfakeJettemplateptbin6->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin7) histoSwisscrossVsSininfakeJettemplateptbin7->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin8) histoSwisscrossVsSininfakeJettemplateptbin8->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin9) histoSwisscrossVsSininfakeJettemplateptbin9->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin10) histoSwisscrossVsSininfakeJettemplateptbin10->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);

	}

      //this is the denominator, i.e. the set of fakeable objects
      if(isfakeable && barrelcut && ptcut)
	{
	  if(ptbin1) histoTSeedVsSininTightAndFakeDataJetptbin1->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin2) histoTSeedVsSininTightAndFakeDataJetptbin2->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin3) histoTSeedVsSininTightAndFakeDataJetptbin3->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin4) histoTSeedVsSininTightAndFakeDataJetptbin4->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin5) histoTSeedVsSininTightAndFakeDataJetptbin5->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin6) histoTSeedVsSininTightAndFakeDataJetptbin6->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin7) histoTSeedVsSininTightAndFakeDataJetptbin7->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin8) histoTSeedVsSininTightAndFakeDataJetptbin8->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin9) histoTSeedVsSininTightAndFakeDataJetptbin9->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);
	  if(ptbin10) histoTSeedVsSininTightAndFakeDataJetptbin10->Fill(Photon_sigmaIetaIeta[i],Photon_maxRecHitTime[i]);

	  if(ptbin1) histoTSeedVsSiphiphiTightAndFakeDataJetptbin1->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin2) histoTSeedVsSiphiphiTightAndFakeDataJetptbin2->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin3) histoTSeedVsSiphiphiTightAndFakeDataJetptbin3->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin4) histoTSeedVsSiphiphiTightAndFakeDataJetptbin4->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin5) histoTSeedVsSiphiphiTightAndFakeDataJetptbin5->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin6) histoTSeedVsSiphiphiTightAndFakeDataJetptbin6->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin7) histoTSeedVsSiphiphiTightAndFakeDataJetptbin7->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin8) histoTSeedVsSiphiphiTightAndFakeDataJetptbin8->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin9) histoTSeedVsSiphiphiTightAndFakeDataJetptbin9->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);
	  if(ptbin10) histoTSeedVsSiphiphiTightAndFakeDataJetptbin10->Fill(Photon_sigmaIphiIphi[i],Photon_maxRecHitTime[i]);

	  if(ptbin1) histoSiphiiphiVsSininTightAndFakeDataJetptbin1->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin2) histoSiphiiphiVsSininTightAndFakeDataJetptbin2->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin3) histoSiphiiphiVsSininTightAndFakeDataJetptbin3->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin4) histoSiphiiphiVsSininTightAndFakeDataJetptbin4->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin5) histoSiphiiphiVsSininTightAndFakeDataJetptbin5->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin6) histoSiphiiphiVsSininTightAndFakeDataJetptbin6->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin7) histoSiphiiphiVsSininTightAndFakeDataJetptbin7->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin8) histoSiphiiphiVsSininTightAndFakeDataJetptbin8->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin9) histoSiphiiphiVsSininTightAndFakeDataJetptbin9->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);
	  if(ptbin10) histoSiphiiphiVsSininTightAndFakeDataJetptbin10->Fill(Photon_sigmaIetaIeta[i],Photon_sigmaIphiIphi[i]);

	  if(ptbin1) histoSwisscrossVsSininTightAndFakeDataJetptbin1->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin2) histoSwisscrossVsSininTightAndFakeDataJetptbin2->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin3) histoSwisscrossVsSininTightAndFakeDataJetptbin3->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin4) histoSwisscrossVsSininTightAndFakeDataJetptbin4->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin5) histoSwisscrossVsSininTightAndFakeDataJetptbin5->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin6) histoSwisscrossVsSininTightAndFakeDataJetptbin6->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin7) histoSwisscrossVsSininTightAndFakeDataJetptbin7->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin8) histoSwisscrossVsSininTightAndFakeDataJetptbin8->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin9) histoSwisscrossVsSininTightAndFakeDataJetptbin9->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);
	  if(ptbin10) histoSwisscrossVsSininTightAndFakeDataJetptbin10->Fill(Photon_sigmaIetaIeta[i],Photon_swisscross[i]);

	}

    }//end of loop over photons

  }//end of loop over entries in event


  histoSiphiiphiVsSininDataJetptbin1->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininDataJetptbin1->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininDataJetptbin10->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininDataJetptbin10->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininDataJetptbin2->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininDataJetptbin2->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininDataJetptbin3->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininDataJetptbin3->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininDataJetptbin4->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininDataJetptbin4->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininDataJetptbin5->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininDataJetptbin5->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininDataJetptbin6->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininDataJetptbin6->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininDataJetptbin7->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininDataJetptbin7->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininDataJetptbin8->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininDataJetptbin8->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininDataJetptbin9->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininDataJetptbin9->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin1->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin1->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin10->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin10->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin2->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin2->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin3->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin3->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin4->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin4->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin5->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin5->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin6->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin6->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin7->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin7->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin8->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin8->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin9->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin9->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininfakeJettemplateptbin1->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininfakeJettemplateptbin1->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininfakeJettemplateptbin10->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininfakeJettemplateptbin10->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininfakeJettemplateptbin2->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininfakeJettemplateptbin2->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininfakeJettemplateptbin3->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininfakeJettemplateptbin3->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininfakeJettemplateptbin4->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininfakeJettemplateptbin4->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininfakeJettemplateptbin5->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininfakeJettemplateptbin5->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininfakeJettemplateptbin6->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininfakeJettemplateptbin6->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininfakeJettemplateptbin7->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininfakeJettemplateptbin7->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininfakeJettemplateptbin8->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininfakeJettemplateptbin8->SetYTitle("#sigma_{i #phi i #phi}");
  histoSiphiiphiVsSininfakeJettemplateptbin9->SetXTitle("#sigma_{i #eta i #eta}");
  histoSiphiiphiVsSininfakeJettemplateptbin9->SetYTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSininDataJetptbin10->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininDataJetptbin10->SetYTitle("T_{seed}");
  histoTSeedVsSininDataJetptbin2->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininDataJetptbin2->SetYTitle("T_{seed}");
  histoTSeedVsSininDataJetptbin3->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininDataJetptbin3->SetYTitle("T_{seed}");
  histoTSeedVsSininDataJetptbin4->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininDataJetptbin4->SetYTitle("T_{seed}");
  histoTSeedVsSininDataJetptbin5->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininDataJetptbin5->SetYTitle("T_{seed}");
  histoTSeedVsSininDataJetptbin6->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininDataJetptbin6->SetYTitle("T_{seed}");
  histoTSeedVsSininDataJetptbin7->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininDataJetptbin7->SetYTitle("T_{seed}");
  histoTSeedVsSininDataJetptbin8->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininDataJetptbin8->SetYTitle("T_{seed}");
  histoTSeedVsSininDataJetptbin9->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininDataJetptbin9->SetYTitle("T_{seed}");
  histoTSeedVsSininTightAndFakeDataJetptbin1->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininTightAndFakeDataJetptbin1->SetYTitle("T_{seed}");
  histoTSeedVsSininTightAndFakeDataJetptbin10->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininTightAndFakeDataJetptbin10->SetYTitle("T_{seed}");
  histoTSeedVsSininTightAndFakeDataJetptbin2->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininTightAndFakeDataJetptbin2->SetYTitle("T_{seed}");
  histoTSeedVsSininTightAndFakeDataJetptbin3->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininTightAndFakeDataJetptbin3->SetYTitle("T_{seed}");
  histoTSeedVsSininTightAndFakeDataJetptbin4->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininTightAndFakeDataJetptbin4->SetYTitle("T_{seed}");
  histoTSeedVsSininTightAndFakeDataJetptbin5->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininTightAndFakeDataJetptbin5->SetYTitle("T_{seed}");
  histoTSeedVsSininTightAndFakeDataJetptbin6->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininTightAndFakeDataJetptbin6->SetYTitle("T_{seed}");
  histoTSeedVsSininTightAndFakeDataJetptbin7->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininTightAndFakeDataJetptbin7->SetYTitle("T_{seed}");
  histoTSeedVsSininTightAndFakeDataJetptbin8->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininTightAndFakeDataJetptbin8->SetYTitle("T_{seed}");
  histoTSeedVsSininTightAndFakeDataJetptbin9->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininTightAndFakeDataJetptbin9->SetYTitle("T_{seed}");
  histoTSeedVsSininfakeJettemplateptbin1->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininfakeJettemplateptbin1->SetYTitle("T_{seed}");
  histoTSeedVsSininfakeJettemplateptbin10->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininfakeJettemplateptbin10->SetYTitle("T_{seed}");
  histoTSeedVsSininfakeJettemplateptbin2->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininfakeJettemplateptbin2->SetYTitle("T_{seed}");
  histoTSeedVsSininfakeJettemplateptbin3->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininfakeJettemplateptbin3->SetYTitle("T_{seed}");
  histoTSeedVsSininfakeJettemplateptbin4->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininfakeJettemplateptbin4->SetYTitle("T_{seed}");
  histoTSeedVsSininfakeJettemplateptbin5->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininfakeJettemplateptbin5->SetYTitle("T_{seed}");
  histoTSeedVsSininfakeJettemplateptbin6->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininfakeJettemplateptbin6->SetYTitle("T_{seed}");
  histoTSeedVsSininfakeJettemplateptbin7->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininfakeJettemplateptbin7->SetYTitle("T_{seed}");
  histoTSeedVsSininfakeJettemplateptbin8->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininfakeJettemplateptbin8->SetYTitle("T_{seed}");
  histoTSeedVsSininfakeJettemplateptbin9->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininfakeJettemplateptbin9->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiDataJetptbin1->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiDataJetptbin1->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiDataJetptbin10->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiDataJetptbin10->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiDataJetptbin2->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiDataJetptbin2->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiDataJetptbin3->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiDataJetptbin3->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiDataJetptbin4->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiDataJetptbin4->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiDataJetptbin5->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiDataJetptbin5->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiDataJetptbin6->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiDataJetptbin6->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiDataJetptbin7->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiDataJetptbin7->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiDataJetptbin8->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiDataJetptbin8->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiDataJetptbin9->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiDataJetptbin9->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin1->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin1->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin10->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin10->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin2->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin2->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin3->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin3->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin4->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin4->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin5->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin5->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin6->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin6->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin7->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin7->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin8->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin8->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin9->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin9->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphifakeJettemplateptbin1->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphifakeJettemplateptbin1->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphifakeJettemplateptbin10->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphifakeJettemplateptbin10->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphifakeJettemplateptbin2->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphifakeJettemplateptbin2->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphifakeJettemplateptbin3->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphifakeJettemplateptbin3->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphifakeJettemplateptbin4->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphifakeJettemplateptbin4->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphifakeJettemplateptbin5->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphifakeJettemplateptbin5->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphifakeJettemplateptbin6->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphifakeJettemplateptbin6->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphifakeJettemplateptbin7->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphifakeJettemplateptbin7->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphifakeJettemplateptbin8->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphifakeJettemplateptbin8->SetYTitle("T_{seed}");
  histoTSeedVsSiphiphifakeJettemplateptbin9->SetXTitle("#sigma_{i #phi i #phi}");
  histoTSeedVsSiphiphifakeJettemplateptbin9->SetYTitle("T_{seed}");
  histoTSeedVsSininDataJetptbin1->SetXTitle("#sigma_{i #eta i #eta}");
  histoTSeedVsSininDataJetptbin1->SetYTitle("T_{seed}");

  histoSwisscrossVsSininDataJetptbin1->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininDataJetptbin1->SetYTitle("swiss cross");
  histoSwisscrossVsSininDataJetptbin10->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininDataJetptbin10->SetYTitle("swiss cross");
  histoSwisscrossVsSininDataJetptbin2->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininDataJetptbin2->SetYTitle("swiss cross");
  histoSwisscrossVsSininDataJetptbin3->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininDataJetptbin3->SetYTitle("swiss cross");
  histoSwisscrossVsSininDataJetptbin4->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininDataJetptbin4->SetYTitle("swiss cross");
  histoSwisscrossVsSininDataJetptbin5->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininDataJetptbin5->SetYTitle("swiss cross");
  histoSwisscrossVsSininDataJetptbin6->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininDataJetptbin6->SetYTitle("swiss cross");
  histoSwisscrossVsSininDataJetptbin7->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininDataJetptbin7->SetYTitle("swiss cross");
  histoSwisscrossVsSininDataJetptbin8->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininDataJetptbin8->SetYTitle("swiss cross");
  histoSwisscrossVsSininDataJetptbin9->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininDataJetptbin9->SetYTitle("swiss cross");
  histoSwisscrossVsSininTightAndFakeDataJetptbin1->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininTightAndFakeDataJetptbin1->SetYTitle("swiss cross");
  histoSwisscrossVsSininTightAndFakeDataJetptbin10->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininTightAndFakeDataJetptbin10->SetYTitle("swiss cross");
  histoSwisscrossVsSininTightAndFakeDataJetptbin2->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininTightAndFakeDataJetptbin2->SetYTitle("swiss cross");
  histoSwisscrossVsSininTightAndFakeDataJetptbin3->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininTightAndFakeDataJetptbin3->SetYTitle("swiss cross");
  histoSwisscrossVsSininTightAndFakeDataJetptbin4->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininTightAndFakeDataJetptbin4->SetYTitle("swiss cross");
  histoSwisscrossVsSininTightAndFakeDataJetptbin5->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininTightAndFakeDataJetptbin5->SetYTitle("swiss cross");
  histoSwisscrossVsSininTightAndFakeDataJetptbin6->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininTightAndFakeDataJetptbin6->SetYTitle("swiss cross");
  histoSwisscrossVsSininTightAndFakeDataJetptbin7->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininTightAndFakeDataJetptbin7->SetYTitle("swiss cross");
  histoSwisscrossVsSininTightAndFakeDataJetptbin8->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininTightAndFakeDataJetptbin8->SetYTitle("swiss cross");
  histoSwisscrossVsSininTightAndFakeDataJetptbin9->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininTightAndFakeDataJetptbin9->SetYTitle("swiss cross");
  histoSwisscrossVsSininfakeJettemplateptbin1->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininfakeJettemplateptbin1->SetYTitle("swiss cross");
  histoSwisscrossVsSininfakeJettemplateptbin10->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininfakeJettemplateptbin10->SetYTitle("swiss cross");
  histoSwisscrossVsSininfakeJettemplateptbin2->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininfakeJettemplateptbin2->SetYTitle("swiss cross");
  histoSwisscrossVsSininfakeJettemplateptbin3->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininfakeJettemplateptbin3->SetYTitle("swiss cross");
  histoSwisscrossVsSininfakeJettemplateptbin4->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininfakeJettemplateptbin4->SetYTitle("swiss cross");
  histoSwisscrossVsSininfakeJettemplateptbin5->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininfakeJettemplateptbin5->SetYTitle("swiss cross");
  histoSwisscrossVsSininfakeJettemplateptbin6->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininfakeJettemplateptbin6->SetYTitle("swiss cross");
  histoSwisscrossVsSininfakeJettemplateptbin7->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininfakeJettemplateptbin7->SetYTitle("swiss cross");
  histoSwisscrossVsSininfakeJettemplateptbin8->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininfakeJettemplateptbin8->SetYTitle("swiss cross");
  histoSwisscrossVsSininfakeJettemplateptbin9->SetXTitle("#sigma_{i #eta i #eta}");
  histoSwisscrossVsSininfakeJettemplateptbin9->SetYTitle("swiss cross");



  canvasDataJet->cd();
  canvasDataJet->SetLogz(1);
  gStyle->SetNumberContours(50);

  histoTSeedVsSininDataJetptbin1->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin1.C","cxx");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin1.eps","eps");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin1.gif","gif");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin1.png","png");
  histoTSeedVsSininDataJetptbin2->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin2.C","cxx");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin2.eps","eps");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin2.gif","gif");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin2.png","png");
  histoTSeedVsSininDataJetptbin3->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin3.C","cxx");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin3.eps","eps");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin3.gif","gif");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin3.png","png");
  histoTSeedVsSininDataJetptbin4->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin4.C","cxx");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin4.eps","eps");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin4.gif","gif");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin4.png","png");
  histoTSeedVsSininDataJetptbin5->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin5.C","cxx");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin5.eps","eps");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin5.gif","gif");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin5.png","png");
  histoTSeedVsSininDataJetptbin6->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin6.C","cxx");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin6.eps","eps");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin6.gif","gif");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin6.png","png");
  histoTSeedVsSininDataJetptbin7->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin7.C","cxx");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin7.eps","eps");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin7.gif","gif");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin7.png","png");
  histoTSeedVsSininDataJetptbin8->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin8.C","cxx");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin8.eps","eps");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin8.gif","gif");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin8.png","png");
  histoTSeedVsSininDataJetptbin9->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin9.C","cxx");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin9.eps","eps");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin9.gif","gif");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin9.png","png");
  histoTSeedVsSininDataJetptbin10->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin10.C","cxx");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin10.eps","eps");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin10.gif","gif");
  canvasDataJet->Print("histoTSeedVsSininDataJetptbin10.png","png");

  histoTSeedVsSiphiphiDataJetptbin1->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin1.C","cxx");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin1.eps","eps");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin1.gif","gif");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin1.png","png");
  histoTSeedVsSiphiphiDataJetptbin2->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin2.C","cxx");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin2.eps","eps");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin2.gif","gif");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin2.png","png");
  histoTSeedVsSiphiphiDataJetptbin3->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin3.C","cxx");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin3.eps","eps");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin3.gif","gif");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin3.png","png");
  histoTSeedVsSiphiphiDataJetptbin4->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin4.C","cxx");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin4.eps","eps");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin4.gif","gif");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin4.png","png");
  histoTSeedVsSiphiphiDataJetptbin5->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin5.C","cxx");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin5.eps","eps");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin5.gif","gif");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin5.png","png");
  histoTSeedVsSiphiphiDataJetptbin6->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin6.C","cxx");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin6.eps","eps");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin6.gif","gif");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin6.png","png");
  histoTSeedVsSiphiphiDataJetptbin7->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin7.C","cxx");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin7.eps","eps");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin7.gif","gif");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin7.png","png");
  histoTSeedVsSiphiphiDataJetptbin8->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin8.C","cxx");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin8.eps","eps");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin8.gif","gif");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin8.png","png");
  histoTSeedVsSiphiphiDataJetptbin9->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin9.C","cxx");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin9.eps","eps");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin9.gif","gif");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin9.png","png");
  histoTSeedVsSiphiphiDataJetptbin10->Draw("COLZ");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin10.C","cxx");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin10.eps","eps");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin10.gif","gif");
  canvasDataJet->Print("histoTSeedVsSiphiphiDataJetptbin10.png","png");

  histoSiphiiphiVsSininDataJetptbin1->Draw("COLZ");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin1.C","cxx");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin1.eps","eps");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin1.gif","gif");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin1.png","png");
  histoSiphiiphiVsSininDataJetptbin2->Draw("COLZ");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin2.C","cxx");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin2.eps","eps");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin2.gif","gif");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin2.png","png");
  histoSiphiiphiVsSininDataJetptbin3->Draw("COLZ");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin3.C","cxx");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin3.eps","eps");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin3.gif","gif");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin3.png","png");
  histoSiphiiphiVsSininDataJetptbin4->Draw("COLZ");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin4.C","cxx");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin4.eps","eps");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin4.gif","gif");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin4.png","png");
  histoSiphiiphiVsSininDataJetptbin5->Draw("COLZ");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin5.C","cxx");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin5.eps","eps");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin5.gif","gif");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin5.png","png");
  histoSiphiiphiVsSininDataJetptbin6->Draw("COLZ");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin6.C","cxx");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin6.eps","eps");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin6.gif","gif");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin6.png","png");
  histoSiphiiphiVsSininDataJetptbin7->Draw("COLZ");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin7.C","cxx");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin7.eps","eps");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin7.gif","gif");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin7.png","png");
  histoSiphiiphiVsSininDataJetptbin8->Draw("COLZ");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin8.C","cxx");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin8.eps","eps");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin8.gif","gif");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin8.png","png");
  histoSiphiiphiVsSininDataJetptbin9->Draw("COLZ");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin9.C","cxx");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin9.eps","eps");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin9.gif","gif");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin9.png","png");
  histoSiphiiphiVsSininDataJetptbin10->Draw("COLZ");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin10.C","cxx");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin10.eps","eps");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin10.gif","gif");
  canvasDataJet->Print("histoSiphiiphiVsSininDataJetptbin10.png","png");

  histoSwisscrossVsSininDataJetptbin1->Draw("COLZ");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin1.C","cxx");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin1.eps","eps");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin1.gif","gif");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin1.png","png");
  histoSwisscrossVsSininDataJetptbin2->Draw("COLZ");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin2.C","cxx");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin2.eps","eps");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin2.gif","gif");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin2.png","png");
  histoSwisscrossVsSininDataJetptbin3->Draw("COLZ");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin3.C","cxx");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin3.eps","eps");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin3.gif","gif");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin3.png","png");
  histoSwisscrossVsSininDataJetptbin4->Draw("COLZ");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin4.C","cxx");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin4.eps","eps");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin4.gif","gif");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin4.png","png");
  histoSwisscrossVsSininDataJetptbin5->Draw("COLZ");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin5.C","cxx");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin5.eps","eps");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin5.gif","gif");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin5.png","png");
  histoSwisscrossVsSininDataJetptbin6->Draw("COLZ");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin6.C","cxx");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin6.eps","eps");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin6.gif","gif");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin6.png","png");
  histoSwisscrossVsSininDataJetptbin7->Draw("COLZ");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin7.C","cxx");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin7.eps","eps");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin7.gif","gif");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin7.png","png");
  histoSwisscrossVsSininDataJetptbin8->Draw("COLZ");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin8.C","cxx");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin8.eps","eps");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin8.gif","gif");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin8.png","png");
  histoSwisscrossVsSininDataJetptbin9->Draw("COLZ");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin9.C","cxx");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin9.eps","eps");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin9.gif","gif");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin9.png","png");
  histoSwisscrossVsSininDataJetptbin10->Draw("COLZ");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin10.C","cxx");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin10.eps","eps");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin10.gif","gif");
  canvasDataJet->Print("histoSwisscrossVsSininDataJetptbin10.png","png");

  canvasfakeJet->cd();
  canvasfakeJet->SetLogz(1);
  gStyle->SetNumberContours(50);

  histoTSeedVsSininfakeJettemplateptbin1->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin1.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin1.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin1.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin1.png","png");
  histoTSeedVsSininfakeJettemplateptbin2->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin2.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin2.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin2.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin2.png","png");
  histoTSeedVsSininfakeJettemplateptbin3->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin3.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin3.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin3.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin3.png","png");
  histoTSeedVsSininfakeJettemplateptbin4->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin4.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin4.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin4.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin4.png","png");
  histoTSeedVsSininfakeJettemplateptbin5->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin5.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin5.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin5.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin5.png","png");
  histoTSeedVsSininfakeJettemplateptbin6->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin6.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin6.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin6.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin6.png","png");
  histoTSeedVsSininfakeJettemplateptbin7->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin7.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin7.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin7.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin7.png","png");
  histoTSeedVsSininfakeJettemplateptbin8->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin8.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin8.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin8.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin8.png","png");
  histoTSeedVsSininfakeJettemplateptbin9->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin9.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin9.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin9.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin9.png","png");
  histoTSeedVsSininfakeJettemplateptbin10->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin10.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin10.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin10.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSininfakeJettemplateptbin10.png","png");

  histoTSeedVsSiphiphifakeJettemplateptbin1->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin1.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin1.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin1.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin1.png","png");
  histoTSeedVsSiphiphifakeJettemplateptbin2->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin2.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin2.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin2.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin2.png","png");
  histoTSeedVsSiphiphifakeJettemplateptbin3->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin3.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin3.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin3.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin3.png","png");
  histoTSeedVsSiphiphifakeJettemplateptbin4->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin4.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin4.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin4.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin4.png","png");
  histoTSeedVsSiphiphifakeJettemplateptbin5->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin5.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin5.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin5.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin5.png","png");
  histoTSeedVsSiphiphifakeJettemplateptbin6->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin6.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin6.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin6.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin6.png","png");
  histoTSeedVsSiphiphifakeJettemplateptbin7->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin7.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin7.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin7.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin7.png","png");
  histoTSeedVsSiphiphifakeJettemplateptbin8->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin8.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin8.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin8.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin8.png","png");
  histoTSeedVsSiphiphifakeJettemplateptbin9->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin9.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin9.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin9.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin9.png","png");
  histoTSeedVsSiphiphifakeJettemplateptbin10->Draw("COLZ");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin10.C","cxx");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin10.eps","eps");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin10.gif","gif");
  canvasfakeJet->Print("histoTSeedVsSiphiphifakeJettemplateptbin10.png","png");

  histoSiphiiphiVsSininfakeJettemplateptbin1->Draw("COLZ");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin1.C","cxx");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin1.eps","eps");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin1.gif","gif");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin1.png","png");
  histoSiphiiphiVsSininfakeJettemplateptbin2->Draw("COLZ");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin2.C","cxx");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin2.eps","eps");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin2.gif","gif");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin2.png","png");
  histoSiphiiphiVsSininfakeJettemplateptbin3->Draw("COLZ");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin3.C","cxx");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin3.eps","eps");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin3.gif","gif");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin3.png","png");
  histoSiphiiphiVsSininfakeJettemplateptbin4->Draw("COLZ");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin4.C","cxx");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin4.eps","eps");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin4.gif","gif");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin4.png","png");
  histoSiphiiphiVsSininfakeJettemplateptbin5->Draw("COLZ");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin5.C","cxx");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin5.eps","eps");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin5.gif","gif");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin5.png","png");
  histoSiphiiphiVsSininfakeJettemplateptbin6->Draw("COLZ");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin6.C","cxx");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin6.eps","eps");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin6.gif","gif");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin6.png","png");
  histoSiphiiphiVsSininfakeJettemplateptbin7->Draw("COLZ");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin7.C","cxx");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin7.eps","eps");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin7.gif","gif");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin7.png","png");
  histoSiphiiphiVsSininfakeJettemplateptbin8->Draw("COLZ");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin8.C","cxx");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin8.eps","eps");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin8.gif","gif");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin8.png","png");
  histoSiphiiphiVsSininfakeJettemplateptbin9->Draw("COLZ");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin9.C","cxx");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin9.eps","eps");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin9.gif","gif");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin9.png","png");
  histoSiphiiphiVsSininfakeJettemplateptbin10->Draw("COLZ");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin10.C","cxx");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin10.eps","eps");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin10.gif","gif");
  canvasfakeJet->Print("histoSiphiiphiVsSininfakeJettemplateptbin10.png","png");

  histoSwisscrossVsSininfakeJettemplateptbin1->Draw("COLZ");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin1.C","cxx");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin1.eps","eps");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin1.gif","gif");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin1.png","png");
  histoSwisscrossVsSininfakeJettemplateptbin2->Draw("COLZ");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin2.C","cxx");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin2.eps","eps");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin2.gif","gif");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin2.png","png");
  histoSwisscrossVsSininfakeJettemplateptbin3->Draw("COLZ");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin3.C","cxx");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin3.eps","eps");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin3.gif","gif");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin3.png","png");
  histoSwisscrossVsSininfakeJettemplateptbin4->Draw("COLZ");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin4.C","cxx");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin4.eps","eps");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin4.gif","gif");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin4.png","png");
  histoSwisscrossVsSininfakeJettemplateptbin5->Draw("COLZ");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin5.C","cxx");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin5.eps","eps");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin5.gif","gif");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin5.png","png");
  histoSwisscrossVsSininfakeJettemplateptbin6->Draw("COLZ");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin6.C","cxx");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin6.eps","eps");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin6.gif","gif");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin6.png","png");
  histoSwisscrossVsSininfakeJettemplateptbin7->Draw("COLZ");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin7.C","cxx");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin7.eps","eps");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin7.gif","gif");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin7.png","png");
  histoSwisscrossVsSininfakeJettemplateptbin8->Draw("COLZ");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin8.C","cxx");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin8.eps","eps");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin8.gif","gif");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin8.png","png");
  histoSwisscrossVsSininfakeJettemplateptbin9->Draw("COLZ");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin9.C","cxx");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin9.eps","eps");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin9.gif","gif");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin9.png","png");
  histoSwisscrossVsSininfakeJettemplateptbin10->Draw("COLZ");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin10.C","cxx");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin10.eps","eps");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin10.gif","gif");
  canvasfakeJet->Print("histoSwisscrossVsSininfakeJettemplateptbin10.png","png");

  canvasTightAndFakeDataJet->cd();
  canvasTightAndFakeDataJet->SetLogz(1);
  gStyle->SetNumberContours(50);

  histoTSeedVsSininTightAndFakeDataJetptbin1->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin1.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin1.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin1.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin1.png","png");
  histoTSeedVsSininTightAndFakeDataJetptbin2->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin2.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin2.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin2.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin2.png","png");
  histoTSeedVsSininTightAndFakeDataJetptbin3->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin3.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin3.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin3.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin3.png","png");
  histoTSeedVsSininTightAndFakeDataJetptbin4->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin4.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin4.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin4.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin4.png","png");
  histoTSeedVsSininTightAndFakeDataJetptbin5->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin5.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin5.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin5.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin5.png","png");
  histoTSeedVsSininTightAndFakeDataJetptbin6->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin6.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin6.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin6.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin6.png","png");
  histoTSeedVsSininTightAndFakeDataJetptbin7->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin7.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin7.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin7.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin7.png","png");
  histoTSeedVsSininTightAndFakeDataJetptbin8->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin8.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin8.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin8.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin8.png","png");
  histoTSeedVsSininTightAndFakeDataJetptbin9->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin9.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin9.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin9.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin9.png","png");
  histoTSeedVsSininTightAndFakeDataJetptbin10->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin10.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin10.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin10.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSininTightAndFakeDataJetptbin10.png","png");

  histoTSeedVsSiphiphiTightAndFakeDataJetptbin1->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin1.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin1.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin1.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin1.png","png");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin2->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin2.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin2.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin2.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin2.png","png");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin3->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin3.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin3.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin3.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin3.png","png");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin4->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin4.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin4.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin4.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin4.png","png");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin5->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin5.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin5.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin5.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin5.png","png");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin6->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin6.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin6.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin6.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin6.png","png");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin7->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin7.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin7.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin7.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin7.png","png");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin8->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin8.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin8.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin8.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin8.png","png");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin9->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin9.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin9.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin9.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin9.png","png");
  histoTSeedVsSiphiphiTightAndFakeDataJetptbin10->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin10.C","cxx");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin10.eps","eps");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin10.gif","gif");
  canvasTightAndFakeDataJet->Print("histoTSeedVsSiphiphiTightAndFakeDataJetptbin10.png","png");

  histoSiphiiphiVsSininTightAndFakeDataJetptbin1->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin1.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin1.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin1.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin1.png","png");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin2->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin2.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin2.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin2.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin2.png","png");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin3->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin3.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin3.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin3.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin3.png","png");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin4->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin4.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin4.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin4.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin4.png","png");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin5->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin5.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin5.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin5.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin5.png","png");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin6->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin6.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin6.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin6.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin6.png","png");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin7->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin7.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin7.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin7.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin7.png","png");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin8->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin8.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin8.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin8.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin8.png","png");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin9->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin9.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin9.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin9.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin9.png","png");
  histoSiphiiphiVsSininTightAndFakeDataJetptbin10->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin10.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin10.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin10.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSiphiiphiVsSininTightAndFakeDataJetptbin10.png","png");

  histoSwisscrossVsSininTightAndFakeDataJetptbin1->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin1.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin1.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin1.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin1.png","png");
  histoSwisscrossVsSininTightAndFakeDataJetptbin2->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin2.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin2.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin2.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin2.png","png");
  histoSwisscrossVsSininTightAndFakeDataJetptbin3->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin3.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin3.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin3.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin3.png","png");
  histoSwisscrossVsSininTightAndFakeDataJetptbin4->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin4.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin4.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin4.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin4.png","png");
  histoSwisscrossVsSininTightAndFakeDataJetptbin5->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin5.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin5.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin5.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin5.png","png");
  histoSwisscrossVsSininTightAndFakeDataJetptbin6->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin6.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin6.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin6.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin6.png","png");
  histoSwisscrossVsSininTightAndFakeDataJetptbin7->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin7.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin7.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin7.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin7.png","png");
  histoSwisscrossVsSininTightAndFakeDataJetptbin8->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin8.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin8.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin8.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin8.png","png");
  histoSwisscrossVsSininTightAndFakeDataJetptbin9->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin9.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin9.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin9.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin9.png","png");
  histoSwisscrossVsSininTightAndFakeDataJetptbin10->Draw("COLZ");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin10.C","cxx");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin10.eps","eps");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin10.gif","gif");
  canvasTightAndFakeDataJet->Print("histoSwisscrossVsSininTightAndFakeDataJetptbin10.png","png");

}//end of method









void MyExoTreeJet::LoopTrackerIsolation()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();

  TCanvas *canvasDataJet = new TCanvas("canvasDataJet","canvasDataJet",900,100,500,500);
  TCanvas *canvasfakeJet = new TCanvas("canvasfakeJet","canvasfakeJet",900,100,500,500);
  TCanvas *canvasTightAndFakeDataJet = new TCanvas("canvasTightAndFakeDataJet","canvasTightAndFakeDataJet",900,100,500,500);

  TH1F *histoDataJetptbin1 = new TH1F("histoDataJetptbin1","histoDataJetptbin1",200,0.,20.);
  TH1F *histoDataJetptbin2 = new TH1F("histoDataJetptbin2","histoDataJetptbin2",200,0.,20.);
  TH1F *histoDataJetptbin3 = new TH1F("histoDataJetptbin3","histoDataJetptbin3",200,0.,20.);
  TH1F *histoDataJetptbin4 = new TH1F("histoDataJetptbin4","histoDataJetptbin4",200,0.,20.);
  TH1F *histoDataJetptbin5 = new TH1F("histoDataJetptbin5","histoDataJetptbin5",200,0.,20.);
  TH1F *histoDataJetptbin6 = new TH1F("histoDataJetptbin6","histoDataJetptbin6",200,0.,20.);
  TH1F *histoDataJetptbin7 = new TH1F("histoDataJetptbin7","histoDataJetptbin7",200,0.,20.);
  TH1F *histoDataJetptbin8 = new TH1F("histoDataJetptbin8","histoDataJetptbin8",200,0.,20.);
  TH1F *histoDataJetptbin9 = new TH1F("histoDataJetptbin9","histoDataJetptbin9",200,0.,20.);
  TH1F *histoDataJetptbin10 = new TH1F("histoDataJetptbin10","histoDataJetptbin10",200,0.,20.);

  TH1F *histofakeJettemplateptbin1 = new TH1F("histofakeJettemplateptbin1","histofakeJettemplateptbin1",200,0.,20.);
  TH1F *histofakeJettemplateptbin2 = new TH1F("histofakeJettemplateptbin2","histofakeJettemplateptbin2",200,0.,20.);
  TH1F *histofakeJettemplateptbin3 = new TH1F("histofakeJettemplateptbin3","histofakeJettemplateptbin3",200,0.,20.);
  TH1F *histofakeJettemplateptbin4 = new TH1F("histofakeJettemplateptbin4","histofakeJettemplateptbin4",200,0.,20.);
  TH1F *histofakeJettemplateptbin5 = new TH1F("histofakeJettemplateptbin5","histofakeJettemplateptbin5",200,0.,20.);
  TH1F *histofakeJettemplateptbin6 = new TH1F("histofakeJettemplateptbin6","histofakeJettemplateptbin6",200,0.,20.);
  TH1F *histofakeJettemplateptbin7 = new TH1F("histofakeJettemplateptbin7","histofakeJettemplateptbin7",200,0.,20.);
  TH1F *histofakeJettemplateptbin8 = new TH1F("histofakeJettemplateptbin8","histofakeJettemplateptbin8",200,0.,20.);
  TH1F *histofakeJettemplateptbin9 = new TH1F("histofakeJettemplateptbin9","histofakeJettemplateptbin9",200,0.,20.);
  TH1F *histofakeJettemplateptbin10 = new TH1F("histofakeJettemplateptbin10","histofakeJettemplateptbin10",200,0.,20.);

  TH1F *histoTightAndFakeDataJetptbin1 = new TH1F("histoTightAndFakeDataJetptbin1","histoTightAndFakeDataJetptbin1",200,0.,20.);
  TH1F *histoTightAndFakeDataJetptbin2 = new TH1F("histoTightAndFakeDataJetptbin2","histoTightAndFakeDataJetptbin2",200,0.,20.);
  TH1F *histoTightAndFakeDataJetptbin3 = new TH1F("histoTightAndFakeDataJetptbin3","histoTightAndFakeDataJetptbin3",200,0.,20.);
  TH1F *histoTightAndFakeDataJetptbin4 = new TH1F("histoTightAndFakeDataJetptbin4","histoTightAndFakeDataJetptbin4",200,0.,20.);
  TH1F *histoTightAndFakeDataJetptbin5 = new TH1F("histoTightAndFakeDataJetptbin5","histoTightAndFakeDataJetptbin5",200,0.,20.);
  TH1F *histoTightAndFakeDataJetptbin6 = new TH1F("histoTightAndFakeDataJetptbin6","histoTightAndFakeDataJetptbin6",200,0.,20.);
  TH1F *histoTightAndFakeDataJetptbin7 = new TH1F("histoTightAndFakeDataJetptbin7","histoTightAndFakeDataJetptbin7",200,0.,20.);
  TH1F *histoTightAndFakeDataJetptbin8 = new TH1F("histoTightAndFakeDataJetptbin8","histoTightAndFakeDataJetptbin8",200,0.,20.);
  TH1F *histoTightAndFakeDataJetptbin9 = new TH1F("histoTightAndFakeDataJetptbin9","histoTightAndFakeDataJetptbin9",200,0.,20.);
  TH1F *histoTightAndFakeDataJetptbin10 = new TH1F("histoTightAndFakeDataJetptbin10","histoTightAndFakeDataJetptbin10",200,0.,20.);


  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
    //if(jentry == 5000000) break;

    for(int i=0;i<10;i++) {
      Bool_t towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
      Bool_t CHisocut = (Photon_rhocorPFIsoCharged03[i] < 0.7);
      Bool_t NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 0.4 + 0.04 * Photon_pt[i]);
      Bool_t PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.5 + 0.005 * Photon_pt[i]);
      Bool_t barrelcut = (Photon_isEB[i]);
      Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
      Bool_t isfakeable = (Photon_isPFFakeable[i]);
      Bool_t haspromptelec = (Photon_hasMatchedPromptElectron[i]);

      Bool_t sietaietacut = (Photon_sigmaIetaIeta[i] < 0.011);

      Bool_t ptbin1 = (Photon_pt[i] > 30. && Photon_pt[i] < 40.);
      Bool_t ptbin2 = (Photon_pt[i] > 40. && Photon_pt[i] < 50.);
      Bool_t ptbin3 = (Photon_pt[i] > 50. && Photon_pt[i] < 60.);
      Bool_t ptbin4 = (Photon_pt[i] > 60. && Photon_pt[i] < 70.);
      Bool_t ptbin5 = (Photon_pt[i] > 70. && Photon_pt[i] < 80.);
      Bool_t ptbin6 = (Photon_pt[i] > 80. && Photon_pt[i] < 90.);
      Bool_t ptbin7 = (Photon_pt[i] > 90. && Photon_pt[i] < 100.);
      Bool_t ptbin8 = (Photon_pt[i] > 100. && Photon_pt[i] < 110.);
      Bool_t ptbin9 = (Photon_pt[i] > 110. && Photon_pt[i] < 120.);
      Bool_t ptbin10 = (Photon_pt[i] > 120. && Photon_pt[i] < 130.);

      Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
      Bool_t gapcut = Photon_isEBEEGap[i];
      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

      //put this to go faster but be careful
      if(!ptcut) continue;
      if(!siphiiphicut) continue;
      if(gapcut) continue;
      if(rechitflagcut) continue;

      //this is the track iso template for numerator containing both real and fake components
      if(towerhoecut && sietaietacut && NHisocut && PHisocut && barrelcut && ptcut && !haspromptelec)
	{
	  if(ptbin1) histoDataJetptbin1->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin2) histoDataJetptbin2->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin3) histoDataJetptbin3->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin4) histoDataJetptbin4->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin5) histoDataJetptbin5->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin6) histoDataJetptbin6->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin7) histoDataJetptbin7->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin8) histoDataJetptbin8->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin9) histoDataJetptbin9->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin10) histoDataJetptbin10->Fill(Photon_PFIsoCharged03[i]);
	}

      //this is the sinin fake template (inverting track isolation)
      if(towerhoecut && !sietaietacut && NHisocut && PHisocut && barrelcut && ptcut && !haspromptelec)
	{
	  if(ptbin1) histofakeJettemplateptbin1->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin2) histofakeJettemplateptbin2->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin3) histofakeJettemplateptbin3->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin4) histofakeJettemplateptbin4->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin5) histofakeJettemplateptbin5->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin6) histofakeJettemplateptbin6->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin7) histofakeJettemplateptbin7->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin8) histofakeJettemplateptbin8->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin9) histofakeJettemplateptbin9->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin10) histofakeJettemplateptbin10->Fill(Photon_PFIsoCharged03[i]);
	}

      //this is the denominator, i.e. the set of fakeable objects
      if(isfakeable && barrelcut && ptcut)
	{
	  if(ptbin1) histoTightAndFakeDataJetptbin1->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin2) histoTightAndFakeDataJetptbin2->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin3) histoTightAndFakeDataJetptbin3->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin4) histoTightAndFakeDataJetptbin4->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin5) histoTightAndFakeDataJetptbin5->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin6) histoTightAndFakeDataJetptbin6->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin7) histoTightAndFakeDataJetptbin7->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin8) histoTightAndFakeDataJetptbin8->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin9) histoTightAndFakeDataJetptbin9->Fill(Photon_PFIsoCharged03[i]);
	  if(ptbin10) histoTightAndFakeDataJetptbin10->Fill(Photon_PFIsoCharged03[i]);
	}

    }//end of loop over photons

  }//end of loop over entries in event

  canvasDataJet->cd();

  histoDataJetptbin1->Draw();
  canvasDataJet->Print("histoDataJetptbin1.C","cxx");
  histoDataJetptbin2->Draw();
  canvasDataJet->Print("histoDataJetptbin2.C","cxx");
  histoDataJetptbin3->Draw();
  canvasDataJet->Print("histoDataJetptbin3.C","cxx");
  histoDataJetptbin4->Draw();
  canvasDataJet->Print("histoDataJetptbin4.C","cxx");
  histoDataJetptbin5->Draw();
  canvasDataJet->Print("histoDataJetptbin5.C","cxx");
  histoDataJetptbin6->Draw();
  canvasDataJet->Print("histoDataJetptbin6.C","cxx");
  histoDataJetptbin7->Draw();
  canvasDataJet->Print("histoDataJetptbin7.C","cxx");
  histoDataJetptbin8->Draw();
  canvasDataJet->Print("histoDataJetptbin8.C","cxx");
  histoDataJetptbin9->Draw();
  canvasDataJet->Print("histoDataJetptbin9.C","cxx");
  histoDataJetptbin10->Draw();
  canvasDataJet->Print("histoDataJetptbin10.C","cxx");

  canvasfakeJet->cd();

  histofakeJettemplateptbin1->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin1.C","cxx");
  histofakeJettemplateptbin2->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin2.C","cxx");
  histofakeJettemplateptbin3->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin3.C","cxx");
  histofakeJettemplateptbin4->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin4.C","cxx");
  histofakeJettemplateptbin5->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin5.C","cxx");
  histofakeJettemplateptbin6->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin6.C","cxx");
  histofakeJettemplateptbin7->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin7.C","cxx");
  histofakeJettemplateptbin8->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin8.C","cxx");
  histofakeJettemplateptbin9->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin9.C","cxx");
  histofakeJettemplateptbin10->Draw();
  canvasfakeJet->Print("histofakeJettemplateptbin10.C","cxx");

  canvasTightAndFakeDataJet->cd();

  histoTightAndFakeDataJetptbin1->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin1.C","cxx");
  histoTightAndFakeDataJetptbin2->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin2.C","cxx");
  histoTightAndFakeDataJetptbin3->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin3.C","cxx");
  histoTightAndFakeDataJetptbin4->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin4.C","cxx");
  histoTightAndFakeDataJetptbin5->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin5.C","cxx");
  histoTightAndFakeDataJetptbin6->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin6.C","cxx");
  histoTightAndFakeDataJetptbin7->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin7.C","cxx");
  histoTightAndFakeDataJetptbin8->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin8.C","cxx");
  histoTightAndFakeDataJetptbin9->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin9.C","cxx");
  histoTightAndFakeDataJetptbin10->Draw();
  canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetptbin10.C","cxx");

}//end of method





















// void MyExoTreeJet::LoopSigmaIetaIetaEtaBin()
// {
//   if (fChain == 0) return;

//   Long64_t nentries = fChain->GetEntriesFast();

//   TCanvas *canvasDataJet = new TCanvas("canvasDataJet","canvasDataJet",900,100,500,500);
//   TCanvas *canvasfakeJet = new TCanvas("canvasfakeJet","canvasfakeJet",900,100,500,500);
//   TCanvas *canvasTightAndFakeDataJet = new TCanvas("canvasTightAndFakeDataJet","canvasTightAndFakeDataJet",900,100,500,500);

//   TH1F *histoDataJetetabin1 = new TH1F("histoDataJetetabin1","histoDataJetetabin1",60,0.,0.03);
//   TH1F *histoDataJetetabin2 = new TH1F("histoDataJetetabin2","histoDataJetetabin2",60,0.,0.03);
//   TH1F *histoDataJetetabin3 = new TH1F("histoDataJetetabin3","histoDataJetetabin3",60,0.,0.03);
//   TH1F *histoDataJetetabin4 = new TH1F("histoDataJetetabin4","histoDataJetetabin4",60,0.,0.03);
//   TH1F *histoDataJetetabin5 = new TH1F("histoDataJetetabin5","histoDataJetetabin5",60,0.,0.03);
//   TH1F *histoDataJetetabin6 = new TH1F("histoDataJetetabin6","histoDataJetetabin6",60,0.,0.03);
//   TH1F *histoDataJetetabin7 = new TH1F("histoDataJetetabin7","histoDataJetetabin7",60,0.,0.03);
//   TH1F *histoDataJetetabin8 = new TH1F("histoDataJetetabin8","histoDataJetetabin8",60,0.,0.03);
//   TH1F *histoDataJetetabin9 = new TH1F("histoDataJetetabin9","histoDataJetetabin9",60,0.,0.03);
//   TH1F *histoDataJetetabin10 = new TH1F("histoDataJetetabin10","histoDataJetetabin10",60,0.,0.03);
//   TH1F *histoDataJetetabin11 = new TH1F("histoDataJetetabin11","histoDataJetetabin11",60,0.,0.03);
//   TH1F *histoDataJetetabin12 = new TH1F("histoDataJetetabin12","histoDataJetetabin12",60,0.,0.03);
//   TH1F *histoDataJetetabin13 = new TH1F("histoDataJetetabin13","histoDataJetetabin13",60,0.,0.03);
//   TH1F *histoDataJetetabin14 = new TH1F("histoDataJetetabin14","histoDataJetetabin14",60,0.,0.03);
//   TH1F *histoDataJetetabin15 = new TH1F("histoDataJetetabin15","histoDataJetetabin15",60,0.,0.03);

//   TH1F *histofakeJettemplateetabin1 = new TH1F("histofakeJettemplateetabin1","histofakeJettemplateetabin1",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin2 = new TH1F("histofakeJettemplateetabin2","histofakeJettemplateetabin2",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin3 = new TH1F("histofakeJettemplateetabin3","histofakeJettemplateetabin3",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin4 = new TH1F("histofakeJettemplateetabin4","histofakeJettemplateetabin4",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin5 = new TH1F("histofakeJettemplateetabin5","histofakeJettemplateetabin5",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin6 = new TH1F("histofakeJettemplateetabin6","histofakeJettemplateetabin6",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin7 = new TH1F("histofakeJettemplateetabin7","histofakeJettemplateetabin7",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin8 = new TH1F("histofakeJettemplateetabin8","histofakeJettemplateetabin8",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin9 = new TH1F("histofakeJettemplateetabin9","histofakeJettemplateetabin9",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin10 = new TH1F("histofakeJettemplateetabin10","histofakeJettemplateetabin10",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin11 = new TH1F("histofakeJettemplateetabin11","histofakeJettemplateetabin11",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin12 = new TH1F("histofakeJettemplateetabin12","histofakeJettemplateetabin12",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin13 = new TH1F("histofakeJettemplateetabin13","histofakeJettemplateetabin13",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin14 = new TH1F("histofakeJettemplateetabin14","histofakeJettemplateetabin14",60,0.,0.03);
//   TH1F *histofakeJettemplateetabin15 = new TH1F("histofakeJettemplateetabin15","histofakeJettemplateetabin15",60,0.,0.03);

//   TH1F *histoTightAndFakeDataJetetabin1 = new TH1F("histoTightAndFakeDataJetetabin1","histoTightAndFakeDataJetetabin1",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin2 = new TH1F("histoTightAndFakeDataJetetabin2","histoTightAndFakeDataJetetabin2",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin3 = new TH1F("histoTightAndFakeDataJetetabin3","histoTightAndFakeDataJetetabin3",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin4 = new TH1F("histoTightAndFakeDataJetetabin4","histoTightAndFakeDataJetetabin4",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin5 = new TH1F("histoTightAndFakeDataJetetabin5","histoTightAndFakeDataJetetabin5",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin6 = new TH1F("histoTightAndFakeDataJetetabin6","histoTightAndFakeDataJetetabin6",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin7 = new TH1F("histoTightAndFakeDataJetetabin7","histoTightAndFakeDataJetetabin7",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin8 = new TH1F("histoTightAndFakeDataJetetabin8","histoTightAndFakeDataJetetabin8",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin9 = new TH1F("histoTightAndFakeDataJetetabin9","histoTightAndFakeDataJetetabin9",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin10 = new TH1F("histoTightAndFakeDataJetetabin10","histoTightAndFakeDataJetetabin10",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin11 = new TH1F("histoTightAndFakeDataJetetabin11","histoTightAndFakeDataJetetabin11",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin12 = new TH1F("histoTightAndFakeDataJetetabin12","histoTightAndFakeDataJetetabin12",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin13 = new TH1F("histoTightAndFakeDataJetetabin13","histoTightAndFakeDataJetetabin13",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin14 = new TH1F("histoTightAndFakeDataJetetabin14","histoTightAndFakeDataJetetabin14",60,0.,0.03);
//   TH1F *histoTightAndFakeDataJetetabin15 = new TH1F("histoTightAndFakeDataJetetabin15","histoTightAndFakeDataJetetabin15",60,0.,0.03);


//   Long64_t nbytes = 0, nb = 0;
//   for (Long64_t jentry=0; jentry<nentries;jentry++) {
//     Long64_t ientry = LoadTree(jentry);
//     if (ientry < 0) break;
//     nb = fChain->GetEntry(jentry);   nbytes += nb;
//     // if (Cut(ientry) < 0) continue;

//     if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
//     if(jentry == 5000000) break;

//     for(int i=0;i<10;i++) {
//       Bool_t hoecut = (Photon_hadOverEm[i] < 0.05);
//       Bool_t CHisocut = (Photon_trkIsoSumPtHollow04[i] < 2.0 + 0.001 * Photon_pt[i] + 0.0167*rho25);
//       Bool_t NHisocut = (Photon_hcalIso04[i] < 2.2 + 0.0025*Photon_pt[i]+0.062*rho25);
//       Bool_t PHisocut = (Photon_ecalIso04[i] < 4.2+ 0.006 *Photon_pt[i] + 0.183 *rho25);
//       Bool_t barrelcut = (Photon_isEB[i]);
//       Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
//       Bool_t isfakeable = (Photon_isFakeable[i]);
//       Bool_t haspromptelec = (Photon_haspromptelec[i]);

//       Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
//       Bool_t gapcut = Photon_isEBEEGap[i];
//      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

//       Bool_t etabin1 = (Photon_eta[i] > -1.5 && Photon_eta[i] < -1.3);
//       Bool_t etabin2 = (Photon_eta[i] > -1.3 && Photon_eta[i] < -1.1);
//       Bool_t etabin3 = (Photon_eta[i] > -1.1 && Photon_eta[i] < -0.9);
//       Bool_t etabin4 = (Photon_eta[i] > -0.9 && Photon_eta[i] < -0.7);
//       Bool_t etabin5 = (Photon_eta[i] > -0.7 && Photon_eta[i] < -0.5);
//       Bool_t etabin6 = (Photon_eta[i] > -0.5 && Photon_eta[i] < -0.3);
//       Bool_t etabin7 = (Photon_eta[i] > -0.3 && Photon_eta[i] < -0.1);
//       Bool_t etabin8 = (Photon_eta[i] > -0.1 && Photon_eta[i] < 0.1);
//       Bool_t etabin9 = (Photon_eta[i] > 0.1 && Photon_eta[i] < 0.3);
//       Bool_t etabin10 = (Photon_eta[i] > 0.3 && Photon_eta[i] < 0.5);
//       Bool_t etabin11 = (Photon_eta[i] > 0.5 && Photon_eta[i] < 0.7);
//       Bool_t etabin12 = (Photon_eta[i] > 0.7 && Photon_eta[i] < 0.9);
//       Bool_t etabin13 = (Photon_eta[i] > 0.9 && Photon_eta[i] < 1.1);
//       Bool_t etabin14 = (Photon_eta[i] > 1.1 && Photon_eta[i] < 1.3);
//       Bool_t etabin15 = (Photon_eta[i] > 1.3 && Photon_eta[i] < 1.5);

//       //put this to go faster but be careful
//       if(!ptcut) continue;
//       if(!siphiiphicut) continue;
//       if(gapcut) continue;
//      if(rechitflagcut) continue;

//       //this is the sinin template for numerator containing both real and fake components
//       if(hoecut && CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
// 	{
// 	  if(etabin1) histoDataJetetabin1->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin2) histoDataJetetabin2->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin3) histoDataJetetabin3->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin4) histoDataJetetabin4->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin5) histoDataJetetabin5->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin6) histoDataJetetabin6->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin7) histoDataJetetabin7->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin8) histoDataJetetabin8->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin9) histoDataJetetabin9->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin10) histoDataJetetabin10->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin11) histoDataJetetabin11->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin12) histoDataJetetabin12->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin13) histoDataJetetabin13->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin14) histoDataJetetabin14->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin15) histoDataJetetabin15->Fill(Photon_sigmaIetaIeta[i]);
// 	}

//       //this is the sinin fake template (inverting track isolation)
//       if(hoecut && !CHisocut && NHisocut && PHisocut && barrelcut && ptcut)
// 	{
// 	  if(etabin1) histofakeJettemplateetabin1->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin2) histofakeJettemplateetabin2->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin3) histofakeJettemplateetabin3->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin4) histofakeJettemplateetabin4->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin5) histofakeJettemplateetabin5->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin6) histofakeJettemplateetabin6->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin7) histofakeJettemplateetabin7->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin8) histofakeJettemplateetabin8->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin9) histofakeJettemplateetabin9->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin10) histofakeJettemplateetabin10->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin11) histofakeJettemplateetabin11->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin12) histofakeJettemplateetabin12->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin13) histofakeJettemplateetabin13->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin14) histofakeJettemplateetabin14->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin15) histofakeJettemplateetabin15->Fill(Photon_sigmaIetaIeta[i]);
// 	}

//       //this is the denominator, i.e. the set of fakeable objects
//       if(isfakeable && barrelcut && ptcut)
// 	{
// 	  if(etabin1) histoTightAndFakeDataJetetabin1->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin2) histoTightAndFakeDataJetetabin2->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin3) histoTightAndFakeDataJetetabin3->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin4) histoTightAndFakeDataJetetabin4->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin5) histoTightAndFakeDataJetetabin5->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin6) histoTightAndFakeDataJetetabin6->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin7) histoTightAndFakeDataJetetabin7->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin8) histoTightAndFakeDataJetetabin8->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin9) histoTightAndFakeDataJetetabin9->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin10) histoTightAndFakeDataJetetabin10->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin11) histoTightAndFakeDataJetetabin11->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin12) histoTightAndFakeDataJetetabin12->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin13) histoTightAndFakeDataJetetabin13->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin14) histoTightAndFakeDataJetetabin14->Fill(Photon_sigmaIetaIeta[i]);
// 	  if(etabin15) histoTightAndFakeDataJetetabin15->Fill(Photon_sigmaIetaIeta[i]);
// 	}

//     }//end of loop over photons

//   }//end of loop over entries in event

//   canvasDataJet->cd();

//   histoDataJetetabin1->Draw();
//   canvasDataJet->Print("histoDataJetetabin1.C","cxx");
//   histoDataJetetabin2->Draw();
//   canvasDataJet->Print("histoDataJetetabin2.C","cxx");
//   histoDataJetetabin3->Draw();
//   canvasDataJet->Print("histoDataJetetabin3.C","cxx");
//   histoDataJetetabin4->Draw();
//   canvasDataJet->Print("histoDataJetetabin4.C","cxx");
//   histoDataJetetabin5->Draw();
//   canvasDataJet->Print("histoDataJetetabin5.C","cxx");
//   histoDataJetetabin6->Draw();
//   canvasDataJet->Print("histoDataJetetabin6.C","cxx");
//   histoDataJetetabin7->Draw();
//   canvasDataJet->Print("histoDataJetetabin7.C","cxx");
//   histoDataJetetabin8->Draw();
//   canvasDataJet->Print("histoDataJetetabin8.C","cxx");
//   histoDataJetetabin9->Draw();
//   canvasDataJet->Print("histoDataJetetabin9.C","cxx");
//   histoDataJetetabin10->Draw();
//   canvasDataJet->Print("histoDataJetetabin10.C","cxx");
//   histoDataJetetabin11->Draw();
//   canvasDataJet->Print("histoDataJetetabin11.C","cxx");
//   histoDataJetetabin12->Draw();
//   canvasDataJet->Print("histoDataJetetabin12.C","cxx");
//   histoDataJetetabin13->Draw();
//   canvasDataJet->Print("histoDataJetetabin13.C","cxx");
//   histoDataJetetabin14->Draw();
//   canvasDataJet->Print("histoDataJetetabin14.C","cxx");
//   histoDataJetetabin15->Draw();
//   canvasDataJet->Print("histoDataJetetabin15.C","cxx");

//   canvasfakeJet->cd();

//   histofakeJettemplateetabin1->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin1.C","cxx");
//   histofakeJettemplateetabin2->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin2.C","cxx");
//   histofakeJettemplateetabin3->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin3.C","cxx");
//   histofakeJettemplateetabin4->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin4.C","cxx");
//   histofakeJettemplateetabin5->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin5.C","cxx");
//   histofakeJettemplateetabin6->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin6.C","cxx");
//   histofakeJettemplateetabin7->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin7.C","cxx");
//   histofakeJettemplateetabin8->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin8.C","cxx");
//   histofakeJettemplateetabin9->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin9.C","cxx");
//   histofakeJettemplateetabin10->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin10.C","cxx");
//   histofakeJettemplateetabin11->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin11.C","cxx");
//   histofakeJettemplateetabin12->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin12.C","cxx");
//   histofakeJettemplateetabin13->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin13.C","cxx");
//   histofakeJettemplateetabin14->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin14.C","cxx");
//   histofakeJettemplateetabin15->Draw();
//   canvasfakeJet->Print("histofakeJettemplateetabin15.C","cxx");

//   canvasTightAndFakeDataJet->cd();

//   histoTightAndFakeDataJetetabin1->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin1.C","cxx");
//   histoTightAndFakeDataJetetabin2->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin2.C","cxx");
//   histoTightAndFakeDataJetetabin3->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin3.C","cxx");
//   histoTightAndFakeDataJetetabin4->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin4.C","cxx");
//   histoTightAndFakeDataJetetabin5->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin5.C","cxx");
//   histoTightAndFakeDataJetetabin6->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin6.C","cxx");
//   histoTightAndFakeDataJetetabin7->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin7.C","cxx");
//   histoTightAndFakeDataJetetabin8->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin8.C","cxx");
//   histoTightAndFakeDataJetetabin9->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin9.C","cxx");
//   histoTightAndFakeDataJetetabin10->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin10.C","cxx");
//   histoTightAndFakeDataJetetabin11->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin11.C","cxx");
//   histoTightAndFakeDataJetetabin12->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin12.C","cxx");
//   histoTightAndFakeDataJetetabin13->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin13.C","cxx");
//   histoTightAndFakeDataJetetabin14->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin14.C","cxx");
//   histoTightAndFakeDataJetetabin15->Draw();
//   canvasTightAndFakeDataJet->Print("histoTightAndFakeDataJetetabin15.C","cxx");

// }//end of method







































void MyExoTreeJet::LoopAll(TString method, Int_t limit)
{

  if(!(method.EqualTo("Tight") || method.EqualTo("Medium") || method.EqualTo("Loose"))){
    cout<<"Method not known, please choose: Tight, Medium, Loose."<<endl;
    return;
  }

  cout<<"Method used: "<<method.Data()<<endl;

  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();

  const float PI=3.14159265358979312;
  // int nbinssinin = 60;
  // float minvaluesinin = 0.;
  // float maxvaluesinin = 0.03;

  //for the endcaps
  int nbinssinin = 100;
  float minvaluesinin = 0.;
  float maxvaluesinin = 0.1;

  int nbinschisol = 200;
  float minvaluechisol = 0.;
  float maxvaluechisol = 20.;

  //float ptbinsarray[] = {20.,40.,60.,80.,100.,120.,200.,300.,600.,10000.};
  float ptbinsarray[] = {20.,40.,60.,80.,100.,120.,200.,600.,10000.};
  float etabinsarray[] = {-1.5,-1.3,-1.1,-0.9,-0.7,-0.5,-0.3,-0.1,0.1,0.3,0.5,0.7,0.9,1.1,1.3,1.5};
  float phibinsarray[] = {-180.,-160.,-140.,-120.,-100.,-80.,-60.,-40.,-20.,0.,20.,40.,60.,80.,100.,120.,140.,160.,180.};
  float pubinsarray[] = {0.,10.,15.,20.,25.,50.};

  std::vector<float> ptbins(ptbinsarray,ptbinsarray+sizeof(ptbinsarray)/sizeof(ptbinsarray[0]));
  std::vector<float> etabins(etabinsarray,etabinsarray+sizeof(etabinsarray)/sizeof(etabinsarray[0]));
  std::vector<float> phibins(phibinsarray,phibinsarray+sizeof(phibinsarray)/sizeof(phibinsarray[0]));
  std::vector<float> pubins(pubinsarray,pubinsarray+sizeof(pubinsarray)/sizeof(pubinsarray[0]));

  int nptbins = ptbins.size();
  int netabins = etabins.size();
  int nphibins = phibins.size();
  int npubins = pubins.size();

  //Sinin With Pixel Seed distributions
  std::vector<TH1F*> histoptbinsSininWithPixelSeedDataJet;//Data distribution
  std::vector<TH1F*> histoptbinsSininWithPixelSeedFakeJet;//fake template distribution
  std::vector<TH1F*> histoptbinsSininWithPixelSeedTightAndFakeJet;//denominator distribution

  std::vector<TH2F*> histoptbinsSininWithPixelSeedVsPtDataJet;//Data distribution
  std::vector<TH2F*> histoptbinsSininWithPixelSeedVsPtFakeJet;//fake template distribution
  std::vector<TH2F*> histoptbinsSininWithPixelSeedVsPtTightAndFakeJet;//denominator distribution


  std::vector<TH2F*> histoptbinsSininWithPixelSeedVsCHFakeJet;//fake template distribution

  std::vector<TH1F*> histoetabinsSininWithPixelSeedDataJet;//Data distribution
  std::vector<TH1F*> histoetabinsSininWithPixelSeedFakeJet;//fake template distribution
  std::vector<TH1F*> histoetabinsSininWithPixelSeedTightAndFakeJet;//denominator distribution

  std::vector<TH1F*> histophibinsSininWithPixelSeedDataJet;//Data distribution
  std::vector<TH1F*> histophibinsSininWithPixelSeedFakeJet;//fake template distribution
  std::vector<TH1F*> histophibinsSininWithPixelSeedTightAndFakeJet;//denominator distribution

  std::vector<TH1F*> histopubinsSininWithPixelSeedDataJet;//Data distribution
  std::vector<TH1F*> histopubinsSininWithPixelSeedFakeJet;//fake template distribution
  std::vector<TH1F*> histopubinsSininWithPixelSeedTightAndFakeJet;//denominator distribution

  histoptbinsSininWithPixelSeedDataJet.resize(nptbins);
  histoptbinsSininWithPixelSeedFakeJet.resize(nptbins);
  histoptbinsSininWithPixelSeedTightAndFakeJet.resize(nptbins);

  histoptbinsSininWithPixelSeedVsPtDataJet.resize(nptbins);
  histoptbinsSininWithPixelSeedVsPtFakeJet.resize(nptbins);
  histoptbinsSininWithPixelSeedVsPtTightAndFakeJet.resize(nptbins);

  histoptbinsSininWithPixelSeedVsCHFakeJet.resize(nptbins);


  histoetabinsSininWithPixelSeedDataJet.resize(netabins);
  histoetabinsSininWithPixelSeedFakeJet.resize(netabins);
  histoetabinsSininWithPixelSeedTightAndFakeJet.resize(netabins);

  histophibinsSininWithPixelSeedDataJet.resize(nphibins);
  histophibinsSininWithPixelSeedFakeJet.resize(nphibins);
  histophibinsSininWithPixelSeedTightAndFakeJet.resize(nphibins);

  histopubinsSininWithPixelSeedDataJet.resize(npubins);
  histopubinsSininWithPixelSeedFakeJet.resize(npubins);
  histopubinsSininWithPixelSeedTightAndFakeJet.resize(npubins);

  //Sinin distributions
  std::vector<TH1F*> histoptbinsSininDataJet;//Data distribution
  std::vector<TH1F*> histoptbinsSininFakeJet;//fake template distribution
  std::vector<TH1F*> histoptbinsSininTightAndFakeJet;//denominator distribution

  std::vector<TH1F*> histoetabinsSininDataJet;//Data distribution
  std::vector<TH1F*> histoetabinsSininFakeJet;//fake template distribution
  std::vector<TH1F*> histoetabinsSininTightAndFakeJet;//denominator distribution

  std::vector<TH1F*> histophibinsSininDataJet;//Data distribution
  std::vector<TH1F*> histophibinsSininFakeJet;//fake template distribution
  std::vector<TH1F*> histophibinsSininTightAndFakeJet;//denominator distribution

  std::vector<TH1F*> histopubinsSininDataJet;//Data distribution
  std::vector<TH1F*> histopubinsSininFakeJet;//fake template distribution
  std::vector<TH1F*> histopubinsSininTightAndFakeJet;//denominator distribution

  histoptbinsSininDataJet.resize(nptbins);
  histoptbinsSininFakeJet.resize(nptbins);
  histoptbinsSininTightAndFakeJet.resize(nptbins);

  histoetabinsSininDataJet.resize(netabins);
  histoetabinsSininFakeJet.resize(netabins);
  histoetabinsSininTightAndFakeJet.resize(netabins);

  histophibinsSininDataJet.resize(nphibins);
  histophibinsSininFakeJet.resize(nphibins);
  histophibinsSininTightAndFakeJet.resize(nphibins);

  histopubinsSininDataJet.resize(npubins);
  histopubinsSininFakeJet.resize(npubins);
  histopubinsSininTightAndFakeJet.resize(npubins);

  //CHIsol distributions
  std::vector<TH1F*> histoptbinsCHIsolDataJet;//Data distribution
  std::vector<TH1F*> histoptbinsCHIsolFakeJet;//fake template distribution
  std::vector<TH1F*> histoptbinsCHIsolTightAndFakeJet;//denominator distribution

  std::vector<TH1F*> histoetabinsCHIsolDataJet;//Data distribution
  std::vector<TH1F*> histoetabinsCHIsolFakeJet;//fake template distribution
  std::vector<TH1F*> histoetabinsCHIsolTightAndFakeJet;//denominator distribution

  std::vector<TH1F*> histophibinsCHIsolDataJet;//Data distribution
  std::vector<TH1F*> histophibinsCHIsolFakeJet;//fake template distribution
  std::vector<TH1F*> histophibinsCHIsolTightAndFakeJet;//denominator distribution

  std::vector<TH1F*> histopubinsCHIsolDataJet;//Data distribution
  std::vector<TH1F*> histopubinsCHIsolFakeJet;//fake template distribution
  std::vector<TH1F*> histopubinsCHIsolTightAndFakeJet;//denominator distribution

  histoptbinsCHIsolDataJet.resize(nptbins);
  histoptbinsCHIsolFakeJet.resize(nptbins);
  histoptbinsCHIsolTightAndFakeJet.resize(nptbins);

  histoetabinsCHIsolDataJet.resize(netabins);
  histoetabinsCHIsolFakeJet.resize(netabins);
  histoetabinsCHIsolTightAndFakeJet.resize(netabins);

  histophibinsCHIsolDataJet.resize(nphibins);
  histophibinsCHIsolFakeJet.resize(nphibins);
  histophibinsCHIsolTightAndFakeJet.resize(nphibins);

  histopubinsCHIsolDataJet.resize(npubins);
  histopubinsCHIsolFakeJet.resize(npubins);
  histopubinsCHIsolTightAndFakeJet.resize(npubins);

  TFile *histosfile = new TFile(("TemplateHistosJetCheckBinsEndcaps"+method+".root").Data(),"recreate");

  histosfile->cd();
  for(int num=0;num<nptbins-1;num++) 
    {
      TString tempo = TString::Format("ptbin%4.2f_%4.2f",ptbins[num],ptbins[num+1]);
      tempo.ReplaceAll(".00","");
      tempo.ReplaceAll("-","m");
      tempo.ReplaceAll(".","p");
      tempo.ReplaceAll("10000","Inf");
      //cout<<tempo.Data()<<endl;

      histoptbinsSininWithPixelSeedDataJet[num] = new TH1F(("histoSininWithPixelSeedDataJet"+tempo).Data(),("histoSininWithPixelSeedDataJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histoptbinsSininWithPixelSeedFakeJet[num] = new TH1F(("histoSininWithPixelSeedFakeJet"+tempo).Data(),("histoSininWithPixelSeedFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histoptbinsSininWithPixelSeedTightAndFakeJet[num] = new TH1F(("histoSininWithPixelSeedTightAndFakeJet"+tempo).Data(),("histoSininWithPixelSeedTightAndFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);

      histoptbinsSininWithPixelSeedVsPtDataJet[num] = new TH2F(("histoSininWithPixelSeedVsPtDataJet"+tempo).Data(),("histoSininWithPixelSeedVsPtDataJet"+tempo).Data(),600,0.,600.,nbinssinin,minvaluesinin,maxvaluesinin);
      histoptbinsSininWithPixelSeedVsPtFakeJet[num] = new TH2F(("histoSininWithPixelSeedVsPtFakeJet"+tempo).Data(),("histoSininWithPixelSeedVsPtFakeJet"+tempo).Data(),600,0.,600.,nbinssinin,minvaluesinin,maxvaluesinin);
      histoptbinsSininWithPixelSeedVsPtTightAndFakeJet[num] = new TH2F(("histoSininWithPixelSeedVsPtTightAndFakeJet"+tempo).Data(),("histoSininWithPixelSeedVsPtTightAndFakeJet"+tempo).Data(),600,0.,600.,nbinssinin,minvaluesinin,maxvaluesinin);

      histoptbinsSininWithPixelSeedVsCHFakeJet[num] = new TH2F(("histoSininWithPixelSeedVsCHFakeJet"+tempo).Data(),("histoSininWithPixelSeedVsCHFakeJet"+tempo).Data(),500,0.,50.,nbinssinin,minvaluesinin,maxvaluesinin);

      histoptbinsSininDataJet[num] = new TH1F(("histoSininDataJet"+tempo).Data(),("histoSininDataJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histoptbinsSininFakeJet[num] = new TH1F(("histoSininFakeJet"+tempo).Data(),("histoSininFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histoptbinsSininTightAndFakeJet[num] = new TH1F(("histoSininTightAndFakeJet"+tempo).Data(),("histoSininTightAndFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);

      histoptbinsCHIsolDataJet[num] = new TH1F(("histoCHIsolDataJet"+tempo).Data(),("histoCHIsolDataJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
      histoptbinsCHIsolFakeJet[num] = new TH1F(("histoCHIsolFakeJet"+tempo).Data(),("histoCHIsolFakeJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
      histoptbinsCHIsolTightAndFakeJet[num] = new TH1F(("histoCHIsolTightAndFakeJet"+tempo).Data(),("histoCHIsolTightAndFakeJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
    }

  for(int num=0;num<netabins-1;num++) 
    {
      TString tempo = TString::Format("etabin%4.2f_%4.2f",etabins[num],etabins[num+1]);
      tempo.ReplaceAll(".00","");
      tempo.ReplaceAll("-","m");
      tempo.ReplaceAll(".","p");
      tempo.ReplaceAll("10000","Inf");
      //cout<<tempo.Data()<<endl;

      histoetabinsSininWithPixelSeedDataJet[num] = new TH1F(("histoSininWithPixelSeedDataJet"+tempo).Data(),("histoSininWithPixelSeedDataJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histoetabinsSininWithPixelSeedFakeJet[num] = new TH1F(("histoSininWithPixelSeedFakeJet"+tempo).Data(),("histoSininWithPixelSeedFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histoetabinsSininWithPixelSeedTightAndFakeJet[num] = new TH1F(("histoSininWithPixelSeedTightAndFakeJet"+tempo).Data(),("histoSininWithPixelSeedTightAndFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);

      histoetabinsSininDataJet[num] = new TH1F(("histoSininDataJet"+tempo).Data(),("histoSininDataJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histoetabinsSininFakeJet[num] = new TH1F(("histoSininFakeJet"+tempo).Data(),("histoSininFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histoetabinsSininTightAndFakeJet[num] = new TH1F(("histoSininTightAndFakeJet"+tempo).Data(),("histoSininTightAndFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);

      histoetabinsCHIsolDataJet[num] = new TH1F(("histoCHIsolDataJet"+tempo).Data(),("histoCHIsolDataJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
      histoetabinsCHIsolFakeJet[num] = new TH1F(("histoCHIsolFakeJet"+tempo).Data(),("histoCHIsolFakeJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
      histoetabinsCHIsolTightAndFakeJet[num] = new TH1F(("histoCHIsolTightAndFakeJet"+tempo).Data(),("histoCHIsolTightAndFakeJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
    }

  for(int num=0;num<nphibins-1;num++) 
    {
      TString tempo = TString::Format("phibin%4.2f_%4.2f",phibins[num],phibins[num+1]);
      tempo.ReplaceAll(".00","");
      tempo.ReplaceAll("-","m");
      tempo.ReplaceAll(".","p");
      tempo.ReplaceAll("10000","Inf");
      //cout<<tempo.Data()<<endl;

      histophibinsSininWithPixelSeedDataJet[num] = new TH1F(("histoSininWithPixelSeedDataJet"+tempo).Data(),("histoSininWithPixelSeedDataJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histophibinsSininWithPixelSeedFakeJet[num] = new TH1F(("histoSininWithPixelSeedFakeJet"+tempo).Data(),("histoSininWithPixelSeedFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histophibinsSininWithPixelSeedTightAndFakeJet[num] = new TH1F(("histoSininWithPixelSeedTightAndFakeJet"+tempo).Data(),("histoSininWithPixelSeedTightAndFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);

      histophibinsSininDataJet[num] = new TH1F(("histoSininDataJet"+tempo).Data(),("histoSininDataJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histophibinsSininFakeJet[num] = new TH1F(("histoSininFakeJet"+tempo).Data(),("histoSininFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histophibinsSininTightAndFakeJet[num] = new TH1F(("histoSininTightAndFakeJet"+tempo).Data(),("histoSininTightAndFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);

      histophibinsCHIsolDataJet[num] = new TH1F(("histoCHIsolDataJet"+tempo).Data(),("histoCHIsolDataJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
      histophibinsCHIsolFakeJet[num] = new TH1F(("histoCHIsolFakeJet"+tempo).Data(),("histoCHIsolFakeJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
      histophibinsCHIsolTightAndFakeJet[num] = new TH1F(("histoCHIsolTightAndFakeJet"+tempo).Data(),("histoCHIsolTightAndFakeJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
    }

  for(int num=0;num<npubins-1;num++) 
    {
      TString tempo = TString::Format("pubin%4.2f_%4.2f",pubins[num],pubins[num+1]);
      tempo.ReplaceAll(".00","");
      tempo.ReplaceAll("-","m");
      tempo.ReplaceAll(".","p");
      tempo.ReplaceAll("10000","Inf");
      //cout<<tempo.Data()<<endl;

      histopubinsSininWithPixelSeedDataJet[num] = new TH1F(("histoSininWithPixelSeedDataJet"+tempo).Data(),("histoSininWithPixelSeedDataJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histopubinsSininWithPixelSeedFakeJet[num] = new TH1F(("histoSininWithPixelSeedFakeJet"+tempo).Data(),("histoSininWithPixelSeedFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histopubinsSininWithPixelSeedTightAndFakeJet[num] = new TH1F(("histoSininWithPixelSeedTightAndFakeJet"+tempo).Data(),("histoSininWithPixelSeedTightAndFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);

      histopubinsSininDataJet[num] = new TH1F(("histoSininDataJet"+tempo).Data(),("histoSininDataJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histopubinsSininFakeJet[num] = new TH1F(("histoSininFakeJet"+tempo).Data(),("histoSininFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);
      histopubinsSininTightAndFakeJet[num] = new TH1F(("histoSininTightAndFakeJet"+tempo).Data(),("histoSininTightAndFakeJet"+tempo).Data(),nbinssinin,minvaluesinin,maxvaluesinin);

      histopubinsCHIsolDataJet[num] = new TH1F(("histoCHIsolDataJet"+tempo).Data(),("histoCHIsolDataJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
      histopubinsCHIsolFakeJet[num] = new TH1F(("histoCHIsolFakeJet"+tempo).Data(),("histoCHIsolFakeJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
      histopubinsCHIsolTightAndFakeJet[num] = new TH1F(("histoCHIsolTightAndFakeJet"+tempo).Data(),("histoCHIsolTightAndFakeJet"+tempo).Data(),nbinschisol,minvaluechisol,maxvaluechisol);
    }



  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;

    if( (jentry%500000) == 0) std::cout<<jentry<<" entries"<<std::endl;
    if(jentry == limit) break;

    for(int i=0;i<10;i++) {

      //Bool_t ptcut = (Photon_pt[i] > 30. && Photon_pt[i] < 130.);
      Bool_t siphiiphicut = (Photon_sigmaIphiIphi[i] > 0.009);
      Bool_t gapcut = Photon_isEBEEGap[i];
      Bool_t rechitflagcut = (Photon_recHitFlag[i] == 13);

      //put this to go faster but be careful
      //if(!ptcut) continue;
      if(!siphiiphicut) continue;
      if(gapcut) continue;
      if(rechitflagcut) continue;

      Bool_t towerhoecut = false;
      Bool_t CHisocut = false;
      Bool_t NHisocut = false;
      Bool_t PHisocut = false;
      Bool_t sietaietacut = false;
      Bool_t CHinvisocut = false;

      Bool_t barrelcut = (Photon_isEB[i]);
      Bool_t endcapcut = abs(Photon_detEta[i]) > 1.56 && abs(Photon_detEta[i]) < 2.5;
      Bool_t isfakeable = (Photon_isPFFakeable[i]);
      Bool_t haspromptelec = (Photon_hasMatchedPromptElectron[i]);

      if(method.EqualTo("Tight")){
	towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
	CHisocut = (Photon_rhocorPFIsoCharged03[i] < 0.7);
	NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 0.4 + 0.04 * Photon_pt[i]);
	PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.5 + 0.005 * Photon_pt[i]);
	sietaietacut = (Photon_sigmaIetaIeta[i] < 0.011);
	CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 5. && Photon_rhocorPFIsoCharged03[i] < 10.);
      }

      if(method.EqualTo("Medium")){
	towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
	CHisocut = (Photon_rhocorPFIsoCharged03[i] < 1.5);
	NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 1.0 + 0.04 * Photon_pt[i]);
	PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 0.7 + 0.005 * Photon_pt[i]);
	sietaietacut = (Photon_sigmaIetaIeta[i] < 0.011);
	CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 5. && Photon_rhocorPFIsoCharged03[i] < 10.);
      }

      // if(method.EqualTo("Loose")){
      // 	towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
      // 	CHisocut = (Photon_rhocorPFIsoCharged03[i] < 2.6);
      // 	NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 3.5 + 0.04 * Photon_pt[i]);
      // 	PHisocut = (Photon_rhocorPFIsoPhoton03[i] < 1.3 + 0.005 * Photon_pt[i]);
      // 	sietaietacut = (Photon_sigmaIetaIeta[i] < 0.012);
      // 	CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 5. && Photon_rhocorPFIsoCharged03[i] < 10.);
      // }


      //for the endcaps
      if(method.EqualTo("Loose")){
	towerhoecut = (Photon_hadTowerOverEm[i] < 0.05);
	CHisocut = (Photon_rhocorPFIsoCharged03[i] < 2.3);
	NHisocut = (Photon_rhocorPFIsoNeutral03[i] < 2.9 + 0.04 * Photon_pt[i]);
	PHisocut = true;
	sietaietacut = (Photon_sigmaIetaIeta[i] < 0.034);
	CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 5. && Photon_rhocorPFIsoCharged03[i] < 8.);
      }



      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 0.7 && Photon_rhocorPFIsoCharged03[i] < 10.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 0.7 && Photon_rhocorPFIsoCharged03[i] < 9999999.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 2.6 && Photon_rhocorPFIsoCharged03[i] < 9999999.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 2.6 && Photon_rhocorPFIsoCharged03[i] < 50.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 1.5 && Photon_rhocorPFIsoCharged03[i] < 10.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 1.5 && Photon_rhocorPFIsoCharged03[i] < 50.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 2. && Photon_rhocorPFIsoCharged03[i] < 6.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 3.5 && Photon_rhocorPFIsoCharged03[i] < 10.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 3.5 && Photon_rhocorPFIsoCharged03[i] < 50.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 5. && Photon_rhocorPFIsoCharged03[i] < 50.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 5. && Photon_rhocorPFIsoCharged03[i] < 99999999.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 10. && Photon_rhocorPFIsoCharged03[i] < 20.);
      //Bool_t CHinvisocut = (Photon_rhocorPFIsoCharged03[i] > 5. && Photon_rhocorPFIsoCharged03[i] < 20.);

      std::vector<bool> inptrange;
      std::vector<bool> inetarange;
      std::vector<bool> inphirange;
      std::vector<bool> inpurange;

      inptrange.reserve(nptbins-1);
      inetarange.reserve(netabins-1);
      inphirange.reserve(nphibins-1);
      inpurange.reserve(npubins-1);

      //Create the booleans for pt, eta, phi and pu ranges
      for(int num=0;num<nptbins-1;num++){inptrange[num] = ( (Photon_pt[i] > ptbins[num]) && (Photon_pt[i] < ptbins[num+1]) );}
      for(int num=0;num<netabins-1;num++){inetarange[num] = ( (Photon_eta[i] > etabins[num]) && (Photon_eta[i] < etabins[num+1]) );}
      for(int num=0;num<nphibins-1;num++){inphirange[num] = ( ((Photon_phi[i]*(180./PI)) > phibins[num]) && ((Photon_phi[i]*(180./PI)) < phibins[num+1]) );}
      for(int num=0;num<npubins-1;num++){inpurange[num] = ( ((Vtx_Nvtx*1.) > pubins[num]) && ((Vtx_Nvtx*1.) < pubins[num+1]) );}


      // Bool_t datasamplesininwithpixelseed = towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut  && !haspromptelec;
      // Bool_t fakesamplesininwithpixelseed = towerhoecut && CHinvisocut && NHisocut && PHisocut && barrelcut  && !haspromptelec;
      // //Bool_t denominatorsamplesininwithpixelseed = isfakeable && !haspromptelec && barrelcut;
      // Bool_t denominatorsamplesininwithpixelseed = isfakeable && barrelcut;


      //for the endcaps
      Bool_t datasamplesininwithpixelseed = towerhoecut && CHisocut && NHisocut && PHisocut && endcapcut  && !haspromptelec;
      Bool_t fakesamplesininwithpixelseed = towerhoecut && CHinvisocut && NHisocut && PHisocut && endcapcut  && !haspromptelec;
      Bool_t denominatorsamplesininwithpixelseed = isfakeable && !haspromptelec && endcapcut;



      Bool_t datasamplesinin = towerhoecut && CHisocut && NHisocut && PHisocut && barrelcut;
      Bool_t fakesamplesinin = towerhoecut && CHinvisocut && NHisocut && PHisocut && barrelcut;
      Bool_t denominatorsamplesinin = isfakeable && !haspromptelec && barrelcut;

      Bool_t datasamplechisol = towerhoecut && sietaietacut && NHisocut && PHisocut && barrelcut && !haspromptelec;
      Bool_t fakesamplechisol = towerhoecut && !sietaietacut && NHisocut && PHisocut && barrelcut && !haspromptelec;
      Bool_t denominatorsamplechisol = isfakeable && !haspromptelec && barrelcut;



      //special for sinin vs CH
      //to test sensitivity of sinin
      //shape vs CH sideband
      //therefore this is fake cut
      //but without CH inverted

      if(towerhoecut && NHisocut && PHisocut && endcapcut && !haspromptelec)
	{
	  for(int num=0;num<nptbins-1;num++) {if(inptrange[num]){
	      histoptbinsSininWithPixelSeedVsCHFakeJet[num]->Fill(Photon_rhocorPFIsoCharged03[i],Photon_sigmaIetaIeta[i]);}}
	}


      //---------------Sigma Ieta Ieta with pixel seed
      //this is the sinin template for numerator containing both real and fake components
      if(datasamplesininwithpixelseed)
	{
	  for(int num=0;num<nptbins-1;num++) {if(inptrange[num]){
	      histoptbinsSininWithPixelSeedDataJet[num]->Fill(Photon_sigmaIetaIeta[i]);
	      histoptbinsSininWithPixelSeedVsPtDataJet[num]->Fill(Photon_pt[i],Photon_sigmaIetaIeta[i]);}}
	  for(int num=0;num<netabins-1;num++) {if(inetarange[num]) histoetabinsSininWithPixelSeedDataJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<nphibins-1;num++) {if(inphirange[num]) histophibinsSininWithPixelSeedDataJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<npubins-1;num++) {if(inpurange[num]) histopubinsSininWithPixelSeedDataJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}
      //this is the sinin fake template (inverting track isolation)
      if(fakesamplesininwithpixelseed)
	{
	  for(int num=0;num<nptbins-1;num++) {if(inptrange[num]){
	      histoptbinsSininWithPixelSeedFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);
	      histoptbinsSininWithPixelSeedVsPtFakeJet[num]->Fill(Photon_pt[i],Photon_sigmaIetaIeta[i]);}}
	  for(int num=0;num<netabins-1;num++) {if(inetarange[num]) histoetabinsSininWithPixelSeedFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<nphibins-1;num++) {if(inphirange[num]) histophibinsSininWithPixelSeedFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<npubins-1;num++) {if(inpurange[num]) histopubinsSininWithPixelSeedFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}
      //this is the denominator, i.e. the set of fakeable objects
      if(denominatorsamplesininwithpixelseed)
	{
	  for(int num=0;num<nptbins-1;num++) {if(inptrange[num]){
	      histoptbinsSininWithPixelSeedTightAndFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);
	      histoptbinsSininWithPixelSeedVsPtTightAndFakeJet[num]->Fill(Photon_pt[i],Photon_sigmaIetaIeta[i]);}}
	  for(int num=0;num<netabins-1;num++) {if(inetarange[num]) histoetabinsSininWithPixelSeedTightAndFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<nphibins-1;num++) {if(inphirange[num]) histophibinsSininWithPixelSeedTightAndFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<npubins-1;num++) {if(inpurange[num]) histopubinsSininWithPixelSeedTightAndFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}


      //---------------Sigma Ieta Ieta
      //this is the sinin template for numerator containing both real and fake components
      if(datasamplesinin)
	{
	  for(int num=0;num<nptbins-1;num++) {if(inptrange[num]) histoptbinsSininDataJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<netabins-1;num++) {if(inetarange[num]) histoetabinsSininDataJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<nphibins-1;num++) {if(inphirange[num]) histophibinsSininDataJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<npubins-1;num++) {if(inpurange[num]) histopubinsSininDataJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}
      //this is the sinin fake template (inverting track isolation)
      if(fakesamplesinin)
	{
	  for(int num=0;num<nptbins-1;num++) {if(inptrange[num]) histoptbinsSininFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<netabins-1;num++) {if(inetarange[num]) histoetabinsSininFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<nphibins-1;num++) {if(inphirange[num]) histophibinsSininFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<npubins-1;num++) {if(inpurange[num]) histopubinsSininFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}
      //this is the denominator, i.e. the set of fakeable objects
      if(denominatorsamplesinin)
	{
	  for(int num=0;num<nptbins-1;num++) {if(inptrange[num]) histoptbinsSininTightAndFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<netabins-1;num++) {if(inetarange[num]) histoetabinsSininTightAndFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<nphibins-1;num++) {if(inphirange[num]) histophibinsSininTightAndFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	  for(int num=0;num<npubins-1;num++) {if(inpurange[num]) histopubinsSininTightAndFakeJet[num]->Fill(Photon_sigmaIetaIeta[i]);}
	}


      //---------------Charged Hadron Isolation
      //this is the chisol template for numerator containing both real and fake components
      if(datasamplechisol)
	{
	  for(int num=0;num<nptbins-1;num++) {if(inptrange[num]) histoptbinsCHIsolDataJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	  for(int num=0;num<netabins-1;num++) {if(inetarange[num]) histoetabinsCHIsolDataJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	  for(int num=0;num<nphibins-1;num++) {if(inphirange[num]) histophibinsCHIsolDataJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	  for(int num=0;num<npubins-1;num++) {if(inpurange[num]) histopubinsCHIsolDataJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	}
      //this is the chisol fake template (inverting sinin cut)
      if(fakesamplechisol)
	{
	  for(int num=0;num<nptbins-1;num++) {if(inptrange[num]) histoptbinsCHIsolFakeJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	  for(int num=0;num<netabins-1;num++) {if(inetarange[num]) histoetabinsCHIsolFakeJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	  for(int num=0;num<nphibins-1;num++) {if(inphirange[num]) histophibinsCHIsolFakeJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	  for(int num=0;num<npubins-1;num++) {if(inpurange[num]) histopubinsCHIsolFakeJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	}
      //this is the denominator, i.e. the set of fakeable objects
      if(denominatorsamplechisol)
	{
	  for(int num=0;num<nptbins-1;num++) {if(inptrange[num]) histoptbinsCHIsolTightAndFakeJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	  for(int num=0;num<netabins-1;num++) {if(inetarange[num]) histoetabinsCHIsolTightAndFakeJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	  for(int num=0;num<nphibins-1;num++) {if(inphirange[num]) histophibinsCHIsolTightAndFakeJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	  for(int num=0;num<npubins-1;num++) {if(inpurange[num]) histopubinsCHIsolTightAndFakeJet[num]->Fill(Photon_PFIsoCharged03[i]);}
	}

    }//end of loop over photons
    
  }//end of loop over entries in event

  
  histosfile->cd();
  histosfile->Write();
  histosfile->Close();

}//end of method














