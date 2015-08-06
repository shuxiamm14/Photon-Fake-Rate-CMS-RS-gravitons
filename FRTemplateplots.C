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
  SideBandDefinitions.push_back("SideBand5_10");



  //   ------------FOR TESTING----------------
  unsigned int sidebandloopmax = 1;//5_10, 5_20, ...
  unsigned int templatevarsloopmax = 1;//sinin with conv safe veto, sinin, ch isol
  unsigned int binsloopmax = 1;//pt, eta, phi, pu

  //----------Open .root Templates 
  
  //All the Jet Templates
  TFile *histojetnumfile = TFile::Open("/afs/cern.ch/user/c/ciperez/CMSSW_7_4_5/src/FakePhotonNumEndCaps.root");
  TFile *histojetdenfile = TFile::Open("/afs/cern.ch/user/c/ciperez/CMSSW_7_4_5/src/Denominator_FREndCaps.root");
  TFile *histojetdatafile = TFile::Open("/afs/cern.ch/user/c/ciperez/CMSSW_7_4_5/src/Num_Templates.root");
  
  //Real Photon Templates
  TFile *historealmcfile = TFile::Open("/afs/cern.ch/user/c/ciperez/CMSSW_7_4_5/src/RealPhotonTemplatesEndCaps.root");
  
  //--- Write NEW .root Historams for Fake Rate
  TFile *FRhistosfile = new TFile("FakeRatePlotsCheckBins.root","recreate");
       
	//loop on error systematics
	
  for(unsigned int m = 0; m<templatevarsloopmax; m++){
    for(unsigned int l = 0; l<binsloopmax; l++){


  TMultiGraph *mg = new TMultiGraph();
	TLegend *legendAllGraphs = new TLegend(0.37,0.59,0.57,0.79);
	legendAllGraphs->SetTextSize(0.02);
	legendAllGraphs->SetFillColor(kWhite);
	legendAllGraphs->SetLineColor(kWhite);

	  
  std::vector<float> fakeratevalues;
  std::vector<float> fakerateptvalues;
  std::vector<float> fakerateerrorvalues;
	  
  for(unsigned int k = 0;k<allbins[0].size()-1;k++){
 // for(unsigned int k = 0;k<1;k++){
	    float binlow = allbins[0][k];
	    float binmax = allbins[0][k+1];

	    TString binstring = TString::Format("%4.2f%4.2f",binlow,binmax);
	    binstring.ReplaceAll(".00","");
	    binstring.ReplaceAll("-","m");
	    binstring.ReplaceAll(".","p");
	    binstring.ReplaceAll("10000","Inf");
	    cout<<binstring.Data()<<endl;

      //Histograms for templates
      //Get histograms from each of the histojetfiles declared earlier
	   
      //Numerator Fakes - FakePhotonNumEndCaps.root - FakePhoton_num2040... 
      TH1F *h1 = (TH1F*)histojetnumfile->Get(("FakePhoton_num"+binstring).Data());// .Data() changes to char*
	    h1->Print();
     
      //Numerator Real Photons - RealPhotonTemplatesEndCaps.root - EndCapsMCReal_20_40
	    TH1F *h2 = (TH1F*)historealmcfile->Get(("EndCapsMCReal_"+binstring).Data());
	    h2->Print();
	   
      //Numerator Templates - Num_Templates.root - num2040... 
      TH1F *hData = (TH1F*)histojetdatafile->Get(("num"+binstring).Data());
	    hData->Print();

      //Denominator Templates - Denominator_FREndCaps.root -FakePhoton_den2040...
	    TH1F *hnum = (TH1F*)histojetdenfile->Get(("FakePhoton_den"+binstring).Data());
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
	    model.fitTo(data,RooFit::Minos());
      
      //Define Plot Frame 
	    RooPlot *xframe = sinin.frame();
	    xframe->SetTitle("");

	    data.plotOn(xframe);
	    model.plotOn(xframe);
	    model.plotOn(xframe,Components(extpdfsig),LineColor(2),LineStyle(2));
	    model.plotOn(xframe,Components(extpdffake),LineColor(8),LineStyle(2));

	    canvas->cd();

	    xframe->GetXaxis()->SetRangeUser(0.,0.1);
	    float xframemax = xframe->GetMaximum();
	    xframe->GetYaxis()->SetRangeUser(1.e-1,1.1*xframemax);

	    xframe->Draw();
     
      // ----- DEFINE LEGENDS and their position
	    TLegend *legend = new TLegend(0.62,0.65,0.82,0.85); //Why these values? 
	    legend->SetTextSize(0.02);
	    legend->SetFillColor(kWhite);
	    legend->SetLineColor(kWhite);
      
      //Legend Header which tells the bin
	    TString legendheader = "Pt (GeV):["+ binstring;

	    legendheader.ReplaceAll("_",",");
	    legendheader.ReplaceAll("m","-");
	    legendheader.ReplaceAll("p",".");
	    legendheader.Append("]");

	    cout<<"legend "<<legendheader.Data()<<endl;
	    legend->SetHeader(legendheader.Data());

	    TObject *objdata;  //What is TObect?
	    TObject *objmodel;
	    TObject *objsignal;
	    TObject *objfake;

	    for(int i=0;i<xframe->numItems();i++){
	      cout<<xframe->nameOf(i)<<endl;
	      TString objname = xframe->nameOf(i);
	      if(objname.Contains("data")) objdata = (TObject*)xframe->findObject(objname.Data());
	      if(objname.Contains("model") && !objname.Contains("Comp")) objmodel = (TObject*)xframe->findObject(objname.Data());
	      if(objname.Contains("model") && objname.Contains("Signal")) objsignal = (TObject*)xframe->findObject(objname.Data());
	      if(objname.Contains("model") && objname.Contains("Background")) objfake = (TObject*)xframe->findObject(objname.Data());
	    }

      //------ LEGEND --------
	    legend->AddEntry(objdata,"Data","lp");
	    legend->AddEntry(objsignal,"Signal","l");
	    legend->AddEntry(objfake,"Background","l");
	    legend->AddEntry(objmodel,"Signal + Background","l");
	    legend->Draw("same");//make them overlap for comparison	    
      
      canvas->Print(("TemplateFitResultEndcap"+binstring+".png").Data());
      canvas->Print(("TemplateFitResultEndcap"+binstring+".C").Data());

	    float fakevalue = fakenum.getValV();
	    float fakeerrorhi = fakenum.getErrorHi();
	    float fakeerrorlo = fakenum.getErrorLo();
	    float fakeerrormax = max(fabs(fakeerrorhi),fabs(fakeerrorlo));
	    TString fakeresults = TString::Format("Fake results %f +%f %f",fakevalue,fakeerrorhi,fakeerrorlo);

	    //canvas->SetLogy(0); 
      
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

    /* 

	  cout<<fakeratevalues.size()<<endl;
	  for(int k=0;k<fakeratevalues.size();k++){
	    cout<<"Range: ["<<allbins[l][k]<<"-"<<allbins[l][k+1]<<"] --> fake rate: ("<<fakeratevalues[k]*100<<" +- "<<fakerateerrorvalues[k]*100<<")%"<<endl;    
	  }//end of loop over all fake rate values


    // *************************************************************-//
    
    // 
	  TGraphErrors *FRgraph = new TGraphErrors(fakeratevalues.size());
	  //TGraphAsymmErrors *FRgraph = new TGraphAsymmErrors(fakeratevalues.size());
	  for(int k=0;k<fakeratevalues.size();k++){
	    cout<<(allbins[l][k+1]+allbins[l][k])/2.<<endl;
	    FRgraph->SetPoint(k,(allbins[l][k+1]+allbins[l][k])/2.,fakeratevalues[k]);
	    FRgraph->SetPointError(k,(allbins[l][k+1]-allbins[l][k])/2.,fakerateerrorvalues[k]);
	  }//end of filling TGraph

	 // FRgraph->SetName("FakeRateEndCaps");
   //FRgraph->SetName(("FakeRateJetRun2012ABCD13JulLoose").Data());
	  FRgraph->SetTitle("");

	  canvas->cd();
	  //if(VarString[l].EqualTo("VsPt"))gStyle->SetOptFit(1111);

	  FRgraph->Draw("a*");

   
    // **********************************************************-//

    

     //  *****************************************
   
	  //float maxFRvalue = max_element(fakeratevalues.begin(),fakeratevalues.end());
	  FRgraph->GetYaxis()->SetRangeUser(0.,0.2);
	  FRgraph->GetYaxis()->SetTitle("#epsilon_{FR}");
	  FRgraph->GetXaxis()->SetTitle((GraphXTitleString[l]).Data());
	 // TString FakeRateFunctionName = "FakeRateFunctionJetRun2012ABCD13JulLoose";
	 // TF1 *FRfunc = new TF1(FakeRateFunctionName.Data(),"[0]+[1]/pow(x,[2])",allbins[l][0],allbins[l][fakeratevalues.size()]);
	 // FRfunc->SetParameters(1.,1.,1.);
	  if(l==0){
	    FRgraph->Fit(FakeRateFunctionName.Data(),"R");
	    FRgraph->Fit(FakeRateFunctionName.Data());
	    FRfunc->Draw("same");
	  }
    
  
    // ********************************************
	  cout<<"***** Fit function parameters *****"<<endl;
	  cout<<FRfunc->GetParameter(0)<<" "
	      <<FRfunc->GetParameter(1)<<" "
	      <<FRfunc->GetParameter(2)<<" "
	      <<endl;

	  cout<<"***** Fit function errors *****"<<endl;
	  cout<<FRfunc->GetParError(0)<<" "
	      <<FRfunc->GetParError(1)<<" "
	      <<FRfunc->GetParError(2)<<" "
	      <<endl;

	  if(!debugtest){
	    canvas->Print(("FakeRateJetRun2012ABCD13JulLoose.png").Data(),"png");
	    canvas->Print(("FakeRateJetRun2012ABCD13JulLoose.gif").Data(),"gif");
	    canvas->Print(("FakeRateJetRun2012ABCD13JulLoose.eps").Data(),"eps");
	    canvas->Print(("FakeRateJetRun2012ABCD13JulLoos.pdf").Data(),"pdf");
	    canvas->Print(("FakeRateJetRun2012ABCD13JulLoose.C").Data(),"cxx");
	  }

    // ************************************************
   
	  if(!debugtest){
	    if(count == 0){
	      FRhistosfile->cd();
	      FRgraph->Write();
	      FRfunc->Write();
	    }
	  }
	  if(numbersigmas != 0){
	    FRgraph->SetLineColor(count+numbersigmas+1);
	    FRgraph->SetMarkerColor(count+numbersigmas+1);
	    TString numsigmastring = TString::Format("%d #sigma",count);
	    legendAllGraphs->AddEntry(FRgraph,numsigmastring.Data(),"lep");
	  }

	  mg->Add(FRgraph);
//	}//end of loop over systematic errors

    */
	if(numbersigmas != 0){
	  mg->Draw();
	  legendAllGraphs->Draw("same");
	}

      }//end of loop over all variables (pt, eta, phi, pu)

     }//end of loop over template variables

    histojetnumfile->cd();
    histojetnumfile->Close();

    histojetdenfile->cd();
    histojetdenfile->Close();

    histojetdatafile->cd();
    histojetdatafile->Close();

    historealmcfile->cd();
    historealmcfile->Close();

    FRhistosfile->cd();
    FRhistosfile->Close();

 // }//end of loop over sideband definitions

}//end of method
