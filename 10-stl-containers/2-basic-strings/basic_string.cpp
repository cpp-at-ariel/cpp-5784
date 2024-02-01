/**
 * Demonstrates basic strings vs strings.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <vector>
using std::basic_string;
using std::string;
using std::ostream;
using std::cout;
using std::endl;


ostream& operator<< (ostream& out, const basic_string<int>& s) {
	for (int i: s)
		out << i;
	return out;
}

struct Shape{
	int x,y; 
	virtual void draw() {}
};
ostream& operator<<(ostream& out, const Shape& s) {
	return (out << "(" << s.x << "," << s.y << ")");
}
ostream& operator<< (ostream& out, const basic_string<Shape>& s) {
	for (Shape i: s)
		out << i;
	return out;
}


int main() {
	string s {"abcdefghi"};
	s.replace(3,3,"xyz");
	//s += std::to_string(6.7);
	cout << s << endl;
	cout << s.substr(1,4) << endl;

	basic_string<int> si {1,2,3,4,5,6,7,8,9};
	si.replace(3,3, {7,8,9});
	cout << si << endl;
	cout << si.substr(1,4) << endl;

	// This works only if Shape is a "simple" type (e.g. has no virtual methods):
	// basic_string<Shape> ss { {1,2}, {3,4}, {5,6} };
	// ss.replace(1,1, {{7,8}});
	// cout << ss << endl;
}
