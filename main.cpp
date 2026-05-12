#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>


int main() {

	// Define shapes
	Square s = {Point(-200, -200), Point(-100, -100)};
	Circle c = {50, Point(-200, 100)};
	Triangle t = {Point(100, 0), Point(0, 0), Point(0, 100)};
	
	// Couts
	cout << "The square has a side of " << s.side() << ", has a perimeter of " << s.perimeter() << ", has an area of " << s.area() << " and has a center of (" << s.center().x << "," << s.center().y << ")." << endl;
	cout << "The circle has a circumference of " << c.circumference() << " and has an area of " << c.area() << "." << endl;
	cout << "The triangle has a perimeter of " << t.perimeter() << ", has an area of " << t.area() << " and has a center of gravity of (" << t.center().x << "," << t.center().y << ")." << endl;

	// Draws
	s.draw();
	c.draw();
	t.draw();
	
	return 0;
}
