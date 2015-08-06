{ // Real Photon Templates to be subtracted
  //Kinematic and Fiducial Requirements for photon ID 
  TCut detEta_cut = "abs(Photon.detEta)>1.56 && abs(Photon.detEta)<2.5";
  TCut hadTowerOverEm_cut = "Photon.hadTowerOverEm<0.05";
  TCut sigmaIetaIeta_cut = "0.0009133+0.891832*Photon.sigmaIetaIeta < 0.012";
  TCut rhocorPFIsoCharged03_cut = "Photon.rhocorPFIsoCharged03<2.3";
  TCut rhocorPFIsoPhoton03_cut = "1";
  TCut rhocorPFIsoNeutraln03_cut = "Photon.rhocorPFIsoNeutral03<2.9 + 0.04*Photon.pt";
  TCut sigmaIetaIeta_cut2 = "0.00003+0.99470*Photon.sigmaIetaIeta<10"; //why?
  TCut elecveto = "!Photon.hasMatchedPromptElectron";

  //Additional Sanity Cuts 
  TCut sigmaIphiIphi_cut = "Photon.sigmaIphiIphi > 0.009";
  TCut isEBEEGap_cut = "!Photon.isEBEEGap";
  TCut recHitFlag_cut = "Photon.recHitFlag != 13";
 
  //------ Write out histogram 
  
  // Load input tree
  TFile *file0 = TFile::Open("/data2/ciperez/MyExoAnalyzer_DiPhotonRealMC.root");
  //TFile *file0 = TFile::Open("/data2/ciperez/ExoDiPhotonAnalyzerPF_DATA_Jet.root");
  //TFile *file0 = TFile::Open("/data2/ciperez/MyExoAnalyzer_JetRun2012A06Aug2012Recover.root");
  file0->cd("diphotonAnalyzer");

  //----- Fill histogram
  
  //pT bin: 20-40 GeV
  TH1F *diphoton = new TH1F("EndCapsMCReal_20_40","pT bin: 20-40 GeV", 100,0, 0.1);
  TCut ptcut = "Photon.pt > 20 && Photon.pt <40";
  fTreeAll->Draw("0.00003+0.99470*Photon.sigmaIetaIeta >> EndCapsMCReal_20_40", 
      detEta_cut
      && hadTowerOverEm_cut
      && rhocorPFIsoCharged03_cut
      && rhocorPFIsoPhoton03_cut
      && rhocorPFIsoNeutraln03_cut
      && sigmaIetaIeta_cut2
      && ptcut
      && elecveto
      && sigmaIphiIphi_cut
      && isEBEEGap_cut
      && recHitFlag_cut);

  //pT bin: 40-60 GeV
  TCut ptcut_2 = "Photon.pt >40 && Photon.pt <60";
  TH1F *diphoton_2 = new TH1F("EndCapsMCReal_40_60","pT bin: 40-60 GeV", 100,0, 0.1);
  fTreeAll->Draw("0.00003+0.99470*Photon.sigmaIetaIeta >> EndCapsMCReal_40_60", 
      detEta_cut
      && hadTowerOverEm_cut
      && rhocorPFIsoCharged03_cut
      && rhocorPFIsoPhoton03_cut
      && rhocorPFIsoNeutraln03_cut
      && sigmaIetaIeta_cut2
      && ptcut_2
      && elecveto
      && sigmaIphiIphi_cut
      && isEBEEGap_cut
      && recHitFlag_cut);

   //pT bin: 60-80 GeV
   TCut ptcut_3 = "Photon.pt>60 && Photon.pt <80";
   TH1F *diphoton_3 = new TH1F("EndCapsMCReal_60_80","pT bin: 60-80 GeV", 100,0, 0.1);
   fTreeAll->Draw("0.00003+0.99470*Photon.sigmaIetaIeta >> EndCapsMCReal_60_80", 
      detEta_cut
      && hadTowerOverEm_cut
      && rhocorPFIsoCharged03_cut
      && rhocorPFIsoPhoton03_cut
      && rhocorPFIsoNeutraln03_cut
      && sigmaIetaIeta_cut2
      && ptcut_3
      && elecveto
      && sigmaIphiIphi_cut
      && isEBEEGap_cut
      && recHitFlag_cut);

   //pT bin: 80-100 GeV
   TCut ptcut_4 = "Photon.pt >80 && Photon.pt <100";
   TH1F *diphoton_4 = new TH1F("EndCapsMCReal_80_100","pT bin: 80-100 GeV", 100,0, 0.1);
   fTreeAll->Draw("0.00003+0.99470*Photon.sigmaIetaIeta >> EndCapsMCReal_80_100", 
      detEta_cut
      && hadTowerOverEm_cut
      && rhocorPFIsoCharged03_cut
      && rhocorPFIsoPhoton03_cut
      && rhocorPFIsoNeutraln03_cut
      && sigmaIetaIeta_cut2
      && ptcut_4
      && elecveto
      && sigmaIphiIphi_cut
      && isEBEEGap_cut
      && recHitFlag_cut);

   //pT bin: 100-120 GeV
   TCut ptcut_5 = "Photon.pt>100 && Photon.pt<120";
   TH1F *diphoton_5 = new TH1F("EndCapsMCReal_100_120","pT bin: 100-120 GeV", 100,0, 0.1);
   fTreeAll->Draw("0.00003+0.99470*Photon.sigmaIetaIeta >> EndCapsMCReal_100_120", 
      detEta_cut
      && hadTowerOverEm_cut
      && rhocorPFIsoCharged03_cut
      && rhocorPFIsoPhoton03_cut
      && rhocorPFIsoNeutraln03_cut
      && sigmaIetaIeta_cut2
      && ptcut_5
      && elecveto
      && sigmaIphiIphi_cut
      && isEBEEGap_cut
      && recHitFlag_cut);

   //pT bin: 120-200 GeV
   TCut ptcut_6 = "Photon.pt>120 && Photon.pt<200";
   TH1F *diphoton_6 = new TH1F("EndCapsMCReal_120_200","pT bin: 120-200 GeV", 100,0, 0.1);
   fTreeAll->Draw("0.00003+0.99470*Photon.sigmaIetaIeta >> EndCapsMCReal_120_200", 
      detEta_cut
      && hadTowerOverEm_cut
      && rhocorPFIsoCharged03_cut
      && rhocorPFIsoPhoton03_cut
      && rhocorPFIsoNeutraln03_cut
      && sigmaIetaIeta_cut2
      && ptcut_6
      && elecveto
      && sigmaIphiIphi_cut
      && isEBEEGap_cut
      && recHitFlag_cut);

   //So the error is in the sinin rescaling! CARELESS!!

  //pT bin: 200-600 GeV
  TCut ptcut_7 = "Photon.pt>200 && Photon.pt<600"; 
  TH1F *diphoton_7 = new TH1F("EndCapsMCReal_200_600","pT bin: 200-600", 100,0, 0.1);
  fTreeAll->Draw("0.00003+0.99470*Photon.sigmaIetaIeta >> EndCapsMCReal_200_600", 
      detEta_cut
      && hadTowerOverEm_cut
      && rhocorPFIsoCharged03_cut
      && rhocorPFIsoPhoton03_cut
      && rhocorPFIsoNeutraln03_cut
      && sigmaIetaIeta_cut2
      && ptcut_7
      && elecveto
      && sigmaIphiIphi_cut
      && isEBEEGap_cut
      && recHitFlag_cut);



  // Write out histogram into .root file --- See Desktop
  TFile *outFile = new TFile("RealPhotonTemplatesEndCaps.root","RECREATE");
  diphoton->Write();
  diphoton_2->Write();
  diphoton_3->Write();
  diphoton_4->Write();
  diphoton_5->Write();
  diphoton_6->Write();
  diphoton_7->Write();
  outFile->cd();
  file0->Close();
  outFile->Close();
}
