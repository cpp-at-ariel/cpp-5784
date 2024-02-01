/**
 * Demonstrates STL shuffle algorithm.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <random>
#include <vector>
#include <array>
#include "output_containers.hpp"
using namespace std;



int main() {
	vector<int> v{0,1,2,3,4,5,6,7,8,9};   
	cout << "start: " << v << endl;

	auto v2 = v;

	shuffle(begin(v), end(v), default_random_engine{1});
	cout << "shuffled(1): " << v << endl;

	shuffle(begin(v2), end(v2), default_random_engine{1});
	cout << "shuffled(1): " << v2 << endl;

	shuffle(begin(v), end(v), default_random_engine{2});
	cout << "shuffled(2): " << v << endl;
}

