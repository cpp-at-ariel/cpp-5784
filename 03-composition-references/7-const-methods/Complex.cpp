/**
 * Demonstrates const methods.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
using namespace std;

class Complex {
    double _re, _im;

public:
    Complex(double re=0, double im=0): 
        _re(re),
        _im(im)
        {
            //this++; // compile error
        }

    double real() const {  // getter
        //_im = 7;  // compile error
        cout << "real const" << endl;
        return _re;
    }

    double& real()  {       // setter and getter
        cout << "real non-const" << endl;
        return _re;
    }

    string to_string() const { 
        return std::to_string(_re)+"+"+std::to_string(_im)+"i";
    }
};

int main() {
    Complex a;
    a.real() = 5;
    cout << "a.real = " << a.real() << endl;

    a = Complex(6,7);
    cout << "a.real = " << a.real() << endl;
    cout << a.to_string() << endl;

    const Complex c;
    // c.real() = 5;
    cout << "c.real = " << c.real() << endl;
    cout << c.to_string() << endl;

    return 0;
}
