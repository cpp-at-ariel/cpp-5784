/**
 * Demonstrates converting references to pointers.
 * @author Erel Segal-Halevi
 * @since 2018-02
 */

#include <iostream>
using namespace std;

int i = 5;
int* ip = &i;

int k = 500;

int*& f() {
    return ip;
}

int main() {
    cout << (*ip) << endl;
    (*ip) = 6;
    cout << i << endl << endl;

    int* jp = f();
    cout << (*jp) << endl;
    (*jp) = 7;
    cout << i << endl << endl;

    jp = &k;  // ip does not change - it still points to i.
    cout << (*jp) << endl;
    (*jp) = 501;
    cout << i << endl;
    cout << (*ip) << endl << endl;

    int*& jpr = f();  // equivalent to: jpr = ip;
    cout << (*jpr) << endl;
    (*jpr) = 8;
    cout << i << endl << endl;

    jpr = &k;      // ip changes - it now points to k.
    cout << (*jpr) << endl;
    (*jpr) = 502;
    cout << i << endl;
    cout << (*ip) << endl << endl;
}
