
#include <iostream>
#include <vector>
#include <string>
using namespace std;


template<typename Container, typename BoolContainer>
void test(Container container, BoolContainer v) {
    static_assert(is_integral<typename BoolContainer::value_type>::value, "BoolContainer must be of integral type");
}

int main() {
    vector<int> vi(4);
    vector<string> vs(4);
    cout << is_integral<decltype(vi)::value_type>::value << endl;
    cout << is_integral<decltype(vs)::value_type>::value << endl;

    test(string("abcd"), vi);
    // test(string("abcd"), vs);
}

