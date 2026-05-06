#include "point.hpp"
#include "shapes/triangle.hpp"
#include <draw.cpp>
#include <vector>


Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimeter(){
	return A.distance(B) + A.distance(C) + B.distance(C);
	}

double Triangle::area(){
	return 0.5*(((A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y))**2)**0.5);
	}
	
Point Triangle::center(){
	return Point((A.x+B.x+C.x)/3,(A.y+B.y+C.y)/3);
	}
	
void draw(){
	vector<Point> triangle  = {A,B,C};
	draw_picture(triangle);
	}
