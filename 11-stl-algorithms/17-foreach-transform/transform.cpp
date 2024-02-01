/**
 * Demonstrates STL transform algorithms.
 * From here:  https://en.cppreference.com/w/cpp/algorithm/transform
 */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main()
{
    // transform with one sequence:
    string s("hello");
    transform(
            s.begin(), s.end(), 
            s.begin(),
            [](unsigned char c)  { return toupper(c); });
 
    vector<int> ordinals;
    transform(
        s.begin(), s.end(), 
        back_inserter(ordinals),
        [](unsigned char c)  { return (int)c; });
 
    cout << s << ':';
    for (auto ord : ordinals) 
       cout << ' ' << ord;
    cout << endl << endl;

    // transform with two sequences:
    vector<int> v1{1,2,3,4,5,6};
    vector<int> v2{6,5,4,3,2,1};
    vector<int> v3;
    transform(begin(v1), end(v1), begin(v2), back_inserter(v3),
        [](int x, int y){return x*y;});
    for (auto i : v3) 
       cout << i << " ";
    cout << endl;
 
}