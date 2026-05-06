#include "point.hpp"
#include <cmath>

Point::Point(double x_val, double y_val) : x(x_val), y(y_val) {}

double Point::distance(Point B){
    double X = (x - B.x), Y = (y - B.y)
    return sqrt(X * X + Y * Y)
}