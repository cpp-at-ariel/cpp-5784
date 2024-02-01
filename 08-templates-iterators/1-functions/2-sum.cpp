/**
 * Function template example: sum. 
 * 
 * Also illustrates errors in the template definition, 
 *      that are revealed only in the instantiation.
 * 
 * @author Erel Segal-Halevi
 * @since 2018-04
 */

#include <iostream>
#include <vector>
using namespace std;


template<typename T>
T sum (T a, T b) {
	// f(a);  // compile error
	return a + b;
}


template<typename T>
T sumv (const vector<T>& v, T start=T{}) {
	T result = start;
	for (T element: v)
		result += element;
	return result;
}

// int g(int a) {
// 	f(a);  // compile error
// }


int main() {
	cout << sum(5,6) << endl;
	cout << sum(5.0,6.2)  << endl;
	cout << sum(string("abc"),string("def")) << endl;
	cout << sum("abc" , "def") << endl;  // compile error

	cout << sumv(vector<int>{1,2,3,4,5},0) << endl;
	cout << sumv(vector<string>{"aaa","bbb","ccc","ddd","eee"}) << endl;

	// // With your NumberWithUnits class, you could also do:
	// cout << sumv(vector<NumberWithUnits>{...}) << endl;
}
