/**
 * This is a "hello world" program for the C++ course.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "What is your name? ";
    cin >> name;
    cout << "What is your age? ";
    int age;
    cin >> age;
    cout << endl << "Hello " << name << age << " !" << endl;
    cout << (1 << 5) << endl;
    const auto i = "abc";
    //i = "def";
    //i = 5;  // error
    return 0;
}

