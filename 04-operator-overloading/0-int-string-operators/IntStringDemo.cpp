/**
 * Demonstrates operator overloading in C++.
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
#include <string>
#include <vector>
// using namespace std;
using std::string, std::cout, std::ostream, std::endl;


string operator* (int n, string s) { 
    string result = "";
    for (int i=0; i<n; ++i)
        result += s;
    return result;
}

string operator* (string s, int n) {
    return "(" + n*s + ")";
}

bool operator!(string s) {
    return (s.length()==0);
}

string operator+(string a, string b) {
//    return b+a;   // stack overflow
    return std::operator+(b,a);
}

/* Compiler errors: 
int operator* (int a, int b) {
    return a+b;
}

int operator@ (int a, int b) {
    return a+b;
}
*/


ostream& operator<< (ostream& os, string s) {
    //os << s;  // stack overflow
    std::operator<<(os,'"');
    std::operator<<(os,s);
    std::operator<<(os,'"');
    return os;
}

int main() {
    string x="abc", y="def";
    
    cout << "3 * y  = " << 3 * y << endl;
    cout << "y * 3  = " << y * 3 << endl;
    //Equivalent to: 
    cout << operator*(3,y) << endl;
    cout << "0 * y  = " << 0 * y << endl;

    cout << "x + y = " << (x+y) << endl;  // defined here: https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01075_source.html
    cout << "3 * (x + y) = " << 3 * (x + y) << endl;
    cout << "3 * x + y = " << 3 * x + y << endl;

    cout << "x * 3 = " << (x * 3) << endl;

    cout << "!x = " << (!x) << endl;

    // x = "";
    if (!x) {
        cout << "x is empty" << endl;
    } else {
        cout << "x is not empty" << endl;
    }
    
    return 0;
}
