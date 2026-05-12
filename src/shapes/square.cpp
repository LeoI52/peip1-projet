#include "point.hpp"
#include "shapes/square.hpp"
#include "draw.hpp"
#include <iostream> 
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
    std::vector<Point> Square={A,C};
    draw_picture (Square);
}


void Square::translate(Point T){
    A.x=A.x+T.x;
    A.y=A.y+T.y;


}

void Square::resize(double ratio){
    double O=center();
    A.x=O.x +(A.x-O.x)*ratio;
    A.y=O.y+(A.y-O.y)*ratio;
    C.x=O.x +(C.x-O.x)*ratio;
    C.y=O.y+(C.y-O.y)*ratio;
}



void Square::rotate(double angle) {

    Point O= center();

    double x1 = A.x - O.x;
    double y1 = A.y - O.y;
    double x2 = C.x - O.x;
    double y2 = C.y - O.y;

    double cosA = std::cos(angle);
    double sinA = std::sin(angle);

    double rx1 = x1 * cosA - y1 * sinA; //r..=rotation
    double ry1 = x1 * sinA + y1 * cosA;

    double rx2 = x2 * cosA - y2 * sinA;
    double ry2 = x2 * sinA + y2 * cosA;

    A.x = O.x + rx1;
    A.y = O.y + ry1;

    C.x = O.x + rx2;
    C.y = O.y + ry2;
}



Circle Square::inscribedCircle() {
    // Le rayon est la moitié du côté
    return Circle(center(), side() / 2.0);
}

Circle Square::circumscribedCircle() {
    // Le rayon est la moitié de la diagonale
    return Circle(center(), A.distance(C) / 2.0);
}

