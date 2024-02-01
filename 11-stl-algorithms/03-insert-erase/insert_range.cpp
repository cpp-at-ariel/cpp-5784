/**
 * Demonstrates how to insert a range of items into a container.
 * @author Erel Segal-Halevi
 * @since 2018-05
 */


#include "output_containers.hpp"
using namespace std;

template<typename T> _List_iterator<T> operator+ (_List_iterator<T> it, int inc) {
		if (inc<0) {
			for (int i=0; i<-inc; ++i)
				--it;
		} else {
			for (int i=0; i<inc; ++i)
				++it;
		}
		return it;
}


int main() {
	{
		vector<int> v {1,2,4,7,11,16,22};
		list<int> l {99,66,11,44,88,55,33};
		cout << "v: " << v << endl;
		cout << "l: " << l << endl;

		l.insert(l.begin(), v.begin()+2, v.begin()+5);
		cout << "l: " << l << endl;
	}
	{
		vector<int> v {1,2,4,7,11,16,22};
		list<int> l {99,66,11,44,88,55,33};
		cout << "v: " << v << endl;
		cout << "l: " << l << endl;

		v.insert(v.begin(), l.begin()+2, l.begin()+5);
		cout << "v: " << v << endl;
	}
}
