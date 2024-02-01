/**
 * A demo of enums in C and C++
 */

#include <iostream>
using namespace std;

enum class Season {
	WINTER,	// = 0 by default
	SPRING,	// = WINTER + 1
	SUMMER,	// = WINTER + 2 
	AUTUMN	// = WINTER + 3
};

int WINTER = 60;

int main() {
    cout << WINTER << endl;
    cout << int(Season::WINTER) << endl;
    Season curr_season = Season::WINTER;
    string name[4] {"winter", "spring", "summer", "autumn"};
    cout << name[int(curr_season)];
    //int curr_season = SUMMER;            // won't compile
    //int curr_season = Season::SUMMER;    // won't compile
    //Season curr_season = Season::WINTER;
	// curr_season += 50;                // won't compile
    //int prev_season = Season::SUMMER; // won't compile
    //cout << curr_season << endl;      // won't compile
    //cout << int(curr_season) << endl;      
    //cout << (curr_season==0) << endl; // won't compile
    //cout << (curr_season==Season::WINTER) << endl; 
}
