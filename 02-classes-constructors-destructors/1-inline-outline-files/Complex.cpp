/**
 * Implementation file of class "Complex"
 */

#include "Complex.hpp"

// "outline" constructor implementation:
Complex::Complex(double re, double im) { 
    (*this).re = re;
    this->im = im; 
}   


// "outline" method implementation:
Complex Complex::sum(Complex b) {  
    return Complex(re+b.re, im+b.im);
}

