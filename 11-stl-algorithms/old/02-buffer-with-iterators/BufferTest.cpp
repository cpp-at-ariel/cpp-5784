#include "Buffer.hpp"
#include "gtest/gtest.h"

/*
static int val(int i) {
	return i*3;
}

static void changeVals(Buffer<int>& b, int multFactor= 1) {
	for (size_t i=0; i<b.size(); ++i) {
		b[i]= val(i)*multFactor;
	}
}

static void checkVals(const Buffer<int>& b, int multFactor= 1) {
	for (size_t i=0; i<b.size(); ++i) {
		EXPECT_EQ(b[i], val(i)*multFactor);
	}
}

TEST(Buffer, simple) {
	constexpr size_t MAX_SIZE= 10; 
	for (size_t size= 0; size<MAX_SIZE; ++size) {
		Buffer<int> b(size);
		EXPECT_EQ(b.size(), size);
		changeVals(b);
		checkVals(b);
	}
}

TEST(Buffer, copyCtor) {
	constexpr size_t MAX_SIZE= 10; 
	for (size_t size= 0; size<MAX_SIZE; ++size) {
		Buffer<int> b(size);
		EXPECT_EQ(b.size(), size);
		changeVals(b);
		checkVals(b);

		Buffer<int> b2(b);
		EXPECT_EQ(b2.size(), size);
		checkVals(b2);

		for (size_t i=0; i<b.size(); ++i) {
			b2[i]= 9999;
			EXPECT_EQ(b2[i],9999);
			checkVals(b); // b should not change!
		}
	}
}

TEST(Buffer, assignOp) {
	constexpr size_t MAX_SIZE= 10; 
	for (size_t size= 0; size<MAX_SIZE; ++size) {
		for (double d=0.5; d<=6; d+=0.5) {

			Buffer<int> b(size);
			EXPECT_EQ(b.size(), size);
			changeVals(b);
			checkVals(b);
			
			Buffer<int> b2(size*d);
			changeVals(b2,3);
			checkVals(b2,3);
			
			b2= (b=b); // checks also self assignment
			EXPECT_EQ(b2.size(),b.size());
			checkVals(b2);
			
			changeVals(b,1999);
			checkVals(b2); // b2 should not change
			changeVals(b2,18);
			checkVals(b,1999); // b should not change
		}
	}
}

TEST(Buffer, swapTest) {
	Buffer<int> ib1(2);
	ib1[0]= 1;
	ib1[1]= 2;

	Buffer<int> ib2(3);
	ib2[0]= 10;
	ib2[1]= 20;
	ib2[2]= 30;
	
	myswap(ib1,ib2);

	EXPECT_EQ(ib1.size(),3);
	EXPECT_EQ(ib1[0],10);
	EXPECT_EQ(ib1[1],20);
	EXPECT_EQ(ib1[2],30);
	
	EXPECT_EQ(ib2.size(),2);
	EXPECT_EQ(ib2[0],1);
	EXPECT_EQ(ib2[1],2);

	
}

#include <string>
#include <sstream>
using namespace std;

TEST(Buffer, constIteratorTest) {

	Buffer<int> ib(2);
	ib[0]= 1;
	ib[1]= 2;
	const string expected_str("1 2 ");

	// we we'll print to stringstream
	// printing to stringstream similar to printing to cout
	// but we can compare to a string in the end

	{
		stringstream sstr;
		// almost traditional (traditional without the 'c')
		for (Buffer<int>::const_iterator it= ib.cbegin(); it!=ib.cend(); ++it) {
			sstr<< *it << " ";
		}
		string str= sstr.str();
		EXPECT_EQ(str, expected_str);
	}

	{
		stringstream sstr;
		// c++11 first version
		for (auto it= ib.cbegin(); it!=ib.cend(); ++it) {
			sstr<< *it << " ";
		}
		string str= sstr.str();
		EXPECT_EQ(str, expected_str);
	}

	{
		stringstream sstr;
		// c++11 foreach
		for (const auto& val : ib) {
			sstr<< val << " ";
		}
		string str= sstr.str();
		EXPECT_EQ(str, expected_str);
	}
}

*/

TEST(Buffer, iteratorTest) {
/*
	Buffer<int> ib(2);
	ib[0]= 1;
	ib[1]= 2;

	// we we'll print to stringstream
	// printing to stringstream similar to printing to cout
	// but we can compare to a string in the end

	{
		const string expected_str("10 20 ");
		stringstream sstr;
		// almost traditional (traditional without the 'c')
		for (Buffer<int>::iterator it= ib.begin(); it!=ib.end(); ++it) {
			(*it)*= 10;
			sstr<< *it << " ";
		}
		string str= sstr.str();
		EXPECT_EQ(str, expected_str);
	}

	{
		const string expected_str("100 200 ");
		stringstream sstr;
		// c++11 first version
		for (auto it= ib.begin(); it!=ib.end(); ++it) {
			(*it)*= 10;
			sstr<< *it << " ";
		}
		string str= sstr.str();
		EXPECT_EQ(str, expected_str);
	}

	{
		const string expected_str("1000 2000 ");
		stringstream sstr;
		// c++11 foreach
		for (auto& val : ib) {
			val*= 10;
			sstr<< val << " ";
		}
		string str= sstr.str();
		EXPECT_EQ(str, expected_str);
	}

*/
	const Buffer<int> b99(99);
	for (const int& val: b99) {
		std::cout << val << " " ;
	}
//	for (int& val: b99) {
//		val = 5;
//	}
	for (const int& val: b99) {
		std::cout << val << " " ;
	}
}

