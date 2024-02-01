/**
 * @author Ofir Pele
 * @since 2017
 */

#include <iostream> 
using namespace std;

struct A {
   
   explicit A(int i) { 
      cout << "Constructing A from int " << i << endl; 
   }
   
   A(int i, int j) { 
      cout << "Constructing A from two ints " << i << "," << j << endl; 
   }
   
   A(const A& a) { 
      cout << "Constructing A from A" << endl; 
   }
   
   A& operator=(const A& a) { 
      cout << "Assigning A from A" << endl; 
      return *this;
   }
   
};

void f (A a) {
   cout << "In f" << endl;
}

int main() {   
   //A a1 = 37; // won't compile
   cout << "-------------------" << endl;
   
   A a2(37);  // compile ok
   cout << "-------------------" << endl;
   
   //a1 = 67; // won't compile
   a2 = A{67}; // compile OK
   cout << "-------------------" << endl;
   
   //f(77); // won't compile
   f(A{77});  // compile OK
   cout << "-------------------" << endl;

   return 0;
}
