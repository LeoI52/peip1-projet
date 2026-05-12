#include "point.hpp"
#include "shapes/square.hpp"
#include "draw.hpp"
#include <iostream> 
#define _USE_MATH_DEFINES

#include <cmath>

#include <vector>
using namespace std;


Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side() {
    double diag = A.distance(C);
    return diag / std::sqrt(2.0);
}

double Square::perimeter(){
    return 4*side();

}

double Square::area() {
    double s = side();
    return s * s;
}

Point Square::center() {
    return Point((A.x + C.x) / 2.0, (A.y + C.y) / 2.0);
}

void Square::draw(){
    Point B= {C.x, A.y};
    Point D={A.x,C.y };
    std::vector<Point> Square={A,B,C,D,A};
    draw_picture (Square);
}


void Square::translate(Point T){
    A.x=A.x+T.x;
    A.y=A.y+T.y;


}

void Square::resize(double ratio){
    Point O=center();
    A.x=O.x +(A.x-O.x)*ratio;
    A.y=O.y+(A.y-O.y)*ratio;
    C.x=O.x +(C.x-O.x)*ratio;
    C.y=O.y+(C.y-O.y)*ratio;
}



void Square::rotate(double angle) {
    angle = angle*M_PI/180;
	double temp_Ax = A.x;
	double temp_Cx = C.x;
	double centre_x = center().x;
	double centre_y = center().y;
	
	A.x -= centre_x;
	A.y -= centre_y;
	C.x -= centre_x;
	C.y -= centre_y;

	A.x = A.x*cos(angle) - A.y*sin(angle), 
	A.y = temp_Ax*sin(angle) + A.y*cos(angle);
	C.x = C.x*cos(angle) - C.y*sin(angle), 
	C.y = temp_Cx*sin(angle) + C.y*cos(angle);

	A.x += centre_x;
	A.y += centre_y;
	C.x += centre_x;
	C.y += centre_y;
	}
bool Square::equals(Square square){
    return square.area()==area() && square.perimeter()==perimeter();
 }

Circle Square::inscribedCircle() {
    // Le rayon est la moitié du côté
    return Circle(side()/2.0, center());
}

Circle Square::circumscribedCircle() {
    // Le rayon est la moitié de la diagonale
    return Circle(A.distance(C) / 2.0, center());
}