CXX=clang $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

linkedlist: linkedlist.o
	$(CXX) linkedlist.o

linkedlist.o: linkedlist.c
	$(CXX) -c linkedlist.c




.PHONY: clean
clean:
	-rm -f *.o *~ a.out
