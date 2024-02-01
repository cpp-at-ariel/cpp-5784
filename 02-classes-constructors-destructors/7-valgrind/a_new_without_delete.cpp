class Point {
	int x, y;
	void f() { x=5; }
	void g() { y=x*x; }
	void h() { x=y+x; }
public:
	Point () {}
};

int main() {
	Point array_stack [1000];
	Point* array_heap = new Point[1000];
	// delete[] array_heap;
	return 0;
}
