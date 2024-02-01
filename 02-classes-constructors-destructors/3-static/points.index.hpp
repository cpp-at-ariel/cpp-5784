/**
 * Demonstrates static members.
 * Creates a class "point" with static members for giving a unique index to each object.
 */

#include <iostream>
#include <stdexcept>
using namespace std;

class Point {
    int x;
    int y;
    int index;

    // A non-static const must be initialized out-of-line:
    static int nextPointIndex;

  public:
    Point();

    static const int MAXX=1366;
    static const int MAXY=768;

    void setX(int newX);
    void setY(int newY);
    string to_string();
    static void showMax();
};
