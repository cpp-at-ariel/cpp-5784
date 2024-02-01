#include <iostream>
using namespace std;


// A polymorphic class hierarchy
struct Shape0 {
	double i=222;
	virtual void print() { cout << i << endl; }
};
struct Circle0: public Shape0 {
	char c='c';
	int a[100000];
	Circle0() { a[50000] = 50000; }
	void print() { cout << i << " " << c << endl; }
	//Circle0(Shape0 theBase): Shape0(theBase) { cout << "Conversion constructor" << endl;}
};
struct Square0: public Shape0 {
	char c='s';
	void print() { cout << i << " " << c << endl; }
};


// A non-polymorphic class hierarchy
struct Shape1 {
	int i=111;
	void print() { cout << i << endl; }
};
struct Circle1: public Shape1 {
	char c='a';
	void print() { cout << i << " " << c << endl; }
};
struct Square1: public Shape1 {
	char c='d';
	void print() { cout << i << " " << c << endl; }
};




int main()
{	
	{
		// Dynamic cast with pointers
		Shape0* sp0;
		Circle0* cp0;
		Shape1* sp1;
		Circle1* cp1;

		// Cast succeeds:
		sp0 = new Circle0;
		cout << "\nsp0 = " << sp0 << endl;
		sp0->print();
		// cout << sp0->c << endl; 
		cp0 = dynamic_cast<Circle0*>(sp0);    
		cout << "cp0 = " << cp0 << endl;
		cp0->print();
		cout << cp0->c << endl;

		// Cast fails:
		sp0 = new Square0;
		cout << "\nsp0 = " << sp0 << endl;
		sp0->print();
		// cout << sp0->c << endl; 
		cp0 = dynamic_cast<Circle0*>(sp0);    
		cout << "cp0 = " << cp0 << endl;
		//cp0->print();
		//cout << cp0->c << endl;

		// How to implement instanceof in C++?
		Shape0* sp0a = new Circle0;
		Shape0* sp0c = new Square0;
		if (Circle0* cp0a = dynamic_cast<Circle0*>(sp0a)) {
			cout << "sp0a points to a Circle0! a[50000]=" << cp0a->a[50000] << endl;
		} else {
			cout << "sp0a does NOT point to a Circle0! " << endl;
		}
		if (Circle0* cp0b = dynamic_cast<Circle0*>(sp0c)) {
			cout << "sp0b points to a Circle0! a[50000]=" << cp0b->a[50000] << endl;
		} else {
			cout << "sp0b does NOT point to a Circle0! " << endl;
		}


		sp1 = new Circle1;
		cout << "\nsp1 = " << sp1 << endl;
		sp1->print();
		// cp1 = dynamic_cast<Circle1*>(sp1);    // compile error: 'Shape1' is not polymorphic
	}

	{
		// Dynamic cast with references

		Shape0& sp0a = *new Circle0;
		Shape0& sp0b = *new Shape0;

		try {
			Circle0& cp0a = dynamic_cast<Circle0&>(sp0a);
			cout << "sp0a references a Circle0! " << endl;
		} catch (bad_cast e) {
			cout << "sp0a does NOT reference a Circle0! " << endl;
		}
		try {
			Circle0& cp0b = dynamic_cast<Circle0&>(sp0b);
			cout << "sp0b references a Circle0! " << endl;
		} catch (bad_cast e) {
			cout << "sp0b does NOT reference a Circle0! " << endl;
		}
	}
}
