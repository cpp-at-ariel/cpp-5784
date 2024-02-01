/**
 * Demonstrates constructing references from pointers.
 * @author Erel Segal-Halevi
 * @since 2018-02
 */

#include <iostream>
using namespace std;

int main() {
    int* p1 = new int{5};
    int& r1 = *p1;
    cout << r1 << endl;

    int& r2 = *new int{6};
    cout << r2 << endl;

    int i3 = *new int{7};
    cout << i3 << endl;
}
