#include "Rectangle.hpp"

string Rectangle::to_string() 
{
	return "Rectangle[" + topleft.to_string() + " , " + bottomright.to_string() + "]"; 
}