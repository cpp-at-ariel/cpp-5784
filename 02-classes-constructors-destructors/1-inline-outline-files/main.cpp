/**
 * Main file that uses the class Complex
 */

#include "Complex.hpp"

int main() {
    Complex a(1,2);
    cout << "a = " << a.to_string() << endl;

    Complex b(3,4);
    cout << "b = " << b.to_string() << endl;

    Complex c = a.sum(b);
    cout << "c = " << c.to_string() << endl;

    c = c.sum(b);
    cout << "c = " << c.to_string() << endl;

    Complex d;
    cout << "d = " << d.to_string() << endl;
}
