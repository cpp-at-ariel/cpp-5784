/**
 * A demo of output formatting and IO manipulators
 * 
 * @author Erel Segal-Halevi
 * @since  2019-03
 */

#include <iostream>
#include <iomanip>
using namespace std;

void printxyz() {
    cout << "  ";
    double x = 1.66, y=5./3., z=y*3.;
    cout << x << " " << y << " " << z << endl;
}

void printsmallnums() {
    cout << "  ";
    for(float value = -0.6; value <= 0.6; value += 0.2)
        cout << value << " ";
    cout << endl;
}


void printlargenums() {
    cout << "  ";
    for(float value = -666.0; value <= 666.0; value += 222.0)
        cout << value << " ";
    cout << endl;
}



int main() {
    printf("%.3f\n",1234.5678);
    
    cout << 1234.5678 << endl;
    cout << 12345678. << endl;

    cout << setprecision(4)
         << 1234.5678 << endl
         << 12345678. << endl;

    cout << setprecision(100)
         << 1234.5678 << endl
         << 12345678. << endl;

    ostringstream os;
    os << setprecision(4) <<  1234.5678;
    cout << os.str() << endl;
    // Now, in your doctests, you can do:
    //      CHECK_EQ(os.str(),"1235");
    
    cout << "default: " << endl; 
    printsmallnums(); printlargenums(); printxyz();
    for (int i=0; i<10; ++i) {
        cout << "precision(" << i << "): " << endl << setprecision(i); 
        printsmallnums(); printlargenums(); printxyz();
    }
}
