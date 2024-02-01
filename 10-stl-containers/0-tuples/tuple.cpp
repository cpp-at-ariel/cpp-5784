/**
 * Demonstrates tuples as return values.
 * 
 * @author Erel Segal-Halevi
 * @since 2019-05
 */

#include <iostream>
#include <tuple>
using namespace std;

tuple<int,char,string> f_full() {                    // Long style
	return tuple<int,char,string>{5,'a',"hello"};
}

tuple<int,char,string> f_automatic_constructor() {   // Best style
	return {5,'a',"hello"};
}

auto f_automatic_returntype() {                      
	return tuple<int,char,string>{5,'a',"hello"};
}

auto f_automatic_both() {       // Short style
	// since c++17:
 	return tuple{5,'a',"hello"};

	// until c++14:
 	//return make_tuple(5,'a',"hello");
}

// auto f_automatic_none() {
// 	return {5,'a',"hello"};
// }

auto f_automatic_bug() {        // Python style (does not work)
	return (5,'a',"bug!");
}

// auto all_functions() {
// 	return tuple{f_full, f_automatic_constructor, f_automatic_returntype, f_automatic_both};
// }

int main() {
	auto p = pair{6,'b'};
	cout << p.first << " " << p.second << endl;
	auto [p0,p1]  = p;

	auto t = tuple{5,'a', 6.7};  // equivalent to:
	// tuple<int,char,double> t = tuple(5,'a', 6.7);
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
	auto [t0,t1,t2] = t;
	get<0>(t) = 99;
	cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;

	auto [x0,x1,_] = t;


	auto [ii,cc,ss] = f_automatic_both();
	// Equivalent to:

	// auto tt = f();
	// auto ii = get<0>(tt);
	// auto cc = get<1>(tt);
	// auto ss = get<2>(tt);

	cout << ii << " " << cc << " " << ss << endl;

	// auto af = all_functions();

	cout << f_automatic_bug() << endl;
}
