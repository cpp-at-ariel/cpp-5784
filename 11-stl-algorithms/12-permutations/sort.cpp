/**
 * Demonstrates STL sort algorithms.
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
	vector<int> v{19,18,16,17,14,15,12,10,13,11};   // OK
	// deque<int> v{9,8,6,7,4,5,2,0,3,1};      // OK
	// array<int,10> v{9,8,6,7,4,5,2,0,3,1};   // OK
	// int v[10] {9,8,6,7,4,5,2,0,3,1};        // OK
	// list<int> v{9,8,6,7,4,5,2,0,3,1};       // ERROR - invalid operands to binary expression ('std::_List_iterator<int>' and 'std::_List_iterator<int>')
	cout << "unsorted: " << v << endl;

	sort(begin(v), end(v));
	// sort(begin(v), begin(v)+5);
	cout << "sorted: " << v << endl;

	sort(begin(v), end(v), [](int a, int b){return a>b;});
	sort(begin(v), end(v), greater<int>{});
	cout << "\nsorted with comparator: " << v << endl;

	// Partial sort, in linear time:
	nth_element(begin(v), begin(v)+3, end(v));
	cout << "\nvector after nth_element (3): " << v << endl;  // v[3] is in its correct place;
	                                             // v[0..3] are the smallest 4 elements.
	cout << "4th-smallest element: " << v[3] << endl;

	partial_sort(begin(v), begin(v)+5, end(v));
	// partial_sort(begin(v), end(v)-5, end(v));
	// partial_sort(end(v)-5, end(v), end(v));
	cout << "partial_sort (5): " << v << endl;  // v[0..4] are in their correct place
	partial_sort(begin(v), begin(v)+5, end(v), greater<int>{});
	cout << "partial_sort (5, greater<int>): " << v << endl;  // v[0..4] are in their correct place
	
	reverse(begin(v), end(v));
	cout << "reverse (v): " << v << endl;
	reverse(begin(v)+2, begin(v)+6);
	cout << "reverse (v[2..6]): " << v << endl;

	array<int,10> a{11,13,15,17,19, 12,14,16,18,20};
	cout << "\nTwo sorted halves: " << a << endl;
	inplace_merge(begin(a), begin(a)+5, end(a));
	cout << "inplace_merge: " << a << endl;
}

