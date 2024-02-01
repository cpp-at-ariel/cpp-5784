#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename T1, typename T2> 
struct pair {
	T1 first;
	T2 second;
};

pair<int,char> func() {
	return {2,'c'};
	// equivalent to:
	// return pair<int,char>{2,'c'};
}

template <typename T1, typename T2> 
ostream& operator<< (ostream& out, 
const pair<T1,T2>& thepair) {
	out << thepair.first << "," << thepair.second;
	return out;
}


int main() {
	pair<int,char> p1{1,'b'};
	auto p2 = func();
	// Equivalent to:
	// pair<int,char> p2 = func();
	cout << "p1=" << p1 << " p2=" << p2 << endl;
}
