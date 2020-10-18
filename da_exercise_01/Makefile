CXX=g++
CXXFLAGS=-Wall -std=c++11 -O2 -lm -Werror -Wno-sign-compare -pedantic
all:solution
solution: main.o
	$(CXX) $(CXXFLAGS) -o solution main.cpp
main.o: my_vector.hpp radix_sort.hpp structs.hpp
clean: 
	rm -f *.o solution