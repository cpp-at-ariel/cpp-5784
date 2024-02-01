/**
 * Demonstrates a correct copy constructor.
 * @author Erel Segal-Halevi
 * @since  2018-03
 */

#include <iostream>
using namespace std;

class IntList {
    private:
        int* theInts;
        uint numInts;

    public:
        IntList(uint newNumInts): 
            numInts(newNumInts), 
            theInts(new int[newNumInts]) 
            {  }


        IntList(const IntList& other): 
        // IntList(IntList other): 
            IntList(other.numInts) 
        {
            cout << "copy constructor doing deep copy" << endl;
            for (uint i=0; i<numInts; ++i)
                theInts[i] = other.theInts[i];
        }

        IntList& operator=(const IntList& other) {
            // theInts = other.theInts;
            // numInts = other.numInts;
            if (this==&other)
                return *this;
            cout << "assignment operator doing deep copy..." << endl;

            if (other.numInts!=this->numInts) {
                delete[] theInts;
                theInts = new int[other.numInts]; // init
                numInts = other.numInts;
            }
            
            for (uint i=0; i<numInts; ++i)
                theInts[i] = other.theInts[i];
            return *this;
        }

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

        void operator()(const IntList& other) {
            cout << "hahaha" << endl;
        }
};

/**
 * If you pass a parameter by value - 
 *    the compiler will call the copy ctor
 */
int sum(const IntList& list) {
    int result=0;
    for (int i=0; i<list.size(); ++i) {
        result += list[i];
    }
    return result;
}

int main() {
    // int a,b,c;    a = b = c; // Chaining
    IntList list1 {10};
    cout << "list1[5] = " << list1[5] << endl;
    list1 = 1;
    cout << "list1[5] = " << list1[5] << endl << endl;

    cout << "sum(list1) = " << sum(list1) << endl;

    cout << "list1[5] = " << list1[5] << endl << endl;
    cout << "---" << endl;

    //IntList list2 {list1}; // calls copy ctor
    //IntList list2 (list1); // calls copy ctor
    IntList list2 = list1;   // calls copy ctor

    cout << "list1[5] = " << list1[5] << endl;
    cout << "list2[5] = " << list2[5] << endl;
    list2 = 2;
    cout << "list1[5] = " << list1[5] << endl;
    cout << "list2[5] = " << list2[5] << endl << endl;

    IntList list3{20};
    list3 = list1;   // operator=
    //list3(list1);   // operator()
    cout << "list1[5] = " << list1[5] << endl;
    cout << "list3[5] = " << list3[5] << endl;
    list3 = 3;
    cout << "list1[5] = " << list1[5] << endl;
    cout << "list3[5] = " << list3[5] << endl << endl;

    cout << "sum(list3) = " << sum(list3) << endl;


    list3 = list3;
    cout << "list3[5] = " << list3[5] << endl;

    cout << "chaining assignments: "<<endl;
    list3 = list2 = list1;
    // Equivalent to:
    // list2 = list1;
    // list3 = list2;

    cout << "---" << endl;
    IntList list4 = list2 = list1;

    return 0;
}
