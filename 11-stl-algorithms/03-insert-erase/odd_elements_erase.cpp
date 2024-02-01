/**
 * Demonstrates the invalild-iterator bug,
 * and how to solve it.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-05
 * @url  https://stackoverflow.com/q/2874441/827927
 */


#include "output_containers.hpp"
#include <forward_list>
using namespace std;

template<typename Container, typename Iterator>
void erase_odd_elements(Container& c, Iterator b, Iterator e) {
	for (; b!=e; ++b) {
		bool is_odd = (*b)%2 != 0;
		if (is_odd)
			c.erase(b);
	}
}


template<typename Container, typename Iterator>
void erase_odd_elements_2(Container& c, Iterator b, Iterator e) {
	for (; b!=e;) {
		bool is_odd = (*b)%2 != 0;
		if (is_odd) {
			b = c.erase(b);
		} else {
			++b;
		}
	}
}


int main() {
	{
		cout << "erase with a bug" << endl;
		vector<int> v {1,2,16,4,7,11,22};
		cout << "before: " << v << endl;
		erase_odd_elements(v, v.begin(), v.end());
		cout << "after: " << v << endl;
	}
	{
		cout << "erase correctly" << endl;
		list<int> v {1,2,16,4,7,11,22};
		cout << "before: " << v << endl;
		erase_odd_elements_2(v, v.begin(), v.end());
		cout << "after: " << v << endl;
	}
}
