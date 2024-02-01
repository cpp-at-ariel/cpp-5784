/**
 * Demonstrates the vector iterators
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<class T>
class iterable_printer {
	const T& the_iterable;
	public:
	iterable_printer(const T& x): the_iterable(x) {
		cout << "constructor " << endl;
	}
	void print() {
		for (auto item: the_iterable) {
			cout << item << " ";
		}
		cout << endl;
	}
};


int main() {
	vector<string> v1;

	// vector<int> v2(v1.begin(), v1.end());  // static assert

	auto v3 = vector({1,2,3,4});
	iterable_printer(v3).print();


	auto iter3 = v3.begin();
	*iter3 = 5;

	const vector<int> cv3;
	auto citer3 = cv3.begin();
	//*citer3 = 5;
}
