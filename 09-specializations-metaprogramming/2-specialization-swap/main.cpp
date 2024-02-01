#include "Buffer.hpp"

int main()  {
	int a,b;
	myswap(a,b);
	
	Buffer<double> buffer1{1000000};
	buffer1[0] = 55;
	Buffer<double> buffer2{1000000};
	buffer2[1] = 77;
	myswap(buffer1, buffer2);
}