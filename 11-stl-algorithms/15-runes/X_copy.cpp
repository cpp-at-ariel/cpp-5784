/**
 * Demonstrates STL _copy rune.
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

#include <functional>
using namespace std::placeholders;


bool is_divisible_by(int x, int y) {
	return x%y==0;
}

/*
bind(is_divisible_by,_1,2))

==

bool bind_is_divisible_by_2(int x) {
	return x%2==0;
}
*/


int main() {
	vector<int> v{9,8,6,7,4,5,2,0,3,1};
	cout << "original vector: " << v << endl;
	vector<int> even, odd;

	partition_copy(begin(v), end(v), 
		back_inserter(even), back_inserter(odd), 
		bind(is_divisible_by,_1,2));
		// Equivalent to:
		// [](int x){return x%2==0;});
	cout << "partition_copy to even vs. odd: " << even << "   " << odd << endl;
	cout << "v: " << v << endl;

	vector<int> vr;
	rotate_copy(begin(v), begin(v)+3, end(v), back_inserter(vr));
	cout << "rotate_copy(3): " << vr << endl;
	cout << "v: " << v << endl;

	reverse_copy(begin(v), end(v), begin(vr));
	cout << "reverse_copy(3): " << vr << endl;
	cout << "v: " << v << endl;

	vector<int> vs(10);
	partial_sort_copy(begin(v), end(v), begin(vs), end(vs));
	cout << "partial_sort_copy: " << vs << endl;
	cout << "v: " << v << endl;
}

