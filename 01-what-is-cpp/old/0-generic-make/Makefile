# A generic makefile for running simple C++ projects.
#
# USAGE:
#    1. Put all your non-main files in subfolder "units".
#    2. Run:         make MAIN=<path-to-cpp-file-with-main-program>.cpp
# It should create a file ".depend" with all required dependencies,
#    compile all the cpp files in "units", link them with your main program, and run it.
#
# Based on https://stackoverflow.com/a/2481326/827927
# AUTHOR: Erel Segal-Halevi

CXX=clang++-9
CXXFLAGS=-std=c++2a 
RM=rm -rf

ifndef MAIN
  MAIN=./main.cpp
endif

SOURCES=$(shell ls units/*.cpp) $(MAIN)
OBJECTS=$(subst .cpp,.o,$(SOURCES))
MAINEXECUTABLE=a.out

all: $(MAINEXECUTABLE)
	./$(MAINEXECUTABLE)

$(MAINEXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)


depend: .depend

.depend: $(SOURCES)
	$(RM) ./.depend
	$(CXX) $(CXXFLAGS) -MM $^>>./.depend;

include .depend

#################

clean:
	$(RM) *.o $(MAINEXECUTABLE)

distclean: clean
	$(RM) *~ .depend

