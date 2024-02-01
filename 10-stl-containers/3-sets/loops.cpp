/**
 * Demonstrates iteration on stl sets
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <set>
#include <iostream>
using namespace std;

int main() {
	set<string> m {
		{"abc"},
		{"xyz"},
	};
	m.insert("def");
	m.insert("ghi");

	// Old version:
	for (set<string>::iterator iter = m.begin(); iter!=m.end(); ++iter)
		cout << *iter << endl;	
	cout << endl;

	// C++11 version:
	for (const auto& val: m)
		cout << val << endl;
	cout << endl;

}
