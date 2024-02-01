/**
 * Variable template example: pi.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-04
 */

#include <iostream>
#include <iomanip>
using namespace std;


template<typename T> 
const T pi = 
      static_cast<T>(3.1415926535897932385L);  // variable template

template<typename T> T circular_area(T r) {
    return pi<T> * r * r;
}

int main() {
    int i = 5;
    float f = 5.0;
    double d = 5.0;
    cout << setprecision(100);
    cout << circular_area(i) << endl;
    cout << circular_area(f) << endl;
    cout << circular_area(d) << endl;

    cout << pi<int> << endl;
    cout << pi<float> << endl;
    cout << pi<double> << endl;
}
