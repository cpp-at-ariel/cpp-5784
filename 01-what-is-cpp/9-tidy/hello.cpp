/**
 * This program contains some issues that are detected by clang-tidy.
 * 
 * Run `make tidy` to find out.
 */

#include <iostream>
#include <string>
#include <array>
using namespace std;

const int NUM_OF_SUBMISSIONS_IN_SEMESTER = 12;

int main() {
    cout << "Each student should submit " << 12 << " exercises." << endl;

    int submission_count = 11;
    if (submission_count >= 12) 
        cout << "OK!"  << endl;
    else 
        cout << "Try again." << endl;

    string submission_names[3] = {"a", "b", "c"};
    // array<string,3> submission_names = {"a", "b", "c"};  // Array with a fixed size, like in C
    cout << submission_names[0] << endl;
    return 0;
}

