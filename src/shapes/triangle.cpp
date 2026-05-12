#include "point.hpp"
#include "draw.hpp"
#include "shapes/triangle.hpp"
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>

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
	std::vector<Point> draw_triangle  = {A,B,C,A};
	draw_picture(draw_triangle);
	}

void Triangle::translate(Point T){
	A.x = A.x + T.x,
	A.y = A.y + T.y;
	B.x = B.x + T.x,
	B.y = B.y + T.y;
	C.x = C.x + T.x,
	C.y = C.y + T.y;
	}

void Triangle::resize(double ratio){
	A.x = center().x + ratio * (A.x - center().x);
	A.y = center().y + ratio * (A.y - center().y);
	B.x = center().x + ratio * (B.x - center().x);
	B.y = center().y + ratio * (B.y - center().y);
	C.x = center().x + ratio * (C.x - center().x);
	C.y = center().y + ratio * (C.y - center().y);
	}

void Triangle::rotate(double angle){
	angle = angle*M_PI/180;
	double temp_Ax = A.x;
	double temp_Bx = B.x;
	double temp_Cx = C.x;
	double centre_x = center().x;
	double centre_y = center().y;
	
	A.x -= centre_x;
	A.y -= centre_y;
	B.x -= centre_x;
	B.y -= centre_y;
	C.x -= centre_x;
	C.y -= centre_y;

	A.x = A.x*cos(angle) - A.y*sin(angle), 
	A.y = temp_Ax*sin(angle) + A.y*cos(angle);
	B.x = B.x*cos(angle) - B.y*sin(angle), 
	B.y = temp_Bx*sin(angle) + B.y*cos(angle);
	C.x = C.x*cos(angle) - C.y*sin(angle), 
	C.y = temp_Cx*sin(angle) + C.y*cos(angle);

	A.x += centre_x;
	A.y += centre_y;
	B.x += centre_x;
	B.y += centre_y;
	C.x += centre_x;
	C.y += centre_y;
	}

bool Triangle::equals(Triangle triangle){
	return (A.x == triangle.A.x and A.y == triangle.A.y or A.x == triangle.B.x and A.y == triangle.B.y or A.x == triangle.C.x and A.y == triangle.C.y) 
		and (B.x == triangle.A.x and B.y == triangle.A.y or B.x == triangle.B.x and B.y == triangle.B.y or B.x == triangle.C.x and B.y == triangle.C.y) 
		and (C.x == triangle.A.x and C.y == triangle.A.y or C.x == triangle.B.x and C.y == triangle.B.y or C.x == triangle.C.x and C.y == triangle.C.y);
	}

bool Triangle::isRightAngled(){
	return (A.distance(B)*A.distance(B) == A.distance(C)*A.distance(C) + B.distance(C)*B.distance(C))
		or (A.distance(B)*A.distance(B) + A.distance(C)*A.distance(C) == B.distance(C)*B.distance(C))
		or (A.distance(C)*A.distance(C) == A.distance(B)*A.distance(B) + B.distance(C)*B.distance(C));
	}

bool Triangle::isEquilateral(){
	return A.distance(B) == A.distance(C) == B.distance(C);
	}

bool Triangle::isIsoceles(){
	return (A.distance(B) == A.distance(C)) or (A.distance(B) == B.distance(C)) or (B.distance(C) == A.distance(C));
	}

Circle Triangle::circumscribedCircle(){
	return Circle(A.distance(center()), center());
	}