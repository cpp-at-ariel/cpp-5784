/**
 * Implementation of the Complex class.
 * 
 * @author Ofir Pele
 * @since 2017
 */

#include "Complex.hpp"

using namespace std;



//----------------------------------------
// method operators
//----------------------------------------

Complex Complex::operator+(const Complex& other) const {
    return Complex(_re + other._re, _im + other._im);
}


//----------------------------------------
// friend global binary operators
//----------------------------------------

Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1._re - c2._re, c1._im - c2._im);
}

Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex (c1._re * c2._re - c1._im * c2._im,
                    c1._re * c2._im + c1._im * c2._re);
}


const float TOLERANCE = 0.001;

bool operator==(const Complex& c1, const Complex& c2) {
    // this implementation can cause problems with
    // double precision (== for doubles)
    // return ((c1._re==c2._re)&&(c1._im==c2._im));
    return ( abs(c1._re-c2._re)<=TOLERANCE && abs(c1._im-c2._im)<=TOLERANCE );
}

bool operator!=(const Complex& c1, const Complex& c2) {
    // return ( (c1._re!=c2._re) || (c1._im!=c2._im) );
    return (!(c1==c2));
}




//----------------------------------------
// friend global IO operators
//----------------------------------------
ostream& operator<< (ostream& output, const Complex& c) {
    return (output << c._re << '+' << c._im << 'i');
    // equivalent to:
    // output << c._re << '+' << c._im << 'i';
    // return output;
}


static istream& getAndCheckNextCharIs(istream& input, char expectedChar) {
    char actualChar;
    input >> actualChar;
    if (!input) {return input;}

    if (actualChar!=expectedChar) {
        // failbit is for format error
        input.setstate(ios::failbit);
    }
    return input;
}

istream& operator>> (istream& input, Complex& c) {

    //---------------------------------------------
    // Does not check format
    //---------------------------------------------
    // char ch;
    // return (input >> c._re >> ch >> c._im >> ch);
    //---------------------------------------------

    //---------------------------------------------
    // Checks format, with rewind on failure.
    //---------------------------------------------
    double new_re = 0, new_im = 0;

    // remember place for rewinding
    ios::pos_type startPosition = input.tellg();

    if ( (!(input >> new_re))                 ||
         (!getAndCheckNextCharIs(input,'+'))  ||
         (!(input >> new_im))                 ||
         (!(getAndCheckNextCharIs(input,'i'))) ) {

        // rewind on error
        auto errorState = input.rdstate(); // remember error state
        input.clear(); // clear error so seekg will work
        input.seekg(startPosition); // rewind
        input.clear(errorState); // set back the error flag
    } else {
        c._re = new_re;
        c._im = new_im;
    }

    return input;
    //---------------------------------------------
}
