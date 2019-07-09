//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jul  8 20:53:39 2019 by ROOT version 6.19/01
// from TTree SelectedTree/SelectedTree
// found on file: ./ttH0P_M125_moriond_2018.root
//////////////////////////////////////////////////////////

#ifndef SelectedTree_h
#define SelectedTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "TString.h"

class SelectedTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Float_t         dbkg_kin;
   Float_t         dbkg;
   Float_t         d_2j;
   Float_t         d_2j_up;
   Float_t         d_2j_dn;
   Float_t         d_2j_qq;
   Float_t         d_2j_other;
   Float_t         d_2j_qqgen;
   Float_t         d_2jgen;
   Float_t         dphi;
   Float_t         dphigen;
   Float_t         mjjgen;
   Float_t         mjj;
   Float_t         gene;
   Float_t         genpt;
   Int_t           ngenjet;
   Float_t         vbfMela;
   Float_t         vbfMela_gen;
   Float_t         vbfMela_qg;
   Float_t         weight;
   vector<float>   *weight_up;
   vector<float>   *weight_dn;
   vector<TString> *weight_name;
   Int_t           nmatch;
   vector<float>   *drj;
   vector<float>   *dptj;
   vector<float>   *dphij;
   Float_t         GenHPt;
   Float_t         GenHEta;
   Float_t         GenHPhi;
   Float_t         GenHMass;
   Float_t         ZZPt;
   Short_t         nCleanedJetsPt30BTagged_bTagSF;
   Float_t         ZZPhi;
   Float_t         ZZEta;
   Float_t         ZZMass;
   vector<float>   *JetPt;
   vector<float>   *JetPhi;
   vector<float>   *JetEta;
   vector<float>   *JetMass;
   vector<float>   *LepPt;
   vector<float>   *LepPhi;
   vector<float>   *LepEta;
   vector<float>   *ExtraLepPt;
   vector<float>   *ExtraLepPhi;
   vector<float>   *ExtraLepEta;
   vector<float>   *genjpt;
   vector<float>   *reso;
   vector<int>     *reso_id;
   vector<float>   *opt;
   vector<float>   *LHEDaughterMass;
   vector<float>   *LHEAssociatedParticleEta;
   vector<float>   *LHEAssociatedParticlePhi;
   vector<float>   *LHEAssociatedParticlePt;
   Float_t         qgL;
   Int_t           chan;
   Int_t           vbfcate;
   Int_t           nCleanedJetsPt30;
   Short_t         nCleanedJetsPt30_jecUp;
   Short_t         nCleanedJetsPt30_jecDn;
   Short_t         nExtraLep;
   Int_t           qg;
   Float_t         qqfrac;
   Int_t           category;
   Char_t          categoryName[13];
   Char_t          category_baysien7Name[5];
   Int_t           category_baysien7;
   Float_t         mcweight;
   Float_t         xsec;
   Short_t         RunNumber;
   Short_t         EventNumber;
   Float_t         D2jet;
   Float_t         D2jet_dn;
   Float_t         D2jet_up;
   Float_t         D1jet;
   Float_t         DWH;
   Float_t         DZH;
   Float_t         DVH;
   Float_t         DVBFDEC;
   Float_t         DVHDEC;
   Int_t           htxs_stage1_cat;
   Int_t           htxs_stage1_red_cat;
   Int_t           htxs_stage1_red_prod_cat;
   Int_t           htxs_stage1_reco_cat;
   Int_t           htxs_stage1_reco_cat_jec_up;
   Int_t           htxs_stage1_reco_cat_jec_dn;
   Int_t           htxs_stage1_reco_cat_jer_up;
   Int_t           htxs_stage1_reco_cat_jer_dn;
   Int_t           htxs_stage1_reco_cat_btag_dn;
   Int_t           htxs_stage1_reco_cat_btag_up;
   Int_t           category_jec_up;
   Int_t           category_jec_dn;
   Int_t           category_jer_up;
   Int_t           category_jer_dn;
   Int_t           category_btag_dn;
   Int_t           category_btag_up;
   TString         *htxs_stage1_catName;
   TString         *htxs_stage1_red_catName;
   TString         *htxs_stage1_red_prod_catName;
   TString         *htxs_stage1_reco_catName;
   TString         *htxs_stage1_reco_catName_jec_up;
   TString         *htxs_stage1_reco_catName_jec_dn;
   TString         *htxs_stage1_reco_catName_jer_up;
   TString         *htxs_stage1_reco_catName_jer_dn;
   TString         *htxs_stage1_reco_catName_btag_dn;
   TString         *htxs_stage1_reco_catName_btag_up;
   Int_t           htxs_prodMode;
   TString         *categoryName_jec_up;
   TString         *categoryName_jec_dn;
   TString         *categoryName_btag_dn;
   TString         *categoryName_btag_up;
   TString         *htxs_prodModeName;
   Float_t         JetPt1;
   Float_t         JetEta1;
   Float_t         JetPhi1;
   Float_t         JetMass1;
   Float_t         JetIsBtagged1;
   Float_t         JetBTagger1;
   Float_t         JetPt2;
   Float_t         JetEta2;
   Float_t         JetPhi2;
   Float_t         JetMass2;
   Float_t         JetIsBtagged2;
   Float_t         JetBTagger2;
   Float_t         JetPt3;
   Float_t         JetEta3;
   Float_t         JetPhi3;
   Float_t         JetMass3;
   Float_t         JetIsBtagged3;
   Float_t         JetBTagger3;
   Float_t         JetPt4;
   Float_t         JetEta4;
   Float_t         JetPhi4;
   Float_t         JetMass4;
   Float_t         JetIsBtagged4;
   Float_t         JetBTagger4;
   Float_t         JetPt5;
   Float_t         JetEta5;
   Float_t         JetPhi5;
   Float_t         JetMass5;
   Float_t         JetIsBtagged5;
   Float_t         JetBTagger5;
   Float_t         JetPt6;
   Float_t         JetEta6;
   Float_t         JetPhi6;
   Float_t         JetMass6;
   Float_t         JetIsBtagged6;
   Float_t         JetBTagger6;
   Float_t         ExtraLepPt1;
   Float_t         ExtraLepEta1;
   Float_t         ExtraLepPhi1;
   Float_t         ExtraLepPt2;
   Float_t         ExtraLepEta2;
   Float_t         ExtraLepPhi2;
   Float_t         PFMET;
   Float_t         gen_assoV_m;
   Float_t         gen_assoV_pt;
   Float_t         gen_assoV_eta;
   Float_t         gen_assoV_phi;
   Float_t         pt_hjj;

   // List of branches
   TBranch        *b_dbkg_kin;   //!
   TBranch        *b_dbkg;   //!
   TBranch        *b_d_2j;   //!
   TBranch        *b_d_2j_up;   //!
   TBranch        *b_d_2j_dn;   //!
   TBranch        *b_d_2j_qq;   //!
   TBranch        *b_d_2j_other;   //!
   TBranch        *b_d_2j_qqgen;   //!
   TBranch        *b_d_2jgen;   //!
   TBranch        *b_dphi;   //!
   TBranch        *b_dphigen;   //!
   TBranch        *b_mjjgen;   //!
   TBranch        *b_mjj;   //!
   TBranch        *b_gene;   //!
   TBranch        *b_genpt;   //!
   TBranch        *b_ngenjet;   //!
   TBranch        *b_vbfMela;   //!
   TBranch        *b_vbfMela_gen;   //!
   TBranch        *b_vbfMela_qg;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_weight_up;   //!
   TBranch        *b_weight_dn;   //!
   TBranch        *b_weight_name;   //!
   TBranch        *b_nmatch;   //!
   TBranch        *b_drj;   //!
   TBranch        *b_dptj;   //!
   TBranch        *b_dphij;   //!
   TBranch        *b_GenHPt;   //!
   TBranch        *b_GenHEta;   //!
   TBranch        *b_GenHPhi;   //!
   TBranch        *b_GenHMass;   //!
   TBranch        *b_ZZPt;   //!
   TBranch        *b_nCleanedJetsPt30BTagged_bTagSF;   //!
   TBranch        *b_ZZPhi;   //!
   TBranch        *b_ZZEta;   //!
   TBranch        *b_ZZMass;   //!
   TBranch        *b_JetPt;   //!
   TBranch        *b_JetPhi;   //!
   TBranch        *b_JetEta;   //!
   TBranch        *b_JetMass;   //!
   TBranch        *b_LepPt;   //!
   TBranch        *b_LepPhi;   //!
   TBranch        *b_LepEta;   //!
   TBranch        *b_ExtraLepPt;   //!
   TBranch        *b_ExtraLepPhi;   //!
   TBranch        *b_ExtraLepEta;   //!
   TBranch        *b_genjpt;   //!
   TBranch        *b_reso;   //!
   TBranch        *b_reso_id;   //!
   TBranch        *b_opt;   //!
   TBranch        *b_LHEDaughterMass;   //!
   TBranch        *b_LHEAssociatedParticleEta;   //!
   TBranch        *b_LHEAssociatedParticlePhi;   //!
   TBranch        *b_LHEAssociatedParticlePt;   //!
   TBranch        *b_qgL;   //!
   TBranch        *b_chan;   //!
   TBranch        *b_vbfcate;   //!
   TBranch        *b_nCleanedJetsPt30;   //!
   TBranch        *b_nCleanedJetsPt30_jecUp;   //!
   TBranch        *b_nCleanedJetsPt30_jecDn;   //!
   TBranch        *b_nExtraLep;   //!
   TBranch        *b_qg;   //!
   TBranch        *b_qqfrac;   //!
   TBranch        *b_category;   //!
   TBranch        *b_categoryName;   //!
   TBranch        *b_category_baysien7Name;   //!
   TBranch        *b_category_baysien7;   //!
   TBranch        *b_mcweight;   //!
   TBranch        *b_xsec;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_D2jet;   //!
   TBranch        *b_D2jet_dn;   //!
   TBranch        *b_D2jet_up;   //!
   TBranch        *b_D1jet;   //!
   TBranch        *b_DWH;   //!
   TBranch        *b_DZH;   //!
   TBranch        *b_DVH;   //!
   TBranch        *b_DVBFDEC;   //!
   TBranch        *b_DVHDEC;   //!
   TBranch        *b_htxs_stage1_cat;   //!
   TBranch        *b_htxs_stage1_red_cat;   //!
   TBranch        *b_htxs_stage1_red_prod_cat;   //!
   TBranch        *b_htxs_stage1_reco_cat;   //!
   TBranch        *b_htxs_stage1_reco_cat_jec_up;   //!
   TBranch        *b_htxs_stage1_reco_cat_jec_dn;   //!
   TBranch        *b_htxs_stage1_reco_cat_jer_up;   //!
   TBranch        *b_htxs_stage1_reco_cat_jer_dn;   //!
   TBranch        *b_htxs_stage1_reco_cat_btag_dn;   //!
   TBranch        *b_htxs_stage1_reco_cat_btag_up;   //!
   TBranch        *b_category_jec_up;   //!
   TBranch        *b_category_jec_dn;   //!
   TBranch        *b_category_jer_up;   //!
   TBranch        *b_category_jer_dn;   //!
   TBranch        *b_category_btag_dn;   //!
   TBranch        *b_category_btag_up;   //!
   TBranch        *b_htxs_stage1_catName;   //!
   TBranch        *b_htxs_stage1_red_catName;   //!
   TBranch        *b_htxs_stage1_red_prod_catName;   //!
   TBranch        *b_htxs_stage1_reco_catName;   //!
   TBranch        *b_htxs_stage1_reco_catName_jec_up;   //!
   TBranch        *b_htxs_stage1_reco_catName_jec_dn;   //!
   TBranch        *b_htxs_stage1_reco_catName_jer_up;   //!
   TBranch        *b_htxs_stage1_reco_catName_jer_dn;   //!
   TBranch        *b_htxs_stage1_reco_catName_btag_dn;   //!
   TBranch        *b_htxs_stage1_reco_catName_btag_up;   //!
   TBranch        *b_htxs_prodMode;   //!
   TBranch        *b_categoryName_jec_up;   //!
   TBranch        *b_categoryName_jec_dn;   //!
   TBranch        *b_categoryName_btag_dn;   //!
   TBranch        *b_categoryName_btag_up;   //!
   TBranch        *b_htxs_prodModeName;   //!
   TBranch        *b_JetPt1;   //!
   TBranch        *b_JetEta1;   //!
   TBranch        *b_JetPhi1;   //!
   TBranch        *b_JetMass1;   //!
   TBranch        *b_JetIsBtagged1;   //!
   TBranch        *b_JetBTagger1;   //!
   TBranch        *b_JetPt2;   //!
   TBranch        *b_JetEta2;   //!
   TBranch        *b_JetPhi2;   //!
   TBranch        *b_JetMass2;   //!
   TBranch        *b_JetIsBtagged2;   //!
   TBranch        *b_JetBTagger2;   //!
   TBranch        *b_JetPt3;   //!
   TBranch        *b_JetEta3;   //!
   TBranch        *b_JetPhi3;   //!
   TBranch        *b_JetMass3;   //!
   TBranch        *b_JetIsBtagged3;   //!
   TBranch        *b_JetBTagger3;   //!
   TBranch        *b_JetPt4;   //!
   TBranch        *b_JetEta4;   //!
   TBranch        *b_JetPhi4;   //!
   TBranch        *b_JetMass4;   //!
   TBranch        *b_JetIsBtagged4;   //!
   TBranch        *b_JetBTagger4;   //!
   TBranch        *b_JetPt5;   //!
   TBranch        *b_JetEta5;   //!
   TBranch        *b_JetPhi5;   //!
   TBranch        *b_JetMass5;   //!
   TBranch        *b_JetIsBtagged5;   //!
   TBranch        *b_JetBTagger5;   //!
   TBranch        *b_JetPt6;   //!
   TBranch        *b_JetEta6;   //!
   TBranch        *b_JetPhi6;   //!
   TBranch        *b_JetMass6;   //!
   TBranch        *b_JetIsBtagged6;   //!
   TBranch        *b_JetBTagger6;   //!
   TBranch        *b_ExtraLepPt1;   //!
   TBranch        *b_ExtraLepEta1;   //!
   TBranch        *b_ExtraLepPhi1;   //!
   TBranch        *b_ExtraLepPt2;   //!
   TBranch        *b_ExtraLepEta2;   //!
   TBranch        *b_ExtraLepPhi2;   //!
   TBranch        *b_PFMET;   //!
   TBranch        *b_gen_assoV_m;   //!
   TBranch        *b_gen_assoV_pt;   //!
   TBranch        *b_gen_assoV_eta;   //!
   TBranch        *b_gen_assoV_phi;   //!
   TBranch        *b_pt_hjj;   //!

   SelectedTree(TTree *tree=0);
   virtual ~SelectedTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SelectedTree_cxx
