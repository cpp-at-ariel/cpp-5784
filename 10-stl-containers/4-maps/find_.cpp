/**
 * Demonstrates maps.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <iostream>
#include <map>
using namespace std;

int main() {
	cout << boolalpha;
	map<string,int> m1;

	m1["abc"] = 300;
	cout << "m1[abc]=" << m1["abc"] << endl;
	cout << "m1[def]=" << m1["def"] << endl;

	cout << (m1.count("abc")) << endl;
	cout << (m1.count("def")) << endl;
	cout << (m1.count("xyz")) << endl;

	cout << (m1.find("abc")!=m1.end()) << endl;
	cout << (m1.find("def")!=m1.end()) << endl;
	cout << (m1.find("xyz")!=m1.end()) << endl;

	// In C++ 20:
	// cout << (m1.contains("abc")) << endl;
	// cout << (m1.contains("def")) << endl;
	// cout << (m1.contains("xyz")) << endl;


	auto find_abc = m1.find("abc");
	//find_abc->first = string("abd"); // const
	auto at_find_abc = *find_abc;
	cout << "key=" << at_find_abc.first << " value=" << at_find_abc.second << endl;
	find_abc->second = 500;
	cout << "m1[abc]=" << m1["abc"] << endl;

	// cout << m1.at("xyz") << endl;  // throws exception
	// cout << m1["xyz"] << endl;  
}
