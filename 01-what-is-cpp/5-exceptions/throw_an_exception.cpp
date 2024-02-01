/**
 * Demostrates exceptions and assertions.
 * @author Erel Segal-Halevi
 * @since  2018-03
 */

#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
#include <stdexcept>
using namespace std;

// Throw a standard exception object:
double safesqrt1(double x) {
	if (x<0)
		throw std::out_of_range{"x must be positive"};
	double result = std::sqrt(x);
	return result;
}

int main() {
	cout << "std::sqrt(4) = " << std::sqrt(4) << endl;
	cout << "std::sqrt(-4) = " << std::sqrt(-4) << endl;
	try {
		cout << "safesqrt1(4) = " << safesqrt1(4) << endl;
		cout << "safesqrt1(-4) = " << safesqrt1(-4) << endl;
	}
	catch (string ex) {
		cout << "caught string" << endl;
	}
	catch (std::out_of_range ex) {
	 	cout << "   caught exception: " << ex.what() << endl;
	}
	catch (std::exception ex) {

	}
}
