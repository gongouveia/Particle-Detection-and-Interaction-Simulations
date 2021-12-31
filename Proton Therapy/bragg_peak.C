#include "TROOT.h"
#include "TTree.h"
#include "TH2F.h"

void bragg_peak(){
		TCanvas *c1 = new TCanvas();
		
    TTree *bragg = new TTree("Bragg Peak","Bragg Peak");
    bragg->ReadFile("BraggPeak(50).out","length:edep:step");
    
    bragg->Draw("edep/step:length");
    //bragg->Draw("edep/step:length", "edep/step>100");
    //c1->SetLogy();
    //1->SaveAs("BraggPeak.png");
    
}
