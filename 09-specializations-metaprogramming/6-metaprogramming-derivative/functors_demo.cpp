#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#include "rgb.hpp"

double zero(double x) { 
	return 0; 
}

double halfx(double x) { 
	return x/2; 
}

template <int coefficient>
double cosine(double x) {
	return std::cos(coefficient*x);
}


struct Sine {
	double coefficient;
	Sine(double coefficient=1): coefficient(coefficient) {}
	double operator() (double x) { 
		return std::sin(coefficient*x);
	}
};

template<int y>
struct Constant {
	double operator() (double x) { 
		return y; 
	}
};

int main() {
	Picture pic(800,800);
	pic.setBackground({255,255,0});

	/* 1. You can plot a simple function: */
	// pic.plot(zero, -4.0,4.0,5000,  -4,4, {0,0,0});
	// pic.plot(halfx, -4.0,4.0,5000,  -4,4, {0,0,255});
	// pic.plot(cosine<2>, -4.0,4.0,5000,  -1.1,1.1, {0,128,0});

	/* 2. You can plot a class with an operator(): */
	// pic.plot(Sine{1}, -4.0,4.0,5000,  -1.1,1.1, {0,0,255});
	// pic.plot(Sine{3}, -4.0,4.0,5000,  -1.1,1.1, {0,128,0});
	// pic.plot(Constant<1>{}, -4.0,4.0,1200,  -1.1,1.1, {0,0,0});
	// pic.plot(Constant<-1>{}, -4.0,4.0,1200,  -1.1,1.1, {0,0,0});
	// pic.plot(Constant<0>{}, -4.0,4.0,1200,  -1.1,1.1, {0,0,0});

	// for (int c=0; c<=10; ++c) {
	// 	pic.plot(Sine{double(c)}, -4.0,4.0,5000,  -1.1,1.1, {0,uint8_t(c*25),255});
	// }

	/* 3. You can plot a "lambda expression": */
	// pic.plot( 
	// 	[](double x){return std::abs(x);}, // lambda expression
	// 	-4.0,4.0,5000,  -1.1,1.1, {255,0,0}) ;
	// auto f = [](double x){return std::abs(x/2);};
	// cout << f(-2) << endl;
	// pic.plot(f, -4.0,4.0,5000,  -1.1,1.1, {128,0,0}) ;

	// /* 4. A loop of lambda expressions: */
	for (double c=0; c<10; ++c) {
		pic.plot( 
			[c=c](double x){return std::sin(c*x);}, // lambda expression
			-4.0,4.0,5000,  -1.1,1.1, {uint8_t(25*c),0,255}) ;
	}

	pic.toFile("func.ppm");
	return 0;
}
