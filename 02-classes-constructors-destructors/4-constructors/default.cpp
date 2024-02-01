#include <string>
using namespace std;


struct Test {
	int a; 
	char b;
	string c;
};

class Test2 {
public:
	int a; 
	char b;
	string c;
	int* d;
};


int main () {
	Test2 t{5, 'c', "abc"};
	//Test2 t{"abc", 5, 'c'};
	Test2 t2{5, 'c'};
	// *(t2.d) = 5;
	// Test t{5, 'c', "abc", 55};
}