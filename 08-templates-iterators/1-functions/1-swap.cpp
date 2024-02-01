/**
 * Function template example: swap. 
 * 
 * Also illustrates errors when:
 * - The argument types do not match.
 * - There is no copy ctor.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-04
 */

#include <iostream>
#include <map>
using std::cout;
using std::cerr;
using std::endl;
// Don't use namespace std, since it brings std::swap!


template <typename T> void swap(T& a, T& b) {
	cout << "swap Ts" << endl;
	T tmp = a;
	a = b;
	b = tmp;
}

void swap (double& a, double& b) {
	cout << "swap doubles" << endl;
	a = a + b;
	b = a - b;
	a = a - b;
}

int main() {
	{   // swap ints:
		cout << endl;
		int a=4,b=5;
		cout << a << " " << b << endl;
		swap(a,b);
		cout << a << " " << b << endl;
	}

	{   // swap doubles:
		cout << endl;
		double a=4.1,b=5.1;
		cout << a << " " << b << endl;
		swap(a,b);
		cout << a << " " << b << endl;
		swap<double>(a,b);
		cout << a << " " << b << endl;
	}
	{   // try to swap double and int:
		cout << endl;
		double a=4.1; int b=5;
		cout << a << " " << b << endl;
		// swap(a,b);  // compile error
		cout << a << " " << b << endl;
	}

	{   // try to swap ostream:
		swap(cout, cerr);     // compile error
	}
}
