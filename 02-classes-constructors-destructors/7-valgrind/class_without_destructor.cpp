#include <iostream>
using namespace std;

class IntArray {
	int* ints;
public:
	IntArray(int num) {
		ints = new int[num];
	}
	void put(int index, int value) {
		ints[index] = value;
	}
	int get(int index) {
		return ints[index];
	}
};

int main() {
	for (int i=0; i<20; ++i) {
		IntArray a(1000);
		a.put(4, 10);
		cout << a.get(4) << endl;
	}
	return 0;
}
