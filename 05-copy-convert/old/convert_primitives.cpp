/**
 * @author Ofir Pele
 * @since 2017
 */

#include <iostream> 
using namespace std;

// This does not compile!
operator string(int i) {
    return to_string(i);
}

int main() {

   return 0;
}
