///////////////////////
///  Gouranga Kole, TIFR
///////////////////////

#include <iostream>
#include <fstream>

using namespace std;
int mva()
{
	TString filename="train_FakeRateMethod_output.root";
	TFile* _file1 = new TFile(filename);
	gROOT->SetStyle("Plain");
	gStyle->SetPalette(1,0);
	gStyle->SetOptStat(1110);
	TCanvas *c1 = new TCanvas("c1", "correlation", 500, 600);
	leg = new TLegend(0.2,0.8,0.5,0.89);
	
	
	_file1->cd();
	TH1F* hist1=new TH1F("hist1","quark_jet",100,0.,1.0);
	TestTree->Draw("MLP>>hist1","classID==0");
	hist1->GetXaxis()->SetTitle("Quark-jet");
	
	hist1->GetXaxis()->CenterTitle();
	hist1->GetYaxis()->SetTitle("Number of Events");
	hist1->GetYaxis()->CenterTitle();
	hist1->SetLineColor(2);
	hist1->SetLineWidth(2);
	hist1->Draw("");
	leg->AddEntry(hist1,"Test-sample");
	
	TH1F* hist2=new TH1F("hist2","quark_jet",100,0.,1.0);
	TrainTree->Draw("MLP>>hist2","classID==0");
	hist2->GetXaxis()->SetTitle("Quark-jet");
	hist2->GetXaxis()->CenterTitle();
	hist2->GetYaxis()->SetTitle("Number of Events");
	hist2->GetYaxis()->CenterTitle();
	hist2->SetLineColor(4);
	hist2->SetLineWidth(2);
	leg->AddEntry(hist2,"Train-sample");
	hist2->Draw("");
	hist1->Draw("same");
	leg->Draw();
	c1->SaveAs("quark.png");
	
	//TH2F* hist3=new TH2F("hist3","2d-hist",300,0,1.5,300,0,1.5);
	//hist3->Fill(hist1,hist2);
	//hist3->Draw();
	
	hist1->Delete();
	hist2->Delete();
	
	
	TCanvas *c2 = new TCanvas("c2", "correlation", 500, 600);
	leg = new TLegend(0.6,0.8,0.89,0.89);
	
	
	_file1->cd();
	TH1F* hist1=new TH1F("hist1","quark_jet",100,0.,1.0);
	TestTree->Draw("MLP>>hist1","classID==1");
	hist1->GetXaxis()->SetTitle("Gluon-jet");
	
	hist1->GetXaxis()->CenterTitle();
	hist1->GetYaxis()->SetTitle("Number of Events");
	hist1->GetYaxis()->CenterTitle();
	hist1->SetLineColor(2);
	hist1->SetLineWidth(2);
	leg->AddEntry(hist1,"Test-sample");
	hist1->Draw("");
	
	TH1F* hist2=new TH1F("hist2","quark_jet",100,0.,1.0);
	TrainTree->Draw("MLP>>hist2","classID==1");
	hist2->GetXaxis()->SetTitle("Gluon-jet");
	hist2->GetXaxis()->CenterTitle();
	hist2->GetYaxis()->SetTitle("Number of Events");
	hist2->GetYaxis()->CenterTitle();
	hist2->SetLineWidth(2);
	hist2->SetLineColor(4);
	leg->AddEntry(hist2,"Train-sample");
	
	hist2->Draw("");
	hist1->Draw("same");
	leg->Draw();
	c2->SaveAs("gluon.png");
	
	
	//TH2F* hist3=new TH2F("hist3","2d-hist",300,0,1.5,300,0,1.5);
	//hist3->Fill(hist1,hist2);
	//hist3->Draw();
	
	hist1->Delete();
	hist2->Delete();
	
	TCanvas *c3 = new TCanvas("c3", "correlation", 500, 600);
	leg = new TLegend(0.6,0.8,0.89,0.89);
	
	
	_file1->cd();
	TH1F* hist1=new TH1F("hist1","quark_jet",100,0.,1.0);
	TestTree->Draw("MLP>>hist1","classID==1");
	hist1->GetXaxis()->SetTitle("Gluon-jet");
	
	hist1->GetXaxis()->CenterTitle();
	hist1->GetYaxis()->SetTitle("Number of Events");
	hist1->GetYaxis()->CenterTitle();
	hist1->SetLineColor(2);
	//leg->AddEntry(hist1,"Test-sample");
	//hist1->Draw("");
	
	TH1F* hist2=new TH1F("hist2","quark_jet",100,0.,1.0);
	TrainTree->Draw("MLP>>hist2","classID==1");
	hist2->GetXaxis()->SetTitle("Gluon-jet");
	hist2->GetXaxis()->CenterTitle();
	hist2->GetYaxis()->SetTitle("Number of Events");
	hist2->GetYaxis()->CenterTitle();
	hist2->SetLineColor(4);
	//leg->AddEntry(hist2,"Train-sample");
	
	TH1F* hist3=new TH1F("hist3","Ratio",100,0.,1.0);
	hist3->Divide(hist1,hist2);
	hist3->GetYaxis()->SetRangeUser(0,2);
	hist3->SetLineColor(6);
	hist3->SetTitle("Ratio Plot between training and test samples for quark");
	hist3->SetLineStyle(1); // 2 for dashed line
	hist3->SetLineWidth(2);
	hist3->Draw();
	leg->AddEntry(hist3,"Ratio Plot");
	leg->Draw();
	c3->SaveAs("ratio_quark.png");
	
	
	hist1->Delete();
	hist2->Delete();
	hist3->Delete();
	
	TCanvas *c4 = new TCanvas("c4", "correlation", 500, 600);
	leg = new TLegend(0.6,0.8,0.89,0.89);
	
	
	_file1->cd();
	TH1F* hist1=new TH1F("hist1","quark_jet",100,0.,1.0);
	TestTree->Draw("MLP>>hist1","classID==0");
	hist1->GetXaxis()->SetTitle("Gluon-jet");
	
	hist1->GetXaxis()->CenterTitle();
	hist1->GetYaxis()->SetTitle("Number of Events");
	hist1->GetYaxis()->CenterTitle();
	hist1->SetLineColor(2);
	//leg->AddEntry(hist1,"Test-sample");
	//hist1->Draw("");
	
	TH1F* hist2=new TH1F("hist2","quark_jet",100,0.,1.0);
	TrainTree->Draw("MLP>>hist2","classID==0");
	hist2->GetXaxis()->SetTitle("Gluon-jet");
	hist2->GetXaxis()->CenterTitle();
	hist2->GetYaxis()->SetTitle("Number of Events");
	hist2->GetYaxis()->CenterTitle();
	hist2->SetLineColor(4);
	//leg->AddEntry(hist2,"Train-sample");
	
	TH1F* hist3=new TH1F("hist3","Ratio",100,0.,1.0);
	hist3->Divide(hist1,hist2);
	hist3->GetYaxis()->SetRangeUser(0,2);
	hist3->SetLineColor(6);
	hist3->SetTitle("Ratio Plot between training and test samples for gluon");
	hist3->SetLineStyle(1); // 2 for dashed line
	hist3->SetLineWidth(2);
	hist3->Draw();
	leg->AddEntry(hist3,"Ratio Plot");
	leg->Draw();
	c4->SaveAs("ratio_gluon.png");
	
	
	hist1->Delete();
	hist2->Delete();
	hist3->Delete();
	return 0;
}
