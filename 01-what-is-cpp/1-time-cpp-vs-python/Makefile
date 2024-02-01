#!make -f
CXX=clang++-9
CXXFLAGS=-std=c++2a -O2

ifndef MAIN
  MAIN=./main.cpp
endif

all: 
	$(CXX) $(CXXFLAGS) $(MAIN)
	./a.out
