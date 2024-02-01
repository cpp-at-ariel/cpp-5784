/**
 * A demo of input format errors.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-03
 */

#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;



int main() {
    int i=9999;
    cout << i << endl;
    istringstream input("123 x");
    cout << "Before reading: ";
    if (input) {cout <<"input is OK"<<endl;} else {cout << "input is bad"<<endl;}
    input >> i;
    cout << "After reading: ";
    if (input) {cout <<"input is OK"<<endl;} else {cout << "input is bad"<<endl;}
    cout << i << endl;

    input.clear();
    char nextChar = '#';
    input >> nextChar;
    cout << "next char is: " << nextChar << endl;
}
