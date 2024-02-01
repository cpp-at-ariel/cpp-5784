/**
 * Using template-class-specialization to control return-type
 * 
 * @author M Salters
 * @url    https://stackoverflow.com/a/26876959/827927
 */

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;



int main() {
  vector<int> va;
  decltype(*begin(va)) aa = va[0];
  decay<decltype(*begin(va))>::type bb;
}
