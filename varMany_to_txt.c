//the is program is used to read branches from root file 
// and write the corresponding values into a txt file
void varMany_to_txt(){
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
for(int ijet=1;ijet<7;ijet++){
	for(int ivar=0;ivar<4;ivar++){
		jetvar="jet"+jet_vars[ivar]+"_"+to_string(ijet);
		varNames.push_back(jetvar);
	}
 varNames.push_back("btag_"+to_string(ijet));

}
/*
    varNames.push_back("top1_phi");
	varNames.push_back("top1_eta");
	varNames.push_back("top1_pt");
	varNames.push_back("top1_m" );
	varNames.push_back("top2_phi");
	varNames.push_back("top2_eta");
	varNames.push_back("top2_pt");
	varNames.push_back("top2_m" );

	//varNames.push_back("helcosthetaZ1_1",'F');
	varNames.push_back("helcosthetaZ1_3");
	varNames.push_back("helcosthetaZ1_4");
	varNames.push_back("helcosthetaZ2_1");
	varNames.push_back("helcosthetaZ2_3");
	varNames.push_back("costhetastar_1");
	//varNames.push_back("costhetastar_2"');
	varNames.push_back("costhetastar_3");
	varNames.push_back("costhetastar_4");
	varNames.push_back("helphi_3");
	varNames.push_back("phistarZ1_3");
	varNames.push_back("phistarZ1_4");
	varNames.push_back("phistarZ2_1");
	varNames.push_back("phistarZ2_3");
	varNames.push_back("top1_tt_costheta");
*/

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



const char * filesig = "sig_many_values.csv";
const char *filebkg="bkg_many_values.csv";

ofstream out_sig(filesig); //open a file in writing mode
//write the branch names into the first line
for(int kk=0;kk<num;kk++){
	if(kk<num-1) out_sig << varNames[kk]<<", ";
	if(kk==num-1) out_sig <<varNames[kk]<<endl;
}
//write  data into the file opened 
for(int i=0;i< tp->GetEntries();i++){
	tp->GetEntry(i);
	for(int kk=0;kk<num;kk++){
		if(kk<num-1)
			out_sig<<sig_values[kk]<<",";
		
		if(kk==num-1)
			out_sig<<sig_values[kk]<<endl;
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
	for(int kk=0;kk<num;kk++){
		if(kk<num-1)
			out_bkg<<bkg_values[kk]<<" ,";
		
		if(kk==num-1)
			out_bkg<<bkg_values[kk]<<endl;
	}
} 
out_bkg.close();

//read the first line of file"sig_values.txt"
ifstream infile;
infile.open(filesig);
if (!infile.is_open())
	{
		cout << "can not open this file" << endl;
		return 0;
	}
else{ 
	   cout<<"reading the sig_many_values.csv file"<<endl;
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
cout <<num<<" varaibles(including weights) have been written into the files."<<endl;

}
