/**
 * Demonstrates STL unique algorithm.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_set>
#include <array>
#include "output_containers.hpp"
using namespace std;



int main() {
	vector<int> v {11,8,5,6,11,11,11,9,3,5,5,11,6};
	auto v2 = v;
	cout << "v: " << v << endl;
	auto new_end = unique(begin(v), end(v));

	cout << "v after unique: " << v << endl;
	v.erase(new_end, end(v));
	cout << "v after erase: " << v << endl;

	vector<int> v3;
	unique_copy(begin(v2), end(v2), back_inserter(v3));
	cout << "v2 after unique_copy: " << v2 << endl;
	cout << "v3 after unique_copy: " << v3 << endl;

	cout << "\n unique_copy using unordered_set: " << endl;
	unordered_set<int> vs;
	vector<int> vsv;
	copy(begin(v), end(v), inserter(vs, vs.end()));
	copy(begin(vs), end(vs), back_inserter(vsv));
	cout << "v after unordered_set: " << vsv << endl;
}

