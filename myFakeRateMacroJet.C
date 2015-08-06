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

::vector<TString> TemplateVariables;
  TemplateVariables.push_back("SininWithPixelSeed");
  TemplateVariables.push_back("Sinin");
  TemplateVariables.push_back("CHIsol");

  //float ptbinsarray[] = {20.,40.,60.,80.,100.,120.,200.,600.,10000.};
  float ptbinsarray[] = {20.,40.,60.,80.,100.,120.,200.,600.};
  //float ptbinsarray[] = {20.,40.,60.,80.,100.,120.,200.,300.,600.};
  float etabinsarray[] = {-1.5,-1.3,-1.1,-0.9,-0.7,-0.5,-0.3,-0.1,0.1,0.3,0.5,0.7,0.9,1.1,1.3,1.5};
  float phibinsarray[] = {-180.,-160.,-140.,-120.,-100.,-80.,-60.,-40.,-20.,0.,20.,40.,60.,80.,100.,120.,140.,160.,180.};
  float pubinsarray[] = {0.,10.,15.,20.,25.,50.};

  std::vector<float> ptbins(ptbinsarray,ptbinsarray+sizeof(ptbinsarray)/sizeof(ptbinsarray[0]));
  std::vector<float> etabins(etabinsarray,etabinsarray+sizeof(etabinsarray)/sizeof(etabinsarray[0]));
  std::vector<float> phibins(phibinsarray,phibinsarray+sizeof(phibinsarray)/sizeof(phibinsarray[0]));
  std::vector<float> pubins(pubinsarray,pubinsarray+sizeof(pubinsarray)/sizeof(pubinsarray[0]));

  std::vector<std::vector<float> > allbins;
  allbins.push_back(ptbins);
  allbins.push_back(etabins);
  allbins.push_back(phibins);
  allbins.push_back(pubins);

  std::vector<TString> VarString;
  VarString.push_back("VsPt");
  VarString.push_back("VsEta");
  VarString.push_back("VsPhi");
  VarString.push_back("VsPileUp");

  std::vector<TString> HistoNameString;
  HistoNameString.push_back("ptbin");
  HistoNameString.push_back("etabin");
  HistoNameString.push_back("phibin");
  HistoNameString.push_back("pubin");

  std::vector<TString> GraphXTitleString;
  GraphXTitleString.push_back("p_{t} (GeV)");
  GraphXTitleString.push_back("#eta");
  GraphXTitleString.push_back("#phi (rad)");
  GraphXTitleString.push_back("N_{vtx}");

  std::vector<TString> SideBandDefinitions;
  SideBandDefinitions.push_back("SideBand5_10");
  //SideBandDefinitions.push_back("SideBand5_20");
  //SideBandDefinitions.push_back("SideBand5_50");
  //SideBandDefinitions.push_back("SideBand10_20");
  //SideBandDefinitions.push_back("SideBand5_Inf");


  //SideBandDefinitions.push_back("SideBand2_6");

  //   SideBandDefinitions.push_back("SideBand0p7_10");
  //   SideBandDefinitions.push_back("SideBand0p7_Inf");
  //   SideBandDefinitions.push_back("SideBand1p5_10");
  //   SideBandDefinitions.push_back("SideBand1p5_50");
  //   SideBandDefinitions.push_back("SideBand2p6_10");
  //   SideBandDefinitions.push_back("SideBand2p6_50");
  //   SideBandDefinitions.push_back("SideBand2p6_Inf");

