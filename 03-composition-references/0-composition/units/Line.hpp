#pragma once

#include <iostream>
#include "Point.hpp"

class Line
{
	private:
		Point p1, p2;
	public:
		static int default_value;
		
		Line()
		: p1{default_value,default_value}, p2{default_value,default_value}
		//: p1{}, p2{}  // automatic
		{ 
			// p1.setX(0);
			// p1.setY(0);
			// p2.setX(0);
			// p2.setY(0);
		}

		Line(int xy1, int xy2): 
			p1{xy1}, p2{xy2}
			{ 

				
			}
		Line(int x1,int y1,int x2,int y2);

		Line(Point new_p1): p1(new_p1) {}
		
		void set(int,int,int,int);
		void set(Point,Point);
		string to_string();
};

