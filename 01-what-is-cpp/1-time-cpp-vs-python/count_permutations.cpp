#include "output_containers.hpp"
#include <algorithm>
#include <numeric>
using namespace std;

int count_permutations(int N) {
	vector<int> v(N);
	iota(v.begin(), v.end(), 1); // fill the vector with 1,...,N
	int count=0;
	do {
		++count;
	} while ( next_permutation(v.begin(),v.end()) );
	return count;
}

int main() {
	for (int N=1; N<14; ++N) {
		cout << "Permutations of 1.." << N << ":" << endl;
		auto begin = time(NULL);
		auto count = count_permutations(N);
		auto end = time(NULL);
		auto duration = end-begin;
		cout << "  " << count << " permutations calculated in " << duration << " seconds" << endl;
	}
	return 0;
}
