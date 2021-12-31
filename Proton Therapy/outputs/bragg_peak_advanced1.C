#include "TROOT.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TH2F.h"
#include "TH1F.h"


void bragg_peak_advanced1(){
    
    TCanvas *c1 = new TCanvas();
    
    TTree *bragg = new TTree("Bragg Peak","Bragg Peak");
    bragg->ReadFile("BraggPeak(150).out","length:edep:step");
    
    TH2F *h200 = new TH2F("h200","Bragg Peak for alpha particles",1000,0.,5.,1000,0.,3.5);
    bragg->Draw("edep/step:length");
    h200->GetXaxis()->SetTitle("Range (cm)");
    h200->GetYaxis()->SetTitle("dE/dx (MeV/cm)");
    //c1->SetLogz();
    //c1->SaveAs("BraggPeak.pdf");
    
    TH1F *h100 = new TH1F("h100","Bragg Peak for alpha particles",1000,0.,5.);
    bragg->Draw("length","edep/step>80");
    h100->GetXaxis()->SetTitle("Range (cm)");
    //h100->GetXaxis()->SetTitle("dE/dx (MeV/cm)");
    //c1->SetLogz();
    //c1->SaveAs("BraggPeak.pdf");
/*
    TH2F *h201 = new TH2F("h201","Energy loss for alpha particles",100,0.,6.,100,0.,3.5);
    bragg->Draw("edep/step:e>>h201","","col");
    h201->GetXaxis()->SetTitle("Energy (MeV)");
    h201->GetYaxis()->SetTitle("dE/dx (MeV/cm)");
    c1->SaveAs("EnergyLoss.pdf");
*/
    
}
