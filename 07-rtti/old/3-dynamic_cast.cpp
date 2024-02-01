#include <iostream>
using namespace std;

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


struct Shape2 {
	double i=222;
	virtual void print() { cout << i << endl; }
};
struct Circle2: public Shape2 {
	char c='b';
	int a[100000];
	Circle2() { a[50000] = 50000; }
	void print() { cout << i << " " << c << endl; }
	//Circle2(Shape2 theBase): Shape2(theBase) { cout << "Conversion constructor" << endl;}
};
struct Square2: public Shape2 {
	char c='c';
	void print() { cout << i << " " << c << endl; }
};



int main()
{	
	{
		double d=12.45;
		int i = (int)d;
		//int j = dynamic_cast<int>(d);  // compile error
		//cout << i << " " << j << endl;

		//double f = dynamic_cast<double>(i); // compile  error: 'double' is not a reference or pointer
		//cout << e << " " << f << endl;

		double* dp = &d;
		//int* jp = dynamic_cast<int*>(dp); // compile error:  'int' is not a class.
		//cout << *ip << " " << endl;        // garbage
	}

	{
		// Dynamic cast with pointers

		Shape1* bp1;
		Circle1* dp1;
		Shape2* bp2;
		Circle2* dp2;

		bp1 = dynamic_cast<Shape1*>(new Circle1);    // OK, like static_cast
		bp1 = new Circle1;    // OK, like static_cast
		Shape1* bp1b = new Square1;

		cout << "bp1 = " << bp1 << endl;
		bp1->print();
		// dp1 = dynamic_cast<Circle1*>(new Shape1);    // compile error: 'Shape1' is not polymorphic
		//cout << "dp1 = " << dp1 << endl;
		//dp1->print();

		bp2 = new Circle2;    
		cout << "bp2 = " << bp2 << endl;
		bp2->print();
		dp2 = dynamic_cast<Circle2*>(new Shape2);    // OK, returns null
		cout << "dp2 = " << dp2 << endl;
		//dp2->print();   // segmentation fault

		bp1 = dynamic_cast<Shape1*>(new Shape2);    // OK, returns null
		cout << "bp1 = " << bp1 << endl;
		dp1 = dynamic_cast<Circle1*>(new Shape2);    // OK, returns null
		cout << "dp1 = " << dp2 << endl;

		// How to implement instanceof in C++?
		Shape2* bp2a = new Circle2;
		Shape2* bp2c = new Square2;

		//Circle2 dp5 = *bp2a;

		if (Circle2* dp2a = dynamic_cast<Circle2*>(bp2a)) {
			cout << "bp2a points to a Circle2! a[50000]=" << dp2a->a[50000] << endl;
		} else {
			cout << "bp2a does NOT point to a Circle2! " << endl;
		}
		if (Circle2* dp2b = dynamic_cast<Circle2*>(bp2c)) {
			cout << "bp2b points to a Circle2! a[50000]=" << dp2b->a[50000] << endl;
		} else {
			cout << "bp2b does NOT point to a Circle2! " << endl;
		}
		// if (Circle2* dp2b = reinterpret_cast<Circle2*>(bp2c)) {
		// if (Circle2* dp2b = (Circle2*)(bp2c)) {
		// 	cout << "bp2b points to a Circle2! a[50000]=" << dp2b->a[50000] << endl;
		// } else {
		// 	cout << "bp2b does NOT point to a Circle2! " << endl;
		// }
	}
	{
		Shape1* bp1a = new Circle1;
		Shape1* bp1b = new Shape1;

		// if (Circle1* dp1a = dynamic_cast<Circle1*>(bp1a)) {
		// 	cout << "bp1a points to a Circle1! " << endl;
		// } else {
		// 	cout << "bp1a does NOT point to a Circle1! " << endl;
		// }
	}

	{
		// Dynamic cast with references

		
		Shape1& bp1 = dynamic_cast<Shape1&>(*new Circle1);    // OK, like static_cast
		bp1.print();
		// Circle1& dp1 = dynamic_cast<Circle1&>(*new Shape1);    // compile error: 'Shape1' is not polymorphic
		Shape2& bp2 = dynamic_cast<Shape2&>(*new Circle2);    // OK, like static_cast
		bp2.print();

		//Circle2& dp2 = dynamic_cast<Circle2&>(*new Shape2);    // Runtime error: std::bad_cast
		//dp2.print();

		// bp1 = dynamic_cast<Shape1*>(new Shape2);    // OK, returns null
		// cout << "bp1 = " << bp1 << endl;
		// dp1 = dynamic_cast<Circle1*>(new Shape2);    // OK, returns null
		// cout << "dp1 = " << dp2 << endl;

		// How to implement instanceof in C++?
		Shape2& bp2a = *new Circle2;
		Shape2& bp2b = *new Shape2;

		try {
			Circle2& dp2a = dynamic_cast<Circle2&>(bp2a);
			cout << "bp2a references a Circle2! " << endl;
		} catch (bad_cast e) {
			cout << "bp2a does NOT reference a Circle2! " << endl;
		}
		try {
			Circle2& dp2b = dynamic_cast<Circle2&>(bp2b);
			cout << "bp2b references a Circle2! " << endl;
		} catch (bad_cast e) {
			cout << "bp2b does NOT reference a Circle2! " << endl;
		}
	}
}
