#include <cmath>



double SinCos(double x) {
    return sin(x) + cos(x);
}

class SinCosFunctor {
  public:
    SinCosFunctor(double alpha) : alpha(alpha) {}
    double operator() (double x) const { 
	    return sin(alpha * x) + cos(x);
    }
  private:
    double alpha;
};