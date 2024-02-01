#include <iostream>
using namespace std;


struct Shape {
	int i=555;
	int j;
	void print() { cout << i << endl; }
};

struct Unrelated {
	double d=666.0;
	void print() { cout << d << endl; }
};

struct Circle: public Shape {
	float f=56.78;
	void print() { cout << i << " " << f << endl; }
	// operator Unrelated() { return Unrelated{}; }
};



int main()
{	
	{
		double d=12.45;
		int i = (int)d;               // C-style
		int j = static_cast<int>(d);  // C++-style
		cout << i << " " << j << endl;

		double e = (double)i;
		double f = static_cast<double>(i);
		cout << e << " " << f << endl;

		double* pcircle = &d;
		int* ip = (int*)pcircle;
		//int* jp = static_cast<int*>(pcircle); // compiler error: "static_cast from 'double *' to 'int *' is not allowed"
		cout << *ip << " " << endl;        // junk
	}

	{
		Shape shape1;
		Circle circle1;
		// circle1 = static_cast<Circle>(shape1); // compile error
		// Unrelated u = static_cast<Unrelated>(circle1); // compile error
		shape1 = static_cast<Shape>(circle1); // OK - slicing

		Shape* pshape;
		Circle* pcircle;
		Unrelated* punrelated;

		pshape = static_cast<Shape*>(new Circle);
		//pshape = static_cast<Shape*>(new Unrelated);  // compile error
		pshape->print();

		pcircle = static_cast<Circle*>(pshape);  //  OK
		pcircle->print();
		pcircle = static_cast<Circle*>(new Shape);  //  junk
		pcircle->print();
		//pcircle = static_cast<Circle*>(new Unrelated);  // compile error

		//punrelated = static_cast<Unrelated*>(new Shape); // compile error
		//punrelated = static_cast<Unrelated*>(new Circle); // compile error
	}
}
