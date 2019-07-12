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

void BDT_tthzz_had(){

//Declare Factory
TMVA::Tools::Instance();
auto sigFile = TFile::Open("./ttH0P_M125_moriond_2018.root");
auto bkgFile=TFile::Open("./ttH0M_M125_moriond_2018.root");
TString outfileName( "hzzhad_output.root");
auto outputFile = TFile::Open(outfileName, "RECREATE");
TMVA::Factory factory("TMVAClassification", outputFile,
                      "!V:ROC:!Correlations:!Silent:Color:!DrawProgressBar:AnalysisType=Classification" );

//load input variables
TMVA::DataLoader loader("dataset_hzz_had");

	loader.AddVariable("ZZPt",'F');
	loader.AddVariable("ZZPhi",'F');
	loader.AddVariable("ZZEta",'F');
	loader.AddVariable("ZZMass",'F');

/*	loader.AddVariable("JetPt[0]",'F');
	loader.AddVariable("JetPhi[0]",'F');
	loader.AddVariable("JetMass[0]",'F');
	loader.AddVariable("JetEta[0]",'F');
	loader.AddVariable("JetPt[1]",'F');
	loader.AddVariable("JetPhi[1]",'F');
	loader.AddVariable("JetMass[1]",'F');
	loader.AddVariable("JetEta[1]",'F');
	loader.AddVariable("JetPt[2]",'F');
	loader.AddVariable("JetPhi[2]",'F');
	loader.AddVariable("JetMass[2]",'F');
	loader.AddVariable("JetEta[2]",'F');
	loader.AddVariable("JetPt[3]",'F');
	loader.AddVariable("JetPhi[3]",'F');
	loader.AddVariable("JetMass[3]",'F');
	loader.AddVariable("JetEta[3]",'F'); 
	loader.AddVariable("PFMET",'F');
	loader.AddVariable("pt_hjj",'F');
	loader.AddVariable("mjj",'F');  */




//loop to load all the variables of jets 
TString jetvar,btag,jet_vars[5]={"Pt","Eta","Phi","Mass","BTagger"};
for(int ijet=1;ijet<5;ijet++){
	for(int ivar=0;ivar<5;ivar++){
		jetvar="Jet"+jet_vars[ivar]+to_string(ijet);
		loader.AddVariable(jetvar,'F');
	}
}


//Setup Dataset(s)
TTree *tsignal, *tbackground;
sigFile->GetObject("SelectedTree", tsignal);
bkgFile->GetObject("SelectedTree", tbackground);

TCut mycuts, mycutb;
//mycuts="tthMvaRes>0.38 && pho1_idmva>-0.2 && pho2_idmva >-0.2";
//mycutb="tthMvaRes>0.38 && pho1_idmva>-0.2 && pho2_idmva >-0.2";
mycuts="category==6";
mycutb="category==6";

Double_t signalWeight     =1.0;
Double_t backgroundWeight = 1.0;
loader.AddSignalTree    (tsignal,     signalWeight);   //signal weight  = 1
loader.AddBackgroundTree(tbackground, backgroundWeight);   //background weight = 1 

loader.SetBackgroundWeightExpression( "weight" ); //Set individual event weights 
loader.SetSignalWeightExpression("weight");
loader.PrepareTrainingAndTestTree(mycuts, mycutb,
                                   "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );
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
gPad->Print("roc_had.png");

  // Launch the GUI for the root macros
if (!gROOT->IsBatch()) TMVA::TMVAGui(outfileName);


}
