#include "point.hpp"
#include "shapes/circle.hpp"
#include "draw.hpp"
#include <vector>

#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(double r, Point c) : radius(r), center(c) {};    //constructeur de la structure Circle

double Circle::circumference(){   //fonction calculant le prérimètre du cercle
  return 2*M_PI*radius ;
  
}

double Circle::area(){     //fonction calculant l'aire du cercle
    return M_PI*radius*radius ;
}

void Circle::draw(){   //fonction permettant de dessiner le cercle
    std :: vector<Point> cercle = {center};
    draw_picture(cercle);
}

void Circle::resize(double ratio){     //fonction permettant de modifier le rayon du cercle sans en changer le centre
    if(ratio <= 0){
        std:: cout << "Le rayon ne peut pas être inférieur ou égal à zéro" << std :: endl;
    }else{
        radius *= ratio;
        std :: cout << "Le cercle a été ajusté" << std :: endl;        
    }
}

bool Circle::equals(Circle circle){    //fonction permettant de comparer deux cercles pour savoir s'ils sont les mêmes
    if(circle.circumference() == circumference() && circle.area() == area()){
        return True;
    }else{
        return False;    
    }
}

void Circle::translate(Point T){  //fonction permettant à un cercle de faire une translation sans en changer le rayon (il suffit donc de modifier les coordonnées du centre)
    center.x = T.x;
    center.y = T.y;
    draw();    
}
