#include "TH2F.h"
#include "TH1D.h"
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
#include "TPad.h"

#include <vector>
#include <algorithm>
#include <iostream>
void test(int numbersigmas = 0, Bool_t debugtest = true)
{

  using namespace std;

  float ptbinsarray[] = {20.,40.,60.,80.,100.,120.,200.,600.};

  std::vector<float> ptbins(ptbinsarray,ptbinsarray+sizeof(ptbinsarray)/sizeof(ptbinsarray[0]));
  
  std::vector<std::vector<float> > allbins;
  allbins.push_back(ptbins);
  
  std::vector<TString> VarString;
  VarString.push_back("VsPt");
  
  std::vector<TString> HistoNameString;
  HistoNameString.push_back("ptbin");

  std::vector<TString> GraphXTitleString;
  GraphXTitleString.push_back("p_{t} (GeV)");

  std::vector<TString> SideBandDefinitions;
  SideBandDefinitions.push_back("Sideband3_6"); //n=1
  SideBandDefinitions.push_back("Sideband4_7"); //n=2
  SideBandDefinitions.push_back("Sideband4_10");//n=3
  SideBandDefinitions.push_back("Sideband5_8"); //n=4
  SideBandDefinitions.push_back("Sideband5_10"); //n=5

  //   ------------FOR TESTING----------------
  unsigned int sidebandloopmax = 5;//5_10, 5_20, ...

  //----------Open .root Templates 
  TFile *histojetfile = TFile::Open("/afs/cern.ch/user/c/ciperez/CMSSW_7_4_5/src/FakeTemplates_var_SideBands.root"); 
  //--- Write NEW .root Historams for Fake Rate
  TFile *FRhistosfile = new TFile("SameFakeTemplatePlots.root","recreate");
      	
  TMultiGraph *mg = new TMultiGraph();
//	TLegend *legendAllGraphs = new TLegend(0.37,0.59,0.57,0.79);
	  TH1F *h1[sidebandloopmax];   
     
 // TLegend *legend = new TLegend(0.62,0.65,0.82,0.85); 
 //Begin loop for bins  
  for(unsigned int k = 0;k<allbins[0].size()-1;k++){
	    float binlow = allbins[0][k];
	    float binmax = allbins[0][k+1];

	    TString binstring = TString::Format("%4.2f_%4.2f",binlow,binmax);
	    binstring.ReplaceAll(".00","");
	    binstring.ReplaceAll("-","m");
	    binstring.ReplaceAll(".","p");
	    binstring.ReplaceAll("10000","Inf");
	    cout<<binstring.Data()<<endl;
    
     TCanvas *canvas = new TCanvas("canvas","canvas",900,100,500,500);  

      //---Begin loop for sidebands
      for(unsigned int n =0;n<sidebandloopmax; n++){ 
    
      //****** HERE WE OVERLAY THE TEMPLATES FOR THE SAME PT FOR DIFFERENT SIDEBANDS      
      //Get histograms from each of the histojetfiles declared earlier 
      
      h1[n] = (TH1F*)histojetfile->Get(("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring+SideBandDefinitions[n]).Data());
      
      h1[n]->Print();
     
	    //avoiding 0 entries in the histograms
	    //fake and real mc histos are the most critical
	    for(int bincount = 1; bincount <= h1[n]->GetNbinsX();bincount++){
	      if(h1[n]->GetBinContent(bincount) == 0.) h1[n]->SetBinContent(bincount,1.e-6);
	    }

	    canvas->cd();
      canvas->SetGridx(true);
      canvas->SetGridy(true);

      //Getting the Maximum range of the histogram plots so everything fits
      float padmax = h1[n]->GetMaximum();
      h1[n]->GetYaxis()->SetRangeUser(1.e-1,2.2*padmax);
      
      //Normalization
      Double_t norm = 1;
      Double_t scale = norm/(h1[n]->Integral());
      h1[n]->Scale(scale);

      //Set scale to Log 
      canvas->SetLogy(0);

      //Draw the Stacked Histograms
      h1[n]->Draw("same");
      // ----- DEFINE LEGENDS and their position
      
      //Legend Header which tells the bin
	    //TString legendheader = "Pt:["+ binstring+"],["+SideBandDefinitions[n]+" GeV";

	   /* legendheader.ReplaceAll("_",",");
	    legendheader.ReplaceAll("m","-");
	    legendheader.ReplaceAll("p",".");
	    legendheader.Append("]");
     */

	   // legend->SetHeader(legendheader.Data());

      //------DRAWING AND LEGENDS --------
     h1[n]->SetLineColor(n+1);
     // h1[n]->SetLineStyle(n+1);
      h1[n]->SetLineWidth(2);
      //legend->Draw();//make them overlap for comparison
      h1[n]->Draw("same");       
 
	if(numbersigmas != 0){
	  mg->Draw();
	  //legendAllGraphs->Draw("same");
	}
      }//end of loop over all sidebands
    
  //  (0.37,0.59,0.57,0.79)
  	TLegend *legendAllGraphs = new TLegend(0.47,0.69,0.57,0.79); 
    legendAllGraphs->SetTextSize(0.02);
  	legendAllGraphs->SetFillColor(kWhite);
  	legendAllGraphs->SetLineColor(kWhite);
	
  
    legendAllGraphs->AddEntry(h1[0],SideBandDefinitions[0]+"GeV","l"); 
    legendAllGraphs->AddEntry(h1[1],SideBandDefinitions[1]+"GeV","l"); 
    legendAllGraphs->AddEntry(h1[2],SideBandDefinitions[2]+"GeV","l"); 
    legendAllGraphs->AddEntry(h1[3],SideBandDefinitions[3]+"GeV","l"); 
    legendAllGraphs->AddEntry(h1[4],SideBandDefinitions[4]+"GeV","l");    
    legendAllGraphs->Draw("same");   
    canvas->Print(("PNGSameFakeTemps"+binstring+".png").Data());
    canvas->Print(("SVGSameFakeTemps"+binstring+".eps").Data());
    legendAllGraphs->DeleteEntry();
 
  }//end of loop over all bins
    histojetfile->cd();
    histojetfile->Close();
    
    FRhistosfile->cd();
    FRhistosfile->Close();

}//end of method
