#pragma once

#include <iostream>
using namespace std;

class IntList {
    private:
        int* theInts;
        char* listName;
        unsigned int numInts;
        static const int NAME_LENGTH=5;
        int dummy[NAME_LENGTH];

    public:
        IntList(uint numInts) {
            cout << "construct(" << numInts << ")" << endl;
            theInts = new int[numInts];
            listName = new char[NAME_LENGTH];
            this->numInts = numInts;
        }

        ~IntList() {
            cout << "destruct(" << numInts << ")" << endl;
            delete[] theInts;
            delete[] listName;
            // NOTE: no need to delete dummy - it is on the stack
        }
        
        void print() {cout << "  theInts=" << theInts << endl; }

        void fill(int value);
        int get(uint index);
        void put(uint index, int value);
};
