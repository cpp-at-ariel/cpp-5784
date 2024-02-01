/**
 * Demonstrates virtual overriding (dynamic/late binding)
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
	virtual void output(ostream& out) const {
		out << " Base:" << _vari;
	}
	virtual int f() const {}
private:
	int _vari;
};

class Derived : public Base
{
public:
	Derived() { }
	Derived(int i, int j) : _myObj(0), Base(i), _varj(j) {  }
	void output(ostream& out) const {  // This method is automatically virtual
		Base::output(out);
		out << " Derived:" << _varj;
	}
private:
	int _varj;
	MyClass _myObj;
};

int main()
{
	cout << endl << "---" << endl;
	Derived d1;
	d1.output(cout);
	cout << endl << "---" << endl;

	Derived d2(6, 8);
	d2.output(cout);
	cout << endl << "---" << endl;

	Base b1 = d1;
	b1.output(cout);
	cout << endl << "---" << endl;

	Base& b2 = d2;
	b2.output(cout);
	cout << endl << "---" << endl;

	Base* b2p = &d2;
	b2p->output(cout);
	cout << endl << "---" << endl;

	Base* b3p = new Derived(7,9);
	b3p->output(cout);
	cout << endl << "---" << endl;
}
