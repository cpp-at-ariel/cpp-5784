/**
 * Demonstrates the differences between cout and cerr,
 *   the output buffering,
 *   and the bash output redirection methods.
 */

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

using namespace std;

const int WAIT_TIME=3;

int main() {
	cout << "Start " << endl;
	cout << "The result is 2 ";
	this_thread::sleep_for(chrono::seconds(WAIT_TIME));
	cout << endl;
	// cout.flush();
	this_thread::sleep_for(chrono::seconds(WAIT_TIME));
	cout << "The result is 3 " << endl;
	
	cerr << "There is a bug ";
	this_thread::sleep_for(chrono::seconds(WAIT_TIME));
	cerr << endl;
	// this_thread::sleep_for(chrono::seconds(WAIT_TIME));
	cout << "The result is 4 " << endl;
	return 0;
}