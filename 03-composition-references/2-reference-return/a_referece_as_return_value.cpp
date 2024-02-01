/**
 * Demonstrates returning references from functions.
 * @author Erel Segal-Halevi
 * @since 2018-03
 */

#include <iostream>
using namespace std;


int globalnum = 11;

int g1() { 
    return globalnum;
}

int& g2() {
    return globalnum;
}

const int& g3() {
    return globalnum;
}

int& g4() {   // bug
	int localnum = 9999;
	return localnum;
}


int main() {
    cout << "globalnum = " << globalnum << endl;
    cout << "g1() = " << g1() << endl;
    cout << "g2() = " << g2() << endl;
    cout << "g3() = " << g3() << endl;
    cout << "g4() = " << g4() << endl;

    // g1()=111;
    g2()=222;
    // g3()=333;
    g4()=444;  

    cout << endl << "globalnum = " << globalnum << endl;
    cout << "g1() = " << g1() << endl;
    cout << "g2() = " << g2() << endl;
    cout << "g3() = " << g3() << endl;
    cout << "g4() = " << g4() << endl;
}
