#!make -f
CXX=clang++-9
CXXFLAGS=-std=c++2a 

all: 
	$(CXX) $(CXXFLAGS) *.cpp -o main.exe
	./main.exe

tidy:
	clang-tidy *.cpp -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,hicpp-*,performance-*,portability-*,readability-* --warnings-as-errors=* --

tidycore:
	clang-tidy *.cpp -checks=cppcoreguidelines-* --

tidyread:
	clang-tidy *.cpp -checks=readability-* --

tidyhi:
	clang-tidy *.cpp -checks=hicpp-* --
