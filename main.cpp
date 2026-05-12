#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {

	// Define shapes
	Square s = {Point(0, 0), Point(100, 100)};
	Circle c = {100, Point(0, 0)};
	Triangle t = {Point(100, 0), Point(0, 0), Point(0, 100)};
	
	// Couts
	cout << "The square has a side of " << s.side() << ", has a perimeter of " << s.perimeter() << ", has an area of " << s.area() << " and has a center of (" << s.center().x << "," << s.center().y << ")." << endl;
	cout << "The circle has a circumference of " << c.circumference() << " and has an area of " << c.area() << "." << endl;
	cout << "The triangle has a perimeter of " << t.perimeter() << ", has an area of " << t.area() << " and has a center of gravity of (" << t.center().x << "," << t.center().y << ")." << endl;
	cout << "Triangle right angled : " << t.isRightAngled() << ". Triangle equilateral : " << t.isEquilateral() << ". Triangle isoceles : " << t.isIsoceles() << endl;
	cout << s.equals(s) << " | " << c.equals(c) << " | " << t.equals(t) << endl;

	// Draws
	s.draw();
	c.draw();
	t.draw();
	s.inscribedCircle().draw();
	s.circumscribedCircle().draw();
	t.inscribedCircle().draw();
	t.circumscribedCircle().draw();

	// Square
	s.resize(0.5);
	s.translate(Point(200, 200));
	s.rotate(45);
	s.draw();

	// Circle
	c.resize(0.5);
	c.translate(Point(200, 200));
	c.draw();

	// Triangle
	t.resize(0.5);
	t.translate(Point(200, 200));
	t.rotate(90);
	t.draw();
	
	return 0;
}
