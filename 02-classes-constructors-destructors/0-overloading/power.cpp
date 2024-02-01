/**
 * A demo of function overloading in C++.
 * @author Erel Segal-Halevi
 * @since  2018-03
 */

#include <cmath>       /* log,exp */
#include <iostream>
using std::cout, std::endl;

int power(int a, unsigned int b) {
    cout << "   power of uints" << endl;
    //cout << b;
    return b==0? 1: a*power(a,b-1);
}

double power(double a, double b) {
     cout << "   power of reals" << endl;
     return exp(b*log(a));
}


int main() {
    /* Reminder for signed/unsigned *
    signed int si = 32767;  // equivalent to: short si = 32767
    cout << si << endl;
    si++;
    cout << si << endl;

    unsigned int ui = 0;
    cout << ui << endl;
    ui--;
    cout << ui << endl;
    */

    cout << power(2, 3) << endl;
    cout << power(4.0, 0.5) << endl;
    //cout << power(2, 3.5) << endl;  // ???
    // cout << power(2.0,3.5) << endl;
    // cout << power(2, (int)3.5) << endl;  // ???
    // cout << power(2, -3) << endl;   // ???
}
