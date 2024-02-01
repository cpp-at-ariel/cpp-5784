/**
 * Demonstrates STL copy and copy_backward algorithms
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <array>
#include "output_containers.hpp"
using namespace std;



int main() {
	vector<int> v{0,1,2,3,4,5,6,7,8,9};
	vector<int> v2;
	cout << "v: " << v << endl;
	cout << "v2: " << v2 << endl;
	copy(begin(v), end(v), back_inserter(v2));
	cout << "v: " << v << endl;
	cout << "v2: " << v2 << endl << endl;
	//v2.insert(begin(v2), begin(v), end(v));
	//cout << "v2: " << v2 << endl << endl;

	// COPY A RANGE TO ITSELF:
	// (a) if d_first is within the range [first, last), std::copy is undefined; use std::copy_backward instead.
	v = v2;
	copy(begin(v), begin(v)+5, begin(v)+2);
	cout << "v after copy [0,5) to begin+2: " << v << endl;
	v = v2;
	copy_backward(begin(v), begin(v)+5, begin(v)+7);
	cout << "v after copy_backward [0,5) to begin+7: " << v << endl;

	// (b) If d_last is within (first, last], std::copy_backward is not defined; use std::copy instead.
	v = v2;
	copy_backward(begin(v)+2, begin(v)+7, begin(v)+5);
	cout << "v after copy [begin+2,begin+7) to begin+5: " << v << endl;
	v = v2;
	copy(begin(v)+2, begin(v)+7, begin(v));
	cout << "v after copy_backward [begin+2,begin+7) to begin: " << v << endl;
}

