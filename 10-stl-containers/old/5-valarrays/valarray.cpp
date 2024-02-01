#include <valarray>
#include <iostream>
using namespace std;


int main() {
	valarray a {1,2,3};
	valarray b {4,5,6};
	valarray c = a+b;
	// cout << c << endl;
	cout << c[0] << "," << c[1] << "," << c[2] << endl;
}
