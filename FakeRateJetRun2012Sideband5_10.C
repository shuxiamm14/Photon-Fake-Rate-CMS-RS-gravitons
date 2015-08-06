void FakeRateJetRun2012Sideband5_10()
{
//=========Macro generated from canvas: canvas/canvas
//=========  (Tue Aug  4 17:46:25 2015) by ROOT version6.02/05
   TCanvas *canvas = new TCanvas("canvas", "canvas",900,122,500,500);
   canvas->Range(-0.0125,-1349.369,0.1125,12145.32);
   canvas->SetFillColor(0);
   canvas->SetBorderMode(0);
   canvas->SetBorderSize(2);
   canvas->SetGridx();
   canvas->SetGridy();
   canvas->SetFrameBorderMode(0);
   canvas->SetFrameBorderMode(0);
   
   TPaveText *pt = new TPaveText(0.01,0.9390678,0.3545968,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(1);
   pt->SetFillColor(0);
   TText *AText = pt->AddText("Fake Rate vs pt");
   pt->Draw();
   
   Double_t Graph0_fx1001[7] = {
   30,
   50,
   70,
   90,
   110,
   160,
   400};
   Double_t Graph0_fy1001[7] = {
   0.242332,
   0.1610218,
   0.1363043,
   0.1318385,
   0.1259591,
   0.12168,
   0.1318152};
   Double_t Graph0_fex1001[7] = {
   10,
   10,
   10,
   10,
   10,
   40,
   200};
   Double_t Graph0_fey1001[7] = {
   0.00161518,
   0.001326252,
   0.001406083,
   0.001640829,
   0.001806762,
   0.001163044,
   0.001264752};
   TGraphErrors *gre = new TGraphErrors(7,Graph0_fx1001,Graph0_fy1001,Graph0_fex1001,Graph0_fey1001);
   gre->SetName("Graph0");
   gre->SetTitle("Fake Rate vs pt");
   gre->SetFillColor(1);
   gre->SetFillStyle(4000);
   gre->SetLineColor(6);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","Fake Rate vs pt",100,0,658);
   Graph_Graph1001->SetMinimum(0.05);
   Graph_Graph1001->SetMaximum(0.3);
   Graph_Graph1001->SetDirectory(0);
   Graph_Graph1001->SetStats(0);
   Graph_Graph1001->GetXaxis()->SetTitle("p_{t} (GeV)");
   Graph_Graph1001->GetYaxis()->SetTitle("#epsilon_{FR}");
   gre->SetHistogram(Graph_Graph1001);
   
   
   TF1 *FakeRateFunctionJetRun2012ABCDLooseSideband5_101002 = new TF1("FakeRateFunctionJetRun2012ABCDLooseSideband5_10","[0]+[1]/pow(x,[2])",20,600);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetFillColor(19);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetFillStyle(0);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetLineWidth(3);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetChisquare(16.95136);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetNDF(4);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetParameter(0,-2.523014);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetParError(0,1.702309);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetParLimits(0,0,0);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetParameter(1,3.00355);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetParError(1,1.712881);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetParLimits(1,0,0);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetParameter(2,0.02706848);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetParError(2,0.01707325);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101002->SetParLimits(2,0,0);
   gre->GetListOfFunctions()->Add(FakeRateFunctionJetRun2012ABCDLooseSideband5_101002);
   gre->Draw("");
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("");
   
   Double_t Graph0_fx1003[7] = {
   30,
   50,
   70,
   90,
   110,
   160,
   400};
   Double_t Graph0_fy1003[7] = {
   0.242332,
   0.1610218,
   0.1363043,
   0.1318385,
   0.1259591,
   0.12168,
   0.1318152};
   Double_t Graph0_fex1003[7] = {
   10,
   10,
   10,
   10,
   10,
   40,
   200};
   Double_t Graph0_fey1003[7] = {
   0.00161518,
   0.001326252,
   0.001406083,
   0.001640829,
   0.001806762,
   0.001163044,
   0.001264752};
   gre = new TGraphErrors(7,Graph0_fx1003,Graph0_fy1003,Graph0_fex1003,Graph0_fey1003);
   gre->SetName("Graph0");
   gre->SetTitle("Fake Rate vs pt");
   gre->SetFillColor(1);
   gre->SetFillStyle(4000);
   gre->SetLineColor(6);
   
   TH1F *Graph_Graph_Graph10011003 = new TH1F("Graph_Graph_Graph10011003","Fake Rate vs pt",100,0,658);
   Graph_Graph_Graph10011003->SetMinimum(0.05);
   Graph_Graph_Graph10011003->SetMaximum(0.3);
   Graph_Graph_Graph10011003->SetDirectory(0);
   Graph_Graph_Graph10011003->SetStats(0);
   Graph_Graph_Graph10011003->GetXaxis()->SetTitle("p_{t} (GeV)");
   Graph_Graph_Graph10011003->GetYaxis()->SetTitle("#epsilon_{FR}");
   gre->SetHistogram(Graph_Graph_Graph10011003);
   
   
   TF1 *FakeRateFunctionJetRun2012ABCDLooseSideband5_101004 = new TF1("FakeRateFunctionJetRun2012ABCDLooseSideband5_10","[0]+[1]/pow(x,[2])",20,600);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetFillColor(19);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetFillStyle(0);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetLineWidth(3);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetChisquare(16.95136);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetNDF(4);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetParameter(0,-2.523014);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetParError(0,1.702309);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetParLimits(0,0,0);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetParameter(1,3.00355);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetParError(1,1.712881);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetParLimits(1,0,0);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetParameter(2,0.02706848);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetParError(2,0.01707325);
   FakeRateFunctionJetRun2012ABCDLooseSideband5_101004->SetParLimits(2,0,0);
   gre->GetListOfFunctions()->Add(FakeRateFunctionJetRun2012ABCDLooseSideband5_101004);
   multigraph->Add(gre,"");
   multigraph->Draw("");
   
   TLegend *leg = new TLegend(0.62,0.65,0.82,0.85,NULL,"brNDC");
   leg->SetBorderSize(1);
   leg->SetTextFont(62);
   leg->SetTextSize(0.02);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","Side Band: CHIsolation","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","Sideband3_6 GeV","l");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","Sideband4_7 GeV","l");
   entry->SetLineColor(3);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","Sideband4_10 GeV","l");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph","Sideband5_8 GeV","l");
   entry->SetLineColor(5);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph0","Sideband5_10 GeV","l");
   entry->SetLineColor(6);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   leg->Draw();
   canvas->Modified();
   canvas->cd();
   canvas->SetSelected(canvas);
}
