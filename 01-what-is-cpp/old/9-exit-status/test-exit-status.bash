#!/bin/bash

clang++-9 return0.cpp; ./a.out
echo "Return value $?"

clang++-9 return111.cpp; ./a.out
echo "Return value $?"

./return0.bash
echo "Return value $?"

./return222.bash
echo "Return value $?"

