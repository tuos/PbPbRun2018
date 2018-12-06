//#include "makeMultiPanelCanvas.C"
#include "TF1.h"
#include "TH1.h"
#include "TFile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TLine.h"

#include <vector>

void turnOnHLTeff_LowMultiplicity()
{
   TH1::SetDefaultSumw2();

    //TFile* file0 = TFile::Open("../../openHLT_HLTeff_jbsMergedRun327237_Express_HLT.root");
    //TFile* file0 = TFile::Open("../../openHLT_HLTeff_jbsMergedRun327488_Express_HLT.root");
    TFile* file0 = TFile::Open("../../openHLT_HLTeff_jbsMergedRun327004_327237_Express_HLT.root");
    

    TH1D* h = new TH1D("","",25,0,50);
    TH1D* hFull = h->Clone();
    TH1D* hFullLM020 = (TH1D*)h->Clone("hFullLM020");
    TH1D* hFullLM335 = (TH1D*)h->Clone("hFullLM335");
    TH1D* hFullZB = (TH1D*)h->Clone("hFullZB");
    
    //Get Tree branch
    TNtuple* Tree = (TNtuple*)file0->Get("HLTinfo/HLTeff");
    Tree->AddFriend("HLTtree=hltbitanalysis/HltTree");

    int Ntrkoffline;
    int NtrkFull;
    double HLTVtxZ;
    double ETT;    
    Int_t L1_NotETT95_MinimumBiasHF1_AND_BptxAND; 
    Int_t L1_MinimumBiasHF1_AND_BptxAND;
    Int_t L1_MinimumBiasHF1_OR_BptxAND;
    Int_t HLT_HIZeroBias_v1;

    Tree->SetBranchAddress("Ntrkoffline",&Ntrkoffline);
    Tree->SetBranchAddress("NtrkFull",&NtrkFull);
    Tree->SetBranchAddress("ETT",&ETT);
    Tree->SetBranchAddress("HLTVtxZ",&HLTVtxZ);
    Tree->SetBranchAddress("HLT_HIZeroBias_v1",&HLT_HIZeroBias_v1);
    Tree->SetBranchAddress("L1_MinimumBiasHF1_AND_BptxAND",&L1_MinimumBiasHF1_AND_BptxAND);
    Tree->SetBranchAddress("L1_MinimumBiasHF1_OR_BptxAND",&L1_MinimumBiasHF1_OR_BptxAND);
    
    //int nentry = Tree->GetEntries();
    Tree->Draw("Ntrkoffline>>hFullLM020","L1_MinimumBiasHF1_OR_BptxAND==1&&HLT_HIZeroBias_v1==1&&ETT>0&&ETT<95&&NtrkFull>=1&&NtrkFull<20","goff");
    Tree->Draw("Ntrkoffline>>hFullLM335","L1_MinimumBiasHF1_OR_BptxAND==1&&HLT_HIZeroBias_v1==1&&ETT>0&&ETT<110&&NtrkFull>=3&&NtrkFull<35","goff");
    Tree->Draw("Ntrkoffline>>hFullZB","HLT_HIZeroBias_v1==1","goff");

    TGraphAsymmErrors* grLM020;
    grLM020 = new TGraphAsymmErrors();
    grLM020->Divide(hFullLM020,hFullZB);
    TGraphAsymmErrors* grLM335;
    grLM335 = new TGraphAsymmErrors();
    grLM335->Divide(hFullLM335,hFullZB);

    TCanvas* c3 = new TCanvas("c3","c3",600,600);
    c3->SetLeftMargin(0.1);
    c3->SetRightMargin(0.02);
    c3->SetTopMargin(0.02);
    c3->SetBottomMargin(0.1);
    c3->SetTicks(1);
    c3->SetGrid(1);
    gStyle->SetOptStat(0);
    c3->cd();

    TH1D* L2eff = new TH1D("L2eff","L2eff",50,0,50);
    L2eff->GetXaxis()->SetTitle("NtrkOffline");
    L2eff->GetYaxis()->SetTitle("Eff wrt ZB");
    L2eff->SetTitle("");
    L2eff->SetMaximum(1.2);
    L2eff->SetMinimum(0.);
    L2eff->Draw();

    grLM020->SetMarkerColor(1);
    grLM020->SetLineColor(1);
    grLM020->SetLineWidth(3);
    grLM020->SetMarkerSize(1);
    grLM020->SetMarkerStyle(24);
    grLM020->Draw("PLSAME");
    grLM335->SetMarkerColor(2);
    grLM335->SetLineColor(2);
    grLM335->SetLineWidth(3);
    grLM335->SetMarkerSize(1);
    grLM335->SetMarkerStyle(25);
    grLM335->Draw("PLSAME");

    TLegend* leg1 = new TLegend(0.17,0.86,0.38,0.95);
    leg1->SetFillStyle(0);
    leg1->SetBorderSize(0);
    leg1->SetFillColor(10);
    leg1->SetTextSize(0.03);
    leg1->AddEntry(grLM020,"HLT_HIFullTracks_Multiplicity020_HF1OR_v1, ETT<95","p");
    leg1->AddEntry(grLM335,"HLT_HIFullTracks_Multiplicity335_HF1OR_v1, ETT<110","p");
    leg1->Draw();

    TLine* l = new TLine(0,1,50,1);
    l->SetLineStyle(1);
    l->Draw("LSAME");
    TLine* l1 = new TLine(5,0,5,1.0);
    TLine* l2 = new TLine(12,0,12,1.0);
    l1->SetLineStyle(1);
    l1->SetLineColor(1);
    l1->SetLineWidth(2);
    l2->SetLineStyle(1);
    l2->SetLineColor(1);
    l2->SetLineWidth(2);
    l1->Draw("LSAME");
    l2->Draw("LSAME");
    TLine* l3 = new TLine(5.3,0,5.3,1.0);
    TLine* l4 = new TLine(22,0,22,1.0);
    l3->SetLineStyle(1);
    l3->SetLineColor(2);
    l3->SetLineWidth(2);
    l4->SetLineStyle(1);
    l4->SetLineColor(2);
    l4->SetLineWidth(2);
    l3->Draw("LSAME");
    l4->Draw("LSAME");
    TLatex *text0 = new TLatex(32,0.90,"2018 PbPb Run");
    text0->SetTextSize(0.04);
    text0->Draw();

    c3->SaveAs("plot_turnOnHLTeff_LowMultiplicity.png");


}

