#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename T, int n, T defval> class array {
	T vals[n];
public:
	array() {
		for (int i=0; i<n; i++)
			vals[i]=defval;
	}
	T& operator[](int i) {
		assert(i<n);
		return vals[i];
	}
	T operator[](int i) const {
		assert(i<n);
		return vals[i];
	}

	static const int size = n;
};

template <typename T, int n, T defval> 
ostream& operator<< (ostream& out, const array<T,n,defval>& thearray) {
	for (int i=0; i<n; ++i)
		out << thearray[i] << " ";
	return out;
}


int main() {
	array<int,5,55> array5;
	cout << array5 << endl;
	array5[0] = 99999;
	cout << array5 << endl;
	cout << "size of array5 = " << array5.size << endl << endl;

	array<int,3,33> array3;  // a different class!
	cout << array3 << endl;  // a different operator<<!
	array3[0] = 99999;
	cout << array3 << endl;
	cout << "size of array3 = " << array3.size << endl << endl;
}
