# A generic makefile for running simple C++ projects.
#
# USAGE:
#    1. Put all your non-main files in subfolder "units".
#    2. Run:         make MAIN=<path-to-cpp-file-with-main-program>.cpp
# It should compile all the cpp files in "units", link them with your main program, and run it.
#
# Based on https://stackoverflow.com/a/2481326/827927
# AUTHOR: Erel Segal-Halevi

CXX=clang++-9
RM=rm -f
CPPFLAGS=-std=c++2a

ifndef MAIN
  MAIN=./main.cpp
endif

MAINEXECUTABLE=$(subst .cpp,,$(MAIN)).exe

SOURCES=$(wildcard units/*.cpp) $(MAIN)
HEADERS=$(wildcard units/*.h*)

run: $(MAINEXECUTABLE)
	$(MAINEXECUTABLE)

$(MAINEXECUTABLE): $(SOURCES) $(HEADERS)
	$(CXX) $(CPPFLAGS) $(SOURCES) -o $(MAINEXECUTABLE)

clean:
	$(RM) *.exe a.out *.class
