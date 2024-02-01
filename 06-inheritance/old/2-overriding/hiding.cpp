#include <iostream>
using namespace std;


struct A {
	virtual void f() {
		cout << "A::f" << endl;
	}
	virtual void f() const {
		cout << "A::f const" << endl;
	}
};

struct B: public A {
	void f() const {
		cout << "B::f const" << endl;
	}
};

struct C: public B {
	void f() {
		cout << "C::f" << endl;
	}
	void f() const {
		cout << "C::f const" << endl;
	}
};

int main() {
	A* ap1 = new A;   ap1->f();    // call-virtual f()  [runtime: calls A::f]
	A* ap2 = new B;   ap2->f();    // call-virtual f()  [runtime: calls A::f]
	A* ap3 = new C;   ap3->f();    // call-virtual f()  [runtime: calls C::f] 
	B* bp1 = new B;   bp1->f();    // call-static  B::f()const  
	B* bp2 = new C;   bp2->f();    // call-static  B::f()const  
	C* cp1 = new C;   cp1->f();    // call-virtual f()  [runtime: calls C::f] 
	return 0;
}
