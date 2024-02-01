/**
 * Demonstrates STL replace algorithm.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include <array>
#include "output_containers.hpp"
using namespace std;



int main() {
	vector<int> v {1,8,4,6,1,9,3,5,1,6};
	cout << "v: " << v << endl;
	replace(begin(v), end(v), 1, 1111);
	cout << "replace 1 by 1111: " << v << endl;
}

