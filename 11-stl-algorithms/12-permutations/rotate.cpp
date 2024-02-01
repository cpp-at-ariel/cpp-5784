/**
 * Demonstrates STL rotate algorithms.
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
	vector<int> v{9,8,6,7,4,5,2,0,3,1};       // OK
	cout << "start: " << v << endl;

	rotate(begin(v), begin(v)+3, end(v));
	cout << "rotated(3): " << v << endl;
}

