/**
 * Demonstrates memory usage in C++.
 * @author erelsgl
 */

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class Point {
	private:
		int x;
		int y;
	public:
		Point() { x = y = 5555; }	
};

int main() {
	const int KB = 1024;
	const int SIZE=50*1000*KB;

	cout << "Before new" << ' ' << endl;
	this_thread::sleep_for(chrono::seconds(3));

	Point* p = new Point[SIZE];
	for (int  i=0; i<SIZE; ++i)
		p[i] = Point();
		
	cout << "After new" << endl;
	// The free memory should drop by ... KB.

	this_thread::sleep_for(chrono::seconds(10));

	delete[] p;
}
