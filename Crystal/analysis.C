{
	TTree *test = new TTree("","");
	test->ReadFile("edep.out","edep");
	test->Draw("edep","edep>0");
}
