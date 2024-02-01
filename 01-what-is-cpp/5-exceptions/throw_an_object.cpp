/**
 * Demostrates exceptions and assertions.
 * @author Erel Segal-Halevi
 * @since  2018-03
 */

#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;

// Throw a custom object:
class argument_must_be_positive {};

double safesqrt2(double x) {
	if (x<0)
		throw argument_must_be_positive{};
	double result = std::sqrt(x);
	return result;
}

int main() {
	cout << "std::sqrt(4) = " << std::sqrt(4) << endl;
	cout << "std::sqrt(-4) = " << std::sqrt(-4) << endl;
	try {
		cout << "safesqrt2(4) = " << safesqrt2(4) << endl;
		cout << "safesqrt2(-4) = " << safesqrt2(-4) << endl;
	}
	catch (...) {
		auto exception = std::current_exception();
	 	cout << "   caught exception of type " << exception.__cxa_exception_type()->name() << endl;
	}
	cout << safesqrt2(-9) << endl; // uncaught exception
}
