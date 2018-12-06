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

void HLTeff_HighMultiplicity()
{
   TH1::SetDefaultSumw2();

    //TFile* file0 = TFile::Open("HLTeff_jbAll_mc.root");
    //TFile* file0 = TFile::Open("HLTeff_crabv03_mc.root");
    TFile* file0 = TFile::Open("../../HLTeff_jb100files_mc.root");
    
    //Trigger threshold
    int PixelThreshold = 150;
    int ETTThresholdMin[5] = {35,40,45,50,60};
    int ETTThresholdMax[5] = {80,95,110,125,135};
    int MultiplicityThresholdMin[5] = {0,20,40,60,80};
    int MultiplicityThresholdMax[5] = {20,40,60,80,100};
    int MultiplicityThreshold[5] = {20,2040,4060,6080,80100};
    int NTC = 5;
    int NMult = 5;
    int L1seeds[5];
    //Triggre combination, index corresponds to above array
    int indexMult[5] = {0,1,2,3,4};
    int indexTowerCount[5] = {0,1,2,3,4};
    int Nindex = 5;
    
    //initialize eff plots
    int Nplot = 2+5*2;
    //TH1D* h = new TH1D("","",100,0,200);
    TH1D* h = new TH1D("","",100,0,200);
    TH1D* hFull = h->Clone();
    TH1D* hMult[100];
    TH1D* hTowerCount[100];
    TH1D* hAll[100];
    for(int i=0;i<Nplot;i++)
    {
        hMult[i] = (TH1D*)h->Clone();
        hTowerCount[i] = (TH1D*)h->Clone();
        hAll[i] = (TH1D*)h->Clone();
    }
    
    TGraphAsymmErrors* grMult[100];
    TGraphAsymmErrors* grTowerCount[100];
    TGraphAsymmErrors* grAll[100];
    for(int i=0;i<Nplot;i++)
    {
        grMult[i] = new TGraphAsymmErrors();
        grTowerCount[i] = new TGraphAsymmErrors();
        grAll[i] = new TGraphAsymmErrors();
    }
    
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


    Tree->SetBranchAddress("Ntrkoffline",&Ntrkoffline);
    Tree->SetBranchAddress("NtrkPixel",&NtrkPixel);
    Tree->SetBranchAddress("NtrkFull",&NtrkFull);
    Tree->SetBranchAddress("TowerCount",&TowerCount);
    Tree->SetBranchAddress("ETT",&ETT);
    Tree->SetBranchAddress("OfflineVtxZ",&OfflineVtxZ);
    Tree->SetBranchAddress("HLTVtxZ",&HLTVtxZ);
    //Tree->SetBranchAddress("L1_NotETT80_MinimumBiasHF1_AND_BptxAND",&L1_NotETT80_MinimumBiasHF1_AND_BptxAND);
    //Tree->SetBranchAddress("L1_NotETT95_MinimumBiasHF1_AND_BptxAND",&L1_NotETT95_MinimumBiasHF1_AND_BptxAND);
    //Tree->SetBranchAddress("L1_NotETT80_MinimumBiasHF1_OR_BptxAND",&L1_NotETT80_MinimumBiasHF1_AND_BptxAND);
    //Tree->SetBranchAddress("L1_NotETT95_MinimumBiasHF1_OR_BptxAND",&L1_NotETT95_MinimumBiasHF1_AND_BptxAND);
    //Tree->SetBranchAddress("L1_NotETT80_MinimumBiasHF2_OR_BptxAND",&L1_NotETT80_MinimumBiasHF1_AND_BptxAND);
    //Tree->SetBranchAddress("L1_NotETT95_MinimumBiasHF2_OR_BptxAND",&L1_NotETT95_MinimumBiasHF1_AND_BptxAND);
    Tree->SetBranchAddress("L1_ETT35_NotETT80_BptxAND",&L1_NotETT80_MinimumBiasHF1_AND_BptxAND);
    Tree->SetBranchAddress("L1_ETT40_NotETT95_BptxAND",&L1_NotETT95_MinimumBiasHF1_AND_BptxAND);
    Tree->SetBranchAddress("L1_ETT45_NotETT110_BptxAND",&L1_ETT45_NotETT110_BptxAND);
    Tree->SetBranchAddress("L1_ETT50_NotETT120_BptxAND",&L1_ETT50_NotETT120_BptxAND);
    Tree->SetBranchAddress("L1_ETT55_NotETT130_BptxAND",&L1_ETT55_NotETT130_BptxAND);

    Tree->SetBranchAddress("L1_MinimumBiasHF1_AND_BptxAND",&L1_MinimumBiasHF1_AND_BptxAND);
    //Tree->SetBranchAddress("L1_MinimumBiasHF1_OR_BptxAND",&L1_MinimumBiasHF1_OR_BptxAND);

    ///Tree->SetBranchAddress("L1_MinimumBiasHF1_OR_BptxAND",&L1_MinimumBiasHF1_OR_BptxAND);
    
    //loop for histograms
    int nMB=0;
    int nSeedsTotal=0;
    int nSeeds[5]={0};
    int nMBANDSeeds[5]={0};
    int nMBANDSeedsTotal=0;

    int nentry = Tree->GetEntries();
    for(int it=0;it<nentry;it++)
    {
        Tree->GetEntry(it);
        
        if(it%5000==0) cout<<"processing "<<it<<"/"<<nentry<<" event"<<endl;
        
        if(fabs(OfflineVtxZ)>15) continue;
        
        //fill NtrkFull distribution without any cut
        hFull->Fill(NtrkFull);
        //fill NtrkFull distribution with cuts

        if(L1_MinimumBiasHF1_AND_BptxAND==1) nMB++;
//using L1seeds
        L1seeds[0]=L1_NotETT80_MinimumBiasHF1_AND_BptxAND;
        L1seeds[1]=L1_NotETT95_MinimumBiasHF1_AND_BptxAND;
        L1seeds[2]=L1_ETT45_NotETT110_BptxAND;
        //L1seeds[2]=L1_MinimumBiasHF1_AND_BptxAND;
        L1seeds[3]=L1_ETT50_NotETT120_BptxAND;
        //L1seeds[3]=L1_MinimumBiasHF1_AND_BptxAND;
        L1seeds[4]=L1_ETT55_NotETT130_BptxAND;
        if(L1seeds[0]==1 || L1seeds[1]==1 || L1seeds[2]==1 || L1seeds[3]==1 || L1seeds[4]==1) nSeedsTotal++;
        if( (L1seeds[0]==1 || L1seeds[1]==1 || L1seeds[2]==1 || L1seeds[3]==1 || L1seeds[4]==1) && L1_MinimumBiasHF1_AND_BptxAND==1 ) nMBANDSeedsTotal++;
        for(int i=0;i<NTC;i++)
        {
            //if(ETT<ETTThresholdMin[i] || ETT>ETTThresholdMax[i] ) continue;
            if(L1seeds[i]==0) continue;
            hTowerCount[i]->Fill(NtrkFull);
            if(L1seeds[i]==1) nSeeds[i]++;
            if(L1seeds[i]==1 && L1_MinimumBiasHF1_AND_BptxAND ==1) nMBANDSeeds[i]++;
        }
        for(int j=0;j<NMult;j++)
        {
            if(fabs(HLTVtxZ)>15) continue;
            //if(NtrkPixel>PixelThreshold) continue;
            if(NtrkFull<=MultiplicityThresholdMin[j] || NtrkFull>MultiplicityThresholdMax[j]) continue;
            hMult[j]->Fill(NtrkFull);
        }
        for(int k=0;k<Nindex;k++)
        {
            if(fabs(HLTVtxZ)>15) continue;
            //if(ETT<ETTThresholdMin[k] || ETT>ETTThresholdMax[k] ) continue;
            if(L1seeds[k]==0) continue;
            //if(NtrkPixel>PixelThreshold) continue;
            if(NtrkFull<=MultiplicityThresholdMin[k] || NtrkFull>MultiplicityThresholdMax[k]) continue;
            //if(NtrkFull>MultiplicityThreshold[indexMult[k]]) continue;
            hAll[k]->Fill(NtrkFull);
        }
    }

    cout<<"overlap: "<<nSeedsTotal<<"   "<<nMB<<"  , AND: "<<nMBANDSeedsTotal<<endl;
    for(int i=0;i<NTC;i++) { cout<<nSeeds[i]<<"  AND " <<nMBANDSeeds[i]<<" ,  "; }
    cout<<endl;
 
    //make eff turn-ons
    //double totalRate=1.0;
    double totalRate=50000.0;
    for(int i=0;i<NTC;i++)
    {
        grTowerCount[i]->Divide(hTowerCount[i],hFull);
        cout<<"L1 rate in percent: "<<ETTThresholdMin[i]<<"-"<<ETTThresholdMax[i]<<"  "<<hTowerCount[i]->GetEntries()*totalRate/hFull->GetEntries()<<endl;
    }
    for(int j=0;j<NMult;j++)
    {
        grMult[j]->Divide(hMult[j],hFull);
        cout<<"HLT rate in percent: "<<MultiplicityThresholdMin[j]<<"-"<<MultiplicityThresholdMax[j]<<"  "<<hMult[j]->GetEntries()*totalRate/hFull->GetEntries()<<endl;
    }
    for(int k=0;k<Nindex;k++)
    {
        grAll[k]->Divide(hAll[k],hFull);
        cout<<"L1+HLT rate in percent: "<<MultiplicityThresholdMin[k]<<"-"<<MultiplicityThresholdMax[k]<<"  "<<hAll[k]->GetEntries()*totalRate/hFull->GetEntries()<<endl;
    }

//hFull->Draw();

   
    //plot eff turn-ons
    TH1D* L1eff = new TH1D("L1eff","L1eff",150,0,150);
    L1eff->GetXaxis()->SetTitle("Ntrk(p_{T}>0.4 GeV/c)");
	L1eff->GetYaxis()->SetTitle("L1 eff");
    L1eff->SetTitle("");
	
    TH1D* HLTeff = new TH1D("HLTeff","HLTeff",150,0,150);
    HLTeff->GetXaxis()->SetTitle("Ntrk(p_{T}>0.4 GeV/c)");
    HLTeff->GetYaxis()->SetTitle("HLT eff");
    HLTeff->SetTitle("");

    TH1D* Fulleff = new TH1D("Fulleff","Fulleff",150,0,150);
    Fulleff->GetXaxis()->SetTitle("Ntrk(p_{T}>0.4 GeV/c)");
    Fulleff->GetYaxis()->SetTitle("L1+HLT eff");
    Fulleff->SetTitle("");
   
    //add lines at where the trigger is expected to be efficient
    TLine* l = new TLine(0,1,300,1);
    l->SetLineStyle(3);
    
    TLine* l1 = new TLine(20,0,20,1.05);
    TLine* l2 = new TLine(40,0,40,1.05);
    TLine* l3 = new TLine(60,0,60,1.05);
    TLine* l4 = new TLine(80,0,80,1.05);
    TLine* l5 = new TLine(100,0,100,1.05);
    l1->SetLineStyle(7);
    l2->SetLineStyle(7);
    l3->SetLineStyle(7);
    l4->SetLineStyle(7);
    l5->SetLineStyle(7);
    
    //create canvas
    TCanvas* c1 = new TCanvas("c1","c1",600,600);
    TCanvas* c2 = new TCanvas("c2","c2",600,600);
    TCanvas* c3 = new TCanvas("c3","c3",600,600);

  c1->SetLeftMargin(0.1);
  c1->SetRightMargin(0.02);
  c1->SetTopMargin(0.02);
  c1->SetBottomMargin(0.1);
  c1->SetTicks(1);
  c2->SetLeftMargin(0.1);
  c2->SetRightMargin(0.02);
  c2->SetTopMargin(0.02);
  c2->SetBottomMargin(0.1);
  c2->SetTicks(1);
  c3->SetLeftMargin(0.1);
  c3->SetRightMargin(0.02);
  c3->SetTopMargin(0.02);
  c3->SetBottomMargin(0.1);
  c3->SetTicks(1);
  gStyle->SetOptStat(0);

    
    //L1 eff
    c1->cd();
    L1eff->Draw();
    TLegend* leg = new TLegend(0.18,0.12,0.38,0.35);
    leg->SetFillStyle(0);
    leg->SetBorderSize(0);
    leg->SetFillColor(10);
    leg->SetTextSize(0.032);
    int markers[5]={20, 21,24,25,30};
    int colors[5]={1, 2,4,6,8};
    char L1seedsName[5][200]={"L1_ETT35_NotETT80_BptxAND","L1_ETT40_NotETT95_BptxAND","L1_ETT45_NotETT110_BptxAND","L1_ETT50_NotETT120_BptxAND","L1_ETT55_NotETT130_BptxAND"};
    for(int i=0;i<NTC;i++)
    {
        grTowerCount[i]->SetMarkerColor(colors[i]);
        grTowerCount[i]->SetLineColor(colors[i]);
        grTowerCount[i]->SetLineWidth(3);
        grTowerCount[i]->SetMarkerSize(1);
        grTowerCount[i]->SetMarkerStyle(markers[i]);
        grTowerCount[i]->Draw("PLSAME");
        //leg->AddEntry(grTowerCount[i],Form("%d < ETT < %d",ETTThresholdMin[i], ETTThresholdMax[i]),"p");
        leg->AddEntry(grTowerCount[i],Form("%s", L1seedsName[i]),"p");
    }
    leg->Draw();
    l->Draw("LSAME");
    l1->Draw("LSAME");
    l2->Draw("LSAME");
    l3->Draw("LSAME");
    l4->Draw("LSAME");
    l5->Draw("LSAME");
    
    //HLT eff
    c2->cd();
    HLTeff->Draw();
    TLegend* leg1 = new TLegend(0.68,0.6,0.89,0.8);
    leg1->SetFillStyle(0);
    leg1->SetBorderSize(0);
    leg1->SetFillColor(10);
    leg1->SetTextSize(0.042);
    for(int i=0;i<NMult;i++)
    {
        grMult[i]->SetMarkerColor(colors[i]);
        grMult[i]->SetLineColor(colors[i]);
        grMult[i]->SetLineWidth(3);
        grMult[i]->SetMarkerSize(1);
        grMult[i]->SetMarkerStyle(markers[i]);
        grMult[i]->Draw("PLSAME");
        leg1->AddEntry(grMult[i],Form("%d < Ntrk #leq %d",MultiplicityThresholdMin[i], MultiplicityThresholdMax[i]),"p");
    }
    leg1->Draw();
    l->Draw("LSAME");
    l1->Draw("LSAME");
    l2->Draw("LSAME");
    l3->Draw("LSAME");
    l4->Draw("LSAME");
    l5->Draw("LSAME");
    
    //L1+HLT eff
    c3->cd();
    Fulleff->Draw();
    TLegend* leg2 = new TLegend(0.23,0.14,0.53,0.34);
    leg2->SetFillStyle(0);
    leg2->SetBorderSize(0);
    leg2->SetFillColor(10);
    leg2->SetTextSize(0.032);
    char HLTpathName[5][200]={"HLT_HIFullTracks_Multiplicity020_HF1AND_v1","HLT_HIFullTracks_Multiplicity2040_HF1AND_v1","HLT_HIFullTracks_Multiplicity4060_v1","HLT_HIFullTracks_Multiplicity6080_v1","HLT_HIFullTracks_Multiplicity80100_v1"};
    for(int i=0;i<NMult;i++)
    {
        grAll[i]->SetMarkerColor(colors[i]);
        grAll[i]->SetLineColor(colors[i]);
        grAll[i]->SetLineWidth(3);
        grAll[i]->SetMarkerSize(1);
        grAll[i]->SetMarkerStyle(markers[i]);
        grAll[i]->Draw("PLSAME");
        //leg2->AddEntry(grAll[i],Form("HLT_LM%d",MultiplicityThreshold[i]),"p");
        leg2->AddEntry(grAll[i],Form("%s",HLTpathName[i]),"p");
    }
    leg2->Draw();
    l->Draw("LSAME");
    l1->Draw("LSAME");
    l2->Draw("LSAME");
    l3->Draw("LSAME");
    l4->Draw("LSAME");
    l5->Draw("LSAME");


c1->SaveAs("plot_L1Eff_MC.png");
c2->SaveAs("plot_HLTEff_MC.png");
c3->SaveAs("plot_L1HLTEff_MC.png");

}

