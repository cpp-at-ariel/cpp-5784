/**
 * A demo of enums in C and C++
 */

#include <iostream>
using namespace std;

enum Season {
	WINTER,	// = 0 by default
	SPRING,	// = WINTER + 1
	SUMMER,	// = WINTER + 2 
	AUTUMN		// = WINTER + 3
};

int WINTER = 60;  // won't compile - redefinition

int main() {
		cout << WINTER;
    int curr_season = WINTER;
    curr_season += 50;
    cout << curr_season << endl;
    cout << (curr_season==0) << endl;
}
