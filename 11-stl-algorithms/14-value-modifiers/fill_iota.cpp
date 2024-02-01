/**
 * Demonstrates STL fill and iota algorithms.
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

	Person& operator++() {
		age++;
		return *this;
	}
};


int main() {
	vector<int> v(10);
	cout << "v: " << v << endl;
	fill(begin(v), end(v), 42);
	cout << "fill(42): " << v << endl;
	iota(begin(v), end(v), 42);
	cout << "iota(42): " << v << endl << endl;

	vector<char> vc(10);
	fill(begin(vc), end(vc), 'b');
	cout << "fill(b): " << vc << endl;
	iota(begin(vc), end(vc), 'b');
	cout << "iota(b): " << vc << endl;

	// iota(ostream_iterator<int>(cout), ostream_iterator<int>{}, 52);

	vector<Person> vp(10);
	iota(begin(vp), end(vp), Person{42});
	cout << vp[2].age << endl;
}

