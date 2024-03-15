// File name: Point.cpp
// Author: CS2201 Instructor
// userid: jangj1
// Email: jungwon.jang@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 7
// Description:  Represent a point via x & y coordinates.
// Last Changed: 11-8-2019


#include "Point.h"

// Class Constructor
// post: Initializes x and y to zero
Point::Point(): x(0), y(0)
{}

// Class Constructor
// post: Initializes x and y 
Point::Point(int xVal,int yVal): x(xVal), y(yVal)
{}


// Equality operators
bool Point::operator== (const Point& rhs) const
{
    return (this->x==rhs.x && this->y==rhs.y);
}
bool Point::operator!= (const Point& rhs) const
{
    return !(*this==rhs);
}


// insertion operator for printing a Point
std::ostream & operator<< (std::ostream &out, const Point& p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

