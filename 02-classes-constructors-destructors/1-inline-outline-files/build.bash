#!bash
clang++-9 -std=c++2a --compile Complex.cpp -o Complex.o
clang++-9 -std=c++2a --compile main.cpp -o main.o
clang++-9 -std=c++2a Complex.o main.o
./a.out

