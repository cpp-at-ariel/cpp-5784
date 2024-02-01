#include "Point.hpp"

#include <iostream>
using namespace std;

void Point::setX(int newX) { 
	cout << "setX(" << newX <<")" <<endl;
	x = newX; 
}

void Point::setY(int newY) { 
	cout << "setY(" << newY <<")" <<endl;
	y = newY; 
}

string Point::to_string() {
	return "("+std::to_string(x)+","+std::to_string(y)+")";
}

