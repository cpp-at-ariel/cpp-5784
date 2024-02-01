
/**
 * Demonstrates static members.
 * Creates a class "point" with static members for giving a unique index to each object.
 */

#include "points.index.hpp"

// Initialize the static member:
int Point::nextPointIndex = 0;

Point::Point() {
	//nextPointIndex=0; // logic error
	this->index = nextPointIndex;
	nextPointIndex++;
}

void Point::setX(int newX) { 
	if (newX>MAXX)
		throw out_of_range("New x is too large! The maximum is "+std::to_string(MAXX));
	//x is equivalent to this->x;
	x = newX; 
}

void Point::setY(int newY) { 
	if (newY>MAXY)
		throw out_of_range("New y is too large! The maximum is "+std::to_string(MAXY));
	y = newY; 
}

string Point::to_string() {
	return "point #"+std::to_string(index)+": ("+std::to_string(x)+","+std::to_string(y)+")";
}

void Point::showMax() {
	//cout << this << endl; // compilation error: no this
	cout << MAXX << "," << MAXY << endl;
}
