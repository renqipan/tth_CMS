void roc_plot(){
	string fileNames[3]={"tth_silly_output.root","tth_var_output.root","tth_many_output.root"};
	string dir_sig[]={"dataset_silly/Method_BDT/BDT/MVA_BDT_S","dataset/Method_BDT/BDT/MVA_BDT_S",
	"dataset_many/Method_BDT/BDT/MVA_BDT_S"};
	string dir_bkg[]={"dataset_silly/Method_BDT/BDT/MVA_BDT_B","dataset/Method_BDT/BDT/MVA_BDT_B",
	"dataset_many/Method_BDT/BDT/MVA_BDT_B"};
	TMultiGraph *mg = new TMultiGraph();
	auto leg=new TLegend(.7,.7,.9,.9,"Input variables");
    string legend[3]={"Silly","Var","Many"};
	TGraph *g_1,*g_2,*g_3,*g;
	for(int i=0;i<3;i++){
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

	  g= new TGraph(sigPoints.size(),&sigPoints[0],&bkgPoints[0]);
      g->SetLineColor(i+1);
      g->SetLineWidth(2);
      mg->Add(g);
      TLegendEntry* leg_entry=leg->AddEntry(g,legend[i].c_str());
      leg_entry->SetTextColor(i+1);

      
  }
   
  	mg->SetTitle("Signal efficiency vs. Background rejection");
  	mg->GetXaxis()->SetTitle("Signal efficiency");
  	mg->GetYaxis()->SetTitle("Background rejection");
    mg->Draw("AC"); 
    leg->SetFillColor(0);
	leg->DrawClone("Same");
	gPad->Print("ROC_Curve.png");


}



