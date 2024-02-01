#include <array>
#include <string>
#include <iostream>
using namespace std;

int main() {
    array<int,3> numbers = {111, 222, 333};  // Array with a fixed size
	cout << numbers[1] << endl;
	cout << numbers[4] << endl;  // junk
	cout << numbers.at(1) << endl;  
	cout << numbers.at(4) << endl;  // exception
    
	array<array <string, 8>, 5> strings;
	strings[2][3] = "abc";
	cout << strings[2][3] << endl;
}
