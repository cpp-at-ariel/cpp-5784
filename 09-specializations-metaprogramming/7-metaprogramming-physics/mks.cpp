#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

template <int m, int k, int s> 
struct mks {
	double val;
public:
	mks(double val): val(val) {}
};

template <int m, int k, int s> 
auto operator+(mks<m,k,s> a, mks<m,k,s> b) {
	return mks<m,k,s>(a.val+b.val);
}

template <int ma, int ka, int sa, int mb, int kb, int sb> 
auto operator*(mks<ma,ka,sa> a, mks<mb,kb,sb> b) {
	return mks<ma+mb,ka+kb,sa+sb>(a.val*b.val);
}

template <int ma, int ka, int sa, int mb, int kb, int sb> 
auto operator/(mks<ma,ka,sa> a, mks<mb,kb,sb> b) {
	return mks<ma-mb,ka-kb,sa-sb>(a.val/b.val);
}

template <int m, int k, int s> 
ostream& operator<<(ostream& out, mks<m,k,s> a) {
	return (out << a.val);
}

using Meters=mks<1,0,0>;  // meter
using Seconds=mks<0,0,1>;    // second
using Kilograms=mks<0,1,0>;    // kilogram
using Velocity=mks<1,0,-1>;  // meter*(second)^(-1)
using Acceleration=mks<1,0,-2>;  // meter*(second)^(-2)
using Energy=mks<2,1,-2>;  // kg^2*meter*(second)^(-2)

mks<0,0,1> operator"" _sec(long double x) { return mks<0,0,1>(x); }
mks<0,0,1> operator"" _min(long double x) { return mks<0,0,1>(x*60); }
mks<0,0,1> operator"" _hour(long double x) { return mks<0,0,1>(x*3600); }

int main() {
	//double time=5;   // seconds
	//double length = 7;  // meters
	//
	//cout << time+length;   // logic error

	Meters length = 15; // 15 meters
	cout << "length = " << length << endl;
	Seconds time   = 3;  // 3 seconds
	cout << "time = " << time << endl;
	// cout << time+length;   // compilation error

	Seconds time1 = 1.0_hour + 2.0_min + 50.0_sec;
	cout << "time1 = " << time1 << endl;

	//mks<0,0,2> time2 = 5;
	//cout << time+time2;

	auto velocity = length/time;
	cout << "velocity = " << velocity << endl;

	Velocity velocity2 = 4;
	cout << "velocity2 = " << velocity2 << endl;
	
	auto velocity_sum = velocity+velocity2;
	cout << "velocity_sum = " << velocity_sum << endl;
	//auto v_plus_l = velocity+length; // won't compile

	Velocity c = 3e8;  // speed of light (m/s)
	Kilograms m = 5; // 5 kg uranium
	auto mc = m*c; 
	auto mc2 = m*c*c; 
	Energy E(0);
	E = m*c*c;
	cout << "energy = " << E << endl;
}