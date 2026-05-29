#include <iostream>
#include <cmath>
#include "bodies.h"
#include "physics.h"
#include "orbitalElements.h"
#include "structs.h"
#include "utils.h"
#include <numbers>
int main(){
  const CelestialBody& body = Earth;

  vec3 positionVector {230, 500, 4567};
  vec3 velcoityVector {440, 500, 503}; 
  vec3 angularMomentumVector {angularMomentumVector_calc(positionVector, velcoityVector)};
    
  double r1 {88000000 + body.radius }, r2 {7000000 + body.radius};
  double a {semiMajorAxis_calc(r1, r2, body)};
  double e {eccentricity_calc(r1,r2)};
  double b {semiMinorAxis_calc(a,e)};
  double nu { trueAnomaly_calc(e,a,55000000)};
  double inclination {inclination_calc(angularMomentumVector)};


  std::cout << "position vector";
  printVector(angularMomentumVector);

  std::cout << "Inclination calculated: " << inclination << '\n';
  std::cout << std::numbers::pi; 
//  std::cout << e <<'\n'<< a << '\n';

 // double dV = circularizeOrbit_Calc(a, r1, r2, body);
 // std::cout << '\n' << "test inclination change dv to 60 degrees = " << pureOrbitalPlaneRotationCalc(r1, 60, a, body, true);
  return 0;
}
