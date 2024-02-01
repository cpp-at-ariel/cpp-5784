#include "gtest/gtest.h"
#include "stringify.hpp"
#include <complex>

TEST(stringifyTest, primitivesTest) {
	EXPECT_EQ("42", stringify(42));
	EXPECT_EQ("false", stringify(false));
	EXPECT_EQ("3.14", stringify(3.14));
	EXPECT_EQ("12345000000", stringify(1.2345e+10));
}

TEST(stringifyTest, complexTest) {
	EXPECT_EQ("(3.14,-42)", stringify(std::complex<double>(3.14, -42)));
	EXPECT_EQ("(0,3)", stringify(std::complex<double>(0, 3)));
}
