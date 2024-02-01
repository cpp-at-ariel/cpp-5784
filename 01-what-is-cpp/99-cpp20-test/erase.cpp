/**
 * Testing the std::erase function, which was added in C++ 20.
 * Date: 2021-03
 */

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s = "a b c d ";
	std::erase(s, ' ');                                 // c++20
	cout << s << endl;

	s = "a b c d ";
	s.erase(remove(s.begin(),s.end(), ' '), s.end());   // c++11
	cout << s << endl;

	// s = "a b c d ";
	// s.erase(' ');   // run-time error
	// cout << s << endl;
}