//   unsigned int sidebandloopmax = SideBandDefinitions.size();
//   unsigned int templatevarsloopmax = TemplateVariables.size();
//   unsigned int binsloopmax = allbins.size();

  //   ------------FOR TESTING----------------
  unsigned int sidebandloopmax = 1;//5_10, 5_20, ...
  unsigned int templatevarsloopmax = 1;//sinin with conv safe veto, sinin, ch isol
  unsigned int binsloopmax = 1;//pt, eta, phi, pu

  for(unsigned int n = 0;n<sidebandloopmax;n++){


    TFile *histojetfile = TFile::Open("tempodir/TemplateHistosJetSideBand5_10Loose.root");
    TFile *historealmcfile = TFile::Open("tempodir/TemplateHistosRealMCTestLoose.root");

    TFile *FRhistosfile = new TFile("FakeRatePlotsCheckBins.root","recreate");

    for(unsigned int m = 0;m<templatevarsloopmax;m++){
    
      for(unsigned int l = 0;l<binsloopmax;l++){
      
	//loop on error systematics
	TMultiGraph *mg = new TMultiGraph();
	TLegend *legendAllGraphs = new TLegend(0.37,0.59,0.57,0.79);
	legendAllGraphs->SetTextSize(0.02);
	legendAllGraphs->SetFillColor(kWhite);
	legendAllGraphs->SetLineColor(kWhite);

	for(int count = -1*numbersigmas;count<=numbersigmas;count++){
	  
	  std::vector<float> fakeratevalues;
	  std::vector<float> fakerateptvalues;
	  std::vector<float> fakerateerrorvalues;
	  
	  for(unsigned int k = 0;k<allbins[l].size()-1;k++){

	    float binlow = allbins[l][k];
	    float binmax = allbins[l][k+1];

	    TString binstring = TString::Format("%4.2f_%4.2f",binlow,binmax);
	    binstring.ReplaceAll(".00","");
	    binstring.ReplaceAll("-","m");
	    binstring.ReplaceAll(".","p");
	    binstring.ReplaceAll("10000","Inf");
	    cout<<binstring.Data()<<endl;

	    // get histos
	    // 	  TFile *histojetfile = TFile::Open("tempodir/TemplateHistosJet"+SideBandDefinitions[n]+".root");
	    // 	  TFile *historealmcfile = TFile::Open("tempodir/TemplateHistosRealMC.root");

	    TH1F *h1 = (TH1F*)histojetfile->Get(("histo"+TemplateVariables[m]+"FakeJet"+HistoNameString[l]+binstring).Data());
	    h1->Print();
	    TH1F *h2 = (TH1F*)historealmcfile->Get(("histo"+TemplateVariables[m]+"RealMC"+HistoNameString[l]+binstring).Data());
	    h2->Print();
	    TH1F *hData = (TH1F*)histojetfile->Get(("histo"+TemplateVariables[m]+"DataJet"+HistoNameString[l]+binstring).Data());
	    hData->Print();
	    TH1F *hnum = (TH1F*)histojetfile->Get(("histo"+TemplateVariables[m]+"TightAndFakeJet"+HistoNameString[l]+binstring).Data());
	    hnum->Print();

	    // 	    TH1F *hnumvspt = (TH1F*)histojetfile->Get(("histo"+TemplateVariables[m]+"VsPtTightAndFakeJet"+HistoNameString[l]+binstring).Data());
	    // 	    hnumvspt->Print();
	    // 	    cout<<hnumvspt->GetMean()<<endl;

	    //avoiding 0 entries in the histograms
	    //fake and real mc histos are the most critical
	    for(int bincount = 1; bincount <= h1->GetNbinsX();bincount++){
	      if(h1->GetBinContent(bincount) == 0.) h1->SetBinContent(bincount,1.e-6);
	    }
	    for(int bincount = 1; bincount <= h2->GetNbinsX();bincount++){
	      if(h2->GetBinContent(bincount) == 0.) h2->SetBinContent(bincount,1.e-6);
	    }

	    int ndataentries = hData->GetEntries();

	    float sininmin = 0.;
	    float sininmax = 0.03;
	    //float sininmax = 0.020;
	    //if(l==0 && m!= 2 && binlow >= 100.) sininmax = 0.015;	 
	    if(TemplateVariables[m].EqualTo("CHIsol")){sininmin = 0.;sininmax = 20.;}

	    TString roofitvartitle = "#sigma_{i #eta i #eta}";
	    if(TemplateVariables[m].EqualTo("CHIsol"))roofitvartitle = " CH isolation (GeV)";

	    RooRealVar sinin("sinin",roofitvartitle.Data(),sininmin,sininmax);
	    //sinin.setRange("sigrange",0.005,0.011);
	    sinin.setRange("sigrange",0.005,0.012);
	    if(TemplateVariables[m].EqualTo("CHIsol")) sinin.setRange("sigrange",0.,0.7);

	    RooDataHist faketemplate("faketemplate","fake template",sinin,h1);
	    RooHistPdf fakepdf("fakepdf","test hist fake pdf",sinin,faketemplate);
	    //RooHistPdf fakepdf("fakepdf","test hist fake pdf",sinin,faketemplate,5);

	    RooDataHist realtemplate("realtemplate","real template",sinin,h2);
	    RooHistPdf realpdf("realpdf","test hist real pdf",sinin,realtemplate);
	    //RooHistPdf realpdf("realpdf","test hist real pdf",sinin,realtemplate,5);

	    RooDataHist data("data","data to be fitted to",sinin,hData);

	    RooRealVar fsig("fsig","signal fraction",0.1,0,1);

	    RooRealVar signum("signum","signum",0,ndataentries);
	    RooRealVar fakenum("fakenum","fakenum",0,ndataentries);


	    //RooNDKeysPdf smoothrealpdf("smoothrealpdf","test smooth real pdf",sinin,realpdf,"am");



	    //RooExtendPdf extpdfsig("extpdfsig","extpdfsig",realpdf,signum,"sigrange");
	    RooExtendPdf extpdfsig("Signal","extpdfsig",realpdf,signum,"sigrange");
	    //RooExtendPdf *extpdfsig = new RooExtendPdf("Signal","extpdfsig",realpdf,signum,"sigrange");
	    RooExtendPdf extpdffake("Background","extpdffake",fakepdf,fakenum,"sigrange");

	    RooAddPdf model("model","sig + background",RooArgList(extpdfsig,extpdffake));
	    //RooAddPdf model("model","sig + background",RooArgList(realpdf,fakepdf),fsig);

	    //RooRealVar nsig("nsig","signal events",5000,0.,38000.);
	    //RooRealVar nbackgd("nbackgd","backgd events",10000,0.,38000.);
	    //RooAddPdf model("model","sig + background",RooArgList(realpdf,fakepdf),RooArgList(nsig,nbackgd));

	    model.fitTo(data,RooFit::Minos());

	    RooPlot *xframe = sinin.frame();
	    xframe->SetTitle("");

	    //gStyle->SetOptStat(0);
	    //gStyle->SetOptFit(0);

	    data.plotOn(xframe);
	    model.plotOn(xframe);
	    model.plotOn(xframe,Components(extpdfsig),LineColor(2),LineStyle(2));
	    model.plotOn(xframe,Components(extpdffake),LineColor(8),LineStyle(2));

	    canvas->cd();

	    xframe->GetXaxis()->SetRangeUser(0.,0.03);
	    if(TemplateVariables[m].EqualTo("CHIsol"))xframe->GetXaxis()->SetRangeUser(0.,10.);
	    float xframemax = xframe->GetMaximum();
	    xframe->GetYaxis()->SetRangeUser(1.e-1,1.1*xframemax);

	    xframe->Draw();

	    TLegend *legend = new TLegend(0.62,0.65,0.82,0.85);
	    legend->SetTextSize(0.02);
	    legend->SetFillColor(kWhite);
	    legend->SetLineColor(kWhite);

	    TString legendheader = binstring;

	    legendheader.ReplaceAll("_",",");
	    legendheader.ReplaceAll("m","-");
	    legendheader.ReplaceAll("p",".");

	    if(VarString[l].EqualTo("VsPt"))legendheader.Prepend("p_{t} (GeV): [");
	    if(VarString[l].EqualTo("VsEta"))legendheader.Prepend("#eta : [");
	    if(VarString[l].EqualTo("VsPhi"))legendheader.Prepend("#phi (deg): [");
	    if(VarString[l].EqualTo("VsPileUp"))legendheader.Prepend("N_{vtx}: [");

	    legendheader.Append("]");

	    cout<<"legend "<<legendheader.Data()<<endl;
	    legend->SetHeader(legendheader.Data());

	    //legend->AddEntry(Components(extpdffake),extpdffake.GetName(),"l");
	    //legend->Draw("same");

	    TObject *objdata;
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

	    legend->AddEntry(objdata,"Data","lp");
	    legend->AddEntry(objsignal,"Signal","l");
	    legend->AddEntry(objfake,"Background","l");
	    legend->AddEntry(objmodel,"Signal + Background","l");
	    legend->Draw("same");

	    if(!debugtest){
	      canvas->Print(("FakeRateTemplatePlotsJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+"/TemplatePlot"+TemplateVariables[m]+VarString[l]+binstring+".png").Data(),"png");
	      canvas->Print(("FakeRateTemplatePlotsJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+"/TemplatePlot"+TemplateVariables[m]+VarString[l]+binstring+".eps").Data(),"eps");
	      canvas->Print(("FakeRateTemplatePlotsJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+"/TemplatePlot"+TemplateVariables[m]+VarString[l]+binstring+".gif").Data(),"gif");
	      canvas->Print(("FakeRateTemplatePlotsJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+"/TemplatePlot"+TemplateVariables[m]+VarString[l]+binstring+".pdf").Data(),"pdf");
	      canvas->Print(("FakeRateTemplatePlotsJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+"/TemplatePlot"+TemplateVariables[m]+VarString[l]+binstring+".C").Data(),"cxx");

	      canvas->SetLogy(1);
	      xframe->GetYaxis()->SetRangeUser(1.e-1,pow(10.,1.1)*xframemax);

	      canvas->Print(("FakeRateTemplatePlotsJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+"/TemplatePlot"+TemplateVariables[m]+VarString[l]+binstring+"_Log.png").Data(),"png");
	      canvas->Print(("FakeRateTemplatePlotsJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+"/TemplatePlot"+TemplateVariables[m]+VarString[l]+binstring+"_Log.eps").Data(),"eps");
	      canvas->Print(("FakeRateTemplatePlotsJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+"/TemplatePlot"+TemplateVariables[m]+VarString[l]+binstring+"_Log.gif").Data(),"gif");
	      canvas->Print(("FakeRateTemplatePlotsJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+"/TemplatePlot"+TemplateVariables[m]+VarString[l]+binstring+"_Log.pdf").Data(),"pdf");
	      canvas->Print(("FakeRateTemplatePlotsJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+"/TemplatePlot"+TemplateVariables[m]+VarString[l]+binstring+"_Log.C").Data(),"cxx");

	      canvas->SetLogy(0);
	    }

	    float fakevalue = fakenum.getValV();
	    float fakeerrorhi = fakenum.getErrorHi();
	    float fakeerrorlo = fakenum.getErrorLo();
	    float fakeerrormax = max(fabs(fakeerrorhi),fabs(fakeerrorlo));
	    TString fakeresults = TString::Format("Fake results %f +%f %f",fakevalue,fakeerrorhi,fakeerrorlo);

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
	    // 	    TText *info = new TText();
	    // 	    info->SetNDC();
	    // 	    info->SetTextSize(0.03);

	    // 	    info->DrawText(0.5,0.7,binstring.Data());
	    // 	    info->DrawText(0.5,0.65,fakeresults.Data());
	    // 	    info->DrawText(0.5,0.6,sigresults.Data());

	    //find the bin corresponding to 0.011
	    int binnr = 22;
	    if(m == 2) binnr = 7;
	    //compute the integral of tight and fake in that range
	    float numerator = hData->Integral(0,binnr);
	    float denominator = hnum->Integral();
	    //float contamination = sigvalue;
	    float contamination = sigvalue+count*sigerrormax;
	    //float contamination = sigvalue+sigerrormax;

	    cout<<numerator<<" "<<denominator<<" "<<contamination<<endl;

	    float fakerate = (numerator-contamination)/denominator;
	    float fakerateerror = fakerate * sqrt( (1./numerator) + (1./denominator) + ((sigerrormax/sigvalue)*(sigerrormax/sigvalue)) );

	    cout<<"Here: "<<count<<" "<<fakerate<<" "<<fakerateerror<<endl;

	    //fakerateptvalues.push_back(hnumvspt->GetMean());
	    fakeratevalues.push_back(fakerate);
	    fakerateerrorvalues.push_back(fakerateerror);

	    cout<<""<<endl;
	    cout<<"***********************************************************"<<endl;
	    cout<<"So in sigmaietaieta < 0.011 there are "<<contamination<<" to subtract from "<<numerator<<endl;
	    cout<<"and thus there are "<<(numerator-contamination)<<" total tight entries "<<endl;
	    cout<<"and there are "<<denominator<<" entries in the tight and fake sample "<<endl;
	    cout<<"and so the fake rate for the pt range "<<binlow<<"-"<<binmax<<" is "<<fakerate<<endl;
	    cout<<"***********************************************************"<<endl;
	    cout<<""<<endl;

	  }//loop on all bins

	  cout<<fakeratevalues.size()<<endl;
	  for(int k=0;k<fakeratevalues.size();k++){
	    cout<<"Range: ["<<allbins[l][k]<<"-"<<allbins[l][k+1]<<"] --> fake rate: ("<<fakeratevalues[k]*100<<" +- "<<fakerateerrorvalues[k]*100<<")%"<<endl;    
	  }//end of loop over all fake rate values

	  TGraphErrors *FRgraph = new TGraphErrors(fakeratevalues.size());
	  //TGraphAsymmErrors *FRgraph = new TGraphAsymmErrors(fakeratevalues.size());
	  for(int k=0;k<fakeratevalues.size();k++){
	    cout<<(allbins[l][k+1]+allbins[l][k])/2.<<endl;
	    FRgraph->SetPoint(k,(allbins[l][k+1]+allbins[l][k])/2.,fakeratevalues[k]);
	    FRgraph->SetPointError(k,(allbins[l][k+1]-allbins[l][k])/2.,fakerateerrorvalues[k]);
	    //FRgraph->SetPoint(k,fakerateptvalues[k],fakeratevalues[k]);
	    //FRgraph->SetPointError(k,fakerateptvalues[k]-allbins[l][k],allbins[l][k+1]-fakerateptvalues[k],fakerateerrorvalues[k],fakerateerrorvalues[k]);
	  }//end of filling TGraph

	  FRgraph->SetName(("FakeRateJetRun2012ABCD13JulLoose"+TemplateVariables[m]+VarString[l]).Data());
	  FRgraph->SetTitle("");

	  canvas->cd();
	  if(VarString[l].EqualTo("VsPt"))gStyle->SetOptFit(1111);

	  FRgraph->Draw("a*");

	  //float maxFRvalue = max_element(fakeratevalues.begin(),fakeratevalues.end());
	  FRgraph->GetYaxis()->SetRangeUser(0.,0.2);
	  FRgraph->GetYaxis()->SetTitle("#epsilon_{FR}");
	  FRgraph->GetXaxis()->SetTitle((GraphXTitleString[l]).Data());

	  TString FakeRateFunctionName = "FakeRateFunctionJetRun2012ABCD13JulLoose"+TemplateVariables[m]+VarString[l];
	  TF1 *FRfunc = new TF1(FakeRateFunctionName.Data(),"[0]+[1]/pow(x,[2])",allbins[l][0],allbins[l][fakeratevalues.size()]);
	  FRfunc->SetParameters(1.,1.,1.);
	  if(l==0){
	    FRgraph->Fit(FakeRateFunctionName.Data(),"R");
	    FRgraph->Fit(FakeRateFunctionName.Data());
	    FRfunc->Draw("same");
	  }

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
	    canvas->Print(("FakeRateJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+TemplateVariables[m]+VarString[l]+".png").Data(),"png");
	    canvas->Print(("FakeRateJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+TemplateVariables[m]+VarString[l]+".gif").Data(),"gif");
	    canvas->Print(("FakeRateJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+TemplateVariables[m]+VarString[l]+".eps").Data(),"eps");
	    canvas->Print(("FakeRateJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+TemplateVariables[m]+VarString[l]+".pdf").Data(),"pdf");
	    canvas->Print(("FakeRateJetRun2012ABCD13JulLoose"+SideBandDefinitions[n]+TemplateVariables[m]+VarString[l]+".C").Data(),"cxx");
	  }

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

	}//end of loop over systematic errors

	if(numbersigmas != 0){
	  mg->Draw();
	  legendAllGraphs->Draw("same");
	}

      }//end of loop over all variables (pt, eta, phi, pu)

    }//end of loop over template variables

    histojetfile->cd();
    histojetfile->Close();

    historealmcfile->cd();
    historealmcfile->Close();

    FRhistosfile->cd();
    FRhistosfile->Close();

  }//end of loop over sideband definitions

}//end of method
