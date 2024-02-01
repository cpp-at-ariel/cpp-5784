#pragma once

#include <iostream>

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

    std::string to_string();

    // // Constructors:
    Point() {
      std::cout << "Point()" << std::endl; 
      x = 88; y = 12; 
    }
    Point(int z) { 
      std::cout << "Point(int)" << std::endl; 
      x = y = z; 
    }
    Point(int, int);
};
