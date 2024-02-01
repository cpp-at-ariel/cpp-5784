/**
 * Demonstrates the Complex class and its operators.
 * 
 * @author Ofir Pele, Erel Segal-Halevi
 * @since 2017--2021
 */

#include "Complex.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
#include <assert.h>

class A{};

int main(int argc, char **argv) {
    cout << "Complex Demo" << endl;

    Complex c1(1,2);
    Complex c2(2,3);
    Complex c3(3,4);

    cout << endl << "**** DEMONSTRATE THE ARITHMETIC OPERATORS ****" << endl;

    cout << "c1=" << c1 << "   c2=" << c2 << "  c3=" << c3 << endl;
    cout << "-c1 = " << (-c1) << endl;
    // (-c1) is equivalent to: c1.operator-()

    (c1 += c2) += c3;  // c1 SHOULD get the sum c1+c2+c3 = 6+9i
    cout << "c1=" << c1 << "   c2=" << c2 << "  c3=" << c3 << endl;
    // If we return Complex& (by reference), this is equivalent to:
    // c1 += c2;              // c1 = 3 + 5i;
    // Complex& c_temp = c1;  // c_temp = c1 = 3 + 5i
    // c1 += c3;              // c1 = c_temp = 6 + 9i

    // If we return Complex (by value), this is equivalent to:
    // c1 += c2;              // c1 = 3 + 5i;
    // Complex c_temp = c1;   // c_temp = 3 + 5i
    // c_temp += c3;          // c_temp = 6 + 9i

    // Here is a similar example with ints:
    // int a=2, b=3;
    // cout << (((a += b) += b)  += b) << endl;
    // cout << "a = " << a << endl;


    cout << "(c1 + c2) + c3 = " << (c1 + c2) + c3 << endl;
    // Equivalent to:
    // Complex c_temp_1 = c1 + c2;
    // Complex c_temp_2 = c_temp_1 + c3;

    Complex c11(1,2);
    Complex c22(2,3);
    cout << "c11 = " << c11 << "    c22 = " << c22 << endl;  // should print: 1+2i 2+3i
    c11 *= c22;
    cout << "c11 = " << c11 << endl;  // should print: -4+7i

    cout << "++++++++++++++++++++c1 = " << ++++++++++++++++++++c1 << endl;
    // cout << c1++++ << endl;

    if (!c11) {
        cout << "c11 is zero" << endl;
    }

    cout << endl << "**** DEMONSTRATE IMPLICIT CONVERSION ****" << endl;
    cout << "c1 + 5: " << (c1 + 5) << endl;
    cout << "c1 - 5: " << (c1 - 5) << endl;
    // cout << "5 + c1: " << (5 + c1) << endl;
    cout << "5 - c1: " << (5 - c1) << endl;


    cout << endl << "**** DEMONSTRATE THE INPUT OPERATOR ****" << endl;

    if (argc==2) {
        cout << "Reading a complex number from the console:" << endl;
        cout << "Before: c1 = " << c1 << endl;
        cout << "Enter a complex number: ";
        cin >> c1;
        if (!cin) {
            cout << "Error! Wrong format!" << endl;
        }
        cin.clear();
        cout << "After: c1 = " << c1 << endl;
    } else {
        cout << "Reading a complex number from a file:" << endl;
        const char* filename = "inputs/ok1.txt";
        ifstream fin(filename);
        if (!fin) {
            cerr << "File " << filename << " not open" << endl;
            return 1;
        }
        cout << "Before: c2 = " << c2 << ". fin position = " << fin.tellg() << endl;
        fin >> c2;
        if (!fin) {
            if (fin.bad()) {
                cout << "Fatal error with stream, quiting" << endl;
                return 1;
            }
            cout << "Error in format in file " << filename << endl;
            cout << endl;
            fin.clear();
        }
        cout << "After: c2 = " << c2 << ". fin position = " << fin.tellg() << endl;

        // Demonstrates using istringstream for testing the input operator
        cout << "Reading a complex number from a string:" << endl;
        cout << "Before: c3 = " << c3<<endl;
        istringstream sinput("7+8i");
        sinput >> c3;
        if (!sinput) {
            cout << "Format error!" << endl;
        }
        cout << "After:  c3 = " << c3 << endl << endl;
        assert (c3==Complex(7,8));

        // Demonstrates using ostringstream for testing the output operator
        ostringstream soutput;
        Complex c9(22,33);
        soutput << c9;
        assert (soutput.str()=="22+33i");
    }
    return 0;
}
