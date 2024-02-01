#pragma once

#include <iostream>
using namespace std;

class Point {
  private:    // Not required. All is private by default.
    int x;
    int y;

  public:
    // methods defined inline:
    int getX() { return x;  }
    int getY() { return y;  }

    // methods defined in the CPP file:
    void setX(int);
    void setY(int);

    string to_string();

    // // Constructors:
    Point() {
      cout << "Point()" << endl; 
      x = 88; y = 12;  
    }
    Point(int z) { 
      cout << "Point(int)" << endl; 
      x = y = z; 
    }
    Point(int, int);
};
