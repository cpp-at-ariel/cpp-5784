#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;

class IntList {
    private:
        int* theInts;
        uint numInts;

    public:
        IntList(uint numInts):
          numInts(numInts),
          theInts (new int[numInts])
        {
            cout << "constructing an IntList with " << numInts << " ints." << endl;
        }

        IntList(uint numInts, int value): IntList(numInts)
        {
            cout << "filling an IntList with " << numInts << " ints." << endl;
            // operator=(value);
            *this = value;
        }

        ~IntList() {
            cout << "destructing an intlist with " << numInts << " ints." << endl;
            delete[] theInts;
        }

        // Set all elements in this intList to value
        void operator=(int value);


        // void operator=(int value) const {
        //   theInts[5] = 6;
        //   numInts = 6;
        //   theInts = new int[7];
        //   cout << "hihihi" << endl;
        // }

        const int operator[](uint index) const;
        int& operator[](uint index);
        //int get(uint index) {return theInts[index];} // Java style
        //void set(uint index, int newValue); // Java style

        int operator[] (string s) const {
          if (s==string("first"))
            return theInts[0];
          else if (s==string("last"))
            return theInts[numInts-1];
          else throw invalid_argument{"invalid argument: "+s};
        }
        int& operator[] (string s)  {
          if (s==string("first"))
            return theInts[0];
          else if (s==string("last"))
            return theInts[numInts-1];
          else throw invalid_argument{"invalid argument: "+s};
        }
};
