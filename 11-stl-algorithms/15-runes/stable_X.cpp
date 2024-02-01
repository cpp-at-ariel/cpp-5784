/**
 * Demonstrates STL partition vs. stable_partition, and sort vs. stable_sort.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <array>
#include "output_containers.hpp"
using namespace std;


struct Person {
	string name;
	int age;
};
ostream& operator<<(ostream& out, const Person& p) {
	return out << "(" << p.name << "," << p.age << ")";
}


int main() {
	vector<Person> v1{
		{"a", 10},
		{"b", 20},
		{"c", 15},
		{"d", 17},
		{"e", 20},
		{"f", 10},
		{"g", 15},
		{"h", 17},
		{"i", 17},
		{"j", 17},
	};
	auto v2 = v1;
	cout << "original vector: " << v1<< endl;

	auto middle = partition(begin(v1), end(v1), [](Person x){return x.age%2==0;});
	cout << "_      partition to even age vs. odd age: " << v1 << endl;

	middle = stable_partition(begin(v2), end(v2), [](Person x){return x.age%2==0;});
	cout << "stable_partition to even age vs. odd age: " << v2 << endl;

	sort(begin(v1), end(v1), [](Person p1, Person p2) {return p1.age<p2.age;}); // sort by increasing age
	cout << ".      sort by age: " << v1 << endl;

	stable_sort(begin(v2), end(v2), [](Person p1, Person p2) {return p1.age<p2.age;}); // sort by increasing age
	cout << "stable_sort by age: " << v2 << endl;

	// NOTE: with clang++ (5 and 9), there is no apparent difference between sort and stable_sort.
}

