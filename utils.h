#pragma once 

#include <iostream>
#include <cmath>
#include "structs.h"

void printVector(vec3 vec){
  std::cout << "\n\n";
  std::cout << "X: " << vec.x << '\n'; 
  std::cout << "Y: " << vec.y << '\n'; 
  std::cout << "Z: " << vec.z << '\n'; 
}
