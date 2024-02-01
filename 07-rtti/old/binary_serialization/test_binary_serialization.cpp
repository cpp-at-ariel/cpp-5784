#include "random_image.hpp"

#include "gtest/gtest.h"

TEST(RandomImageBinarySerialization, testEmptyImage) {

	random_image rim;
	rim.writeToFile("pic.raw");
	
	random_image rim2("pic.raw");
	EXPECT_EQ(rim,rim2);

}


TEST(RandomImageBinarySerialization, testImage1) {

	for (uint8_t b=1; b<3; ++b) {
		for (size_t t=0; t<4; ++t) {
			random_image rim(100,200,b);
			rim.writeToFile("pic.raw");
			
			random_image rim2("pic.raw");
			
			EXPECT_EQ(rim,rim2);
		}
	}

}

