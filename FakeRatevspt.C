#include "TH2F.h"
#include "TH1D.h"
#include "TROOT.h"
#include "TSystem.h"
#include "TH1F.h"
#include "TF1.h"
#include "RooHistPdf.h"
#include "RooRealVar.h"
#include "RooPlot.h"
#include "RooDataHist.h"
#include "RooAddPdf.h"
#include "RooExtendPdf.h"
#include "RooNDKeysPdf.h"
#include "RooFitResult.h"
#include "TFile.h"
#include "TLegend.h"
#include "TText.h"
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TStyle.h"

#include <vector>
#include <algorithm>
#include <iostream>
void test(int numbersigmas = 0, Bool_t debugtest = true)
{

  using namespace RooFit;
  using namespace std;

  TCanvas *canvas = new TCanvas("canvas","canvas",900,100,500,500);

  gSystem->Load("libRooFit"); 
  gSystem->AddIncludePath("-I$ROOFITSYS/include");


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
  unsigned int templatevarsloopmax = 1;//sinin with conv safe veto, sinin, ch isol
  unsigned int binsloopmax = 1;//pt, eta, phi, pu

  TF1 *FRfunc[sidebandloopmax];
  TGraphErrors *FRgraph[sidebandloopmax];

  //Begin loop for sidebands
for(unsigned int n =0;n<sidebandloopmax; n++){ 
	
  //----------Open .root Templates 

  //All the Jet Templates
  TFile *histojetdenfile = TFile::Open("/afs/cern.ch/user/c/ciperez/CMSSW_7_4_5/src/TemplateHistosJetCheckBinsEndcapsLoose.root");
  TFile *histojetfile = TFile::Open("/afs/cern.ch/user/c/ciperez/CMSSW_7_4_5/src/FakeTemplates_var_SideBands.root");
  
  //Real Photon Templates
  TFile *historealmcfile = TFile::Open("/afs/cern.ch/user/c/ciperez/CMSSW_7_4_5/src/RealPhotonTemplatesEndCaps.root");
  
  //--- Write NEW .root Historams for Fake Rate
  TFile *FRhistosfile = new TFile("FakeRatePlotsCheckBins.root","recreate");
	
//  for(unsigned int m = 0; m<templatevarsloopmax; m++){
   for(unsigned int l = 0; l<binsloopmax; l++){


  TMultiGraph *mg = new TMultiGraph();
	  
  std::vector<float> fakeratevalues;
  std::vector<float> fakerateptvalues;
  std::vector<float> fakerateerrorvalues;
 
	//Begin loop for bins  
  for(unsigned int k = 0;k<allbins[0].size()-1;k++){
 // for(unsigned int k = 0;k<1;k++){
	    float binlow = allbins[0][k];
	    float binmax = allbins[0][k+1];

	    TString binstring = TString::Format("%4.2f_%4.2f",binlow,binmax);
	    binstring.ReplaceAll(".00","");
	    binstring.ReplaceAll("-","m");
	    binstring.ReplaceAll(".","p");
	    binstring.ReplaceAll("10000","Inf");
	    cout<<binstring.Data()<<endl;

      //Histograms for templates
      //Get histograms from each of the histojetfiles declared earlier
	   
      //Numerator Fakes - FakePhotonNumEndCaps.root - FakePhoton_num2040... 
      TH1F *h1 = (TH1F*)histojetfile->Get(("histoSininWithPixelSeedVsCHFakeJetptbin"+binstring+SideBandDefinitions[n]).Data());// .Data() changes to char*
	  //  histoSininWithPixelSeedVsCHFakeJetptbin"+binstring+"Sideband3_6
      h1->Print();
     
      //Numerator Real Photons - RealPhotonTemplatesEndCaps.root - EndCapsMCReal_20_40
	    TH1F *h2 = (TH1F*)historealmcfile->Get(("EndCapsMCReal_"+binstring).Data());
	    h2->Print();
	   
      //Numerator Templates - Num_Templates.root - num2040... 
      TH1F *hData = (TH1F*)histojetdenfile->Get(("histoSininWithPixelSeedDataJetptbin"+binstring).Data());
	    hData->Print();

      //Denominator Templates - Denominator_FREndCaps.root -FakePhoton_den2040...
	    TH1F *hnum = (TH1F*)histojetdenfile->Get(("histoSininWithPixelSeedTightAndFakeJetptbin"+binstring).Data());
	    hnum->Print();

	    //avoiding 0 entries in the histograms
	    //fake and real mc histos are the most critical
	    for(int bincount = 1; bincount <= h1->GetNbinsX();bincount++){
	      if(h1->GetBinContent(bincount) == 0.) h1->SetBinContent(bincount,1.e-6);
	    }
	    for(int bincount = 1; bincount <= h2->GetNbinsX();bincount++){
	      if(h2->GetBinContent(bincount) == 0.) h2->SetBinContent(bincount,1.e-6);
	    }

	    int ndataentries = hData->GetEntries();

	    float sininmin = 0.; //? sigmaIetaIeta 
	    float sininmax = 0.1; //? sigmaIetaIeta 
      
      // ----------------- Probability Density Function 

	    TString roofitvartitle = "#sigma_{i #eta i #eta}";
       
	    RooRealVar sinin("sinin",roofitvartitle.Data(),sininmin,sininmax);
	    sinin.setRange("sigrange",0.018,0.06); //? this is the range because? Need to recall.
      //sinin.setRange("sigrange",0.005, 0.011);

      //Fake Template pdf
	    RooDataHist faketemplate("faketemplate","fake template",sinin,h1);
	    RooHistPdf fakepdf("fakepdf","test hist fake pdf",sinin,faketemplate);
      
      //Real Template pdf
	    RooDataHist realtemplate("realtemplate","real template",sinin,h2);
	    RooHistPdf realpdf("realpdf","test hist real pdf",sinin,realtemplate);
     
      //Data to be fitted to
	    RooDataHist data("data","data to be fitted to",sinin,hData);

	    
      //Declaration of Variables for Fake Rate
      RooRealVar fsig("fsig","signal fraction",0.1,0,1);// 

	    RooRealVar signum("signum","signum",0,ndataentries);// #of real contamination
	    RooRealVar fakenum("fakenum","fakenum",0,ndataentries); //# of fake

      //Extend 
	    RooExtendPdf extpdfsig("Signal","extpdfsig",realpdf,signum,"sigrange");
	    RooExtendPdf extpdffake("Background","extpdffake",fakepdf,fakenum,"sigrange");

	    RooAddPdf model("model","sig + background",RooArgList(extpdfsig,extpdffake));


      //----------- FITTING TO DATA -------------------
	   RooFitResult* fitResult = model.fitTo(data,RooFit::Minos());
     //Double_t fit_res = fitResult->minNll();
     cout<<fitResult->minNll()<<endl;
     //cout << "FITRESULT" << fit_res  <<endl;  
    //  model.chi2FitTo(data);
     //Define Plot Frame 
	    RooPlot *xframe = sinin.frame();
	    xframe->SetTitle("Fake Rate vs pt");

	    data.plotOn(xframe);
	    model.plotOn(xframe);
	    model.plotOn(xframe,Components(extpdfsig),LineColor(2),LineStyle(2));
	    model.plotOn(xframe,Components(extpdffake),LineColor(8),LineStyle(2));

	    canvas->cd();
      canvas->SetGridx(true);
      canvas->SetGridy(true);

	    xframe->GetXaxis()->SetRangeUser(0.,0.1);
	    float xframemax = xframe->GetMaximum();
	    xframe->GetYaxis()->SetRangeUser(1.e-1,1.1*xframemax);

	    xframe->Draw();
      //Double_t chi2_temp = xframe->chiSquare("model","data"); 
      //Double_t chi2_temp = xframe->chiSquare("","data"); 
    //cout<< "TEMPLATE FIT CHI2:"<< chi2_temp << endl;     

	    float fakevalue = fakenum.getValV();
	    float fakeerrorhi = fakenum.getErrorHi();
	    float fakeerrorlo = fakenum.getErrorLo();
	    float fakeerrormax = max(fabs(fakeerrorhi),fabs(fakeerrorlo));
	    TString fakeresults = TString::Format("Fake results %f +%f %f",fakevalue,fakeerrorhi,fakeerrorlo);

	  //  canvas->SetLogy(0); 
      
      float sigvalue = signum.getValV();
	    float sigerrorhi = signum.getErrorHi();
	    float sigerrorlo = signum.getErrorLo();
	    float sigerrormax = max(fabs(sigerrorhi),fabs(sigerrorlo));
	    TString sigresults = TString::Format("Signal results %f +%f %f",sigvalue,sigerrorhi,sigerrorlo);

	    cout<<"sigvalue "<<sigvalue<<" sigerrormax "<<sigerrormax<<" sigerrormax/sigvalue "<<sigerrormax/sigvalue<<endl;
	    cout<<"fakevalue "<<fakevalue<<" fakeerrormax "<<fakeerrormax<<" fakeerrormax/fakevalue "<<fakeerrormax/fakevalue<<endl;

	    cout<<fakeresults.Data()<<endl;
	    cout<<sigresults.Data()<<endl;

	    float Ratio = (fakevalue/(fakevalue+sigvalue));
	    float RatioError = Ratio*sqrt( ((fakeerrormax/fakevalue)*(fakeerrormax/fakevalue) + (sigerrormax/sigvalue)*(sigerrormax/sigvalue)) );
	    cout<<"Ratio "<<Ratio<<" +- "<<RatioError<<endl;

      //---------------------- FAKE RATE CALCULATOR -------------------------
	    //find the bin corresponding to 0.011
	    //int binnr = 22;
      int binnr = 34;
      	   
	   
      //compute the integral of tight and fake in that range
	    float numerator = hData->Integral(0,binnr); //Is the Integral function part of RooFit?
	    float denominator = hnum->Integral();
	   
     
      float contamination = sigvalue;
	    cout<<numerator<<" "<<denominator<<" "<<contamination<<endl;

	    float fakerate = (numerator-contamination)/denominator;
	    float fakerateerror = fakerate * sqrt( (1./numerator) + (1./denominator) + ((sigerrormax/sigvalue)*(sigerrormax/sigvalue)) );

	    cout<<"Here: "<<fakerate<<" "<<fakerateerror<<endl;

	    //fakerateptvalues.push_back(hnumvspt->GetMean());
	    fakeratevalues.push_back(fakerate);
	    fakerateerrorvalues.push_back(fakerateerror);

	    cout<<""<<endl;
	    cout<<"***********************************************************"<<endl;
	    cout<<"So in sigmaietaieta < 0.011 there are "<<contamination<<" to subtract from "<<numerator<<endl;
	    cout<<"and thus there are "<<(numerator-contamination)<<" total tight entries "<<endl;
	    cout<<"and there are "<<denominator<<" entries in the tight and fake sample "<<endl;
	    cout<<"and so the fake rate for the pt range "<<binlow<<"-"<<binmax<<" is "<<fakerate<<"+-"<<fakerateerror<<endl;
	    cout<<"***********************************************************"<<endl;
	    cout<<""<<endl;

	  }//loop on all bins
  
//********* FAKE RATE PLOTS vs PT 

	  cout<<fakeratevalues.size()<<endl;
	  for(int k=0;k<fakeratevalues.size();k++){
	    cout<<"Range: ["<<allbins[l][k]<<"-"<<allbins[l][k+1]<<"] --> fake rate: ("<<fakeratevalues[k]*100<<" +- "<<fakerateerrorvalues[k]*100<<")%"<<endl;    
	  }//end of loop over all fake rate values
       
    FRgraph[n] = new TGraphErrors(fakeratevalues.size());
	  for(int k=0;k<fakeratevalues.size();k++){
	    cout<<(allbins[l][k+1]+allbins[l][k])/2.<<endl;
	    FRgraph[n]->SetPoint(k,(allbins[l][k+1]+allbins[l][k])/2.,fakeratevalues[k]);
	    FRgraph[n]->SetPointError(k,(allbins[l][k+1]-allbins[l][k])/2.,fakerateerrorvalues[k]);
	  }//end of filling TGraph

   //****** Axis Labels and Title
	  FRgraph[n]->SetTitle("Fake Rate vs pt"); 
	  FRgraph[n]->GetYaxis()->SetRangeUser(0.05,0.3);
	  FRgraph[n]->GetYaxis()->SetTitle("#epsilon_{FR}");
	  FRgraph[n]->GetXaxis()->SetTitle((GraphXTitleString[l]).Data());
	  
    TString FakeRateFunctionName = "FakeRateFunctionJetRun2012ABCDLoose"+SideBandDefinitions[n];
    FRfunc[n] = new TF1(FakeRateFunctionName.Data(),"[0]+[1]/pow(x,[2])", allbins[l][0],allbins[l][fakeratevalues.size()]);
    FRfunc[n]->SetParameters(1.,1.,1.);
	  FRgraph[n]->Fit(FakeRateFunctionName.Data(),"R");//Does the fitting
    
    //Goodness of fit: chi2
    TF1 *f[sidebandloopmax];
    f[n] = FRgraph[n]->GetFunction(FakeRateFunctionName.Data());
    Double_t chi2 = f[n]->GetChisquare();  
   // }//end of loop systematics
    // ********************************************
	  cout<<"***** Fit function parameters *****"<<endl;
	  cout<<FRfunc[n]->GetParameter(0)<<" "
	      <<FRfunc[n]->GetParameter(1)<<" "
	      <<FRfunc[n]->GetParameter(2)<<" "
	      <<endl;

	  cout<<"***** Fit function errors *****"<<endl;
	  cout<<FRfunc[n]->GetParError(0)<<" "
	      <<FRfunc[n]->GetParError(1)<<" "
	      <<FRfunc[n]->GetParError(2)<<" "
	      <<endl;


   canvas->Print(("FakeRateJetRun2012"+SideBandDefinitions[n]+".png").Data(),"png");
    cout<< "word" << endl;

	  FRhistosfile->cd();
	 
   cout<< "word" << endl;
 
	  FRgraph[n]->SetLineColor(n+2);
 

cout<< "word" << endl;
    FRgraph[n]->SetLineWidth(1);
    FRgraph[n]->SetFillStyle(4000);
    FRgraph[n]->SetMarkerColor(1);
	  mg->Add(FRgraph[n]); 
//	}//end of loop over systematic errors

 cout<< "word" << endl;
   
//	/if(numbersigmas == 0){
	    if(n==4){
      FRgraph[n]->Draw();
      cout << "GOODNESS OF FIT: chi2 = " << chi2 << endl;}
      mg->Draw(); //draws out the fitted curve
	//  legendAllGraphs->Draw("same");
   // mg->Write();
//	}

      }//end of loop over all pt bins 
   
    histojetfile->cd();
    histojetfile->Close();
    
    histojetdenfile->cd();
    histojetdenfile->Close();

    historealmcfile->cd();
    historealmcfile->Close();

    FRhistosfile->cd();
    FRhistosfile->Close();
  
  }//end of loop over sideband definitions
  // ----- DEFINE LEGENDS and their position
	    TLegend *legend = new TLegend(0.62,0.65,0.82,0.85); //Why these values? 
	    legend->SetTextSize(0.02);
	    legend->SetFillColor(kWhite);
	    legend->SetLineColor(kWhite);
      
      //Legend Hei/n
      //ader which tells the bin
	    TString legendheader = "Side Band: CHIsolation";

	    legendheader.ReplaceAll("_",",");
	    legendheader.ReplaceAll("m","-");
	    legendheader.ReplaceAll("p",".");
	   // legendheader.Append("]");

	    cout<<"legend "<<legendheader.Data()<<endl;
	    legend->SetHeader(legendheader.Data());

    legend->AddEntry(FRgraph[0],SideBandDefinitions[0]+" GeV","l");  
    legend->AddEntry(FRgraph[1],SideBandDefinitions[1]+" GeV","l");
    legend->AddEntry(FRgraph[2],SideBandDefinitions[2]+ " GeV","l");  
    legend->AddEntry(FRgraph[3],SideBandDefinitions[3]+ " GeV","l");
    legend->AddEntry(FRgraph[4],SideBandDefinitions[4]+ " GeV","l");
    legend->Draw("same");//make them overlap for comparison  
    canvas->Print(("FakeRateJetRun2012"+SideBandDefinitions[4]+".png").Data(),"png");
    canvas->Print(("FakeRateJetRun2012"+SideBandDefinitions[4]+".C").Data(),"cxx");

    canvas->Update();
}//end of method
