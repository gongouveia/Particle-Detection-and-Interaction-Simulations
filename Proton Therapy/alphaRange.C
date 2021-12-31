#include "TROOT.h"
#include "TTree.h"
#include "TH2F.h"

void bragg_peaka(){
		TCanvas *c1 = new TCanvas();
		
    TTree *bragg = new TTree("Bragg Peak","Bragg Peak");
    bragg->ReadFile("BraggPeak.out","length:edep:step");
    
    bragg->Draw("edep/step:length");
    c1->SetLogz();
    c1->SaveAs("BraggPeak.pdf");
    
}
