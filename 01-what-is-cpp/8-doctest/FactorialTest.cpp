#include "doctest.h"
#include "Factorial.hpp"
#include <stdexcept>

TEST_CASE("Factorials of small numbers") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
}


TEST_CASE("Factorials of large numbers") {
    CHECK(factorial(4) == 24);
    CHECK(factorial(6) == 720);
    CHECK(factorial(10) == 3628800);

    // auto f3 = factorial(3);
    // CHECK((f3==5 || f3==6)); // logic OR requires parentheses!
}


TEST_CASE("Factorials of negative numbers") { 
    CHECK_THROWS(factorial(-1));  // check that some exception is thrown
    CHECK_THROWS_AS(factorial(-2), std::out_of_range);  // check that a specific exception type is thrown
    CHECK_THROWS_AS(factorial(-2), std::exception);  // check that a specific exception type (or a descendant) is thrown
}


/* add more test cases here */
