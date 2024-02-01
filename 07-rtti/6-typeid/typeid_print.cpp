#include <iostream>
#include <sstream>
#include <fstream>
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
		double& dr = d;
		cout << "typeid(d) = " << typeid(d).name() << endl;
		cout << "typeid(&d) = " << typeid(&d).name() << endl;
		cout << "typeid(dr) = " << typeid(dr).name() << endl;
		int i = (int)d;
		int& ir = i;
		cout << "typeid(i) = " << typeid(i).name() << endl;
		cout << "typeid(&i) = " << typeid(&i).name() << endl;
		cout << "typeid(ir) = " << typeid(ir).name() << endl;
	}

	{
		Shape1* bp1 = new Shape1;
		cout << "typeid(bp1) = " << typeid(bp1).name() << endl;
		cout << "typeid(*bp1) = " << typeid(*bp1).name() << endl;

		bp1 = new Circle1;
		cout << "typeid(bp1) = " << typeid(bp1).name() << endl;
		cout << "typeid(*bp1) = " << typeid(*bp1).name() << endl;
		
		Shape2* bp2 = new Shape2;
		cout << "typeid(bp2) = " << typeid(bp2).name() << endl;
		cout << "typeid(*bp2) = " << typeid(*bp2).name() << endl;

		bp2 = new Circle2;
		cout << "typeid(bp2) = " << typeid(bp2).name() << endl;
		cout << "typeid(*bp2) = " << typeid(*bp2).name() << endl;
		
	}
}
