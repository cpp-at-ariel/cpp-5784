/**
 * Using template-class-specialization to create type-information
 * 
 * @author ?
 * @url    ?
 */

#include <iostream>
#include <cassert>
using namespace std;


template<typename T> const bool is_numeric = false;
template<>           const bool is_numeric<int>    = true;
template<>           const bool is_numeric<long>   = true;
template<>           const bool is_numeric<float>  = true;
template<>           const bool is_numeric<double> = true;


template<typename T> T divide(T a, T b) {
    static_assert(is_numeric<T>, "Can only be numeric type");  // Creates a compile-time error
	assert(b!=0);                                              // Creates a run-time error
	return a/b;
}



int main() {
	cout << boolalpha;

    cout << is_numeric<int> << endl;
    cout << divide(8,2) << '\n';

	double f = 1.2;
    cout << is_numeric<double> << endl;
	cout << divide(f,f) << endl;
	// cout << divide(f,0.0) << endl;

	cout << is_numeric<char> << endl;
    // cout << divide('a','b') << endl;
}
