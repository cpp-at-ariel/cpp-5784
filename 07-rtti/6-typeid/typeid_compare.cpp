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


int main() {
		cout << boolalpha;  // a manipulator to print boolean values as strings.

		cout << "Non-polymorphic types:" << endl;
		Shape1* ps1 = new Shape1;
		Shape1* pc1 = new Circle1;
		cout << (typeid(ps1)==typeid(pc1)) << endl;     // true - both are Shape1*
		cout << (typeid(*ps1)==typeid(*pc1)) << endl;   // true - both are Shape1, since it is not polymorphic
		cout << (typeid(ps1)==typeid(Shape1)) << endl;  // false - ps1 is Shape1* and not Shape1
		cout << (typeid(ps1)==typeid(Shape1*)) << endl;  // true
		cout << (typeid(*ps1)==typeid(Shape1)) << endl;  // true
		cout << (typeid(*pc1)==typeid(Shape1)) << endl;  // true - since it is not polymorphic
		cout << (typeid(*pc1)==typeid(Circle1)) << endl; // false - since it is not polymorphic 


		cout << "Polymorphic types:" << endl;
		Shape2* ps2 = new Shape2;
		Shape2* pc2 = new Circle2;
		cout << (typeid(ps2)==typeid(pc2)) << endl;     // true - both are Shape1*
		cout << (typeid(*ps2)==typeid(*pc2)) << endl;   // false - Shape2 is not Circle2 - they are polymorphic
		cout << (typeid(ps2)==typeid(Shape2)) << endl;  // false - it is Shape2* and not Shape2
		cout << (typeid(ps2)==typeid(Shape2*)) << endl;  // true
		cout << (typeid(*ps2)==typeid(Shape2)) << endl;  // true
		cout << (typeid(*pc2)==typeid(Shape2)) << endl;  // false - since it is polymorphic
		cout << (typeid(*pc2)==typeid(Circle2)) << endl; // true - since it is  polymorphic 
}
