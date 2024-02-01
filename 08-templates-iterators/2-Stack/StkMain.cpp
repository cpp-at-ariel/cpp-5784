#include "Stk.hpp"

#include <string>
#include <iostream>
#include <vector>
using namespace std;


int main() {
	/*** A stack of strings ***/

	Stk<string>  strStk;
	strStk.push(string("world !\n"));
	strStk.push(string("Hello "));

	while(!strStk.isEmpty()) {
		cout << strStk.top();
		strStk.pop();
	}
	
	strStk.push(string("world !\n"));
	strStk.push(string("Hello "));
	// Old C++ style
	auto e = strStk.end();
	for (
		auto it = strStk.begin(); 
		// Stk<string>::iterator it = strStk.begin(); 
		it!=e; 
		++it
		)
	{
		const string& val = *it;
		cout << it->size() << " ";
		cout << *it;
	}

	// C++-11 style
	for (const string& val: strStk) {
		cout << val.size() << " ";
		cout << val;
	}

	/*** A stack of ints ***/

	int arr[]= {43, 21, -22};

	// Calling templated ctor, old C++ style
	Stk<int> intStk(arr, arr+3);
	for (const auto& val: intStk) {
		cout << val << " ";
	}
	cout << endl;

	// Calling templated ctor, C++-11 style
	Stk<int> intStk2(begin(arr), end(arr));
	for (const auto& val: intStk2) {
		cout << val << " ";
	}
	cout << endl;

	Stk<int> intStk3 (begin(intStk), end(intStk));
	for (const auto& val: intStk3) {
		cout << val << " ";
	}
	cout << endl;

	vector<int> v {1,2,3,4};
	Stk<int> intStk4 (rbegin(v), rend(v));
	for (const auto& val: intStk4) {
		cout << val << " ";
	}

	return 0;
}
