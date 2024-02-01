#include "Point.hpp"

#include <iostream>
#include <vector>
#include <array>
using namespace std;


int main() {
    cout << endl << "array1" << endl;
    
    Point array1[5];
    //sizeof(array1)/sizeof(array1[0]);
    cout << "array1[3] = " << array1[3].to_string() << endl;

    cout << endl << "array2" << endl;
    Point array2[5] {1, 2, 3, 4, 5};
    cout << "array2[1] = " << array2[1].to_string() << endl;
    cout << "array2[3] = " << array2[3].to_string() << endl;

    cout << endl << "array3" << endl;
    Point array3[5] {{1,2} , {2,3} , {3,4}};
    cout << "array3[1] = " << array3[1].to_string() << endl;
    cout << "array3[3] = " << array3[3].to_string() << endl;

    cout << endl << "array4" << endl;
    Point array4[3] { 1 , {2,3} };
    cout << "array4[0] = " << array4[0].to_string() << endl;
    cout << "array4[1] = " << array4[1].to_string() << endl;

    cout << endl << "pArray" << endl;
    int size = 5;
    Point* pArray = new Point[size] { {}, 1, {2,3} };

    cout << endl << "cppArray" << endl;
    array<Point,3> cppArray {1, {2,3} };
    cout << "cppArray[0] = " << cppArray[0].to_string() << endl;
    cout << "cppArray[1] = " << cppArray[1].to_string() << endl;

    cout << endl << "cppVector" << endl;
    vector<Point> cppVector {1, {2,3} };
    cout << "cppVector[0] = " << cppVector[0].to_string() << endl;
    cout << "cppVector[1] = " << cppVector[1].to_string() << endl;
    return 0;
}
