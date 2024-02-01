#include "Point.hpp"

#include <iostream>
using namespace std;


int main() {
    Point p1;
    //     // Calls no-arg constructor IF EXISTS.
    //     // If there is NO constructor, VALUE IS UNDEFINED.
    //     // If there is NO no-arg constructor: COMPILATION ERROR.
    cout << "p1 = " << p1.to_string() << endl;

    p1.setX(10);
    p1.setY(20);
    cout << "p1 = " << p1.to_string() << endl;

    Point p2 {11,21};
    cout << "p2 = " << p2.to_string() << endl;

    cout << "Point{7} = " << Point{7}.to_string() << endl;

    // //Point p3();
    // //cout << p3.to_string() << endl;
    // //   Compilation error! Empty parentheses interpreted as a function declaration!
    return 0;
}
