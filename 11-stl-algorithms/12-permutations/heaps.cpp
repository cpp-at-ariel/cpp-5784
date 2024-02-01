/**
 * Demonstrates STL heap algorithms.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <array>
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

template<typename T, size_t N> ostream& operator<<(ostream& out, const array<T,N>& v) {
	copy(v.begin(), v.end(), ostream_iterator<T>(out," "));
	print_vector_as_tree_recursive(out, v, 0, "");
	cout << endl;
	return out;
}


int main() {
	cout << "A heap:" << endl;
	vector<int> v{9,8,6,7,4,5,2,0,3,1};
	cout << v << endl;

	cout << "Not a heap:" << endl;
	vector<int> v1{1,2,3,4,5,6,7,8,9};
	cout << v1 << endl;

	cout << "make_heap: " << endl;
	make_heap(begin(v1), end(v1));
	cout << v1 << endl;

	v1.push_back(10);
	cout << "After push_back - not a heap:" << v1 << endl;
	push_heap(begin(v1), end(v1));
	cout << "push_heap: " << v1 << endl;


	pop_heap(begin(v1), end(v1));
	cout << "pop_heap: " << v1 << endl;
	cout << "popped maximum element: " << v1.back() << endl;
	v1.pop_back();
	cout << "After pop_back: " << v1 << endl;

	sort_heap(begin(v1), end(v1));
	cout << "sort_heap: " << v1 << endl;

	cout << "make_heap with comparator: " << endl;
	make_heap(begin(v1), end(v1), [](int a, int b){return a>b;});
	make_heap(begin(v1), end(v1), greater<int>{});  // equivalent
	cout << v1 << endl;
}

