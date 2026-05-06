#include "point.hpp"
#include "shapes/circle.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double circumference(){
  return 2*M_PI*radius ;
  
}

