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

void f(int& i) {
	cout << "by reference" << endl;
}

void f(const int& i) {
	cout << "by const reference" << endl;
}

void f(int&& i) {
	cout << "by rvalue reference" << endl;
}


int main() { 
	int x;
	const int y = 5;

	cout << "f(x): ";
	f(x);

	cout << "f(y): ";
	f(y);

	cout << "f(x+y): ";
	f(x+y);

	cout << "f(move(x)): ";
	f(move(x));

	cout << "f(move(y)): ";
	f(move(y));

	cout << "f(move(x+y)): ";
	f(move(x+y));
}
