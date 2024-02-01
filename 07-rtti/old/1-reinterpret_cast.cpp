#include <iostream>
#include <iomanip>
using namespace std;


struct Shape {
	int i=555;
	void print() { cout << i << endl; }
};

struct Circle: public Shape {
	char c='a';
	void print() { cout << i << " " << c << endl; }
};

struct Unrelated {
	double d=1.234;
	void print() { cout << d << endl; }
};

/*
struct char8 {
	char c[8];
};
*/

int main()
{	
	{
		int i=5;   // 10100000 00000000 00000000 00000000 ???????? ???????? ???????? ????????

		int* ip = &i;
		double* dp = (double*)ip;
		double* ep = reinterpret_cast<double*>(ip);
		cout << "i interpreted as a double: " << setprecision(100) << *dp << " " << *ep << endl;        // junk junk

		double d = 5.555;
		int& ir = (int&)d;
		int& jr = reinterpret_cast<int&>(d);
		cout << "d interpreted as an int: " << ir << " " << jr << endl;        // junk junk
		cout << "---" << endl;
	}

	{
		Shape shape1;
		Circle circle1;
		//d = reinterpret_cast<Circle>(b); // compile error
		//b = reinterpret_cast<Shape>(d); //compile error

		Shape* pshape;
		Circle* pcircle;
		Unrelated* punrelated;

		pshape = reinterpret_cast<Shape*>(new Circle);
		pshape->print();  // OK
		pshape = reinterpret_cast<Shape*>(new Unrelated);
		pshape->print();  // junk

		cout << "---" << endl;

		pcircle = reinterpret_cast<Circle*>(pshape);  //  same junk
		pcircle->print();
		pcircle = reinterpret_cast<Circle*>(new Shape);  //  555 junk
		pcircle->print();
		pcircle = reinterpret_cast<Circle*>(new Unrelated);  // junk
		pcircle->print();
		cout << "---" << endl;

		punrelated = reinterpret_cast<Unrelated*>(new Shape); // junk
		punrelated->print();
		punrelated = reinterpret_cast<Unrelated*>(new Circle); // junk
		punrelated->print();
	}
}
