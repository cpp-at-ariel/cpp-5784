
/**
 * This program demonstrates what happens when a class does not have a default constructor.
 */


struct A {
	public:
	A(int) {}
	A() = default;
	//A(const A&) = default;
	//A& operator=(const A&) = default;
	//A(int,int) = default;
};


int main() {
	A a;
}
