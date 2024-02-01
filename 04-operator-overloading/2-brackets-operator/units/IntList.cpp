#include "IntList.hpp"
#include <stdexcept>

void IntList::operator=(int value) {
    for (uint i=0; i<this->numInts; ++i)
        theInts[i] = value;
}

const int IntList::operator[](uint index) const {
    cout << "c ";
    if (index >= numInts)
        throw out_of_range("Array index out of bounds: "+to_string(index));
    return theInts[index];
}

int& IntList::operator[](uint index) {
    cout << "r ";
    if (index >= numInts)
        throw out_of_range("Array index out of bounds: "+to_string(index));
    return theInts[index];
}
