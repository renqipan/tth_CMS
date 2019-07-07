//the is program is used to read branches from root file 
// and write the corresponding values into a txt file
void var_to_txt(){
	TFile *fm=new TFile("ttHiggs0MToGG.root");
	TFile *fp=new TFile("ttHiggs0PToGG.root");
	TTree *tm, *tp;
	fm->GetObject("ttH_0M_125_13TeV_TTHHadronicTag",tm);
	fp->GetObject("ttH_0P_125_13TeV_TTHHadronicTag",tp);
	vector <string> varNames,names;
/*
//loop to load the variables of photons 
string  var,pho_vars[3]={"pt","eta","phi"};
for(int ipho=1;ipho<3;ipho++){
	for(int ivar=0;ivar<3;ivar++){
		var="pho"+to_string(ipho)+"_"+pho_vars[ivar];
		varNames.push_back(var);	}
	}
*/
//loop to load all the variables of jets 
string jetvar,jet_vars[4]={"Pt","Eta","Phi","E"};
for(int ijet=1;ijet<8;ijet++){
	for(int ivar=0;ivar<4;ivar++){
		jetvar="jet"+jet_vars[ivar]+"_"+to_string(ijet);
		varNames.push_back(jetvar);
		varNames.push_back("btag_"+to_string(ijet));
	}
}
varNames.push_back("diPhoPhi");
varNames.push_back("diPhoEta");
varNames.push_back("diPhoPtoM");
varNames.push_back("weight");

int num=varNames.size();
float sig_values[num],bkg_values[num];
for(int k=0;k<num;k++){
tm->SetBranchAddress(varNames[k].c_str(),&bkg_values[k]);
tp->SetBranchAddress(varNames[k].c_str(),&sig_values[k]);
}

const char * filesig = "sig_values.csv";
const char *filebkg="bkg_values.csv";

float sig_tthMvaRes,sig_pho1_idmva,sig_pho2_idmva;
float bkg_tthMvaRes,bkg_pho1_idmva,bkg_pho2_idmva;
tm->SetBranchAddress("tthMvaRes",&bkg_tthMvaRes);
tm->SetBranchAddress("pho1_idmva",&bkg_pho1_idmva);
tm->SetBranchAddress("pho2_idmva",&bkg_pho2_idmva);
tp->SetBranchAddress("tthMvaRes",&sig_tthMvaRes);
tp->SetBranchAddress("pho1_idmva",&sig_pho1_idmva);
tp->SetBranchAddress("pho2_idmva",&sig_pho2_idmva);

ofstream out_sig(filesig); //open a file in writing mode
//write the branch names into the first line
for(int kk=0;kk<num;kk++){
	if(kk<num-1) out_sig << varNames[kk]<<", ";
	if(kk==num-1) out_sig <<varNames[kk]<<endl;
}
//write  data into the file opened 
for(int i=0;i< tp->GetEntries();i++){
	tp->GetEntry(i);
 if(sig_tthMvaRes>0.38&& sig_pho1_idmva>-0.2&&sig_pho2_idmva>-0.2){	
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
for(int kk=0;kk<num;kk++){
	if(kk<num-1) out_bkg << varNames[kk]<<", ";
	if(kk==num-1) out_bkg <<varNames[kk]<<endl;
}
for(int i=0;i< tm->GetEntries();i++){
	tm->GetEntry(i);
	if(bkg_tthMvaRes>0.38&& bkg_pho1_idmva>-0.2&&bkg_pho2_idmva>-0.2) {
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
	   cout<<"reading the sig_values file"<<endl;
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

}
