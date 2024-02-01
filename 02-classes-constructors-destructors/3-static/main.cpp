
/**
 * Demonstrates static members.
 * Creates a class "point" with static members for giving a unique index to each object.
 */

#include "points.index.hpp"

int main() {
    //Point::to_string();
    Point p1;
    cout << "p1 = " << p1.to_string() << endl;

    Point p2;
    p2.setX(10);
    p2.setY(20);
    cout << "p2 = " << p2.to_string() << endl;
    
    cout << "Maximum values: " << endl;
    cout << Point::MAXX << "," << Point::MAXY << endl;
    Point::showMax();

    // p1.setX(2000);  // exception

    return 0;
}
