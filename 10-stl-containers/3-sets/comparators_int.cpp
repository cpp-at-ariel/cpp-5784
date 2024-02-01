/**
 * Demonstrates how to define and use different comparators.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;




/**
 * This is a comparator for ordering elements from large to small
 * (instead of the default which is from small to large).
 */
struct SederYored {
	bool operator()(int x, int y) const {
		return y<x;
	}
};

/**
 * This is a comparator for ordering the even elements first, and then the odd elements.
 * In each group, elements are arranged from small to large.
 */
struct ZugiIzugi {
	bool operator()(int x, int y) const {
		if (x%2==0 && y%2!=0)
			return true;
		if (x%2!=0 && y%2==0)
			return false;
		else //  (x%2 == y%2)
			return x<y;
	}
};


bool yored;

struct UserDefinedOrder {
	UserDefinedOrder() {  }
	bool operator()(int x, int y) const {
		return yored? x>y: x<y;
	}
};



int main() {
	// Demonstrate two kinds of comparison functors:
	SederYored compare;
	cout << boolalpha << compare(5,4) << endl;

	auto seder_yored = [] (int a, int b) {return a>b;};
	cout << seder_yored(5,4)  << endl;

	// Demonstrate using comparison functors in sets:
	// set<int> s1;
	// set<int,SederYored> s1;
	// set<int,decltype(seder_yored)> s1 (seder_yored);

	// set<int, less<int> > s1;  // default
	// set<int, greater<> > s1;
	// set<int,ZugiIzugi> s1 {1,2,4,6};


	set<int, UserDefinedOrder> s1;

	yored = false;
	s1.emplace(5);
	s1.emplace(7);
	s1.emplace(3);
	s1.emplace(5);
	s1.emplace(7);
	s1.emplace(3);
	for (auto s: s1)
		cout << s << endl;
	cout << endl;

	// yored = true;
	// s1.clear();
	// s1.emplace(2);
	// s1.emplace(4);
	// s1.emplace(6);
	// s1.emplace();
	// for (auto s: s1)
	// 	cout << s << endl;

}
