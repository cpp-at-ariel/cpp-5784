/**
 * Demonstrates "next_permutation", "prev_permutation" and "reverse".
 */

#include "output_containers.hpp"
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

int main() {
	string v {"abdc"};
	next_permutation(v.begin(),v.end());
	cout << v << endl;
	sort(begin(v), end(v));
	cout << "Permutations in increasing order:" << endl;
	do {
		cout << v << endl;
	} while ( next_permutation(v.begin(),v.end()) );

	reverse(begin(v), end(v));
	cout << endl << "Permutations in decreasing order:" << endl;
	do {
		cout << v << endl;
	} while ( prev_permutation(v.begin(),v.end()) );
	return 0;
}
