/**
 * A minimal Fraction class for demonstrating
 * type-conversion operators and the ambiguity they cause.
 * 
 * @author Erel Segal-Halevi
 * @since 2018
 */

#include <iostream>
#include <cmath>
using namespace std;


class Fraction {
	int 	nom;
	int 	den;
public:
	Fraction(int nn, int dn): nom(nn), den(dn) { }

	Fraction(int nn): Fraction(nn, 1) { }  // conversion constructor

	operator double() const {              // conversion operator
		cout << "converting Fraction to double" << endl;
		return double(nom) / double(den);
	}
	
	operator string() const {              // conversion operator
		return to_string(nom)+"/"+to_string(den);
	}

	friend ostream& operator<<(ostream& os, const Fraction& frac);

	friend Fraction operator+ (const Fraction& a, const Fraction& other);

	Fraction operator- (const Fraction& other) const {
		int nn = nom * other.den -
			den * other.nom;
		int dd = den * other.den;
		return Fraction(nn, dd);
	}
};

Fraction operator+ (const Fraction& a, const Fraction& other) {
	int nn = a.nom * other.den +
		a.den * other.nom;
	int dd = a.den * other.den;
	return Fraction(nn, dd);
}

ostream& operator<<(ostream& os, const Fraction& frac) {
	return os << frac.nom << '/' << frac.den;
}

int main() {
	Fraction f1 {1, 4};
	cout << "f1 = " << f1 << endl;

	// Explicit conversion from double to fraction:
	double d1 {f1};
	// equivalent to: 
	// double d1 (f1);
	// double d1 = f1;
	cout << "d1 = " << d1 << endl;

	// Implicit conversion from double to fraction:
	cout << "sqrt(f1) = " << sqrt(f1) << endl;
	cout << "std::sqrt(f1) = " << std::sqrt(f1) << endl;
	cout << "sin(f1) = " << sin(f1) << endl;

	Fraction f2 {2};  // explicit
	Fraction f3 (3);  // explicit
	Fraction f4 = 4;  // implicit

	Fraction farray[5] {2,3,4,5,6};  // 5 times implicit constructor
	//Fraction farray[5] (2,3,4,5,6);  // does not compile

	// cout << "f2 = " << f2 << endl;
	// cout << ((Fraction)2) << endl;
	cout << "f1+2 = " << (f1 + Fraction{2}) << endl;   // OK! explicit conversion constructor
	cout << "f1+2 = " << ((double)f1 + 2) << endl;     // OK! explicit conversion operator
	// cout << "f1+2 = " << (f1 + 2) << endl;             // ambiguous! implicit conversion
	// cout << "2+f1 = " << (2 + f1) << endl;             // ambiguous! implicit conversion

	// cout << "f1-2 = " << (f1 - 2) << endl;   
	// cout << "2-f1 = " << (2 - f1) << endl;   

	return 0;
}
