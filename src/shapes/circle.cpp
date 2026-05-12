#include "point.hpp"
#include "shapes/circle.hpp"
#include "draw.hpp"
#include <vector>
#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(double r, Point c) : radius(r), center(c) {};

double Circle::circumference(){
  return 2*M_PI*radius ;
  
}

double Circle::area(){
    return M_PI*radius*radius ;
}

void Circle::draw(){
    Point p;
    std :: vector<Point> cercle = {};
    for(int i = 0; i <= 64; i++){
        p.x = cos((M_PI/32)*i);
        p.y = sin((M_PI/32)*i);
        cercle.push_back(p);
}
    Point p1;
    p1.x = cos(0);
    p1.y = sin(0);
    cercle.push_back(p1);
    draw_picture(cercle);
}

void Circle::resize(double ratio){
    if(ratio <= 0){
        std:: cout << "Le rayon ne peut pas être inférieur ou égal à zéro";
    }else{
        radius *= ratio;
    }
}

bool Circle::equals(Circle circle){
    if(circle.circumference() == circumference() && circle.area() == area()){
        return true;
    }else{
        return false;    
    }
}

void Circle::translate(Point T){
    center.x = T.x;
    center.y = T.y;
    draw();    
}
