/**
 * Header file of class "Complex"
 */

#include <iostream>
using namespace std;

class Complex {
    double re, im;

public:
    Complex() {  re = im  = 999; }    // inline constructor
    Complex(double re, double im);  // "outline" constructor

    string to_string() {           // inline method  
        return std::to_string(re)+"+"+std::to_string(im)+"i";
    }
    Complex sum(Complex b);        // "outline" method
};
