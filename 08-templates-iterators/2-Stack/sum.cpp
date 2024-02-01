/**
 * Illustrates how to call a sum function with iterators.
 * 
 * Author: Erel Segal-Halevi
 * Since: 2020-04
 */


#include <iostream>
#include <vector>
using namespace std;
// #include "sum.hpp"    // Writing this file is left as an exercise :-)

template<typename T,typename IT>
T sum(IT begin, IT end, T start) {
	T result = start;
	for(IT i=begin; i!=end; ++i) {
		result += (*i);
	}
	return result;
}


struct MyClass {
	MyClass& operator+=(const MyClass& other) {
		// do some adding...
		return *this;
	}
};

int main() {
	int arr[4] {1,2,3,4};
	cout << sum(begin(arr),end(arr),0) << endl;

	MyClass arr2[4];
	sum(begin(arr2), end(arr2), MyClass{});

	vector<string> v {"aa","bb","cc"};
	cout << sum(begin(v), end(v), string(""));
}
