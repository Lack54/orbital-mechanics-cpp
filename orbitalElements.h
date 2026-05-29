#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <numbers>

#include "bodies.h"
#include "structs.h"


double semiMajorAxis_calc(double r1, double r2, [[maybe_unused]] const CelestialBody& body){
  // set the apoapsis and periapsis relative to 
  // the center of Kerbin

  // calculate semi major axis average distance between r1, r2
  return (r1+r2) / 2.0;
}

double semiMinorAxis_calc(double a, double e){
  if (e>= 1.0) return NAN; // check to make sure its a ellipse 
  return a*std::sqrt(1 - e * e);
}
double eccentricity_calc(double r1, double r2){
  return (r1 - r2) / (r1+r2);
}

vec3 angularMomentumVector_calc(vec3 positionVector, vec3 velocityVector)
{

  vec3 angularVector {

    (positionVector.y * velocityVector.z) - (positionVector.z * velocityVector.y),
    (positionVector.z * velocityVector.x) - (positionVector.x * velocityVector.z),
    (positionVector.x * velocityVector.y) - (positionVector.y * velocityVector.x)

  };
  return angularVector;
}

double inclination_calc(vec3 hVector){
  // might need to square these total mag = sqrt hx2 + hy2 + hz2
  double magH {std::sqrt(

      pow(hVector.x,2) +
      pow(hVector.y,2) + 
      pow(hVector.z,2)
      )};
  double inclination_radians {std::acos(hVector.z / magH)};
  double inclination_degrees {inclination_radians * (180 / std::numbers::pi)};
  return inclination_degrees; 
}

double trueAnomaly_calc(double e, double a, double current_radius){
  // semi latus rectum 
  double p { a * (1 - e * e ) };

  double cosv { ((p/current_radius) - 1 ) / e };
  if (cosv > 1.0) cosv = 1.0;
  if (cosv < -1.0) cosv = -1.0;
  // solve for the true anomaly from radius 
  double trueAnomalyNu_Rad { std::acos(cosv) };
  return trueAnomalyNu_Rad;
}
