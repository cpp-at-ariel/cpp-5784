#include "units/Point.hpp"
#include "units/Line.hpp"
#include <iostream>
using namespace std;


int main() {
    Line l1;
    cout << "l1=" << l1.to_string() << endl;

    Line::default_value = 55;

    Line l2;
    cout << "l2=" << l2.to_string() << endl;

    // l1.set(1,2,3,4);
    // cout << "l1=" << l1.to_string() << endl;

    Line l3(5,6,7,8);
    cout << "l3=" << l3.to_string() << endl;

    // Line l4(Point(11,12));
    // cout << "l4=" << l4.to_string() << endl;
    return 0;
}
