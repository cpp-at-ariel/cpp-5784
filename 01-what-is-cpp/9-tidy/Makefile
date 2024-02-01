#!make -f
CXX=clang++-9
CXXFLAGS=-std=c++2a 

tidy:
	clang-tidy *.cpp -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=* --

tidycore:
	clang-tidy *.cpp -checks=cppcoreguidelines-* --

tidyread:
	clang-tidy *.cpp -checks=readability-* --

run: 
	$(CXX) $(CXXFLAGS) *.cpp -o main.exe
	./main.exe
