#include "SteppingAction.hh"
#include "EventAction.hh"
#include "G4SteppingManager.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(EventAction* myEA) : theEventAction(myEA)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* thisStep)
{ 
    G4Track* thisTrack = thisStep->GetTrack();
    G4VPhysicalVolume* theVolume = thisTrack->GetVolume();
    G4String thisVolumeName = theVolume->GetName();
    G4double edep_inStep = thisStep->GetTotalEnergyDeposit();
    
    if(thisVolumeName =="Crystal")
	theEventAction->edep += edep_inStep;
    // This is how you can access a variable from the EventAction class
    // theEventAction->edep
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

