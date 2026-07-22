#include <iostream>
#include <cmath>
#include "bodies.h"
#include "physics.h"
#include "orbitalElements.h"
#include "structs.h"
#include "utils.h"

int main(){
  const CelestialBody& body = Earth;
  vec3 positionVector {0, 500, 0};
  vec3 velcoityVector {0, 500, 500}; 
  
    
  double r1 {88000000 + body.radius }, r2 {7000000 + body.radius};
  double a {semiMajorAxis_calc(r1, r2, body)};
  double e {eccentricity_calc(r1,r2)};
  double b {semiMinorAxis_calc(a,e)};
  double nu { trueAnomaly_calc(e,a,55000000)};
  vec3 angularMomentumVector {angularMomentumVector_calc(positionVector, velcoityVector)};


  std::cout << "position vector";
  printVector(positionVector);
  std::cout << "Velocity Vector";
  printVector(velcoityVector);
  std::cout << "angular Momentum Vector";
  printVector(angularMomentumVector);
  
  std::cout << "Inclination calculated: " << inclination_calc(angularMomentumVector) << '\n';

//  std::cout << e <<'\n'<< a << '\n';

 // double dV = circularizeOrbit_Calc(a, r1, r2, body);
 // std::cout << '\n' << "test inclination change dv to 60 degrees = " << pureOrbitalPlaneRotationCalc(r1, 60, a, body, true);
  return 0;
}
