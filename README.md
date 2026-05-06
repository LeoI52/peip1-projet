# Geometric Drawing Project

### Authors
Léo Imbert, Yael Ennon, Matsilo Rakotondrainibe, Rodrigo Manatas

### Description

This project is made in C++.  
It gives simple shapes to draw on the screen in 2D. You can find all the available shapes and their own methods below.

## Point

This is the base struct for all of this project and is used.  
**Attributes :**
- x (The x coordinate of the point)
- y (The y coordinate of the point)

**Methods :**
- distance(Point) (Returns the distance between two points)

## Square

**Attributes :**
- A (The top left point of the square)
- C (The bottom right point of the square)

**Methods :**
- side (Returns the side lenght of the square)
- permimeter (Returns the perimeter of the square)
- area (Returns the area of the square)
- center (Returns the center point of the square)
- draw (Draws the square to the screen)
- translate(Point) (Changes the point top left corner of the square)
- resize(double) ()
- rotate(double) ()
- equals(Square) (Returns if the square is equal to another one)
- inscribedCircle (Returns the circle inscribed in the square)
- circumscribedCircle (Returns the circle circumscribed in the square)

## Circle

## Triangle