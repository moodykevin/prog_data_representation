# This is a comment
# Lab05 POSTLAB

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2# Enable all warnings
DEBUG=-g

AVLTree: AVLTree.o AVLPathTest.o AVLNode.o
	$(CXX) AVLTree.o AVLPathTest.o AVLNode.o

AVLTree.o: AVLTree.cpp
	$(CXX) -c AVLTree.cpp


AVLPathTest.o: AVLPathTest.cpp
	$(CXX) -c  AVLPathTest.cpp

AVLNode.o: AVLNode.cpp
	$(CXX) -c AVLNode.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
