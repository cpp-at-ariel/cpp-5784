/**
 * Demonstrates assignment and brackets operators.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-04
 */
#include "units/IntList.hpp"

#include <iostream>
using namespace std;

class A {
    public:
    void operator= (int i) {
        cout << "hahaha" << endl;
    }
};

int main() {
    // A my_a;
    // my_a = 5;
    IntList list0 {1000};
    list0 = 99;
    //equivalent to: list0
    // list0.operator=(99);
    cout << "list0[5] = " << list0[5] << endl;
    //equivalent to: 
    //cout << "list0[5] = " << list0.operator[](5) << endl;

    list0[5] = 11;       // similar to: list0.set(5, 11);
    // equivalent to:
    // list0.operator[](5) = 11;

    cout << "list0[5] = " << list0[5] << endl;

    const IntList clist(10, 88);
    cout << "clist[5] = " << clist[5] << endl;
    // clist[5] = 5;

    list0[0] = 123;
    list0[999] = 456;
    cout << "list0[first] = " << list0["first"] << endl;
    cout << "list0[last] = " << list0["last"] << endl;
    // cout << "list0[middle] = " << list0["middle"] << endl;
    list0["first"] = 555;
    cout << "list[0] = " << list0[0] << endl;

    return 0;
}
