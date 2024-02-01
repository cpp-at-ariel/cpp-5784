/**
 * To run the demo, open "top" in another window,
 * or run ../../cpp-5781/01-what-is-cpp/1-memory-cpp-vs-java/show-memory
 * 
 * Then, run this program and watch the changes in the free memory.
 * 
 * Then, delete the destructor in units/IntList.hpp and try again.
 * 
 * 
 * @author Erel Segal-Halevi
 * @since  2018-03
 */
#include "units/IntList.hpp"

#include <iostream>
using namespace std;

#include <thread>
#include <chrono>
#include <vector>
constexpr int SIZE=100000*1024; // 400,000 KB
constexpr int TIME=2; // seconds

int main() {
    cout << "Before loop" << endl;
    this_thread::sleep_for(chrono::seconds(TIME));

    for (uint i=0; i<5; ++i) {
        cout << "Before list construction" << endl;
        this_thread::sleep_for(chrono::seconds(TIME));

        // This is freed automatically iff there is a correct destructor in units/IntList.hpp
        IntList list(SIZE);
        cout << list.get(5) << endl;
        list.fill(9);
        cout << list.get(5) << endl;
        list.put(5, 100);
        cout << list.get(5) << endl;

        cout << "After list construction" << endl;
        this_thread::sleep_for(chrono::seconds(TIME));
    }

    cout << "After loop" << endl;
    this_thread::sleep_for(chrono::seconds(TIME));

    IntList* listArray = new IntList[10] {100,100,100,100,100,100,100,100,100,100};
    return 0;
}
