#include <iostream>
using namespace std;

void test (const int& i) {
	if (&i)
		cout << i << endl;
	else
		cout << "NULL" << endl;
}

int main() {
	test(5);
	int i=6;
	test(i);
	int* j=nullptr;
	test(*j);  // This is considered undefined behavior!
	           // But on my computer, it works and prints NULL.



    // Segmentation fault:
    int* nullnumptr = nullptr;
    int& nullnumref = *nullnumptr;
    // int& nullnumref = *nullptr; // compilation error

    nullnumref = 5;
    cout << "nullnumptr = " << nullnumptr << endl;
    cout << "&nullnumref = " << &nullnumref << endl;
    // cout << "(*nullnumptr) = " << (*nullnumptr) << endl;
    cout << "nullnumref" << nullnumref << endl; // segmentation fault
}
