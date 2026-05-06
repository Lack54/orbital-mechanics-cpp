#include <iostream>
#include <cmath>
#include "bodies.h"
#include "physics.h"


int main(){
  const CelestialBody& body = Earth;

  double r1 {100000 + body.radius }, r2 {100000 + body.radius};
  double a {semiMajorAxis_calc(r1, r2, body)};
  

  double dV = circularizeOrbit_Calc(a, r1, r2, body); 
  return 0;
}
