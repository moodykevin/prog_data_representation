
CXX = clang++
CXXFLAGS = -Wall -O2 -g


OBJECTS = huffmandec.o
.SUFFIXES: .o .cpp

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
