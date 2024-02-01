#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const string foo() {return string();}

int main() {
	const string a = foo();
	string b = foo(); 
	const string& c = foo();
	// string& d  = foo();
}
