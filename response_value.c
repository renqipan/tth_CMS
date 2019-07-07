void response_value(){
	string fileNames[3]={"btag6jets_silly_output.root","xgboost_hist.root","keras_DNN_hist.root"};
	string dir_sig[3]={"dataset_silly/Method_BDT/BDT/MVA_BDT_S","sig","sig"};
	string dir_bkg[3]={"dataset_silly/Method_BDT/BDT/MVA_BDT_B","bkg","bkg"};
	TString title[3]={"Distribution of response value of TMVA-BDT","Distribution of response value of XGBoost","Distribution of response value of Keras-DNN"};
	TString outNames[3]={"tmva_response.png","xgboost_reponse.png","keras_response.png"};
	for(int i=0;i<3;i++){
		auto canvas= new TCanvas();
		TFile *fvar=TFile::Open(fileNames[i].c_str()); 
		auto hist_sig=(TH1F*)fvar->Get(dir_sig[i].c_str());
		auto hist_bkg=(TH1F*)fvar->Get(dir_bkg[i].c_str());
		gStyle->SetOptStat(kFALSE);
		//hist_sig->SetLineColor(2);
		hist_sig->GetXaxis()->SetTitle("response value");
		hist_sig->GetYaxis()->SetTitle("Density");
		hist_sig->SetTitle(title[i]);
		hist_sig->SetFillColorAlpha(kBlue, 0.6);

		hist_bkg->GetXaxis()->SetTitle("response value");
		hist_bkg->GetYaxis()->SetTitle("Density");
		hist_bkg->SetTitle(title[i]);
		hist_bkg->SetFillColorAlpha(kGreen, 0.6);
		double max_sig,max_bkg;
		max_sig=hist_sig->GetMaximum();
		max_bkg=hist_bkg->GetMaximum();
		if(max_sig > max_bkg){
			hist_sig->Draw("HIST");
			hist_bkg->Draw("HISTSAME"); 
		}
		else{
			hist_bkg->Draw("HIST");
			hist_sig->Draw("HISTSAME");
		 
		}


	TLegend leg(.7,.7,.9,.9,"CP Property");
	leg.SetFillColor(0);
	leg.AddEntry(hist_bkg,"CP Odd");
	leg.AddEntry(hist_sig,"CP Even");
	leg.DrawClone("Same");					
	gPad->Print(outNames[i]);

	}
}