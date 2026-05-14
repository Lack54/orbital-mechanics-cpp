
#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include "bodies.h"
#include <numbers>


double semiMajorAxis_calc(double r1, double r2, [[maybe_unused]] const CelestialBody& body){
  // set the apoapsis and periapsis relative to 
  // the center of Kerbin

  // calculate semi major axis average distance between r1, r2
  return (r1+r2) / 2.0;
}

double semiMinorAxis_calc(double a, double e){
  double b { a*std::sqrt(1-std::pow(e,2)) };
  return b;
}
double eccentricity_calc(double r1, double r2){
  double e { (r1 - r2) / (r1+r2) };
  return e;  
}

double orbitalPeriod_calc(double a,const CelestialBody & body){
  double pi { std::numbers::pi };
  double t { 2*pi * (std::sqrt(std::pow(a,3) * body.mu)) };
    
  return t;

}
double findOrbitalVelocityAtAltitude(double a, double altitude, const CelestialBody& body, bool isCircular){
  
  //calculate velocity at a given altitude
  //double velocity { std::sqrt( body.mu * ( 2.0 / altitude - 1.0 / a ) )};
  double velocity {0};
  if (isCircular == true) {
    velocity = std::sqrt( body.mu / altitude);
    
  } else {
    velocity = std::sqrt( body.mu * ( 2.0 / altitude - 1.0 / a ) );
    
  }

  return velocity;

}

double circularizeOrbit_Calc(double a, double r_ap, double r_pe, const CelestialBody& body){

  double desiredOrbitAltitude {};

  std::string input;

  std::cout << "Enter your desired circularized orbit altitude, or press enter to use current apoapsis" << '\n';
  std::cout << "> ";

  std::getline(std::cin, input);
// get the desired orbit altitude apoapsis and periapsis
  if (input.empty()) {
    desiredOrbitAltitude = r_ap;
  } else {
    desiredOrbitAltitude = std::stod(input) + body.radius;
  }
  
  // transfer a after first burn
  double a_transfer { semiMajorAxis_calc(desiredOrbitAltitude, r_pe, body) };


  // calculate the burn from periapsis to increase apoapsis altitude to target
  double initial_peVelocity { findOrbitalVelocityAtAltitude(a, r_pe, body, false) };
  double transfer_peVelocity { findOrbitalVelocityAtAltitude(a_transfer, r_pe, body, false) };
  double burn1_dV { std::abs(transfer_peVelocity - initial_peVelocity) };


  // calculate brun from apoapsis to change periapsisto desired orbit
  // since in a circular orbit both r1, r2 r1 = r2 = a
  double final_cirularOrbitA { semiMajorAxis_calc(desiredOrbitAltitude, desiredOrbitAltitude, body) }; 

  double transfer_apVelocity { findOrbitalVelocityAtAltitude(a_transfer, desiredOrbitAltitude, body, false) };
  double final_circularOrbitVelocity { findOrbitalVelocityAtAltitude(final_cirularOrbitA, desiredOrbitAltitude, body, true) };
  double burn2_dV { std::abs(final_circularOrbitVelocity - transfer_apVelocity) };
  

  double dV_Total_Cost { burn1_dV + burn2_dV };
  
  std::cout << "---------------------------" << '\n';
  std::cout << "Periapsis Δv cost: " << burn1_dV << " m/s" << '\n';
  std::cout << "Apoapsis  Δv cost: " << burn2_dV << " m/s" << '\n';
  std::cout << "Total     Δv cost: " << dV_Total_Cost << " m/s" << "\n\n";

  std::cout << "Orbit    velocity: " << final_circularOrbitVelocity << " m/s" << '\n';
  std::cout << "---------------------------" << '\n';

  return dV_Total_Cost;
}

double pureOrbitalPlaneRotationCalc(double r1, double desiredInclination, double a,  const CelestialBody & body, bool circular){
   double currentVelocity { findOrbitalVelocityAtAltitude(a, r1, body, circular) };
   double requiredDv { 2 * currentVelocity * std::sin(desiredInclination/2) };
   return requiredDv;
}

