/**
 * Demonstrates the difference between l-value and r-value in functions.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-02
 */

#include <iostream>
using namespace std;

void test1(int& z) {
    z = z + 6;
}

void test2(const int& z) {
    // z = z + 6;
}


int main() {
    int x = 5;
    const int y = 6;

    // RIDDLE: Which of the following is legal?

    // test1(x);   
    // test1(x+1);
    // test1(5);
    // test2(x);
    // test2(x+1);
    // test2(5);

    // test1(y);
    // test2(y);
}
