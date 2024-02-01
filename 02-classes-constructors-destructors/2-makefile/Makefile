#!make -f

CXX=clang++-9
CXXFLAGS=-std=c++2a 

all: a.out
	./a.out

a.out: main.o Point.o Rectangle.o Triangle.o Circle.o
	$(CXX) $(CXXFLAGS) Point.o main.o Rectangle.o Triangle.o Circle.o

Point.o: Point.cpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile Point.cpp -o Point.o

Rectangle.o: Rectangle.cpp Rectangle.hpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile Rectangle.cpp -o Rectangle.o

Circle.o: Circle.cpp Circle.hpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile Circle.cpp -o Circle.o

Triangle.o: Triangle.cpp Triangle.hpp Point.hpp
	$(CXX) $(CXXFLAGS) --compile Triangle.cpp -o Triangle.o

main.o: main.cpp Point.hpp Rectangle.hpp Circle.hpp Triangle.hpp
	$(CXX) $(CXXFLAGS) --compile main.cpp -o main.o

clean:
	rm -f *.o a.out
