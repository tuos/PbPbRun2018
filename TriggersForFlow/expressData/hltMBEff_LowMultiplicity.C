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

void hltMBEff_LowMultiplicity()
{
   TH1::SetDefaultSumw2();

    //TFile* file0 = TFile::Open("../../openHLT_HLTeff_jbsMergedRun326617_Express.root");
    //TFile* file0 = TFile::Open("../../openHLT_HLTeff_jbsMergedRun327004_Express_HLT.root");
    //TFile* file0 = TFile::Open("../../openHLT_HLTeff_jbsMergedRun327174_Express_HLT.root");
    //TFile* file0 = TFile::Open("../../openHLT_HLTeff_jbsMergedRun327237_Express_HLT.root");
    TFile* file0 = TFile::Open("../../openHLT_HLTeff_jbsMergedRun327004_327237_Express_HLT.root");
    
    TH1D* h = new TH1D("","",25,0,50);
    TH1D* hFull = h->Clone();
    TH1D* hFullHF1OR = (TH1D*)h->Clone("hFullHF1OR");
    TH1D* hFullHF1AND = (TH1D*)h->Clone("hFullHF1AND");
    TH1D* hFullZeroBias = (TH1D*)h->Clone("hFullZeroBias");
    TH1D* hFullHF2OR = (TH1D*)h->Clone("hFullHF2OR");
    
    //Get Tree branch
    TNtuple* Tree = (TNtuple*)file0->Get("HLTinfo/HLTeff");
    Tree->AddFriend("HLTtree=hltbitanalysis/HltTree");

    int Ntrkoffline;
    int NtrkFull;
    int NtrkPixel;
    double TowerCount;
    double OfflineVtxZ;
    double HLTVtxZ;
    double ETT;    
    Int_t L1_NotETT80_MinimumBiasHF1_AND_BptxAND;
    Int_t L1_NotETT95_MinimumBiasHF1_AND_BptxAND; 
    Int_t L1_ETT45_NotETT110_BptxAND;
    Int_t L1_ETT50_NotETT120_BptxAND;
    Int_t L1_ETT55_NotETT130_BptxAND;

    Int_t L1_MinimumBiasHF1_AND_BptxAND;
    Int_t L1_MinimumBiasHF1_OR_BptxAND;
    Int_t L1_MinimumBiasHF2_OR_BptxAND;
    Int_t HLT_HIUPC_ZeroBias_SinglePixelTrack_v1;

    Int_t HLT_HIZeroBias_v1;
    Int_t HLT_HIMinimumBias_part1_v1;

    Int_t L1_MinimumBiasHF2_AND_BptxAND;
Int_t L1_CastorHighJet_OR_MinimumBiasHF2_AND_BptxAND;
Int_t L1_ZDC_AND_OR_MinimumBiasHF2_AND_BptxAND;
Int_t HLT_HIL1_ZDC_AND_OR_MinimumBiasHF2_AND_BptxAND_v1;

    Tree->SetBranchAddress("Ntrkoffline",&Ntrkoffline);
    Tree->SetBranchAddress("NtrkPixel",&NtrkPixel);
    Tree->SetBranchAddress("NtrkFull",&NtrkFull);
    Tree->SetBranchAddress("TowerCount",&TowerCount);
    Tree->SetBranchAddress("ETT",&ETT);
    Tree->SetBranchAddress("OfflineVtxZ",&OfflineVtxZ);
    Tree->SetBranchAddress("HLTVtxZ",&HLTVtxZ);

    Tree->SetBranchAddress("HLT_HIZeroBias_v1",&HLT_HIZeroBias_v1);
    Tree->SetBranchAddress("HLT_HIUPC_ZeroBias_SinglePixelTrack_v1",&HLT_HIUPC_ZeroBias_SinglePixelTrack_v1);

    Tree->SetBranchAddress("L1_MinimumBiasHF1_AND_BptxAND",&L1_MinimumBiasHF1_AND_BptxAND);
    Tree->SetBranchAddress("L1_MinimumBiasHF1_OR_BptxAND",&L1_MinimumBiasHF1_OR_BptxAND);
    Tree->SetBranchAddress("L1_MinimumBiasHF2_OR_BptxAND",&L1_MinimumBiasHF2_OR_BptxAND);

    Tree->SetBranchAddress("L1_MinimumBiasHF2_AND_BptxAND",&L1_MinimumBiasHF2_AND_BptxAND);

    Tree->SetBranchAddress("L1_CastorHighJet_OR_MinimumBiasHF2_AND_BptxAND",&L1_CastorHighJet_OR_MinimumBiasHF2_AND_BptxAND);
    //Tree->SetBranchAddress("L1_ZDC_AND_OR_MinimumBiasHF2_AND_BptxAND",&L1_ZDC_AND_OR_MinimumBiasHF2_AND_BptxAND);
    //Tree->SetBranchAddress("HLT_HIL1_ZDC_AND_OR_MinimumBiasHF2_AND_BptxAND_v1",&HLT_HIL1_ZDC_AND_OR_MinimumBiasHF2_AND_BptxAND_v1);
    
    
    //int nentry = Tree->GetEntries();
    //plot eff turn-ons
    TH1D* L1eff = new TH1D("L1eff","L1eff",50,0,50);
    L1eff->GetXaxis()->SetTitle("NtrkOffline");
    L1eff->GetYaxis()->SetTitle("#Event");
    L1eff->SetTitle("");
	
    Tree->Draw("Ntrkoffline>>hFullHF1OR","L1_MinimumBiasHF1_OR_BptxAND==1&&NtrkFull>=0&&HLT_HIZeroBias_v1==1","goff");
    Tree->Draw("Ntrkoffline>>hFullHF1AND","L1_MinimumBiasHF1_AND_BptxAND==1&&NtrkFull>=0&&HLT_HIZeroBias_v1==1","goff");
    Tree->Draw("Ntrkoffline>>hFullHF2OR","L1_MinimumBiasHF2_OR_BptxAND==1&&NtrkFull>=0&&HLT_HIZeroBias_v1==1","goff");
    //Tree->Draw("Ntrkoffline>>hFullHF2OR","L1_CastorHighJet_OR_MinimumBiasHF2_AND_BptxAND==1&&NtrkFull>=0&&HLT_HIZeroBias_v1==1","goff");
    //Tree->Draw("Ntrkoffline>>hFullHF2OR","L1_ZDC_AND_OR_MinimumBiasHF2_AND_BptxAND==1&&NtrkFull>=0&&HLT_HIZeroBias_v1==1","goff");
    //Tree->Draw("Ntrkoffline>>hFullHF2OR","HLT_HIL1_ZDC_AND_OR_MinimumBiasHF2_AND_BptxAND_v1==1&&NtrkFull>=0&&HLT_HIZeroBias_v1==1","goff");
    Tree->Draw("Ntrkoffline>>hFullZeroBias","HLT_HIZeroBias_v1==1&&NtrkFull>=0","goff");


    TGraphAsymmErrors* grHF2OR;
    TGraphAsymmErrors* grHF1AND;
    TGraphAsymmErrors* grHF1OR;
    gr2OR = new TGraphAsymmErrors();
    gr1AND = new TGraphAsymmErrors();
    gr1OR = new TGraphAsymmErrors();
    gr2OR->Divide(hFullHF2OR,hFullZeroBias);
    gr1AND->Divide(hFullHF1AND,hFullZeroBias);
    gr1OR->Divide(hFullHF1OR,hFullZeroBias);

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

    gr2OR->SetMarkerColor(4);
    gr2OR->SetLineColor(4);
    gr2OR->SetLineWidth(3);
    gr2OR->SetMarkerSize(1);
    gr2OR->SetMarkerStyle(20);
    gr2OR->Draw("PLSAME");
    gr1AND->SetMarkerColor(2);
    gr1AND->SetLineColor(2);
    gr1AND->SetLineWidth(3);
    gr1AND->SetMarkerSize(1);
    gr1AND->SetMarkerStyle(25);
    gr1AND->Draw("PLSAME");
    gr1OR->SetMarkerColor(1);
    gr1OR->SetLineColor(1);
    gr1OR->SetLineWidth(3);
    gr1OR->SetMarkerSize(1);
    gr1OR->SetMarkerStyle(24);
    gr1OR->Draw("PLSAME");

    TLegend* leg1 = new TLegend(0.43,0.28,0.63,0.47);
    leg1->SetFillStyle(0);
    leg1->SetBorderSize(0);
    leg1->SetFillColor(10);
    leg1->SetTextSize(0.038);
    leg1->AddEntry(gr1OR,"HF1OR","p");
    //leg1->AddEntry(gr2OR,"CastorHighJet_OR_HF2AND","p");
    //leg1->AddEntry(gr2OR,"ZDCAND_OR_HF2AND","p");
    leg1->AddEntry(gr2OR,"HF2OR","p");
    leg1->AddEntry(gr1AND,"HF1AND","p");
    leg1->Draw();

    TLatex *text0 = new TLatex(5,1.10,"2018 PbPb Run");
    text0->SetTextSize(0.04);
    text0->Draw();

    c3->SaveAs("plot_HLTMBEff_LowMultiplicity.png");

}

