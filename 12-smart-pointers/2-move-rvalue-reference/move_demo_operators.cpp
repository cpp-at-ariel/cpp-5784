/**
 * Demonstrates the difference between lvalue and rvalue-reference,
 * and between copy-semantics and move-semantics.
 * 
 * Author: Erel Segal-Halevi
 * Since:  2020-06
 * 
 * For more details see https://stackoverflow.com/a/3109981/827927 by Fred Overflow
 */

#include <iostream>
using namespace std;

class Test {
public:
	Test() = default;
	Test(int i) { cout << "conversion from int" << endl; }
	Test& operator=(const Test& other) {
		cout << "deep copy" << endl;
		return *this;
	}
	Test& operator=(Test&& other) {
		cout << "shallow copy (should nullify other)" << endl;
		return *this;
	}
};

Test make_test() {
	return Test{};
}


int main() {
	Test x;
	Test y;

	y = x;
	y = Test{};
	y = make_test();
	y = move(make_test());
	y = move(x);

	int i;
	y = i;
}
