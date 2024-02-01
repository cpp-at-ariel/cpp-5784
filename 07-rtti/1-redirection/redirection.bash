#!bash

clang++-9 --std=c++2a redirection.cpp -o redirection.exe

echo ---
./redirection.exe  
echo ---
./redirection.exe > out.txt
echo ---
./redirection.exe 2> err.txt
echo ---
./redirection.exe 1> out.txt 2> err.txt
echo ---
