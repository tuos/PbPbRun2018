void trkETT_plot(){

   TH1::SetDefaultSumw2();

   //TFile *inFile = new TFile("../HLTeff_jbs_mc.root");
   //TFile *inFile = new TFile("../HLTeff_jb1030All_mc.root");

   //TFile *inFile = new TFile("../HLTeff_crabv03_mc.root");
   TFile *inFile = new TFile("../HLTeff_jb100files_mc.root");
   TTree *tree1 = (TTree*)inFile->Get("HLTinfo/HLTeff");
   Int_t trk;
   Double_t ett, trkp, trkm, vz;
   tree1->SetBranchAddress("ETT",&ett);
   tree1->SetBranchAddress("NtrkFull",&trk);
   //tree1->SetBranchAddress("nTrkMinus",&trkm);
   tree1->SetBranchAddress("HLTVtxZ",&vz);

   //create two histograms
   TH1F *hETT   = new TH1F("ett","",2500,0,2500);
   TH1F *hNtrk   = new TH1F("ntrk","",150,0,150);
   TH2F *hETTntrk = new TH2F("ettntrk","",150,0,150,150,0,150);
   TH1F *hNtrkp   = new TH1F("ntrkp","",150,0,150);
   TH1F *hNtrkm   = new TH1F("ntrkm","",150,0,150);
   TH1F *px;

   //read all entries and fill the histograms
   Long64_t nentries = tree1->GetEntries();
   cout<<"Total events: "<<nentries<<endl;
   for (Long64_t i=0;i<nentries;i++) {
     tree1->GetEntry(i);
     hETT->Fill(ett);
     hNtrk->Fill(trk);
     hETTntrk->Fill(trk, ett);
  }

  hprof = new TProfile("hprof","ETT vs Ntrk",200,0,200,0,200);
  //tree1->Draw("ETT:(nTrkPlus+nTrkMinus)>>hprof","(nTrkPlus+nTrkMinus)<200&&ETT<70","profs");
  tree1->Draw("ETT:NtrkFull>>hprof","NtrkFull<200&&ETT<200","goff");

  for(int k=0; k<hETTntrk->GetXaxis()->GetNbins(); k++){
    px=(TH1F*)hETTntrk->ProjectionY("px", k+1, k+1);
//cout<<"k = "<<k<<"  mx: "<<px->GetMean()<<endl;
    hNtrkp->SetBinContent(k+1, px->GetMean()+2*px->GetRMS());
    //hNtrkp->SetBinError(k+1, px->GetRMS());
    hNtrkm->SetBinContent(k+1, px->GetMean()-2*px->GetRMS());
    //hNtrkm->SetBinError(k+1, px->GetRMS());
  }

  TCanvas* c1 = new TCanvas("c1","",550,500);
  c1->SetLeftMargin(0.12);
  c1->SetRightMargin(0.1);
  c1->SetTopMargin(0.02);
  c1->SetBottomMargin(0.12);
  c1->SetTicks(1);
  c1->SetGrid(1);
  c1->SetLogz();
  gStyle->SetOptStat(0);

  TH1D *htmp = new TH1D("htmp","",150,0,150);
  htmp->SetMarkerStyle(20);
  htmp->SetMarkerColor(1);
  htmp->SetMarkerSize(1.0);
  htmp->SetAxisRange(0,200,"Y");
  htmp->SetAxisRange(0,200,"X");
  htmp->GetYaxis()->SetTitle("ETT");
  htmp->GetXaxis()->SetTitle("Ntrk(p_{T}>0.4 GeV/c)");
  htmp->GetXaxis()->CenterTitle(1);
  htmp->GetYaxis()->CenterTitle(1);
  htmp->GetYaxis()->SetTitleOffset(1.2);
  htmp->GetXaxis()->SetTitleOffset(1.2);
  htmp->GetXaxis()->CenterTitle(1);
  htmp->GetYaxis()->CenterTitle(1);
  htmp->GetXaxis()->SetTitleSize(0.046);
  htmp->GetYaxis()->SetTitleSize(0.046);
  htmp->GetXaxis()->SetTitleFont(62);
  htmp->GetYaxis()->SetTitleFont(62);
  htmp->SetTitle("");
  htmp->Draw();
  
  hETTntrk->Draw("samecolz");
  hprof->Draw("same");
  hNtrkp->SetLineWidth(3);
  hNtrkp->SetLineColor(2);
  hNtrkp->Draw("same");
  hNtrkm->SetLineWidth(3);
  hNtrkm->SetLineColor(1);
  hNtrkm->Draw("same");

  TLatex *t8 = new TLatex(20,160,"PbPb MC 2018");
  t8->SetTextSize(0.05);
  //t8->SetTextColor(2);
  t8->Draw();


  //int binStartA = 20;
  //int binStartB = 60;
  const int endN = 5;
  int binStart[endN] = {0,20, 40, 60, 80};
  int binEnd[endN] = {20,40, 60, 80, 100};
   TH1F *hETTtmp   = new TH1F("hETTtmp","",2500,0,2500);
  for(int k=0; k<endN; k++){
    cout<<"ETT range for : "<<binStart[k]<<" - "<<binEnd[k]<<"   "<<hNtrkm->GetBinContent(binStart[k])<<"   "<<hNtrkp->GetBinContent(binEnd[k])<<endl;
    //cout<<"ETT range for B: "<<hNtrkm->GetBinContent(binStartB)<<"   "<<hNtrkp->GetBinContent(binEnd[k])<<endl;
  }
  for(int k=0; k<endN; k++){
    cout<<"Weighted ETT range for : "<<binStart[k]<<" - "<<binEnd[k]<<"   "<<0.95*hNtrkm->GetBinContent(binStart[k])<<"   "<<0.95*hNtrkp->GetBinContent(binEnd[k])<<endl;
  }


  //int ettBinStartA = 0;
  //int ettBinStartB = 3.53135;
  int ettBinStartA = 0;
  int ettBinStartB = 5;
  int ettBinEnd[endN] = {20.0, 25.9835, 29.8973, 30.0};

  //double totalRate = 50.0;
  double totalRate = 30.0;
  tree1->Draw("ETT>>hETTtmp","ETT>35&& ETT<80","goff");
  cout<<"Rate : "<<hETTtmp->GetEntries()*totalRate/nentries<<endl;
  tree1->Draw("ETT>>hETTtmp","ETT>40&& ETT<95","goff");
  cout<<"Rate : "<<hETTtmp->GetEntries()*totalRate/nentries<<endl;
  tree1->Draw("ETT>>hETTtmp","ETT>45&& ETT<110","goff");
  cout<<"Rate : "<<hETTtmp->GetEntries()*totalRate/nentries<<endl;
  tree1->Draw("ETT>>hETTtmp","ETT>50&& ETT<125","goff");
  cout<<"Rate : "<<hETTtmp->GetEntries()*totalRate/nentries<<endl;
  tree1->Draw("ETT>>hETTtmp","ETT>60&& ETT<135","goff");
  cout<<"Rate : "<<hETTtmp->GetEntries()*totalRate/nentries<<endl;

  tree1->Draw("ETT>>hETTtmp","ETT>0&& ETT<135","goff");
  cout<<"Rate with ETT<135 : "<<hETTtmp->GetEntries()*totalRate/nentries<<endl;

//Rate B are the same as Rate A

  c1->SaveAs("fig_trkETT.pdf");
  c1->SaveAs("fig_trkETT.png");
  c1->SaveAs("fig_trkETT.C");
}


