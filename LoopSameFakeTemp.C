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
	TLegend *legendAllGraphs = new TLegend(0.37,0.59,0.57,0.79);
	legendAllGraphs->SetTextSize(0.02);
	legendAllGraphs->SetFillColor(kWhite);
	legendAllGraphs->SetLineColor(kWhite);
	  
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
  
     // PADS FOR OVERLAYING
    // TPad *pad = new TPad("pad", "",0,0,1,1);
    // pad->Draw();
    // pad->cd(); 


      //---Begin loop for sidebands
      for(unsigned int n =0;n<sidebandloopmax; n++){ 
      
      //PADS FOR OVERLAYING 
     // TPad *pad2 = new TPad("pad2","",0,0,1,1);
     // pad2->SetFillStyle(4000); //will be transparent

      //****** HERE WE OVERLAY THE TEMPLATES FOR THE SAME PT FOR DIFFERENT SIDEBANDS      
      //Get histograms from each of the histojetfiles declared earlier 
      TH1F *h1[sidebandloopmax]; 
      h1[n] = (TH1F*)histojetfile->Get(("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring+SideBandDefinitions[n]).Data());
     // h1->Draw("same");
      
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
     // float padmax = pad2->GetMaximum();
      //pad2->GetYaxis()->SetRangeUser(1.e-1,1.1*padmax);
      float padmax = h1[n]->GetMaximum();
      h1[n]->GetYaxis()->SetRangeUser(1.e-1,2.2*padmax);
      h1[n]->Draw("same");
	    /*xframe->GetXaxis()->SetRangeUser(0.,0.1);
	    float xframemax = xframe->GetMaximum();
	    xframe->GetYaxis()->SetRangeUser(1.e-1,1.1*xframemax);
      xframe->Draw();
     */
      // ----- DEFINE LEGENDS and their position
	    TLegend *legend = new TLegend(0.62,0.65,0.82,0.85); //Why these values? 
	    legend->SetTextSize(0.02);
	    legend->SetFillColor(kWhite);
	    legend->SetLineColor(kWhite);
             
      //TObjecs for legends
      TObject *band3_6;
      TObject *band4_7;
      TObject *band4_10;
      TObject *band5_8;
      TObject *band5_10;
    
        
      //Legend Header which tells the bin
	    //TString legendheader = "Pt:["+ binstring+"],["+SideBandDefinitions[n]+" GeV";

	   /* legendheader.ReplaceAll("_",",");
	    legendheader.ReplaceAll("m","-");
	    legendheader.ReplaceAll("p",".");
	    legendheader.Append("]");
     */

	   // cout<<"legend "<<legendheader.Data()<<endl;
	   // legend->SetHeader(legendheader.Data());
      legend->AddEntry(h1[n],SideBandDefinitions[n],"l"); 
     // legend->AddEntry(h1[2],SideBandDefinitions[1],"l"); 
     // legend->AddEntry(h1[3],SideBandDefinitions[2],"l"); 
     // legend->AddEntry(h1[4],SideBandDefinitions[3],"l"); 
      //legend->AddEntry(h1[5],SideBandDefinitions[4],"l"); 
   
      //------DRAWING AND LEGENDS --------
     // h1->SetLineColor(n+1);
      h1[1]->SetLineStyle(5-n);
      legend->Draw("same");//make them overlap for comparison
      h1[1]->Draw("same");      
      
     // canvas->Print(("Endcapfits_SideBand_"+SideBandDefinitions[n]+binstring+".C").Data());
 
	if(numbersigmas != 0){
	  mg->Draw();
	  legendAllGraphs->Draw("same");
	}
      }//end of loop over all sidebands
   canvas->Print(("PNGSameFakeTemps"+binstring+".png").Data());
  }//end of loop over all bins

    histojetfile->cd();
    histojetfile->Close();
    
    FRhistosfile->cd();
    FRhistosfile->Close();

}//end of method
