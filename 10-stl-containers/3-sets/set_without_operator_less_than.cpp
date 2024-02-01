/**
 * Demonstrates how to use a set on a struct without operator<.
 * 
 * @author Erel Segal-Halevi
 * @since 2021-06
 */

#include <iostream>
#include <set>
using namespace std;

template<typename T>
class MyTree {

	struct CompareAddresses {
	   bool operator() (const T& lhs, const T& rhs) const {
		   return (&lhs) < (&rhs);
	   }
	};

	set<T, CompareAddresses> my_set;
public:
	void insert(T item) {
		my_set.insert(item);
	}
	int size() {
		return my_set.size();
	}
};



struct Dummy {};


int main() {
	MyTree<int> t_int;
	t_int.insert(5);  // OK
	cout << t_int.size() << endl;

	MyTree<Dummy> t_dummy;
	t_dummy.insert(Dummy{});
	cout << t_int.size() << endl;
}
