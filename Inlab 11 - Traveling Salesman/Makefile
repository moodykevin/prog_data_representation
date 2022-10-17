CXX = clang++
CXXFLAGS = -Wall -O2 -g
DOX = doxygen

OBJECTS = traveling.o middleearth.o
.SUFFIXES: .o .cpp

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	$(DOX)

.PHONY: clean
clean:
	-rm -f *.o *- a.out
