//this is a c++ program for tth analysis
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

void var_BDT_tth(){

//Declare Factory
TMVA::Tools::Instance();
auto sigFile = TFile::Open("./ttHiggs0PToGG.root");
auto bkgFile=TFile::Open("./ttHiggs0MToGG.root");
TString outfileName( "tth_var_output.root");
auto outputFile = TFile::Open(outfileName, "RECREATE");
TMVA::Factory factory("TMVAClassification", outputFile,
                      "!V:ROC:!Correlations:!Silent:Color:!DrawProgressBar:AnalysisType=Classification" );

TString delta_phi_pho,delta_phi_jet,delta_phi_bjet;
delta_phi_pho="delta_phi_pho:=(abs(pho1_phi-pho2_phi))*(abs(pho1_phi-pho2_phi)<3.14)+\
(2*3.14-abs(pho1_phi-pho2_phi))*(abs(pho1_phi-pho2_phi)>3.14)";
delta_phi_jet="delta_phi_jet:=(abs(jetPhi_1-jetPhi_2))*(abs(jetPhi_1-jetPhi_2)<3.14)+\
(2*3.14-abs(jetPhi_1-jetPhi_2))*(abs(jetPhi_1-jetPhi_2)>3.14)";
delta_phi_bjet="delta_phi_jet:=(abs(bjetPhi_1-bjetPhi_2))*(abs(bjetPhi_1-bjetPhi_2)<3.14)+\
(2*3.14-abs(bjetPhi_1-bjetPhi_2))*(abs(bjetPhi_1-bjetPhi_2)>3.14)";

//Declare DataLoader(s)
TMVA::DataLoader loader("dataset");
loader.AddVariable("delta_phoj_eta:=pho1_eta-jetEta_1",'F');
loader.AddVariable("delta_phoj_phi:=pho1_phi-jetPhi_1",'F');
loader.AddVariable("delata_jj_eta:=jetEta_1-jetEta_2",'F');
loader.AddVariable("delta_pho_eta:=pho1_eta-pho2_eta",'F');
loader.AddVariable(delta_phi_pho,"delta_phi_pho","",'F');
loader.AddVariable(delta_phi_jet,"delta_phi_jet","",'F');
loader.AddVariable("diPhoPt",'F');
loader.AddVariable("diPhoEta",'F');
loader.AddVariable(delta_phi_bjet,'F');
loader.AddVariable("top1_tt_costheta",'F');  


//Setup Dataset(s)
TTree *tsignal, *tbackground;
sigFile->GetObject("ttH_0P_125_13TeV_TTHHadronicTag", tsignal);
bkgFile->GetObject("ttH_0M_125_13TeV_TTHHadronicTag", tbackground);

TCut mycuts, mycutb;
mycuts="tthMvaRes>0.38 && pho1_idmva>-0.2 && pho2_idmva >-0.2";
mycutb="tthMvaRes>0.38 && pho1_idmva>-0.2 && pho2_idmva >-0.2";

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

bool useDNN = false; 
if (useDNN) { 
    
     TString layoutString ("Layout=TANH|128,TANH|128,TANH|128,LINEAR");

      // Training strategies.
      TString training0("LearningRate=1e-1,Momentum=0.9,Repetitions=1,"
                        "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
                        "WeightDecay=1e-4,Regularization=L2,"
                        "DropConfig=0.0+0.5+0.5+0.5, Multithreading=True");
      TString training1("LearningRate=1e-2,Momentum=0.9,Repetitions=1,"
                        "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
                        "WeightDecay=1e-4,Regularization=L2,"
                        "DropConfig=0.0+0.0+0.0+0.0, Multithreading=True");
      TString training2("LearningRate=1e-3,Momentum=0.0,Repetitions=1,"
                        "ConvergenceSteps=20,BatchSize=256,TestRepetitions=10,"
                        "WeightDecay=1e-4,Regularization=L2,"
                        "DropConfig=0.0+0.0+0.0+0.0, Multithreading=True");
      TString trainingStrategyString ("TrainingStrategy=");
      trainingStrategyString += training0 + "|" + training1 + "|" + training2;

      // General Options.                                                                                                                                                                
      TString dnnOptions ("!H:V:ErrorStrategy=CROSSENTROPY:VarTransform=None:"
                          "WeightInitialization=XAVIERUNIFORM");
      dnnOptions.Append (":"); dnnOptions.Append (layoutString);
      dnnOptions.Append (":"); dnnOptions.Append (trainingStrategyString);

      dnnOptions += ":Architecture=CPU";
      factory.BookMethod(&loader, TMVA::Types::kDNN, "DNN_CPU", dnnOptions);

}


//Train Methods
factory.TrainAllMethods();
//Test and Evaluate Methods
factory.TestAllMethods();
factory.EvaluateAllMethods();
outputFile->Close(); // Save the output

//Plot ROC Curve
auto c1 = factory.GetROCCurve(&loader);
c1->Draw();
gPad->Print("var_Significance.png");

  // Launch the GUI for the root macros
if (!gROOT->IsBatch()) TMVA::TMVAGui(outfileName);

}


