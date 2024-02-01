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


// Throw a string:
double safesqrt(double x) {
	if (x<0)
		throw string(
			"x must be non-negative, but it is "
			+to_string(x));
	return std::sqrt(x);
}


int main() {
	cout << "std::sqrt(4) = " << std::sqrt(4) << endl;
	cout << "std::sqrt(-4) = " << std::sqrt(-4) << endl;
	try {
		cout << "safesqrt(4) = " << safesqrt(4) << endl;
		cout << "safesqrt(-4) = " << safesqrt(-4) << endl;
	}
	catch (string message) {
		cout << "   caught exception: " << message << endl;
	}

	cout << safesqrt(-9) << endl; // uncaught exception
	cout << "Program finished successfully" << endl;
}
