
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
void f(T& t) {
    cout << typeid(t).name() << endl;
}

int main() {
    int i;
    vector<int> v;
    f(i);
    f(v);
    // f(5);
    f(vector<int>{1,2,3});
}

