/**
 * Demo of the Functor objects.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Represents a polynomial of degree 2: ax^2 + bx + c
 */
class Polynomial {
		double _a,_b,_c;
	public:
		Polynomial(double a=0): 
			_a(a), _b(0), _c(0)			{  }
		Polynomial(double a, double b, double c): 
			_a(a), _b(b), _c(c)			{  }

		const Polynomial operator-() const {
			return Polynomial(-_a, -_b, -_c);
		}

		double operator() (double x) const { 
			return _a*x*x + _b*x + _c; }
		// double getValue(double x) {   // Java style
		// 	return _a*x*x + _b*x + _c; }

		double operator() () const { 
			return 0; 
		}
};


int maximize(Polynomial p, int from, int to) {
	// Find the maximum value of the given polynomial over all integers between from and to
	int result = -INT32_MAX;
	for (int i=from; i<=to; ++i) {
		if (p(i) > result)
			result = p(i);
	}
	return result;
}

int minimize(Polynomial p, int from, int to) {
	return - maximize (-p, from, to);
}


int main() {
	Polynomial poly1(2,3,4);
	cout << "poly1(5) = " << poly1(5) << endl; // prints 69
	// equivalent to:
	//  poly1.operator()(5)
	cout << "Polynomial(2,3,4)(5) = " << Polynomial(2,3,4)(5) << endl; // prints 69
	cout << "poly1() = " << poly1() << endl; // prints 0

	Polynomial poly2(5);
	cout << "poly2(5) = " << poly2(5) << endl; 
	cout << "Polynomial(5)(5) = " << Polynomial(5)(5) << endl; // prints 125

	// Polynomial poly3;
	// poly3(5);

	cout << "minimize (x^2 + 3, -10, 10) = " << minimize(Polynomial(1,0,3), -10, 10) << endl;

	return 0;
}
