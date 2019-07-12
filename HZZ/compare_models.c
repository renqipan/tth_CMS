void compare_models(){
	TMultiGraph *mg = new TMultiGraph();
	auto leg=new TLegend(.7,.7,.9,.9,"Models");
	string legend[4]={"AdaBoost:hadronic","AdaBoost:leptonic","XGBoost:hadronic","XGBoost:leptonic"};

	string fileNames[]={"hzzhad_output.root","hzzlep_output.root","xgboost_had_hist.root","xgboost_lep_hist.root"};
	string dir_sig[]={"dataset_hzz_had/Method_BDT/BDT/MVA_BDT_S",
	"dataset_hzz_lep/Method_BDT/BDT/MVA_BDT_S","sig","sig"};
	string dir_bkg[]={"dataset_hzz_had/Method_BDT/BDT/MVA_BDT_B",
	"dataset_hzz_lep/Method_BDT/BDT/MVA_BDT_B","bkg","bkg"};
		for(int i=0;i<4;i++){
		TFile *fvar=TFile::Open(fileNames[i].c_str()); 
		//c_str returns a const char* that points to a null-terminated string (i.e. a C-style string)
		auto hist_sig=(TH1F*)fvar->Get(dir_sig[i].c_str());
		auto hist_bkg=(TH1F*)fvar->Get(dir_bkg[i].c_str());
		//hist_sig->Draw();
		
		int nbins=hist_sig->GetNbinsX();
		int nbinb=hist_bkg->GetNbinsX();
		if(nbinb==nbins) 
		cout<<"the signal and background have same number of bins"<<endl;
		else 
		cout<<"the bins number of signal and background is unequal."<<endl;

	// get the total integrals for each histogram
		float sig_integral=hist_sig->Integral(1,nbins);
		float bkg_integral=hist_bkg->Integral(1,nbins);

		// create containers sig = x points, bkg = y points
		std::vector<float> sigPoints;
		std::vector<float> bkgPoints;

		for ( int ii =0; ii < nbins; ++ii ) {
		  // notice the slice integral is dependent on i!
		  float sig_slice_integral = hist_sig->Integral(nbins-ii,nbins);
		  float bkg_slice_integral = hist_bkg->Integral(nbins-ii,nbins);
		  sigPoints.push_back(sig_slice_integral/sig_integral);
		  bkgPoints.push_back(1-bkg_slice_integral/bkg_integral);
		  }
	   auto g= new TGraph(sigPoints.size(),&sigPoints[0],&bkgPoints[0]);
	   if(i<2)  g->SetMarkerStyle(20);
	   else g->SetMarkerStyle(22);
	   if(i<3){
		   g->SetMarkerColor(i+2);	
		   g->SetLineColor(i+2);}
	  else { g->SetLineColor(6);
	  		g->SetMarkerColor(6);
	  	  }
      g->SetLineWidth(2);
      mg->Add(g);
      TLegendEntry* leg_entry=leg->AddEntry(g,legend[i].c_str());
      if(i<3)leg_entry->SetTextColor(i+2);
      if(i==3) leg_entry->SetTextColor(6);
    

	}
   
  	mg->SetTitle("Signal efficiency vs. Background rejection");
  	mg->GetXaxis()->SetTitle("Signal efficiency(sensitivity)");
  	mg->GetYaxis()->SetTitle("Background rejection(specificity)");
    mg->Draw("ACP");
    leg->SetFillColor(0);
	leg->DrawClone("Same");
	gPad->SetGrid();
	gPad->Print("ROC_BDT_points.png");



}
