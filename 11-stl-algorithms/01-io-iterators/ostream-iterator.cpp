/**
 * Demonstrates IO iterators with STL containers.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

template<typename T> ostream& operator<<(ostream& out, const set<T>& container) {
	copy(container.begin(), container.end(), 
		ostream_iterator<T>(out,"; "));
	return out;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& container) {
	copy(container.begin(), container.end(), 
		ostream_iterator<T>(out,"; "));
	return out;
}

int main() {
	// example of ostream_iterator:
	ostream_iterator<double> my_ostream_iterator(cout,"---");
	for (double i=0; i<10; ++i) {
		(*my_ostream_iterator) = i; // cout << i << "---";
		//double x = (*my_ostream_iterator); // compile error
		++my_ostream_iterator;
	}
	//cout << v0 << endl;
	cout << endl;

	// example of copy:
	set<int> s1 = {1,7,3,5};
	cout << "s1: " << s1 << endl;
	vector<int> v1(4);
	copy(s1.begin(), s1.end(), v1.begin());
	cout << "v1: " << v1 << endl;

	// example of copy + ostream_iterator
	set<int> s2 = {1,7,3,55};
	cout << "s2: " << s2 << endl;
	copy(s2.begin(), s2.end(), ostream_iterator<int>(cout,"###"));
	//copy(ostream_iterator<int>(cout,"###"), ostream_iterator<int>(cout,"###"), s2.begin());
	cout << endl;
}
