/**
 * Demonstrates STL is_ and is_._until runes.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
using namespace std;


template<typename T> void print_vector_as_tree_recursive(ostream& out, const vector<T>& v, uint root=0, string prefix="") {
	if (root >= v.size())
		return;
	out << endl << prefix << v[root];
	print_vector_as_tree_recursive(out, v, 2*root+1, prefix+"--");
	print_vector_as_tree_recursive(out, v, 2*root+2, prefix+"--");
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
	copy(v.begin(), v.end(), ostream_iterator<T>(out," "));
	print_vector_as_tree_recursive(out, v, 0, "");
	cout << endl;
	return out;
}

template<typename T> ostream& operator<<(ostream& out, const deque<T>& v) {
	copy(v.begin(), v.end(), ostream_iterator<T>(out," "));
	return out;
}


int main() {
	cout << boolalpha;

	deque<int> v{4,6,8,5,2,0,3,1,9,7};   
	cout << "unsorted: " << v << endl;
	cout << "is_sorted: " << is_sorted(begin(v), end(v)) << endl;
	auto iter = is_sorted_until(begin(v), end(v));
	cout << "Number of sorted elements: " << (iter-begin(v)) << endl << endl;

	sort(begin(v), end(v));
	cout << "sorted: " << v << endl;
	cout << "is_sorted: " << is_sorted(begin(v), end(v)) << endl;
	iter = is_sorted_until(begin(v), end(v));
	cout << "Number of sorted elements: " << (iter-begin(v)) << endl << endl;

	cout << "Not a heap:" << endl;
	vector<int> v1{1,2,3,4,5,6,7,8,9};
	cout << "is_heap: " << is_heap(begin(v1), end(v1)) << endl;
	auto iter1 = is_heap_until(begin(v1), end(v1));
	cout << "Number of heap-like elements: " << (iter1-begin(v1)) << endl << endl;
	cout << v1 << endl;

	cout << "make_heap: " << endl;
	make_heap(begin(v1), end(v1));
	cout << "is_heap: " << is_heap(begin(v1), end(v1)) << endl;
	iter1 = is_heap_until(begin(v1), end(v1));
	cout << "Number of heap-like elements: " << (iter1-begin(v1)) << endl << endl;
	cout << v1 << endl;
}	
	

