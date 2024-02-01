/**
 * Random number generator
 * Demonstrates the "generate" algorithm 
 * and the "bind" function.
 */

#include "output_containers.hpp"
#include <algorithm>
#include <random>
#include <functional>
using namespace std;

int return1() {
	return 1;
}

int powers_of_two() {
	static int n=1;
	n *= 2;
	return n;
}

struct powers_of_three {
	int n;

	powers_of_three() { 
		n = 1; 
	}

	int operator()() { 
		n*=3; 
		return n; 
	}
};

struct powers_of_k_struct {
	int n, k;

	powers_of_k_struct(int k): k(k), n(1) { 
	}

	int operator()() { 
		n*=k; 
		return n; 
	}
};

int powers_of_k(int k) {
	static int n=1;
	n *= k;
	return n;
}




default_random_engine generator {1};
uniform_int_distribution<int> distribution(1,6);

int main() {
	// Demonstrates the generate algorithm:	
	vector<int> v1 (10);
	generate(v1.begin(), v1.end(), powers_of_two);
	cout << v1 << endl  << endl;
	generate(v1.begin(), v1.end(), powers_of_three{});
	cout << v1 << endl  << endl;
	//generate(v1.begin(), v1.end(), powers_of_k(3));
	generate(v1.begin(), v1.end(), powers_of_k_struct{4});
	cout << v1 << endl  << endl;

	// Demonstrates the bind function:
	auto powers_of_three = bind(powers_of_k, 3);
	cout << "powers_of_three(): " << powers_of_three() << endl;
	// generate(v1.begin(), v1.end(), powers_of_k); // compile error
	generate(v1.begin(), v1.end(), powers_of_three);
	//generate(v1.begin(), v1.end(), bind(powers_of_k, 3));
	cout << v1 << endl  << endl;

	cout << "----------" << endl;

	// Demonstrates the distribution generator:
	for (int i=0; i<20; ++i)
		cout << distribution(generator) << " "; // dice roll
	cout << endl << endl;

	// Demonstrates the bind function:
	auto dice = bind(distribution, generator);
	for (int i=0; i<20; ++i)
		cout << dice() << " "; // same dice roll
	cout << endl << endl;

	// Demonstrates generate+bind:
	generate(v1.begin(), v1.end(), bind(distribution,generator) );
	cout << v1 << endl  << endl;
}
