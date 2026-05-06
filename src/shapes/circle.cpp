#include "point.hpp"
#include "shapes/circle.hpp"
#include "draw.cpp"
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double circumference(){
  return 2*M_PI*radius ;
  
}

double area(){
    return M_PI*radius*radius ;
}

void draw(){
    vector<Point> cercle = {center};
    draw_picture(cercle);
}
