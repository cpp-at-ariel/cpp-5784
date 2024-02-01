# A generic makefile for running single-file C++ projects.
#
# AUTHOR: Erel Segal-Halevi

CXX=clang++-9
RM=rm -f
CPPFLAGS=-std=c++2a

ifndef MAIN
  MAIN=./main.cpp
endif

MAINEXECUTABLE=$(subst .cpp,,$(MAIN)).exe

SOURCES=$(MAIN) Complex.cpp
HEADERS=Complex.hpp

all: $(MAINEXECUTABLE)
	$(MAINEXECUTABLE)

$(MAINEXECUTABLE): $(SOURCES) $(HEADERS)
	$(CXX) $(CPPFLAGS) $(SOURCES) -o $(MAINEXECUTABLE)

valgrind:
	valgrind --tool=memcheck $(MAINEXECUTABLE)

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

clean:
	$(RM) *.exe a.out *.class
