void check(){
	TFile *file=TFile::Open("ttHiggs0MToGG.root");
	TTree *tree=(TTree*)file->Get("ttH_0M_125_13TeV_TTHHadronicTag");
	

	float bjetE_1,bjetPt_1,bjetEta_1,bjetPhi_1;
	float bjetE_2,bjetPt_2,bjetEta_2,bjetPhi_2;
	tree->SetBranchAddress("bjetPt_1",&bjetPt_1);
	tree->SetBranchAddress("bjetE_1",&bjetE_1);
	tree->SetBranchAddress("bjetEta_1",&bjetEta_1);
	tree->SetBranchAddress("bjetPhi_1",&bjetPhi_1);
	tree->SetBranchAddress("bjetPt_2",&bjetPt_2);
	tree->SetBranchAddress("bjetE_2",&bjetE_2);
	tree->SetBranchAddress("bjetEta_2",&bjetEta_2);
	tree->SetBranchAddress("bjetPhi_2",&bjetPhi_2);
	
	tree->GetEntry(100);

	//loop to load all the variables of jets 
TString jetvar,jet_vars[4]={"Pt","Eta","Phi","E"};
float jet[10][4];
bool b1=false, b2=false;
for(int ijet=1;ijet<11;ijet++){
	for(int ivar=0;ivar<4;ivar++){
		jetvar="jet"+jet_vars[ivar]+"_"+to_string(ijet);
		tree->SetBranchAddress(jetvar,&jet[ijet-1][ivar]);
	}

	if(jet[ijet-1][0]==bjetPt_1&& jet[ijet-1][1]==bjetEta_1 &&
			jet[ijet-1][2]==bjetPhi_1&&jet[ijet-1][3]==bjetE_1)
		{cout<<"bjet_1 is the "<<ijet<<"th jet"<<endl;
			b1=true;
		}

	if(jet[ijet-1][0]==bjetPt_2&& jet[ijet-1][1]==bjetEta_2 &&
			jet[ijet-1][2]==bjetPhi_2&&jet[ijet-1][3]==bjetE_2)
		{cout<<"bjet_2 is the "<<ijet<<"th jet"<<endl;
			b2=true;
		}
	if(b1 && b2){break;}
	if(ijet==10) cout<<"the two bjets are not contained in the ten jets."<<endl;
}


}
