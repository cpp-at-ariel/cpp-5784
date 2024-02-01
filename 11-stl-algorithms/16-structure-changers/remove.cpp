/**
 * Demonstrates STL remove algorithm.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include <array>
#include "output_containers.hpp"
using namespace std;


struct Person {
	int age;
	Person(int age) {cout << "constructing " << age << endl; this->age=age;}
	Person(const Person& other) {cout << "copying " << other.age << endl; this->age=other.age;}
	Person& operator=(const Person& other) {cout << "operator= " << this->age << " -> " << other.age << endl; this->age=other.age; return *this;}
	~Person() { cout << "destructing " << age << endl; }
};

ostream& operator<< (ostream& out, const Person& person) {
	return (out << "Person(" << person.age<< ")" << " ");
}

bool operator==(const Person& person1, const Person& person2) {
	return (person1.age==person2.age);
}


int main() {
	vector<Person> v {11,8,4,6,11,9,3,5,11,6};
	cout << "v: " << v << endl;
	auto new_end = remove(begin(v), end(v), Person{11});
	cout << "v after remove 11: " << v << endl;
	v.erase(new_end, end(v));
	cout << "v after erase: " << v << endl<<endl;

	// One line:
	// v.erase(remove(begin(v), end(v), 11), end(v));

	vector<int> v1  {11,8,4,6,11,9,3,5,11,6};
	vector<int> v2 = v1;
	vector<int> v3;
	remove_copy(begin(v1), end(v1), back_inserter(v3), 11);
	cout << "v1 after remove_copy: " << v1 << endl;
	cout << "v3 after remove_copy: " << v3 << endl<<endl;

	remove_copy(begin(v2), end(v2), ostream_iterator<int>{cout,";"}, 11);
	cout << endl;

	v2.erase(remove_if(begin(v2), end(v2), [](int a){return a%2==0;}), v2.end());
	cout << "v2 after removing and erasing even numbers: " << v2 << endl << endl; 
	v3.clear();
	remove_copy_if(
		begin(v1), end(v1),  
		back_inserter(v3), 
		[](int a){return a%2==0;});
	cout << "v1 after remove_copy_if: " << v1 << endl;
	cout << "v3 after remove_copy_if: " << v3 << endl<<endl;
}

