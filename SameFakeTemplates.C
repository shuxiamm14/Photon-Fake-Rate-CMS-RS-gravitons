#include "TROOT.h"
#include "TSystem.h"
#include "TH1F.h"
#include "TF1.h"
#include "TFile.h"
#include "TLegend.h"
#include "TText.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TH2F.h"
#include "TH1D.h"

#include <vector>
#include <algorithm>

void test(int numbersigmas = 0, Bool_t debugtest = true, TString region = "5-8")
{

  using namespace std;

  TCanvas *canvas = new TCanvas("canvas","canvas",900,100,500,500);
  float ptbinsarray[] = {20.,40.,60.,80.,100.,120.,200.,600.};
  //Open Input .root file 
  
  TFile *histojetfile = TFile::Open("/afs/cern.ch/user/c/ciperez/CMSSW_7_4_5/src/FakeTemplates_var_SideBands.root");
  std::vector<float> ptbins(ptbinsarray,ptbinsarray+sizeof(ptbinsarray)/sizeof(ptbinsarray[0]));
  
  std::vector<std::vector<float> > allbins;
  allbins.push_back(ptbins);

  unsigned int sidebandloopmax = 1;//5_10, 5_20, ...
  unsigned int templatevarsloopmax = 1;//sinin with conv safe veto, sinin, ch isol
  unsigned int binsloopmax = 1;//pt, eta, phi, pu


  //--- Write NEW .root Historams for Fake Rate
  TFile *FRhistosfile = new TFile("FakeTemplates_var_SideBands.root","recreate"); 
	  
  for(unsigned int k = 0;k<allbins[0].size()-1;k++){
	    float binlow = allbins[0][k];
	    float binmax = allbins[0][k+1];

	    TString binstring = TString::Format("%4.2f_%4.2f",binlow,binmax);
	    binstring.ReplaceAll(".00","");
	    binstring.ReplaceAll("-","m");
	    binstring.ReplaceAll(".","p");
	    binstring.ReplaceAll("10000","Inf");
	    cout<<binstring.Data()<<endl;
   
      //---------------- FAKE TEMPLATES FOR DIFFERENT SIDEBANDS
      
      //-------------------- 3-6 GeV
      TH2F *histo3_6 = (TH2F*)histojetfile->Get(("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring).Data());
      TH1D *histopy3_6;
      histopy3_6 = histo3_6->ProjectionY("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring+"Sideband3_6",31,60);
      //TH1F *histotemp = (TH1F*)gDirectory->FindObject("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring+"Sideband3_6",31,60);
      
     // histopy3_6->Scale(scale);
      histopy3_6->Draw("same");
      canvas->Update();
     // canvas->Print(("SameFakeTemplates"+binstring+"Sideband3_6.png").Data(),"png");
      
      //------------------  4-7 GeV
      //histoSininWithPixelSeedVsCHFakeJetptbin20_40->ProjectionY("histoSininWithPixelSeedVsCHFakeJetptbin20_40Sideband4_7",41,70)
      TH2F *histo4_7 = (TH2F*)histojetfile->Get(("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring).Data());
      TH1D *histopy4_7;
      histopy4_7 = histo4_7->ProjectionY("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring+"Sideband4_7",41,70);
     // histopy4_7->Scale(scale);
      histopy4_7->Draw("same");
       
    //  canvas->Print(("SameFakeTemplates"+binstring+"Sideband4_7.png").Data(),"png");
      canvas->Update();

     //-------------------- 4-10 GeV
      TH2F *histo4_10 = (TH2F*)histojetfile->Get(("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring).Data());
      TH1D *histopy4_10;
      histopy4_10 = histo4_10->ProjectionY("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring+"Sideband4_10",41,100);
     // histopy4_10->Scale(scale);
      
      histopy4_10->Draw("same");
      
     // canvas->Print(("SameFakeTemplates"+binstring+"Sideband4_10.png").Data(),"png");
      canvas->Update();

     //-------------------- 5-8 GeV
      TH2F *histo5_8 = (TH2F*)histojetfile->Get(("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring).Data());
      TH1D *histopy5_8;
      histopy5_8 = histo3_6->ProjectionY("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring+"Sideband5_8",51,80);
    //  histopy5_8->Scale(scale);
      histopy5_8->Draw("same");
      
    //  canvas->Print(("SameFakeTemplates"+binstring+"Sideband5_8.png").Data(),"png");
      canvas->Update();

    //-------------------- 5-10 GeV
      TH2F *histo5_10 = (TH2F*)histojetfile->Get(("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring).Data());
      TH1D *histopy5_10;
      histopy5_10 = histo5_10->ProjectionY("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring+"Sideband5_10",51,100);
  //    histopy5_10->Scale(scale);
      histopy5_10->Draw("same");
      canvas->Update();
     // canvas->Print(("SameFakeTemplates"+binstring+"Sideband5_10.png").Data(),"png");

    //Write the Fake Template Histograms into the root file
    FRhistosfile->cd();
    histopy3_6->Write();
    histopy4_7->Write();
    histopy4_10->Write();
    histopy5_8->Write();
    histopy5_10->Write();  
     
	  }//loop on all bins
 
    histojetfile->cd();
    histojetfile->Close();

}//end of method
