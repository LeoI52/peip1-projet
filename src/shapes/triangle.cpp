#include "point.hpp"
#include "draw.hpp"
#include "shapes/triangle.hpp"
#include <vector>


Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimeter(){
	return A.distance(B) + A.distance(C) + B.distance(C);
	}

double Triangle::area(){
	int res = (A.x*(B.y-C.y)+B.x*(C.y-A.y)+C.x*(A.y-B.y));
	if (res<0){
		res*=-1;
		}
	return 0.5*res;
	}
	
Point Triangle::center(){
	return Point((A.x+B.x+C.x)/3,(A.y+B.y+C.y)/3);
	}
	
void Triangle::draw(){
	std::vector<Point> draw_triangle  = {A,B,C};
	draw_picture(draw_triangle);
	}
