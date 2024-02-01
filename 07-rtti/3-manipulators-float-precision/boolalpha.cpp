/**
 * A simple program demonstrating the use of output manipulators.
 * 
 * See https://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt.
 * 
 * @author Erel Segal-Halevi
 * @since  2021-04
 */

#include <iostream>
#include <iomanip>
using namespace std;



int main() {
    cout << "3 > 2: " << (3 > 2) << endl
         << "3 < 2: " << (3 < 2) << endl
         << boolalpha      // calls boolalpha(cout)
         << "3 > 2: " << (3 > 2) << endl
         << "3 < 2: " << (3 < 2) << endl
         << noboolalpha
         << "3 > 2: " << (3 > 2) << endl
         << "3 < 2: " << (3 < 2) << endl;
}
