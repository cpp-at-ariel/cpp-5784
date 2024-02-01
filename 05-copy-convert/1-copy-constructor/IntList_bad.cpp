/**
 * Demonstrates what happens when there is NO copy constructor and NO assignment operator.
 * @author Erel Segal-Halevi
 * @since  2018-04
 */

#include <iostream>
using namespace std;

class IntList {
    private:
        uint numInts;
        int* theInts;

    public:
        IntList(uint newNumInts): 
            numInts(newNumInts),
            theInts(new int[newNumInts]) 
            {  }

        ~IntList() {
            delete[] theInts;
        }

        int size() const { 
            return numInts; 
        }

        void operator=(int value) {
            cout << "filling with "<<value<<"..."<<endl;
            for (uint i=0; i<this->numInts; ++i)
                theInts[i] = value;
        }

        int operator[](uint index) const {
            return theInts[index];
        }

        int& operator[](uint index) {
            return theInts[index];
        }
};

/**
 * If you pass a parameter by value - 
 *    the compiler will call the DEFAULT copy ctor
 */
int sum(IntList list) {
    cout << "INSIDE sum: &list = " << &list << endl;
    int result=0;
    for (int i=0; i<list.size(); ++i) {
        result += list[i];
    }
    list[5] = 88;
    return result;
}


int main() {
    IntList list1 {10};
    cout << "list1[5] = " << list1[5] << endl;
    list1 = 1;
    cout << "list1[5] = " << list1[5] << endl << endl;
    cout << "OUTSIDE sum: &list1 = " << &list1 << endl;
    cout << "sum(list1) = " << sum(list1) << endl;
    cout << "list1[5] = " << list1[5] << endl << endl;
    cout << "---" << endl;

    IntList list2 = list1; // equivalent to:
    // IntList list2 {list1};
    // IntList list2 (list1);
    cout << "list1[5] = " << list1[5] << endl;
    cout << "list2[5] = " << list2[5] << endl;
    list2 = 2;
    cout << "list1[5] = " << list1[5] << endl;
    cout << "list2[5] = " << list2[5] << endl << endl;

    IntList list3{20};


    list3 = list1;

    cout << "list1[5] = " << list1[5] << endl;
    cout << "list3[5] = " << list3[5] << endl;
    list3 = 3;
    cout << "list1[5] = " << list1[5] << endl;
    cout << "list3[5] = " << list3[5] << endl << endl;

    return 0;

    // This happens implicitly:
    // list1.~IntList();
    // list2.~IntList();
    // list3.~IntList();
}
