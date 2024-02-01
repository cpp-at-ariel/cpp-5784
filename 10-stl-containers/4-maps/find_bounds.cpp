/**
 * Demonstrates iteration on stl maps
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <map>
#include <iostream>
using namespace std;

int main() {
	multimap<string, int> m {
		{"abc", 2},
		{"def", 4},
		{"xyz", 6},
		{"abc", 22},
		{"def", 44},
		{"xyz", 66},
	};
	// m["abc"]=222;

	for (auto [k,v]: m)
		cout << k << "," << v << endl;
	cout << endl;

	auto iter = m.find("abc");
	cout <<  "find: " << iter->first << "," << iter->second << endl;
	cout <<  "count: " << m.count("abc") << endl;

	auto begin_abc = m.lower_bound("abc");
	cout << "lower_bound: " << begin_abc->first << "," << begin_abc->second << endl;

	auto end_abc = m.upper_bound("abc");
	cout << "upper_bound: " << end_abc->first << "," << end_abc->second << endl;

	cout << endl << "all abc in multimap: " << endl;
	for (auto i=begin_abc; i!=end_abc; ++i) 
		cout << i->first << "," << i->second << endl;
}
