void tmva_xgboost(){
	

	TMultiGraph *mg = new TMultiGraph();
	auto leg=new TLegend(.7,.7,.9,.9,"Methods");
	//plot roc curve of tmva
	string fileName="6jets_many_output.root";
	string dir_sig="dataset_many/Method_BDT/BDT/MVA_BDT_S";
	string dir_bkg="dataset_many/Method_BDT/BDT/MVA_BDT_B";
	TFile *fvar=TFile::Open(fileName.c_str()); 
	auto hist_sig=(TH1F*)fvar->Get(dir_sig.c_str());
	auto hist_bkg=(TH1F*)fvar->Get(dir_bkg.c_str());

	int nbins=hist_sig->GetNbinsX();
	int nbinb=hist_bkg->GetNbinsX();
	if(nbinb==nbins) 
		cout<<"the signal and background have same number of bins"<<endl;
	else 
		cout<<"the bins number of signal and background is unequal."<<endl;

	float sig_integral=hist_sig->Integral(1,nbins);
	float bkg_integral=hist_bkg->Integral(1,nbins);

		// create containers sig = x points, bkg = y points
		std::vector<float> sigPoints(nbins);
		std::vector<float> bkgPoints(nbins);
		for ( int ii = 0; ii < nbins; ++ii ) {
		  // notice the slice integral is dependent on i!
		  float sig_slice_integral = hist_sig->Integral(nbins-ii,nbins);
		  float bkg_slice_integral = hist_bkg->Integral(nbins-ii,nbins);
		  sigPoints.push_back(sig_slice_integral/sig_integral);
		  bkgPoints.push_back(1-bkg_slice_integral/bkg_integral);
		  if(sig_slice_integral <0) cout<<sig_slice_integral<<endl;
		  }

	  auto g= new TGraph(sigPoints.size(),&sigPoints[0],&bkgPoints[0]);
      g->SetLineColor(2);
      g->SetLineWidth(2);
      mg->Add(g);
      TLegendEntry* leg_entry=leg->AddEntry(g,"tmva:BDT");
      leg_entry->SetTextColor(1);
//plot roc curve of xgboost

    ifstream infile;
    infile.open("xgboost.CSV");
    if(!infile) cout<<"error"<<endl;
    int fpr_size=27846;  //define the lenth of fpr and tpr
    float a[fpr_size][2];  //define a empty array 

    if(infile){
        string str;
        float t1;
        cout<<"write data into an array"<<endl;
        float *p=&a[0][0];
        while(infile>>t1){
            *p=t1;
            p++;
        }
    }    
	std::vector<float> ffpr;
	std::vector<float> tpr;
    for(int i=0;i<fpr_size;i++) ffpr.push_back(1-a[i][0]);
    for(int i=0;i<fpr_size;i++) tpr.push_back(a[i][1]);
     auto g1= new TGraph(fpr_size,&tpr[0],&ffpr[0]);
      g1->SetLineColor(3);
      g1->SetLineWidth(2);
      mg->Add(g1);
      TLegendEntry* leg_entry1=leg->AddEntry(g1,"xgboost");
      leg_entry1->SetTextColor(1);
	

    mg->SetTitle("Signal efficiency vs. Background rejection");
  	mg->GetXaxis()->SetTitle("Signal efficiency(sensitivity)");
  	mg->GetYaxis()->SetTitle("Background rejection(specificity)");
    mg->Draw("AC"); 
    leg->SetFillColor(0);
	leg->DrawClone("Same");
	gPad->Print("tmva_xgboost.png");


}