/**
 * Demonstrates what happens when looping past the end of a container.
 * @author Erel Segal-Halevi
 * @since 2019-06
 */

#include <vector>
#include "output_containers.hpp"
using namespace std;

int main() {
	vector<int> v {1,2,4};
	auto i = v.begin();  cout << *i << endl;  // 1
	cout << " capacity == " << v.capacity() << endl;
	++i; cout << *i << endl; // 2
	++i; cout << *i << endl; // 4
	++i; cout << *i << endl; // undefined, but sometimes prints 0
	for (int j=0; j<1000; ++j) {
		cout << j << " ";
		++i; cout << *i << endl; // undefined, but sometimes prints 0
	}
}
