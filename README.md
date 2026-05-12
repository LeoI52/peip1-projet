# Geometric Drawing Project

### Authors
Léo Imbert, Yael Ennon, Matsilo Rakotondrainibe, Rodrigo Manatas

### Description

This project is made in C++.  
It gives simple shapes to draw on the screen in 2D. You can find all the available shapes and their own methods below.

## Point

This is the base struct for all of this project and is used.  
**Attributes :**
- x (double) : the x coordinate of the point
- y (double) : the y coordinate of the point

**Methods :**
- distance(Point) : returns the distance between two points

## Square

**Attributes :**
- A (Point) : the top left point of the square
- C (Point) : the bottom right point of the square

**Methods :**
- side : returns the side lenght of the square
- permimeter : returns the perimeter of the square
- area : returns the area of the square
- center : returns the center point of the square
- draw : draws the square to the screen
- translate(Point) : changes the point top left corner of the squar
- resize(double) : resize the square while maintaining center
- rotate(double) : rotate counterclockwise around the center of the square in degrees
- equals(Square) : returns if the square is equal to another one
- inscribedCircle : returns the circle inscribed in the square
- circumscribedCircle : returns the circle circumscribed in the square

## Circle

**Attributes :**
- radius (double) : the radius of the circle
- center (Point) : the center point of the circle

**Methods :**
- circumference : returns the circumference of the circle
- area : returns the area of the circle
- draw : draws the circle
- translate(Point) : changes the center point
- resize(double) : resize the circle with a ratio
- equals(Circle) : returns if the circle is equal to another one

## Triangle

**Attributes :**
- A (Point) : the first point of the triangle
- B (Point) : the second point of the triangle
- C (Point) : the third point of the triangle

**Methods :**
- perimeter : returns the perimeter of the triangle
- area : returns the area of the triangle
- center : returns the center of gravity of the triangle
- draw : draws the triangle
- translate(Point) : changes the triangle position using point has a vector
- resize(double) : resize the triangle while maintaining the center
- rotate(double) : rotate counterclockwise around the center of the triangle
- equals(Triangle) : returns if the triangle is equal to another triangle
- isRightAngled : returns if the triangle is right angled
- isEquilateral : returns if the triangle is equilateral
- isIsoceles : returns if the triangle is isoceles
- inscribedCircle : returns the inscribed circle of the triangle
- circumscribedCircle : returns the circumscribed circle of the triangle