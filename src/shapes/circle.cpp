#include "point.hpp"
#include "shapes/circle.hpp"
#include "draw.cpp"
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(double r, Point c) : radius(r), center(c) {};

Circle :: double circumference(){
  return 2*M_PI*radius ;
  
}

Circle :: double area(){
    return M_PI*radius*radius ;
}

Circle :: void draw(){
    std :: vector<Point> cercle = {center};
    draw_picture(cercle);
}

Circle :: void resize(double ratio){
    if(ratio <= 0){
        std:: cout << "Le rayon ne peut pas être inférieur ou égal à zéro" << std :: endl;
    }else{
        radius *= ratio;
        std :: cout << "Le cercle a été ajusté" << std :: endl;        
    }
}

Circle :: bool equals(Circle circle){
    if(circle.radius == radius && circle.center == center){
        return True;
    }else{
        return False;    
    }
}

Circle :: void translate(Point T){
    center.x = T.x;
    center.y = T.y;
    draw();    
}
