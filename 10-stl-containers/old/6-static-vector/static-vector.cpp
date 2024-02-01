#include <vector>
#include <iostream>
using namespace std;

struct MyClass {
	static vector<int> myvector; // only a declaration, not a definition
};

vector<int> MyClass::myvector{10,20,30};

int main() {
	MyClass a;
	MyClass b;
	cout << MyClass::myvector.size() << endl;
	cout << MyClass::myvector[0] << endl;
}
