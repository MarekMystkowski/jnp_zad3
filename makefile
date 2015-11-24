test1: test1.o very_long_int.o
	g++ test1.o very_long_int.o -o test1
very_long_int.o : very_long_int.cc very_long_int.h
	g++ -Wall -c -std=c++11 very_long_int.cc -o very_long_int.o
test1.o: test1.cc
	g++ -Wall -c -std=c++11 test1.cc -o test1.o
