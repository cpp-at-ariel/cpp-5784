/**
 * Demonstrates iteration on stl maps
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <map>
#include <iostream>
using namespace std;

map<string, int> m {
	{"abc", 2},
	{"xyz", 8},
};

int main() {
	m["def"] = 4;
	m["ghi"] = 6;

	// Old version:
	for (map<string, int>::iterator iter = m.begin(); iter!=m.end(); ++iter) 
		cout << iter->first << "," << iter->second << endl;	
	cout << endl;

	// C++11 version:
	for (const auto& pair: m) 
		cout << pair.first << "," << pair.second << endl;	
	cout << endl;

	// C++17 version:
	for (auto [key,value]: m)
		cout << key << "," << value << endl;	
	cout << endl;
}
