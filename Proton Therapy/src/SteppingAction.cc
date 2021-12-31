
#include "SteppingAction.hh"
#include "G4SteppingManager.hh"

using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction()
{
    bout.open("BraggPeak.out");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{
    bout.close();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
/*
// USE THIS METHOD FOR STEP #1 -- GETTING THE RANGE OF ALPHA PARTICLES

void SteppingAction::UserSteppingAction(const G4Step* thisStep)
{ 
	G4Track* thisTrack = thisStep->GetTrack();
	G4VPhysicalVolume* theVolume = thisTrack->GetVolume();
    
	if(theVolume->GetName() == "Target"){
		const G4ParticleDefinition* thisParticle = thisTrack->GetParticleDefinition();
		if(thisParticle->GetParticleName() == "proton"){
			double kinEner = thisTrack->GetKineticEnergy();
            		if (kinEner == 0) {
                		G4double trackLength = thisTrack->GetTrackLength();
                		G4ThreeVector finalPosition = thisTrack->GetPosition();
                		bout << trackLength /mm << "\t" << finalPosition.r() /mm << G4endl;
            		}
		}
	}
	
}
*/

// USE THIS METHOD FOR STEP #2 -- PRODUCING THE BRAGG PEAK 
void SteppingAction::UserSteppingAction(const G4Step* thisStep)
{ 
	G4Track* thisTrack = thisStep->GetTrack();
	G4VPhysicalVolume* theVolume = thisTrack->GetVolume();
    
	if(theVolume->GetName() == "Target"){
		const G4ParticleDefinition* thisParticle = thisTrack->GetParticleDefinition();
		if(thisParticle->GetParticleName() == "proton"){
			bout << thisTrack->GetTrackLength() / cm << "\t"
				<< thisStep->GetTotalEnergyDeposit() /MeV << "\t"
                << thisStep->GetStepLength() / cm << G4endl;
		}
	}
	
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

