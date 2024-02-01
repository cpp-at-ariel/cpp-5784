/**
 * Demo of the quotes operator / suffix operator.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
using namespace std;


int operator"" _h(const unsigned long long hours) {
	return hours*3600;
}

int operator"" _m(unsigned long long minutes) {
	return minutes*60;
}

int operator"" _s(unsigned long long seconds) {
	return seconds;
}

int operator ""_aaa(unsigned long long x) {
	return x*111;
}



class Complex {
	double _re, _im;
public:
	Complex(double re, double im=0): _re(re), _im(im) {
		cout << "constructing complex(" << re << "," << im << ")"<<endl;
	}
    friend ostream& operator<< (ostream& os, const Complex& c);
    friend const Complex operator+ (const Complex& c1, const Complex& c2);
	friend const Complex operator+ (double r, const Complex& c2);
};


ostream& operator<< (ostream& os, const Complex& c) {
    return (os << c._re << '+' << c._im << 'i');
}

const Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1._re + c2._re, c1._im + c2._im);
}

const Complex operator+(double r, const Complex& c2) {
    return Complex(c2._re + r, c2._im);
}

/**
 * This is the suffix operator.
 */
Complex operator"" i(long double x) {
	// return Complex { 0, static_cast<double>(x) };
	return Complex { 0, (double)x };
}



int main() {
	int timeInSeconds = 1_h + 30_m + 12_s;

	// 1_h  is compiled to
	//   operator"" _h(1)
	cout << "1_h + 30_m + 12_s = " << timeInSeconds << endl;

	cout << 2_aaa << endl;


	Complex c {3,5}, d {4,6};
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "c+d = " << c+d << endl;

	cout << "4+5i = " << (4 + 5.0i) << endl;

	Complex e = c + (6 + 7.0i);
	cout << "e = " << e << endl;

	//cout << typeid("abc").name() << " " << typeid("abc"s).name() << endl;

}
