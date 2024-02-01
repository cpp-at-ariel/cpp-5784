#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>

using namespace std;

struct Complex {
	double re, im;

	Complex(double re, double im): re(re), im(im) {}
};

ostream& operator<< (ostream& os, const Complex& c) {
	os << c.re << "+" << c.im << "i";
	return os;
}

istream& operator>> (istream& is, Complex& c) {
	char d;
	is >> c.re >> d >> c.im >> d;
	return is;
}

string to_string(const Complex& c) {
	ostringstream s;
	s << c;
	return s.str();
}

int main() {
	ostringstream sout;
	Complex c{2,3};

	sout << 1 << " " << c << " ";
	assert(sout.str().compare("1 2+3i ")==0);
	cout << sout.str() << endl;

	ofstream fout("abc.txt");
	fout << 1 << " " << c << endl;

	ifstream fin("abc.txt");
	int k1;
	Complex c1{0,0};
	fin >> k1 >> c1;
	cout << " k1=" << k1 << " c1=" << c1 <<endl; 


	stringstream sinout("12 b aa");
	int i, j; string a; 
	cout << "state before: " << (sinout.rdstate()) << endl;
	cout << "tellg before: " << (sinout.tellg()) << endl;
	sinout >> i >> a >> j;
	cout << "state after: " << (sinout.rdstate()) << endl;
	cout << (sinout? "good": "bad") << endl;
	cout << (!sinout? "bad": "good") << endl;
	sinout.clear();
	cout << "tellg after: " << (sinout.tellg()) << endl;
	// if (!sinout) throw runtime_error("bad input");
	cout << (sinout? "good": "bad") << endl;
	cout << (!sinout? "bad": "good") << endl;
	cout << "i = " << i << endl;
	cout << "a = " << a << endl;
	cout << "j = " << j << endl;
	cout << sinout.str() << endl;
	sinout << "efg";
	cout << sinout.str() << endl;

	stringstream s3("12 a, bcd\n34 b def\n56 C DFE");
	char buffer[200];
	s3.getline(buffer, 200);
	//cin.getline(buffer, 200, ',');
	cout << "first line is " << buffer << endl;
//	cout << "line1 = " << line1 << endl;

	return 0;
}
