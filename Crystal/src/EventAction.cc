#include "EventAction.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4ios.hh"
#include "Randomize.hh"

#include <math.h>

using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
EventAction::EventAction()
{
    bout.open("edep.out");
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
EventAction::~EventAction()
{
    bout.close();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void EventAction::BeginOfEventAction(const G4Event*)
{
    edep = 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
 
void EventAction::EndOfEventAction(const G4Event* evt)
{
    //G4cout << edep / keV << G4endl;
    bout << edep /keV << G4endl;
    
    
    // This is how you get a random from a uniform distribution in GEANT4
    // You'll need this for the project... ;)
    //double rand1 = G4UniformRand();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
