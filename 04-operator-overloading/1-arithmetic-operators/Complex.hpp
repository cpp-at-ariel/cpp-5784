#pragma once
/**
 * Header file for the Complex class.
 * 
 * @author Ofir Pele
 * @since 2017
 */


#include <iostream>

class Complex {

private:

    double _re;
    double _im;

public:

    // Constructor. Also works as a conversion from double and
    // also as a default ctor.
    Complex (const double& re= 0.0,
             const double& im= 0.0)
        : _re(re), _im(im) {
    }
    //-------------------------------------

	//-------------------------------------
	// getters
	//-------------------------------------
	double re() const {
		return _re;
	}

	double im() const {
		return _im;
	}
	//-------------------------------------
	
    //-------------------------------------
    // operators
    //-------------------------------------

    //----------------------------------
    // unary operator
    //----------------------------------

    // Logical NOT
    bool operator!() const {
        return _re==0 && _im==0;
    }

    Complex operator-() const {
        return Complex(-_re , -_im);
        // longer version:
        //Complex result;
        //result._re = -_re;
        //result._im = -_im;
        //return result;
    }

    //----------------------------------------
    // binary operators
    //----------------------------------------

    Complex operator+(const Complex& other) const;

    Complex& operator+=(const Complex& other) {
        _re+= other._re;
        _im+= other._im;
        return *this; // for call chaining
    }

    // const Complex operator-(const Complex& other) const {
    //     return Complex(_re - other._re, _im - other._im);
    // }

    Complex& operator-=(const Complex& other) {
        _re-= other._re;
        _im-= other._im;
        return *this;
    }

    // (a+bi)*(c+di) = 
    // (ac-bd) + (ad+bc)i
    Complex& operator*=(const Complex& other) {
        double new_re = _re*other._re - _im*other._im;
        double new_im = _re*other._im + _im*other._re; 
        _re = new_re;
        _im = new_im;
		// version with bug
		// _im = _re*other._im + _im*other._re; 
		// _re = _re*other._re - _im*other._im;
		return *this;
    }
    //----------------------------------------

    // prefix increment:
    Complex& operator++() {
        _re++;
        return *this;
    }

    // postfix increment:
    Complex operator++(int dummy_flag_for_postfix_increment) {
        Complex copy = *this;
        _re++;
        return copy;
    }
    

    /* 
    // Compile error:
    std::ostream& operator<< (std::ostream& os, const Complex& c) const {
        os << "(" << _re << "+" << _im << "i)";
        return os;
    }

    // Compiles, but unexpected - don't do it:

    std::ostream& operator<< (std::ostream& os) const {
        os << "[[" << _re << "+" << _im << "i]]";
        return os;
    }
    */

    //-------------------------------------
    // friend global binary operators
    //-------------------------------------
    friend Complex operator- (const Complex& c1, const Complex& c2);
    friend Complex operator* (const Complex& c1, const Complex& c2);
    friend bool operator==(const Complex& c1, const Complex& c2);
    friend bool operator!=(const Complex& c1, const Complex& c2);

   
    //----------------------------------
    // friend global IO operators
    //----------------------------------
    friend std::ostream& operator<< (std::ostream& output, const Complex& c);
    friend std::istream& operator>> (std::istream& input , Complex& c);
    //-------------------------------------
}; // end of class Complex

