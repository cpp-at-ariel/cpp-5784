#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <typename T, int n=5, T defval=T()> class array {
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
	array<int> array5;  // equivalent to array<int,5,int()>
	cout << array5 << endl;
	array5[0] = 99999;
	cout << array5 << endl;
	cout << "size of array5 = " << array5.size << endl << endl;

	array<int,7> array7;  // equivalent to array<int,7,int()>
	cout << array7 << endl;
}
