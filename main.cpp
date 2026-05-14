#include <iostream>
#include <cmath>
#include "bodies.h"
#include "physics.h"


int main(){
  const CelestialBody& body = Earth;

  double r1 {7000000 + body.radius }, r2 {7000000 + body.radius};
  double a {semiMajorAxis_calc(r1, r2, body)};
  double e {eccentricity_calc(r1,r2)};
  double b {semiMinorAxis_calc(a,e)};
  double t { orbitalPeriod_calc(a,body)};
  std::cout << e <<'\n'<< b << '\n' << t;

 // double dV = circularizeOrbit_Calc(a, r1, r2, body);
 // std::cout << '\n' << "test inclination change dv to 60 degrees = " << pureOrbitalPlaneRotationCalc(r1, 60, a, body, true);
  return 0;
}
