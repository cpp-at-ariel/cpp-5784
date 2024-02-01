#include <iostream>
#include <iomanip>
using namespace std;


struct char8 {
	char c[8];
};


int main() {	
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

	char8* cp = reinterpret_cast<char8*>(&d);
	cout << "d interpreted as chars: ";
	for (i=0; i<8; ++i)
		cout << cp->c[i];

	// double dd = reinterpret_cast<double>(i);
	// int ii    = reinterpret_cast<int>(d);
}
