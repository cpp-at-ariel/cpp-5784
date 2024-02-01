MAINNAME= Buffer

#########################################################
# compiler stuff 
#########################################################
CXX= g++
CXXFLAGS= -Wall -Wvla -Werror -g -D_GLIBCXX_DEBUG -std=c++11
#CXXFLAGS= -Wall -Wvla -Werror -g -D_GLIBCXX_DEBUG -std=c++11 -DINT_BUFFER_MALLOC_REALLOC_VERSION

CEXELINKFLAGS=
CXXTESTLINKFLAGS= -lgtest -lgtest_main -pthread
##########################################################


##########################################################
# sources files
##########################################################
# There is no SRCTESTMAIN as we are linking with gtest_main that has main
SRCSTESTNOMAIN= $(MAINNAME)Test.cpp 
##########################################################


#######################
# executables name
#######################
TEST= $(MAINNAME)Test
#######################


#########################################################
# actions
#########################################################
all: $(TEST)

$(TEST): $(subst .cpp,.o,$(SRCSTESTNOMAIN))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(CXXLINKFLAGS) $(CXXTESTLINKFLAGS)
	./$@
	@read -p "Press [Enter] key to start memory check of test executable..." MEMCHK
	valgrind --leak-check=full --show-leak-kinds=all -v ./$(TEST)

clean:
	rm *.o $(TEST) -f

depend: $(SRCSTESTNOMAIN)
	makedepend -Y -- $(CXXFLAGS) -- $^

##############################################
# installs that should be done once
##############################################
installonce: gtestinstall makedependinstall valgrindinstall

gtestinstall: 
	sudo apt-get install libgtest-dev
	sudo apt-get install cmake
	cd /usr/src/gtest; \
	sudo cmake CMakeLists.txt; \
	sudo make; \
	sudo cp *.a /usr/lib
	sudo chmod u+r /usr/lib/libgtest.a
	sudo chmod u+r /usr/lib/libgtest_main.a

makedependinstall:
	sudo apt-get install xutils-dev

valgrindinstall:
	sudo apt-get install valgrind
##############################################

.PHONY: all clean depend installonce gtestinstall makedependinstall valgrindinstall


# DO NOT DELETE THIS LINE -- make depend depends on it.

BufferTest.o: Buffer.hpp
