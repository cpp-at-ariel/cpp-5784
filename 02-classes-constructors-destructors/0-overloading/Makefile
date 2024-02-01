#!make -f

CXX=clang++-9
CXXFLAGS=-std=c++2a 

ifndef MAIN
  MAIN=./power.cpp
endif

build: 
	$(CXX) $(CXXFLAGS) $(MAIN)
	./a.out

build_safe:  # protect against accidental conversion of a negative number to a large positive number
	$(CXX) $(CXXFLAGS) -Wsign-conversion -Werror $(MAIN)
	./a.out

tidy:
	clang-tidy *.cpp -checks=*,-modernize-*,-*-magic-* --
