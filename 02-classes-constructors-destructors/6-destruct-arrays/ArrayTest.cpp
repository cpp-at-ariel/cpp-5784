/**
 * Demonstrates destructors with arrays and points,
 *    and the importance of the delete[] operator.
 * 
 * @author Erel Segal-Halevi
 * @since  2018-03
 */
#include "units/IntList.hpp"

#include <iostream>
using namespace std;

int main() {
    cout << "{" << endl;
    {   
        IntList listarray[5] {1,2,3,4,5};  // five constructions
    }
    cout << "}" << endl;

    IntList* listpointer;
    cout << "{" << endl;
    {
        listpointer = new IntList[5] {6,7,8,9,10};  // five constructions
    }
    cout << "}" << endl;
    delete[] listpointer;   // five destructions
    // delete   listpointer;   // one destructor + segmentation fault / memory leak

    return 0;
}
