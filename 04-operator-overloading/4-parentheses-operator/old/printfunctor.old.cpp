/**
 * Demo of the Functor objects.
 * 
 * @author Erel Segal-Halevi
 * @since 2017
 */

#include <iostream>
#include <vector>

using namespace std;

class PrintFunctor {
		char _x;
	public:
		PrintFunctor(char x='*'): 
			_x(x) {  }
		void operator() () { cout << _x; }
};

void newline() { cout << endl; }

void repeat(int n, PrintFunctor action) {
	for (int i=0; i<n; ++i)
		action();
}

int main() {
	PrintFunctor f("*");
	repeat(10, f); cout << endl; // print 10 stars
	repeat(10, PrintFunctor{'6'});    cout << endl;
	repeat(10, newline);
}