SelectedTree::SelectedTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("./ttH0P_M125_moriond_2018.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("./ttH0P_M125_moriond_2018.root");
      }
      f->GetObject("SelectedTree",tree);

   }
   Init(tree);
}

SelectedTree::~SelectedTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SelectedTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SelectedTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SelectedTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   weight_up = 0;
   weight_dn = 0;
   weight_name = 0;
   drj = 0;
   dptj = 0;
   dphij = 0;
   JetPt = 0;
   JetPhi = 0;
   JetEta = 0;
   JetMass = 0;
   LepPt = 0;
   LepPhi = 0;
   LepEta = 0;
   ExtraLepPt = 0;
   ExtraLepPhi = 0;
   ExtraLepEta = 0;
   genjpt = 0;
   reso = 0;
   reso_id = 0;
   opt = 0;
   LHEDaughterMass = 0;
   LHEAssociatedParticleEta = 0;
   LHEAssociatedParticlePhi = 0;
   LHEAssociatedParticlePt = 0;
   htxs_stage1_catName = 0;
   htxs_stage1_red_catName = 0;
   htxs_stage1_red_prod_catName = 0;
   htxs_stage1_reco_catName = 0;
   htxs_stage1_reco_catName_jec_up = 0;
   htxs_stage1_reco_catName_jec_dn = 0;
   htxs_stage1_reco_catName_jer_up = 0;
   htxs_stage1_reco_catName_jer_dn = 0;
   htxs_stage1_reco_catName_btag_dn = 0;
   htxs_stage1_reco_catName_btag_up = 0;
   categoryName_jec_up = 0;
   categoryName_jec_dn = 0;
   categoryName_btag_dn = 0;
   categoryName_btag_up = 0;
   htxs_prodModeName = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("dbkg_kin", &dbkg_kin, &b_dbkg_kin);
   fChain->SetBranchAddress("dbkg", &dbkg, &b_dbkg);
   fChain->SetBranchAddress("d_2j", &d_2j, &b_d_2j);
   fChain->SetBranchAddress("d_2j_up", &d_2j_up, &b_d_2j_up);
   fChain->SetBranchAddress("d_2j_dn", &d_2j_dn, &b_d_2j_dn);
   fChain->SetBranchAddress("d_2j_qq", &d_2j_qq, &b_d_2j_qq);
   fChain->SetBranchAddress("d_2j_other", &d_2j_other, &b_d_2j_other);
   fChain->SetBranchAddress("d_2j_qqgen", &d_2j_qqgen, &b_d_2j_qqgen);
   fChain->SetBranchAddress("d_2jgen", &d_2jgen, &b_d_2jgen);
   fChain->SetBranchAddress("dphi", &dphi, &b_dphi);
   fChain->SetBranchAddress("dphigen", &dphigen, &b_dphigen);
   fChain->SetBranchAddress("mjjgen", &mjjgen, &b_mjjgen);
   fChain->SetBranchAddress("mjj", &mjj, &b_mjj);
   fChain->SetBranchAddress("gene", &gene, &b_gene);
   fChain->SetBranchAddress("genpt", &genpt, &b_genpt);
   fChain->SetBranchAddress("ngenjet", &ngenjet, &b_ngenjet);
   fChain->SetBranchAddress("vbfMela", &vbfMela, &b_vbfMela);
   fChain->SetBranchAddress("vbfMela_gen", &vbfMela_gen, &b_vbfMela_gen);
   fChain->SetBranchAddress("vbfMela_qg", &vbfMela_qg, &b_vbfMela_qg);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("weight_up", &weight_up, &b_weight_up);
   fChain->SetBranchAddress("weight_dn", &weight_dn, &b_weight_dn);
   fChain->SetBranchAddress("weight_name", &weight_name, &b_weight_name);
   fChain->SetBranchAddress("nmatch", &nmatch, &b_nmatch);
   fChain->SetBranchAddress("drj", &drj, &b_drj);
   fChain->SetBranchAddress("dptj", &dptj, &b_dptj);
   fChain->SetBranchAddress("dphij", &dphij, &b_dphij);
   fChain->SetBranchAddress("GenHPt", &GenHPt, &b_GenHPt);
   fChain->SetBranchAddress("GenHEta", &GenHEta, &b_GenHEta);
   fChain->SetBranchAddress("GenHPhi", &GenHPhi, &b_GenHPhi);
   fChain->SetBranchAddress("GenHMass", &GenHMass, &b_GenHMass);
   fChain->SetBranchAddress("ZZPt", &ZZPt, &b_ZZPt);
   fChain->SetBranchAddress("nCleanedJetsPt30BTagged_bTagSF", &nCleanedJetsPt30BTagged_bTagSF, &b_nCleanedJetsPt30BTagged_bTagSF);
   fChain->SetBranchAddress("ZZPhi", &ZZPhi, &b_ZZPhi);
   fChain->SetBranchAddress("ZZEta", &ZZEta, &b_ZZEta);
   fChain->SetBranchAddress("ZZMass", &ZZMass, &b_ZZMass);
   fChain->SetBranchAddress("JetPt", &JetPt, &b_JetPt);
   fChain->SetBranchAddress("JetPhi", &JetPhi, &b_JetPhi);
   fChain->SetBranchAddress("JetEta", &JetEta, &b_JetEta);
   fChain->SetBranchAddress("JetMass", &JetMass, &b_JetMass);
   fChain->SetBranchAddress("LepPt", &LepPt, &b_LepPt);
   fChain->SetBranchAddress("LepPhi", &LepPhi, &b_LepPhi);
   fChain->SetBranchAddress("LepEta", &LepEta, &b_LepEta);
   fChain->SetBranchAddress("ExtraLepPt", &ExtraLepPt, &b_ExtraLepPt);
   fChain->SetBranchAddress("ExtraLepPhi", &ExtraLepPhi, &b_ExtraLepPhi);
   fChain->SetBranchAddress("ExtraLepEta", &ExtraLepEta, &b_ExtraLepEta);
   fChain->SetBranchAddress("genjpt", &genjpt, &b_genjpt);
   fChain->SetBranchAddress("reso", &reso, &b_reso);
   fChain->SetBranchAddress("reso_id", &reso_id, &b_reso_id);
   fChain->SetBranchAddress("opt", &opt, &b_opt);
   fChain->SetBranchAddress("LHEDaughterMass", &LHEDaughterMass, &b_LHEDaughterMass);
   fChain->SetBranchAddress("LHEAssociatedParticleEta", &LHEAssociatedParticleEta, &b_LHEAssociatedParticleEta);
   fChain->SetBranchAddress("LHEAssociatedParticlePhi", &LHEAssociatedParticlePhi, &b_LHEAssociatedParticlePhi);
   fChain->SetBranchAddress("LHEAssociatedParticlePt", &LHEAssociatedParticlePt, &b_LHEAssociatedParticlePt);
   fChain->SetBranchAddress("qgL", &qgL, &b_qgL);
   fChain->SetBranchAddress("chan", &chan, &b_chan);
   fChain->SetBranchAddress("vbfcate", &vbfcate, &b_vbfcate);
   fChain->SetBranchAddress("nCleanedJetsPt30", &nCleanedJetsPt30, &b_nCleanedJetsPt30);
   fChain->SetBranchAddress("nCleanedJetsPt30_jecUp", &nCleanedJetsPt30_jecUp, &b_nCleanedJetsPt30_jecUp);
   fChain->SetBranchAddress("nCleanedJetsPt30_jecDn", &nCleanedJetsPt30_jecDn, &b_nCleanedJetsPt30_jecDn);
   fChain->SetBranchAddress("nExtraLep", &nExtraLep, &b_nExtraLep);
   fChain->SetBranchAddress("qg", &qg, &b_qg);
   fChain->SetBranchAddress("qqfrac", &qqfrac, &b_qqfrac);
   fChain->SetBranchAddress("category", &category, &b_category);
   fChain->SetBranchAddress("categoryName", categoryName, &b_categoryName);
   fChain->SetBranchAddress("category_baysien7Name", category_baysien7Name, &b_category_baysien7Name);
   fChain->SetBranchAddress("category_baysien7", &category_baysien7, &b_category_baysien7);
   fChain->SetBranchAddress("mcweight", &mcweight, &b_mcweight);
   fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("D2jet", &D2jet, &b_D2jet);
   fChain->SetBranchAddress("D2jet_dn", &D2jet_dn, &b_D2jet_dn);
   fChain->SetBranchAddress("D2jet_up", &D2jet_up, &b_D2jet_up);
   fChain->SetBranchAddress("D1jet", &D1jet, &b_D1jet);
   fChain->SetBranchAddress("DWH", &DWH, &b_DWH);
   fChain->SetBranchAddress("DZH", &DZH, &b_DZH);
   fChain->SetBranchAddress("DVH", &DVH, &b_DVH);
   fChain->SetBranchAddress("DVBFDEC", &DVBFDEC, &b_DVBFDEC);
   fChain->SetBranchAddress("DVHDEC", &DVHDEC, &b_DVHDEC);
   fChain->SetBranchAddress("htxs_stage1_cat", &htxs_stage1_cat, &b_htxs_stage1_cat);
   fChain->SetBranchAddress("htxs_stage1_red_cat", &htxs_stage1_red_cat, &b_htxs_stage1_red_cat);
   fChain->SetBranchAddress("htxs_stage1_red_prod_cat", &htxs_stage1_red_prod_cat, &b_htxs_stage1_red_prod_cat);
   fChain->SetBranchAddress("htxs_stage1_reco_cat", &htxs_stage1_reco_cat, &b_htxs_stage1_reco_cat);
   fChain->SetBranchAddress("htxs_stage1_reco_cat_jec_up", &htxs_stage1_reco_cat_jec_up, &b_htxs_stage1_reco_cat_jec_up);
   fChain->SetBranchAddress("htxs_stage1_reco_cat_jec_dn", &htxs_stage1_reco_cat_jec_dn, &b_htxs_stage1_reco_cat_jec_dn);
   fChain->SetBranchAddress("htxs_stage1_reco_cat_jer_up", &htxs_stage1_reco_cat_jer_up, &b_htxs_stage1_reco_cat_jer_up);
   fChain->SetBranchAddress("htxs_stage1_reco_cat_jer_dn", &htxs_stage1_reco_cat_jer_dn, &b_htxs_stage1_reco_cat_jer_dn);
   fChain->SetBranchAddress("htxs_stage1_reco_cat_btag_dn", &htxs_stage1_reco_cat_btag_dn, &b_htxs_stage1_reco_cat_btag_dn);
   fChain->SetBranchAddress("htxs_stage1_reco_cat_btag_up", &htxs_stage1_reco_cat_btag_up, &b_htxs_stage1_reco_cat_btag_up);
   fChain->SetBranchAddress("category_jec_up", &category_jec_up, &b_category_jec_up);
   fChain->SetBranchAddress("category_jec_dn", &category_jec_dn, &b_category_jec_dn);
   fChain->SetBranchAddress("category_jer_up", &category_jer_up, &b_category_jer_up);
   fChain->SetBranchAddress("category_jer_dn", &category_jer_dn, &b_category_jer_dn);
   fChain->SetBranchAddress("category_btag_dn", &category_btag_dn, &b_category_btag_dn);
   fChain->SetBranchAddress("category_btag_up", &category_btag_up, &b_category_btag_up);
   fChain->SetBranchAddress("htxs_stage1_catName", &htxs_stage1_catName, &b_htxs_stage1_catName);
   fChain->SetBranchAddress("htxs_stage1_red_catName", &htxs_stage1_red_catName, &b_htxs_stage1_red_catName);
   fChain->SetBranchAddress("htxs_stage1_red_prod_catName", &htxs_stage1_red_prod_catName, &b_htxs_stage1_red_prod_catName);
   fChain->SetBranchAddress("htxs_stage1_reco_catName", &htxs_stage1_reco_catName, &b_htxs_stage1_reco_catName);
   fChain->SetBranchAddress("htxs_stage1_reco_catName_jec_up", &htxs_stage1_reco_catName_jec_up, &b_htxs_stage1_reco_catName_jec_up);
   fChain->SetBranchAddress("htxs_stage1_reco_catName_jec_dn", &htxs_stage1_reco_catName_jec_dn, &b_htxs_stage1_reco_catName_jec_dn);
   fChain->SetBranchAddress("htxs_stage1_reco_catName_jer_up", &htxs_stage1_reco_catName_jer_up, &b_htxs_stage1_reco_catName_jer_up);
   fChain->SetBranchAddress("htxs_stage1_reco_catName_jer_dn", &htxs_stage1_reco_catName_jer_dn, &b_htxs_stage1_reco_catName_jer_dn);
   fChain->SetBranchAddress("htxs_stage1_reco_catName_btag_dn", &htxs_stage1_reco_catName_btag_dn, &b_htxs_stage1_reco_catName_btag_dn);
   fChain->SetBranchAddress("htxs_stage1_reco_catName_btag_up", &htxs_stage1_reco_catName_btag_up, &b_htxs_stage1_reco_catName_btag_up);
   fChain->SetBranchAddress("htxs_prodMode", &htxs_prodMode, &b_htxs_prodMode);
   fChain->SetBranchAddress("categoryName_jec_up", &categoryName_jec_up, &b_categoryName_jec_up);
   fChain->SetBranchAddress("categoryName_jec_dn", &categoryName_jec_dn, &b_categoryName_jec_dn);
   fChain->SetBranchAddress("categoryName_btag_dn", &categoryName_btag_dn, &b_categoryName_btag_dn);
   fChain->SetBranchAddress("categoryName_btag_up", &categoryName_btag_up, &b_categoryName_btag_up);
   fChain->SetBranchAddress("htxs_prodModeName", &htxs_prodModeName, &b_htxs_prodModeName);
   fChain->SetBranchAddress("JetPt1", &JetPt1, &b_JetPt1);
   fChain->SetBranchAddress("JetEta1", &JetEta1, &b_JetEta1);
   fChain->SetBranchAddress("JetPhi1", &JetPhi1, &b_JetPhi1);
   fChain->SetBranchAddress("JetMass1", &JetMass1, &b_JetMass1);
   fChain->SetBranchAddress("JetIsBtagged1", &JetIsBtagged1, &b_JetIsBtagged1);
   fChain->SetBranchAddress("JetBTagger1", &JetBTagger1, &b_JetBTagger1);
   fChain->SetBranchAddress("JetPt2", &JetPt2, &b_JetPt2);
   fChain->SetBranchAddress("JetEta2", &JetEta2, &b_JetEta2);
   fChain->SetBranchAddress("JetPhi2", &JetPhi2, &b_JetPhi2);
   fChain->SetBranchAddress("JetMass2", &JetMass2, &b_JetMass2);
   fChain->SetBranchAddress("JetIsBtagged2", &JetIsBtagged2, &b_JetIsBtagged2);
   fChain->SetBranchAddress("JetBTagger2", &JetBTagger2, &b_JetBTagger2);
   fChain->SetBranchAddress("JetPt3", &JetPt3, &b_JetPt3);
   fChain->SetBranchAddress("JetEta3", &JetEta3, &b_JetEta3);
   fChain->SetBranchAddress("JetPhi3", &JetPhi3, &b_JetPhi3);
   fChain->SetBranchAddress("JetMass3", &JetMass3, &b_JetMass3);
   fChain->SetBranchAddress("JetIsBtagged3", &JetIsBtagged3, &b_JetIsBtagged3);
   fChain->SetBranchAddress("JetBTagger3", &JetBTagger3, &b_JetBTagger3);
   fChain->SetBranchAddress("JetPt4", &JetPt4, &b_JetPt4);
   fChain->SetBranchAddress("JetEta4", &JetEta4, &b_JetEta4);
   fChain->SetBranchAddress("JetPhi4", &JetPhi4, &b_JetPhi4);
   fChain->SetBranchAddress("JetMass4", &JetMass4, &b_JetMass4);
   fChain->SetBranchAddress("JetIsBtagged4", &JetIsBtagged4, &b_JetIsBtagged4);
   fChain->SetBranchAddress("JetBTagger4", &JetBTagger4, &b_JetBTagger4);
   fChain->SetBranchAddress("JetPt5", &JetPt5, &b_JetPt5);
   fChain->SetBranchAddress("JetEta5", &JetEta5, &b_JetEta5);
   fChain->SetBranchAddress("JetPhi5", &JetPhi5, &b_JetPhi5);
   fChain->SetBranchAddress("JetMass5", &JetMass5, &b_JetMass5);
   fChain->SetBranchAddress("JetIsBtagged5", &JetIsBtagged5, &b_JetIsBtagged5);
   fChain->SetBranchAddress("JetBTagger5", &JetBTagger5, &b_JetBTagger5);
   fChain->SetBranchAddress("JetPt6", &JetPt6, &b_JetPt6);
   fChain->SetBranchAddress("JetEta6", &JetEta6, &b_JetEta6);
   fChain->SetBranchAddress("JetPhi6", &JetPhi6, &b_JetPhi6);
   fChain->SetBranchAddress("JetMass6", &JetMass6, &b_JetMass6);
   fChain->SetBranchAddress("JetIsBtagged6", &JetIsBtagged6, &b_JetIsBtagged6);
   fChain->SetBranchAddress("JetBTagger6", &JetBTagger6, &b_JetBTagger6);
   fChain->SetBranchAddress("ExtraLepPt1", &ExtraLepPt1, &b_ExtraLepPt1);
   fChain->SetBranchAddress("ExtraLepEta1", &ExtraLepEta1, &b_ExtraLepEta1);
   fChain->SetBranchAddress("ExtraLepPhi1", &ExtraLepPhi1, &b_ExtraLepPhi1);
   fChain->SetBranchAddress("ExtraLepPt2", &ExtraLepPt2, &b_ExtraLepPt2);
   fChain->SetBranchAddress("ExtraLepEta2", &ExtraLepEta2, &b_ExtraLepEta2);
   fChain->SetBranchAddress("ExtraLepPhi2", &ExtraLepPhi2, &b_ExtraLepPhi2);
   fChain->SetBranchAddress("PFMET", &PFMET, &b_PFMET);
   fChain->SetBranchAddress("gen_assoV_m", &gen_assoV_m, &b_gen_assoV_m);
   fChain->SetBranchAddress("gen_assoV_pt", &gen_assoV_pt, &b_gen_assoV_pt);
   fChain->SetBranchAddress("gen_assoV_eta", &gen_assoV_eta, &b_gen_assoV_eta);
   fChain->SetBranchAddress("gen_assoV_phi", &gen_assoV_phi, &b_gen_assoV_phi);
   fChain->SetBranchAddress("pt_hjj", &pt_hjj, &b_pt_hjj);
   Notify();
}

Bool_t SelectedTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SelectedTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SelectedTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SelectedTree_cxx
