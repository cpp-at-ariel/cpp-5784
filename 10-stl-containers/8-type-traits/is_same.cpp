#include <type_traits>
#include <iostream>
using namespace std;



template<class T1, class T2>
bool is_almost_same_v = std::is_same_v<const T1&,const T2&>;



int main() {
	cout << boolalpha;
	cout << "is_same" << endl;
	cout << is_same_v<char,int> << endl;    // false
	cout << is_same_v<char,char> << endl;   // true
	cout << is_same_v<char,char&> << endl;   // false
	cout << is_same_v<char,const char> << endl;  // false
	cout << is_same_v<char,const char&> << endl; // false

	cout << "is_almost_same" << endl;
	cout << is_almost_same_v<char,int> << endl;    // false
	cout << is_almost_same_v<char,char> << endl;   // true
	cout << is_almost_same_v<char,char&> << endl;   // false
	cout << is_almost_same_v<char,const char> << endl;  // true
	cout << is_almost_same_v<char,const char&> << endl; // true
}
