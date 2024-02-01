/**
 * Template for numerically calculating the n-th derivative.
 * 
 * Author: Peter Gottschling
 * Url: https://github.com/petergottschling/discovering_modern_cpp/blob/master/c%2B%2B11/derivative.cpp
 */

#include "derivative.hpp"
#include "rgb.hpp"
#include "sincos.hpp"


int main()  {
    using namespace std;

	Picture pic(800,800);
	pic.setBackground({255,255,0});
	pic.plot( [](double){return 0;} , -4.0,4.0,1200,  -2.1,2.1, {0,0,0});

    auto baseFunction = 
        // SinCosFunctor(0.5);   // sin(0.5x) + cos(x)
        [](double x) {return x*x*x/3;};
        //[](double x) {return std::abs(x);};

    auto derivativeOfBase = derivative(baseFunction, 0.001); // represents the function x^2

	pic.plot(baseFunction, -7.0,7.0,5000,  -2.1,2.1, {0,0,255});
    pic.plot(derivative(baseFunction,0.001), -7.0,7.0,5000,  -2.1,2.1, {0,128,0});
    // pic.plot(derivative(derivative(baseFunction,0.001),0.001), -7.0,7.0,5000,  -2.1,2.1, {255,0,0});
    pic.plot(make_nth_derivative<2>(baseFunction,0.001), -7.0,7.0,5000,  -2.1,2.1, {255,0,0});
    pic.plot(make_nth_derivative<3>(baseFunction,0.001), -7.0,7.0,5000,  -2.1,2.1, {255,0,0});

	pic.toFile("func.ppm");
	return 0;
}

