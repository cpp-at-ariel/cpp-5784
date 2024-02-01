/**
 * Demostrates exceptions and assertions.
 * @author Erel Segal-Halevi
 * @since  2018-03
 */
 
// To disable the assertions:
// Either uncomment this line:
// #define NDEBUG
// Or Compile with the flag -DNDEBUG 


#include <iostream>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;

double sqrtWithBug(double x) {
	double result = -std::sqrt(x);
	assert (result>=0);
	return result;
}

int main() {
	cout << "std::sqrt(4) " << std::sqrt(4) << endl;
	cout << "sqrtWithBug(4) " << sqrtWithBug(4) << endl;
}
