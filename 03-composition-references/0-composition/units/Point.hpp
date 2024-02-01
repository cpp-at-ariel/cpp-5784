#pragma once

// Before the invention of "pragma once", this is what people used to do:
// #ifndef __POINT_HPP
// #define __POINT_HPP

#include <string>
using namespace std;

class Point {
  private:
    int x;
    int y;
  public:
    void setX(int);
    void setY(int);
    string to_string();

    Point() { setX(9); setY(9); }

    Point(int z): Point(z,z) {}
    // x(z), y(z) { }
    //Point(int z) { x=y=z; }

    //Point(int xx, int yy): x(xx), y(yy)  { }
    Point(int xx, int yy)  {  { setX(xx); setY(yy); } }
};

// #endif
