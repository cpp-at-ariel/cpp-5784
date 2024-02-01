# A generic makefile for running single-file C++ projects.
#
# AUTHOR: Erel Segal-Halevi

CXX=clang++-9
CXXFLAGS=-std=c++2a 

RM=rm -f

# VALGRIND_FLAGS=
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

ifndef MAIN
  MAIN=./a_new_without_delete.cpp
endif

MAINEXECUTABLE=$(subst .cpp,,$(MAIN)).exe

SOURCES=$(MAIN)

valgrind: $(MAINEXECUTABLE)
	valgrind --tool=memcheck $(VALGRIND_FLAGS) $(MAINEXECUTABLE) 2>&1 | { egrep "lost| at " || true; }

$(MAINEXECUTABLE): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(MAINEXECUTABLE)

clean:
	$(RM) *.exe a.out
