/**
 * Demonstrates STL two-range query algorithms.
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
	cout << boolalpha;
	vector<int> v1{10,11,12,13,14,15,16,17,18,19};
	list<int>   v2{10,11,12,18,14,15,16,17,13,19};
	cout << "equal(v1,v2): " << equal(begin(v1),end(v1),begin(v2),end(v2)) << endl;
	cout << "is_permutation(v1,v2): " << is_permutation(begin(v1),end(v1),begin(v2),end(v2)) << endl;
	cout << "lexicographical_compare(v1,v2): " << lexicographical_compare(begin(v1),end(v1),begin(v2),end(v2)) << endl; // is v1 < v2?
	cout << "lexicographical_compare(v2,v1): " << lexicographical_compare(begin(v2),end(v2),begin(v1),end(v1)) << endl; // is v2 < v1?

	auto [iter1,iter2] = mismatch(begin(v1)+4,end(v1),++++++++begin(v2),end(v2));
	cout << "mismatch-1: " << *iter1 << endl;
	cout << "mismatch-2: " << *iter2 << endl;
}

