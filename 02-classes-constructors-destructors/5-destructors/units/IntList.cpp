#include "IntList.hpp"

void IntList::fill(int value) {
    for (uint i=0; i<this->numInts; ++i)
        theInts[i] = value;
}

int IntList::get(uint index) {
    return theInts[index];
}

void IntList::put(uint index, int value) {
    theInts[index] = value;
}
