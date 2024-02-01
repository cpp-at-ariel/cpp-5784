/**
 * Demostrates friend methods.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using namespace std;

class MyClass {
private:
	int myField;
public:
	MyClass(): myField(555) {}
	void print1(ostream& out) const;                      // member method
	friend void print2(ostream& out, const MyClass& obj); // friend function
	friend void set(int i, MyClass& obj);

	static void print4(ostream& out, const MyClass& obj); // static function
};

void MyClass::print1(ostream& out)  const {
	out << this << endl;
	out << "print1: " << myField << endl;
}

void print2(ostream& out, const MyClass& obj) {
	//cout << this << endl;
	out << "print2: " << obj.myField << endl;
}

void print3(ostream& out, const MyClass& obj) {
   	// out << "print3: " << obj.myField << endl;  // Compile error
}


void set(int i, MyClass& obj) {
	obj.myField = i;
}


void MyClass::print4(ostream& out, const MyClass& obj) {
	out << "print4: " << obj.myField << endl;
	//obj.myField =6;
}

int main() {
	const MyClass obj;
	obj.print1(cout);
	print2(cerr, obj);
	MyClass::print4(cerr, obj);
	// obj.print2(cerr);  // Compile error

	return 0;
}
