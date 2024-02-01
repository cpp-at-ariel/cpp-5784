/**
 * Demonstrates STL numeric query algorithms.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <vector>
#include <forward_list>
#include <array>
#include "output_containers.hpp"
using namespace std;

struct Person{};

int product(int a, int b) { return a*b; }

int main() {
	vector<int> v{4,6,8,5,4,1,3,1,4,7};   
	int a[10] {4,6,8,5,4,1,3,1,4,7};
	cout << "v = " << v << endl;
	cout << "count(4): " << count(v.begin(),v.end(),4) << endl;
	cout << "count(1): " << count(begin(v),end(v),1) << endl;
	cout << "count(9): " << count(begin(v),end(v),9) << endl;
	cout << "count(4) from third place: " << count(begin(v)+3,end(v),4) << endl;

	istringstream istr{"4 5 4 6 4 7 4 8 4 9 4 10 4 4 4"};
	cout << "count(4) in istr: " << count(istream_iterator<int>(istr), istream_iterator<int>{}, 4) << endl;

	cout << "accumulate (sum): " << accumulate(begin(v),end(v),0) << endl;
	cout << "accumulate (product): " << accumulate(begin(v),end(v),
		1, product) << endl;
	cout << "accumulate (product): " << accumulate(begin(v),end(v),
		1, [](int a, int b){return a*b;}) << endl;

	vector<string> vs {"abc","def","ghi"};
	cout << "accumulate (sum strings): " << 
		accumulate(begin(vs),end(vs),string("")) << endl;

	// vector<Person> vp(3);
	// accumulate(begin(vp),end(vp),Person{});

	cout << "v = " << v << endl;
	vector<int> v2;
	partial_sum(begin(v),end(v), back_inserter(v2));
	cout << "\npartial_sum: " << v2 << endl;

	vector<int> v2a(v.size());
	partial_sum(begin(v),end(v), begin(v2a));
	cout << "\npartial_sum: " << v2a << endl;

	partial_sum(begin(v),end(v), ostream_iterator<int>(cout,","));
	cout << endl;

	// istringstream istr2{"4 5 4 6 4 7 4 8 4 9 4 10 4 4 4"};
	// partial_sum(istream_iterator<int>{istr2}, istream_iterator<int>{}, ostream_iterator<int>(cout,","));
	// cout << endl;


	vector<int> v3;
	adjacent_difference(begin(v2),end(v2), back_inserter(v3));
	cout << "adjacent_difference: " << v3 << endl;

	forward_list<int> u1 {1,2,3};
	vector<int> u2       {4,5,6};
	cout << "\ninner_product: " << inner_product(begin(u1),end(u1), begin(u2), 0) << endl;
}

