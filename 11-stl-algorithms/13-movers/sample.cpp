// example from https://en.cppreference.com/w/cpp/algorithm/sample

#include <iostream>
#include <random>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;
 
int main()
{
    string in = "abcdefgh", out;
    sample(in.begin(), in.end(), back_inserter(out), 5, default_random_engine(1));
    cout << "five random letters out of " << in << " : " << out << '\n';
    sample(in.begin(), in.end(), begin(out), 5, default_random_engine(7));
    cout << "five random letters out of " << in << " : " << out << '\n';

    sample(in.begin(), in.end(), ostream_iterator<char>(cout), 5, default_random_engine(9));
}