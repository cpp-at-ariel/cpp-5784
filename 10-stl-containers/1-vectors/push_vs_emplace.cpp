/**
 * Demonstrates the difference between push_back and emplace
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <vector>
using namespace std;

struct MyClass {
	int a,b;
	MyClass(int a) { cout << "ctor("<<a<<")"<<endl; this->a=a; this->b=-1; }
	MyClass(int a,int b) { cout << "ctor("<<a<<","<<b<<")"<<endl; this->a=a; this->b=b; }
	MyClass(const MyClass& other) { cout << "copy-ctor("<<other.a << "," << other.b << ")"<<endl; a=other.a; b=other.b; }
	MyClass& operator=(const MyClass& other) { cout << "operator="<<endl; a=other.a; b=other.b; return *this;}
	~MyClass() { cout << "dtor(" << a << "," << b << ")"<<endl; }
};


int main() {
	vector<MyClass> v1;
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;
	v1.reserve(4);
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;
	cout << "push_back" << endl;
	MyClass aa(2);
	v1.push_back(aa);
	v1.push_back(MyClass(22,44));
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;
	cout << "emplace_back" << endl;
	v1.emplace_back(3);
	v1.emplace_back(33,55);
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;

	cout << "emplace_back above capacity: " << endl;
	v1.emplace_back(9);
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl << endl;
	// v1[6]    = MyClass{5,6};  // bug
	// v1.at(6) = MyClass{7,7};  // exception

	auto v1iter = v1.begin();
	v1iter++;
	*v1iter = MyClass{88,99};

	cout << "shrink_to_fit: " << endl;
	v1.shrink_to_fit();
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;

	v1.emplace_back(10);
	cout << "size=" << v1.size() << " capacity=" << v1.capacity() << endl;
}
