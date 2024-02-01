/**
 * Demonstrates STL partition algorithms.
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

bool is_divisible_by_5(int x) {
	return x%5==0;
}


int main() {
	vector<int> v{9,8,6,7,4,5,2,0,3,1};    
	cout << "original vector: " << v << endl;

	auto middle = partition(begin(v), end(v), [](int x){return x%2==0;});
	cout << "partition to even vs. odd: " << v << endl;
	cout << "even elements: "; copy(begin(v), middle, ostream_iterator<int>(cout,",")); cout << endl;//  << tostring(begin(v), middle) << endl;
	cout << "odd elements: "; copy(middle, end(v), ostream_iterator<int>(cout,",")); cout << endl;//  << tostring(begin(v), middle) << endl;

	//middle = partition(begin(v), end(v), is_divisible_by_5);
	// equivalent to:
	//auto middle = partition(begin(v), end(v), [](int x){ return is_divisible_by_5(x); });
	//cout << "partition by 5: " << v << endl;
	//cout << "divisible by 5: " << tostring(begin(v), middle) << endl;
	//cout << "indivisible by 5: " << tostring(middle, end(v)) << endl;

	sort(begin(v),middle);
	sort(middle  ,end(v));
	cout << "sorted even elements: " << tostring(begin(v), middle) << endl;
	cout << "sorted odd elements: " << tostring(middle, end(v)) << endl;

	// v.insert(v.begin()+3, 11);
	auto middle2 = partition_point(begin(v), end(v), [](int x){return x%2==0;});
	cout << "\neven elements: " << tostring(begin(v), middle2) << endl;
	cout << "odd elements: " << tostring(middle2, end(v)) << endl;
	cout << "all elements: " << tostring(begin(v), end(v)) << endl;
}

