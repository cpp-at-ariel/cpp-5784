#include <iostream>
using namespace std;


struct char8 {
	char c[8];

	// operator int() {return 5;}
};


int main() {
	double d=12.45;
	int i = (int)d;               // C-style
	int j = static_cast<int>(d);  // C++-style
	cout << "d casted as an int: " << i << " " << j << endl;

	double e = (double)i;
	double f = static_cast<double>(i);
	cout << "i casted as a double: " << e << " " << f << endl;

	char8 c;

	// These require a conversion operator:	
	// int ic = static_cast<int>(c);
	// double dc = static_cast<double>(c);

	// These do not compile at all:
	// double* pd = static_cast<double*>(&i);   
	// int* pi = static_cast<double*>(&d);
}
