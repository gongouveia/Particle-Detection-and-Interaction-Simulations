
#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "globals.hh"

#include <iostream>
#include <cmath>
#include <random>
#include <stdlib.h>
#include <math.h>

#include "BoxMullerGenerator.hh"
using namespace CLHEP;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::PrimaryGeneratorAction(
                                               DetectorConstruction* myDC)
:myDetector(myDC)
{
  G4int n_particle = 1;
  particleGun = new G4ParticleGun(n_particle);

// default particle

  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4ParticleDefinition* particle = particleTable->FindParticle("proton");
  
  particleGun->SetParticleDefinition(particle);
  particleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));
  Muller number;
  particleGun->SetParticleEnergy(number.box_muller(150.0,0.02*150.0)*MeV);// ALTERAR AQUI energia 100mev * valor do muller box 
  //G4double z1 = G4UniformRand();
  //G4double z2 = G4UniformRand();
  //G4double energy = 150.0 + sqrt(-2*log(z1))*cos(2*pi*z2)*0.02*150.0;
  //particleGun->SetParticleEnergy(energy *MeV);
  particleGun->SetParticlePosition(G4ThreeVector(-25.0*cm,0.*cm,0.*cm));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete particleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{ 

  particleGun->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......




