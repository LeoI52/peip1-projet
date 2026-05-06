#include "point.hpp"
#include "shapes/square.hpp"
#include <iostream> 
#include <cmath>

Square::Square(Point P, Point R) : A(P), C(R) {};

Square::double side(){
    return A.x - C.x;
}

Square::double perimeter(){
    return 4*(A.x-C.x);

}

Square::double area(){
    return (A.x-C.x)*(A.x-C.x);
}

Square::Point centre(){

}

Square::void draw(){
    for (int i=0; i<A.x-C.x; i++){
        cout << "*";}
}
