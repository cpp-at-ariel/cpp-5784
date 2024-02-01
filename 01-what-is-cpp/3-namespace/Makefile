#!make -f
CXX=clang++-9
CXXFLAGS=-std=c++2a 

ifndef MAIN
  MAIN=./main.cpp
endif

all: 
	# $(CXX) $(CXXFLAGS) $(MAIN)
	$(CXX) $(CXXFLAGS) *.cpp
	./a.out
