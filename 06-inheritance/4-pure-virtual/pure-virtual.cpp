#include <iostream>
using namespace std;

struct A {
	virtual void f() = 0;
};

// void A::f() {
// 	cout << "A::f" << endl;
// }

struct B: public A {
	virtual void g() {}
};

struct C: public B {
	void f() {
		cout << "C::f" << endl;
	};
};


int main(){
	// A a; a.f();
	// B b;
	C c;
	A* a = &c;
	a->f();
}
