//return 4 momentum
float *fun_4p(float particle[4],char p_fisrt){
	//particle[]={m,pt,phi,eta}
	static float momentum[4];
	momentum[1]=particle[1]*cos(particle[2]);//px
	momentum[2]=particle[1]*sin(particle[2]);//py
	momentum[3]=particle[1]*(1-exp(-2*particle[3]))/(2*exp(-particle[3]));//pz
	if(p_fisrt=='m')
	momentum[0]=sqrt(momentum[1]*momentum[1]+momentum[2]*momentum[2]+
					momentum[3]*momentum[3]+particle[0]*particle[0]);//E
	if(p_fisrt=='E') momentum[0]=particle[0];
	return momentum;
}
//return 4 momentum after boost
float *lorentz_boost(float *p,float *q,float m_q){
	float q_square=q[1]*q[1]+q[2]*q[2]+q[3]*q[3];
    float hq=((q[0]-m_q)*(p[1]*q[1]+p[2]*q[2]+p[3]*q[3])/q_square-p[0])/m_q;
	 static float p_boosted[4];
	 p_boosted[1]=p[1]+hq*q[1];
	 p_boosted[2]=p[2]+hq*q[2];
	 p_boosted[3]=p[3]+hq*q[3];
	 p_boosted[0]=(p[0]*q[0]-p[1]*q[1]-p[2]*q[2]-p[3]*q[3])/m_q;
	 return p_boosted;
}
//calculate the magnitude of 3 momentum
float momenta(float pp[4]){
	float magnitude;
	magnitude=sqrt(pp[1]*pp[1]+pp[2]*pp[2]+pp[3]*pp[3]);
	return magnitude;

}
void addBranch(){
	TFile *sigFile = new TFile("./ttHiggs0MToGG.root","update");
	//read the top1 top2 information
	float top1_m,top1_pt,top1_eta,top1_phi;
	float top2_m,top2_pt,top2_eta,top2_phi;
	TTree *tree=(TTree *) sigFile->Get("ttH_0M_125_13TeV_TTHHadronicTag");
	tree->SetBranchAddress("top1_phi",&top1_phi);
	tree->SetBranchAddress("top1_eta",&top1_eta);
	tree->SetBranchAddress("top1_pt",&top1_pt);
	tree->SetBranchAddress("top1_m",&top1_m );
	tree->SetBranchAddress("top2_phi",&top2_phi);
	tree->SetBranchAddress("top2_eta",&top2_eta);
	tree->SetBranchAddress("top2_pt",&top2_pt);
	tree->SetBranchAddress("top2_m",&top2_m );
	
	float top1_tt_costheta,top2_tt_costheta,bjet_tt_cosphi;
	TBranch *costheat1=tree->Branch("top1_tt_costheta",&top1_tt_costheta,"top1_tt_costheta/F");
    TBranch *costheat2=tree->Branch("top2_tt_costheta",&top2_tt_costheta,"top2_tt_costheta/F");

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
    TBranch *cosphi=tree->Branch("bjet_tt_cosphi",&bjet_tt_cosphi,"bjet_tt_cosphi/F");


//read and over loop the tree
	Int_t nentries = (Int_t)tree->GetEntries();
   for (Int_t i=0; i<nentries; i++) {
   	tree->GetEntry(i);

   //add variable top1_tt_costheta  to the tree
   float top1_angle[4]={top1_m,top1_pt,top1_phi,top1_eta};
   	float top2_angle[4]={top2_m,top2_pt,top2_phi,top2_eta};
   	float *top1_4p,*top2_4p;
   	top1_4p=fun_4p(top1_angle,'m');
   	//store the data into array t1_4p,t2_4p
   	float t1_4p[4],t2_4p[4];
   	for(int i=0;i<4;i++) t1_4p[i]=*(top1_4p+i);
	top2_4p=fun_4p(top2_angle,'m');
	for(int i=0;i<4;i++)t2_4p[i]=*(top2_4p+i);
	
   	float *top1_4pboost,*top2_4pboost;
   	float tt_q[4];
   	for(int ii=0;ii<4;ii++) 
   		tt_q[ii]=t1_4p[ii]+t2_4p[ii];
   	float m_q=sqrt(tt_q[0]*tt_q[0]-tt_q[1]*tt_q[1]-tt_q[2]*tt_q[2]-tt_q[3]*tt_q[3]);

   	 float top1_tt[4],top2_tt[4];
	top1_4pboost=lorentz_boost(t1_4p,tt_q,m_q);
	for(int kk=0;kk<4;kk++) top1_tt[kk]=*(top1_4pboost+kk);

   	top2_4pboost=lorentz_boost(t2_4p,tt_q,m_q);
   	for(int kk=0;kk<4;kk++) top2_tt[kk]=*(top2_4pboost+kk);

   	float top1_tt_p,top2_tt_p;
    top1_tt_p=momenta(top1_tt);
    top2_tt_p=momenta(top2_tt);
    top1_tt_costheta=top1_tt[3]/top1_tt_p;
    top2_tt_costheta=top2_tt[3]/top2_tt_p;
	costheat1->Fill();
	costheat2->Fill();

	//add variable bjet_tt_cosphi to the tree
	float bjet1_angle[4]={bjetE_1,bjetPt_1,bjetPhi_1,bjetEta_1};
	float bjet2_angle[4]={bjetE_2,bjetPt_2,bjetPhi_2,bjetEta_2};
	//get the bjet momentum in form {E,px,py,pz}
	float *bjet1_4p,*bjet2_4p;
	float b1_4p[4],b2_4p[4];
	bjet1_4p=fun_4p(bjet1_angle,'E');

	for(int kk=0;kk<4;kk++) b1_4p[kk]=*(bjet1_4p+kk);
	bjet2_4p=fun_4p(bjet2_angle,'E');
	for(int kk=0;kk<4;kk++) b2_4p[kk]=*(bjet2_4p+kk);
	//boost the bjets to tt reference frame
	float *bjet1_boosted,*bjet2_boosted;
	float bjet1_tt[4],bjet2_tt[4];
	bjet1_boosted=lorentz_boost(b1_4p,tt_q,m_q);
	for(int kk=0;kk<4;kk++) bjet1_tt[kk]=*(bjet1_boosted+kk);
		
	bjet2_boosted=lorentz_boost(b2_4p,tt_q,m_q);
	for(int kk=0;kk<4;kk++) bjet2_tt[kk]=*(bjet2_boosted+kk);
	//calculate the cosphi of the two bjets in tt frame
	float bjet1_tt_pt=sqrt(bjet1_tt[1]*bjet1_tt[1]+bjet1_tt[2]*bjet1_tt[2]);
	float bjet2_tt_pt=sqrt(bjet2_tt[1]*bjet2_tt[1]+bjet2_tt[2]*bjet2_tt[2]);
	bjet_tt_cosphi=(bjet1_tt[1]*bjet2_tt[1]+bjet1_tt[2]*bjet2_tt[2])/bjet1_tt_pt/bjet2_tt_pt;
	cosphi->Fill();

   }
    tree->Write("",TObject::kOverwrite); // save only the new version of the tree
    auto branches=tree->GetListOfBranches(); // the retun type is TObjectArray *
    for(int j=0;j<branches->GetEntries();j++){
    string	branchName=branches->At(j)->GetName();
    	if(branchName=="top1_tt_costheta")
    		cout<<"the variable top1_tt_costheta has been writen to the root file."<<endl;
    	if(branchName=="bjet_tt_cosphi")
    		cout<<"the variable bjet_tt_cosphi has been writen to the root file."<<endl;
     }
     cout<<"the number of total events is "<<tree->GetEntries()<<endl;
     sigFile->Close();
    
 }

