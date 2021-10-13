
#include "SteppingAction.hh"
#include "G4SteppingManager.hh"

using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction()
{
    bout.open("Shielding_Pb.out");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{
    bout.close();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* thisStep)
{ 
	G4Track* thisTrack = thisStep->GetTrack();
	G4VPhysicalVolume* theVolume = thisTrack->GetVolume();
    const G4ParticleDefinition* thisParticle = thisTrack->GetParticleDefinition();
    double kinEner = thisTrack->GetKineticEnergy();
    G4ThreeVector position = thisTrack->GetPosition();
    
    // You will need this, eventually
    //thisTrack->SetTrackStatus(fStopAndKill);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

