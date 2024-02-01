/**
 * Demonstrates multiple inheritance.
 * 
 * @author Erel Segal-Halevi
 * @since 2020
 */

#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass() { cout << "MyClass:default\n"; }
	MyClass(int x) { cout << "MyClass::int\n"; }
	~MyClass() { cout << "MyClass dtor\n"; }
	int myint() const { return 999; }
	int vari() const { return 999; }
};

class OtherClass
{
public:
	OtherClass() { cout << "OtherClass:default\n"; }
	OtherClass(int x) { cout << "OtherClass::int\n"; }
	~OtherClass() { cout << "OtherClass dtor\n"; }
};


class Base
{
public:
	// Base() : _vari(0) { cout << "Base::default\n"; }
	Base(int i) : _vari(i) { cout << "Base: int\n"; }
	~Base() { cout << "Base dtor\n"; }
	int baseint() const { return 111; }
	int vari() const { return _vari; }
private:
	int _vari;
};

class Derived : public Base, public MyClass
{
public:
	Derived(): _otherObj(), _myObj(), Base(2) { cout << "Derived::default\n"; }
	Derived(int i, int j): _myObj(0), Base(i), _varj(j) { cout << "Derived:: int int\n"; }
	~Derived() { cout << "---\nDerived dtor\n"; }
	int vari2 () const { return MyClass::vari(); }
private:
	int _varj;
	MyClass _myObj;
	OtherClass _otherObj;
};

int main()
{
	cout << "---" << endl;
	Derived d1;

	cout << "d1.myint() = " << d1.myint() << endl;
	cout << "d1.myint() = " << d1.baseint() << endl;
	cout << "d1.vari2() = " << d1.vari2() << endl;

	// cout << "d1.vari() = " << d1.vari() << endl;
	cout << "d1.Base::vari() = " << d1.Base::vari() << endl;
	cout << "d1.MyClass::vari() = " << d1.MyClass::vari() << endl;


	cout << "---" << endl;
	Derived d2(6, 8);

	Base b1    = d1;  // slicing of Base
	MyClass c1 = d1;  // slicing of MyClass
	cout << "---" << endl;
}