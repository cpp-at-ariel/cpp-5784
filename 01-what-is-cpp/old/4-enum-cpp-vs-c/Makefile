#!make -f
CXX=clang++-9
CXXFLAGS=-std=c++2a 

ifndef MAIN
  MAIN=./enumclass.cpp
endif

all: 
	$(CXX) $(CXXFLAGS) $(MAIN)
	./a.out
