#pragma once

#include <iostream>
using namespace std;

class IntList2D {
    private:
        int** theInts;
        char* listName;
        unsigned int rows, cols;

    public:
        IntList2D(uint rows, uint cols) {
            cout << "construct(" << rows << "," << cols << ")" << endl;
            theInts = new int*[rows];
            for (int r=0; r<rows; ++r) {
                theInts[r] = new int[cols];
            }
            this->rows = rows;
            this->cols = cols;
        }

        ~IntList2D() {
            cout << "destruct(" << rows << "," << cols << ")" << endl;
            for (int r=0; r<rows; ++r) {
                delete[] theInts[r];
            }
            delete[] theInts;
        }
        
        void print() {cout << "  theInts=" << theInts << endl; }

        // void fill(int value);
        // int get(uint index);
        // void put(uint index, int value);
};
