/**
 * Demonstrates IO iterators with STL containers.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	// example of istream_iterator:
    istringstream str("0.12     0.2 \n 0.3   0.4");
	// reminder:
	// double d;
	// str >> d;
	// cout << d << endl;
	istream_iterator<float> ibegin {str};
	istream_iterator<float> iend {};
	cout << "istream_iterator: ";
	for (auto i=ibegin; i!=iend; ++i)
		cout << (*i) << endl;
	cout << endl;

	// cout << *(find(istream_iterator<int>(str), istream_iterator<int>{} , 0.3));

	// example of istream_iterator + copy:
    istringstream str2("8 5 7 1");
	vector<int> v1(4);
	// copy(istream_iterator<int>(cin), istream_iterator<int>{} , v1.begin());
	copy(istream_iterator<int>(str2), istream_iterator<int>{}, v1.begin());
	for (auto i: v1)
		cout << i << endl;
}