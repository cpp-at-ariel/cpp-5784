/**
 * Demonstrates STL _if rune.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <array>
#include "output_containers.hpp"
using namespace std;



int main() {
	vector<int> v{4,6,8,5,4,1,3,1,4,0};    
	cout << "v = " << v << endl;
	cout << "count_if(even): " << count_if(begin(v),end(v), [](int x){return x%2==0;}) << endl;
	cout << "count_if(odd): " << count_if(begin(v),end(v), [](int x){return x%2!=0;}) << endl << endl;

	vector<int> v_even;
	copy_if(begin(v), end(v), back_inserter(v_even), [](int x){return x%2==0;});
	cout << "copy_if(even): " << v_even << endl << endl;

	replace_if(begin(v), end(v), [](int x){return x%2==0;}, 999);
	cout << "replace_if(even): " << v << endl;
}

