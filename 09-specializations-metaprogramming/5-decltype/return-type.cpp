/**
 * Using template-class-specialization to control return-type
 * 
 * @author M Salters
 * @url    https://stackoverflow.com/a/26876959/827927
 */

#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
struct ReturnType {
  static T returned_value;
};

template <> struct ReturnType<int> {
  static double returned_value;
};

template <class T>
decltype(ReturnType<T>::returned_value) div10(T number) {
	decltype(ReturnType<T>::returned_value) result = number / 10.0;
  return result;
}


int main() {
  decltype(ReturnType<short>::returned_value) aa;
  decltype(ReturnType<int>::returned_value) bb;
  decltype(ReturnType<char*>::returned_value) cc;

  cout << setprecision(100);
	cout << "short: " << div10(short{36}) << endl;
	cout << "int: " << div10(int{36}) << endl;
	cout << "float: " << div10(float{36}) << endl;
	cout << "double: " << div10(double{36}) << endl;
	// cout << "char*: " << div10("a") << endl;
}
