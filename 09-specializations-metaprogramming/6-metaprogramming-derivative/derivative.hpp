/**
 * Template for numerically calculating the n-th derivative.
 * 
 * @author Peter Gottschling
 *         [Shortened by: Erel Segal-Halevi]
 * 
 * @url https://github.com/petergottschling/discovering_modern_cpp/blob/master/c%2B%2B11/derivative.cpp
 */

#include <iostream>


template <typename Functor> 
double derivative_at_point(Functor f, double x, double h) {
    return ( f(x+h) - f(x) ) / h;
}

template <typename Functor>
class derivative {
  private:
    double          h;
    const Functor& f;
  public:
    derivative(const Functor& f, double h):  f(f), h(h)  {}

    double operator()(double x) const {
	    return derivative_at_point(f, x, h);
    }
};


template <unsigned N, typename Functor> class nth_derivative {
  private:
     double h;
     nth_derivative<N-1,Functor> prev_derivative;   // (N-1)-th derivative of f
        
  public:
     nth_derivative(const Functor& f, double h): 
        h(h), 
        prev_derivative(f, h) {}

     double operator()(double x) const {
	      return derivative_at_point(prev_derivative, x, h);
     }
};




template <typename Functor> 
class nth_derivative<1, Functor>: public derivative<Functor> {
  public:
     nth_derivative(const Functor& f, const  double& h) : derivative<Functor>(f, h) {}
};


template <unsigned N, typename Function>
nth_derivative<N, Function> 
make_nth_derivative(const Function& f, const double& h) {
    return nth_derivative<N,Function>(f, h);
}

