/**
 * Demonstrates how to define and use different comparators.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;


struct Point {
	int x, y;
	Point(int x, int y): x(x), y(y) {}
};

ostream& operator<< (ostream& out, const Point& p) {
	return (out << "(" << p.x << "," << p.y << ")");
}

struct PointCompare {
	bool operator() (Point a, Point b) const {
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	}
};


int main() {
	cout << endl << "Set of points: " << endl;
	set<Point, PointCompare> sp;
	sp.emplace(2,3);
	sp.emplace(1,5);
	sp.emplace(3,1);
	for (auto s: sp)
		cout << s << endl;

	cout << endl << "Set of points 2: " << endl;
	set<Point> sp2;
	// sp2.emplace(2,3);  // Compile error
	// sp2.emplace(1,5);
	// sp2.emplace(3,1);
	for (auto s: sp2)
		cout << s << endl;
}
