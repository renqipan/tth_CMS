//this is a c++ program for tth analysis
//the input variables are the kinematics of all jets and the double photons
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"

#include "TMVA/Factory.h"
#include "TMVA/DataLoader.h"
#include "TMVA/Tools.h"
#include "TMVA/TMVAGui.h"

void silly_BDT_tth(){

//Declare Factory
TMVA::Tools::Instance();
auto sigFile = TFile::Open("./ttHiggs0PToGG.root");
auto bkgFile=TFile::Open("./ttHiggs0MToGG.root");
TString outfileName( "btag6jets_silly_output.root");
auto outputFile = TFile::Open(outfileName, "RECREATE");
TMVA::Factory factory("TMVAClassification", outputFile,
                      "!V:ROC:!Correlations:!Silent:Color:!DrawProgressBar:AnalysisType=Classification" );
/*
TString delta_phi_pho,delta_phi_jet;
delta_phi_pho="delta_phi_pho:=(abs(pho1_phi-pho2_phi))*(abs(pho1_phi-pho2_phi)<3.14)+\
(2*3.14-abs(pho1_phi-pho2_phi))*(abs(pho1_phi-pho2_phi)>3.14)";
delta_phi_jet="delta_phi_jet:=(abs(jetPhi_1-jetPhi_2))*(abs(jetPhi_1-jetPhi_2)<3.14)+\
(2*3.14-abs(jetPhi_1-jetPhi_2))*(abs(jetPhi_1-jetPhi_2)>3.14)";

//Declare DataLoader(s)
TMVA::DataLoader loader("dataset");
loader.AddVariable("delta_phoj_eta:=pho1_eta-jetEta_1",'F');
loader.AddVariable("delta_phoj_phi:=pho1_phi-jetPhi_1",'F');
loader.AddVariable("delata_jj_eta:=jetEta_1-jetEta_2",'F');
loader.AddVariable("delta_pho_eta:=pho1_eta-pho2_eta",'F');
loader.AddVariable(delta_phi_pho,"delta_phi_pho","",'F');
loader.AddVariable(delta_phi_jet,"delta_phi_jet","",'F');
*/
//load input variables
TMVA::DataLoader loader("dataset_silly");
/*
TString  var,pho_vars[3]={"pt","eta","phi"};
//loop to load the variables of photons 
for(int ipho=1;ipho<3;ipho++){
	for(int ivar=0;ivar<3;ivar++){
		var="pho"+to_string(ipho)+"_"+pho_vars[ivar];
		loader.AddVariable(var,'F');	}
}
//loop to load all the variables of jets 
TString jetvar,jet_vars[4]={"Pt","Eta","Phi","E"};
for(int ijet=1;ijet<11;ijet++){
	for(int ivar=0;ivar<4;ivar++){
		jetvar="jet"+jet_vars[ivar]+"_"+to_string(ijet);
		loader.AddVariable(jetvar,'F');
	}
}
	loader.AddVariable("top1_phi",'F');
	loader.AddVariable("top1_eta",'F');
	loader.AddVariable("top1_pt",'F');
	loader.AddVariable("top1_m",'F' );
	loader.AddVariable("top2_phi",'F');
	loader.AddVariable("top2_eta",'F');
	loader.AddVariable("top2_pt",'F');
	loader.AddVariable("top2_m",'F' );
	loader.AddVariable("top1_tt_costheta",'F');
*/
	loader.AddVariable("diPhoPhi");
	loader.AddVariable("diPhoPtoM",'F');
	loader.AddVariable("diPhoEta",'F');
/*	loader.AddVariable("bjetE_1",'F');
	loader.AddVariable("bjetPhi_1",'F');
	loader.AddVariable("bjetEta_1",'F');
	loader.AddVariable("bjetPt_1",'F');

	loader.AddVariable("bjetPt_2",'F');
	loader.AddVariable("bjetE_2",'F');
	loader.AddVariable("bjetPhi_2",'F');
	loader.AddVariable("bjetEta_2",'F');  */

//loop to load all the variables of jets 
TString jetvar,btag,jet_vars[4]={"Pt","Eta","Phi","E"};
for(int ijet=1;ijet<7;ijet++){
	btag="btag_"+to_string(ijet);
	loader.AddVariable(btag);
	for(int ivar=0;ivar<4;ivar++){
		jetvar="jet"+jet_vars[ivar]+"_"+to_string(ijet);
		loader.AddVariable(jetvar,'F');
	}
}


//Setup Dataset(s)
TTree *tsignal, *tbackground;
sigFile->GetObject("ttH_0P_125_13TeV_TTHHadronicTag", tsignal);
bkgFile->GetObject("ttH_0M_125_13TeV_TTHHadronicTag", tbackground);

TCut mycuts, mycutb;
mycuts="tthMvaRes>0.38 && pho1_idmva>-0.2 && pho2_idmva >-0.2";
mycutb="tthMvaRes>0.38 && pho1_idmva>-0.2 && pho2_idmva >-0.2";

Double_t signalWeight     =1;
Double_t backgroundWeight = 1.0;
loader.AddSignalTree    (tsignal,     signalWeight);   //signal weight  = 1
loader.AddBackgroundTree(tbackground, backgroundWeight);   //background weight = 1 

loader.SetBackgroundWeightExpression( "weight" ); //Set individual event weights 
loader.SetSignalWeightExpression("weight");
loader.PrepareTrainingAndTestTree(mycuts, mycutb,
                                   "nTrain_Signal=47084:nTrain_Background=59149:SplitMode=Random:NormMode=NumEvents:!V" );
//Booking Methods
//Boosted Decision Trees
factory.BookMethod(&loader,TMVA::Types::kBDT, "BDT",
                   "!V:NTrees=200:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );

//Multi-Layer Perceptron (Neural Network)
factory.BookMethod(&loader, TMVA::Types::kMLP, "MLP",
                   "!H:!V:NeuronType=tanh:VarTransform=N:NCycles=100:HiddenLayers=N+5:TestRate=5:!UseRegulator" );
//factory.BookMethod(&loader, TMVA::Types::kLikelihood, "Likelihood",
 //                         "H:!V:TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmoothBkg[1]=10:NSmooth=1:NAvEvtPerBin=50" );
//factory.BookMethod(&loader, TMVA::Types::kLD, "LD", "H:!V:VarTransform=None:CreateMVAPdfs:PDFInterpolMVAPdf=Spline2:NbinsMVAPdf=50:NsmoothMVAPdf=10" );
//Train Methods
factory.TrainAllMethods();
//Test and Evaluate Methods
factory.TestAllMethods();
factory.EvaluateAllMethods();
outputFile->Close(); // Save the output

//Plot ROC Curve
auto c1 = factory.GetROCCurve(&loader);
c1->Draw();
gPad->Print("silly_Significance.png");

  // Launch the GUI for the root macros
if (!gROOT->IsBatch()) TMVA::TMVAGui(outfileName);


}
