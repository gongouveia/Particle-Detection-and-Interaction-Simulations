#include "TROOT.h"
#include "TTree.h"
#include "TH2F.h"

void bragg_peak1(){
		TCanvas *c1 = new TCanvas();
		
    TTree *bragg = new TTree("Bragg Peak","Bragg Peak");
    bragg->ReadFile("BraggPeak(130).out","length:edep:step");
    
    //bragg->Draw("edep/step:length");
    bragg->Draw("edep/step:length", "edep/step>80");
    //c1->SetLogy();
    //1->SaveAs("BraggPeak.png");
    
}
