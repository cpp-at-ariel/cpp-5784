#include <iostream>
#include <vector>
using namespace std;


/* This class wraps a vector and adds a print statement in the copy constructor.
   It is used only to check when a vector is copied. */
template<class T>
class vector_with_prints {
	vector<T> v;
public:

	template<typename Argument> vector_with_prints(Argument arg): v(arg) {}
	template<typename Argument1, typename Argument2> vector_with_prints(Argument1 arg1, Argument2 arg2): v(arg1,arg2) {}

	vector_with_prints(const vector_with_prints<T>& vwp): v(vwp.v) {
		cout << "copy constructor " << endl;
	}
	auto begin() const { return v.begin(); }
	auto end() const { return v.end(); }
};

/* This is an iterable with a reference field.
   It can handle l-values but not r-values. */
template<typename Container>
class DummyIterable1 {
	const Container& container;
public:
	DummyIterable1(const Container& the_container): container(the_container) {	}
	auto begin() { return container.begin(); }
	auto end() { return container.end(); }
};


/* This is an iterable with a field that can be either a reference or a copy.
   It can handle both l-values (by referencing) and r-values (by copying). 
   
   See https://stackoverflow.com/q/48862454/827927 for more details.
*/
template<typename Container>
class DummyIterable2 {
	Container container;
public:
	DummyIterable2(const Container&& the_container): container{forward<const Container>(the_container)} {} 
	// DummyIterable2(const Container& the_container): container{the_container} {} 
	auto begin() { return container.begin(); }
	auto end() { return container.end(); }
};

template<typename Container>
DummyIterable2(Container&&) -> DummyIterable2<Container>;


void demo_iterables() {
	vector_with_prints<int> v1(5,55);

	cout << endl << "DummyIterable1: " << endl;
	// DummyIterable on an l-value works:
	for (auto i: DummyIterable1{v1}) {
		cout << i << " ";
	} cout << endl;

	// DummyIterable on an r-value leads to undefined behavior:
	for (auto i: DummyIterable1{vector_with_prints<int>(5,55)}) {
		cout << i << " ";
	} cout << endl;

	cout << endl << "DummyIterable2: " << endl;
	// DummyIterable on an l-value works without copying:
	for (auto i: DummyIterable2{v1}) {
		cout << i << " ";
	} cout << endl;

	// DummyIterable on an r-value copies and works too!:
	for (auto i: DummyIterable2{vector_with_prints<int>(5,55)}) {
		cout << i << " ";
	} cout << endl;
}

int main() {
	cout << boolalpha;
	demo_iterables();
}
