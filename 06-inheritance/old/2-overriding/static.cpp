/**
 * Demonstrates non-virtual overriding (static/early binding)
 */

#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass() {  }
	MyClass(int x) {  }
	~MyClass() {  }
};


class Base
{
public:
	Base() : _vari(999) {  }
	Base(int i) : _vari(i) { }
	void output(ostream& out) {
		out << " Base:" << _vari;
	}
private:
	int _vari;
};

class Derived : public Base
{
public:
	Derived() { }
	Derived(int i, int j) : _myObj(0), Base(i), _varj(j) {  }
	void output(ostream& out) {
		Base::output(out);
		out << " Derived:" << _varj;
	}
private:
	int _varj;
	MyClass _myObj;
};


Base operator-(const Base& b) {
	return Base(-5);
}

Derived operator-(const Derived& b) {
	return Derived(-7,-9);
}


int main()
{
	cout << endl << "---" << endl;
	Derived d1;  // calls default ctor of Base (inits i) and Derived (does not init j)
	d1.output(cout);
	cout << endl << "---" << endl;

	Derived d2(6, 8);
	d2.output(cout);
	cout << endl << "---" << endl;

	// Object slicing:
	Base b1 = d1;  // calls copy ctor of Base with d1.[Base]
	b1.output(cout);
	cout << endl << "---" << endl;

	Base* b2p = &d2;
	b2p->output(cout);
	cout << endl << "---" << endl;

	Base& b2 = d2;
	b2.output(cout);
	cout << endl << "---" << endl;

	Base* b3p = new Derived(7,9);
	b3p->output(cout);
	cout << endl << "---" << endl;

	Base b10(10);
	(-b10).output(cout);
	cout << endl << "---" << endl;
	Derived d10(10,20);
	(-d10).output(cout);
}
