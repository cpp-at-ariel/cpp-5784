#pragma once

#include <iostream>
using namespace std;

class IntList {
    private:
        int* theInts;
        uint numInts;

    public:
        IntList(uint numInts) {
            cout << "construct(" << numInts << ")" << endl;
            theInts = new int[numInts];
            this->numInts = numInts;
        }

        ~IntList() {
            cout << "destruct(" << numInts << ")" << endl;
            delete[] theInts;
        }

        void fill(int value);
        int get(uint index);
        void put(uint index, int value);
};
