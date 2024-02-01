/**
 * Demonstrates IO iterators with STL containers.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include <set>
#include <unordered_set>
#include <vector>
#include <numeric>
#include "output_containers.hpp"
using namespace std;

int main() {
	// example of insert iterator:
	vector<int> v(2);
	// v.reserve(3);
	// auto viter = v.begin(); 
	auto viter = back_insert_iterator(v);
	*viter = 2; viter++;
	*viter = 5; viter++;
	*viter = 3; viter++;
	cout << "v: " << v << endl;

	set<int> s;
	auto siter = insert_iterator(s, s.begin());
	*siter = 0;
	*siter = 2;
	*siter = 5;
	*siter = 3;
	cout << "s: " << s << endl;

	// example of copy + inserter:
	// (copy vector to set - get rid of duplicates, and sort by value):
	vector<int> v1 {1,7,3,5,1,3};
	cout << "v1: " << v1 << endl;
	set<int> s1;
	copy(v1.begin(), v1.end(), insert_iterator{s1, s1.begin()});
	// copy(v1.begin(), v1.end(), s1.begin()); // compile error 
	cout << "s1: " << s1 << endl;
	
	list<int> v2;
	copy(s1.begin(), s1.end(), front_insert_iterator{v2});  // calls v2.push_front()
	// copy(s1.begin(), s1.end(), v2.begin());
	cout << "v2: " << v2 << endl;
}

