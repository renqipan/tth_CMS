//the is program is used to read branches from root file 
// and write the corresponding values into a txt file
void rootvar_to_txt(){
	TFile *fm=new TFile("./ttH0M_M125_moriond_2018.root");
	TFile *fp=new TFile("./ttH0P_M125_moriond_2018.root");
	TTree *tm, *tp;
	fm->GetObject("SelectedTree",tm);
	fp->GetObject("SelectedTree",tp);
	vector <string> varNames,names;

//loop to load all the variables of jets 
string jetvar,jet_vars[5]={"Pt","Eta","Phi","Mass","BTagger"};
for(int ijet=1;ijet<3;ijet++){
	for(int ivar=0;ivar<5;ivar++){
		jetvar="Jet"+jet_vars[ivar]+to_string(ijet);
		varNames.push_back(jetvar);
	}

}

	varNames.push_back("ExtraLepPt1");
	varNames.push_back("ExtraLepPhi1");
	varNames.push_back("ExtraLepEta1");

	/*varNames.push_back("ZZPt");
	varNames.push_back("ZZPhi");
	varNames.push_back("ZZEta");
	varNames.push_back("ZZMass"); */
	varNames.push_back("weight");

Int_t  sig_category,bkg_category;
tm->SetBranchAddress("category",&bkg_category);
tp->SetBranchAddress("category",&sig_category);

int num=varNames.size();
float sig_values[num],bkg_values[num];
for(int k=0;k<num;k++){
tm->SetBranchAddress(varNames[k].c_str(),&bkg_values[k]);
tp->SetBranchAddress(varNames[k].c_str(),&sig_values[k]);
}

vector <Float_t> *sig_LepPt=new vector <Float_t>();
vector <Float_t> *sig_LepPhi=new vector <Float_t>();
vector <Float_t> *sig_LepEta=new vector <Float_t>();
vector <Float_t> *bkg_LepPt=new vector <Float_t>();
vector <Float_t> *bkg_LepPhi=new vector <Float_t>();
vector <Float_t> *bkg_LepEta=new vector <Float_t>();

tm->SetBranchAddress("LepPt",&bkg_LepPt);
tm->SetBranchAddress("LepPhi",&bkg_LepPhi);
tm->SetBranchAddress("LepEta",&bkg_LepEta);
tp->SetBranchAddress("LepPt",&sig_LepPt);
tp->SetBranchAddress("LepPhi",&sig_LepPhi);
tp->SetBranchAddress("LepEta",&sig_LepEta);


const char * filesig = "sig_lep_values.csv";
const char *filebkg="bkg_lep_values.csv";

ofstream out_sig(filesig); //open a file in writing mode
//write the branch names into the first line
out_sig<<"LepPt[0]"<<","<<"LepPt[1]"<<","<<"LepPt[2]"<<","<<"LepPt[3]"<<",";
out_sig<<"LepPhi[0]"<<","<<"LepPhi[1]"<<","<<"LepPhi[2]"<<","<<"LepPhi[3]"<<",";
out_sig<<"LepEta[0]"<<","<<"LepEta[1]"<<","<<"LepEta[2]"<<","<<"LepEta[3]"<<",";

for(int kk=0;kk<num;kk++){
	if(kk<num-1) out_sig << varNames[kk]<<", ";
	if(kk==num-1) out_sig <<varNames[kk]<<endl;
}
//write  data into the file opened 
for(int i=0;i< tp->GetEntries();i++){
	tp->GetEntry(i);
	if(sig_category==5){
	    for(int ii=0;ii<4;ii++){
	    	out_sig<< (*sig_LepPt)[ii]<<",";
	    }
	    for(int ii=0;ii<4;ii++){
	    	out_sig<< (*sig_LepPhi)[ii]<<",";
	    }
	    for(int ii=0;ii<4;ii++){
	    	out_sig<< (*sig_LepEta)[ii]<<",";
	    }

		for(int kk=0;kk<num;kk++){
			if(kk<num-1)
				out_sig<<sig_values[kk]<<",";
			
			if(kk==num-1)
				out_sig<<sig_values[kk]<<endl;
		}
	}	
} 
out_sig.close();

ofstream out_bkg(filebkg);
//write the branch names into the first line
out_bkg<<"LepPt[0]"<<","<<"LepPt[1]"<<","<<"LepPt[2]"<<","<<"LepPt[3]"<<",";
out_bkg<<"LepPhi[0]"<<","<<"LepPhi[1]"<<","<<"LepPhi[2]"<<","<<"LepPhi[3]"<<",";
out_bkg<<"LepEta[0]"<<","<<"LepEta[1]"<<","<<"LepEta[2]"<<","<<"LepEta[3]"<<",";

for(int kk=0;kk<num;kk++){
	if(kk<num-1) out_bkg << varNames[kk]<<", ";
	if(kk==num-1) out_bkg <<varNames[kk]<<endl;
}
for(int i=0;i< tm->GetEntries();i++){
	tm->GetEntry(i);
	if(bkg_category==5){

		for(int ii=0;ii<4;ii++){
	    	out_bkg<< (*bkg_LepPt)[ii]<<",";
	    }
	    for(int ii=0;ii<4;ii++){
	    	out_bkg<< (*bkg_LepPhi)[ii]<<",";
	    }
	    for(int ii=0;ii<4;ii++){
	    	out_bkg<< (*bkg_LepEta)[ii]<<",";
	    }
		for(int kk=0;kk<num;kk++){
			if(kk<num-1)
				out_bkg<<bkg_values[kk]<<" ,";
			
			if(kk==num-1)
				out_bkg<<bkg_values[kk]<<endl;
		}
	}
} 
out_bkg.close();

//read the first line of file"sig_values.txt"
ifstream infile;
infile.open(filebkg);
if (!infile.is_open())
	{
		cout << "can not open this file" << endl;
		return 0;
	}
else{ 
	   cout<<"reading from "<<filebkg<<endl;
	   char names[1000],data[1000];
	   infile.getline(names,1000);
	   cout<<names<<endl;
	   infile.getline(data,1000);
	   cout<<data<<endl;
	  //second method for printing the first line from the txt file
	  /* float var_values[num];
	   for(int ii=0; ii<num;ii++)
	   	infile >> var_values[ii];
	   for(int jj=0;jj<num;jj++)
	   	cout<<var_values[jj]<<" ";
	  */
}
infile.close();
cout <<num+12<<" varaibles(including weights) have been written into the files."<<endl;

}
