# This is a comment
# Lab06 PRELAB
# Kevin Moody

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

wordPuzzle: wordPuzzle.o hashTable.o timer.o
	$(CXX) wordPuzzle.o hashTable.o timer.o

wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp


hashTable.o: hashTable.cpp
	$(CXX) -c  hashTable.cpp

timer.o: timer.cpp
	$(CXX) -c timer.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
