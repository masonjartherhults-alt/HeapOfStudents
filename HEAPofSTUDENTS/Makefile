CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

studentData: main.o address.o date.o
	$(CXX) $(CXXFLAGS) main.o address.o date.o -o studentData

main.o: main.cpp address.h date.h student.h
	$(CXX) $(CXXFLAGS) -c main.cpp

address.o: address.cpp address.h
	$(CXX) $(CXXFLAGS) -c address.cpp

date.o: date.cpp date.h
	$(CXX) $(CXXFLAGS) -c date.cpp
run: studentData
	./studentData

debug: studentData
	gdb ./studentData

clean:
	rm -f *.o studentData

valgrind: studentData
	valgrind --leak-check=full ./studentData

.PHONY: run debug clean valgrind