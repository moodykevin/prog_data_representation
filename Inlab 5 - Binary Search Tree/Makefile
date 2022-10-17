# This is a comment
# Lab05 INLAB

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2# Enable all warnings
DEBUG=-g

BinaryTree: BinarySearchTree.o BSTPathTest.o BinaryNode.o
	$(CXX) BinarySearchTree.o BSTPathTest.o BinaryNode.o

BinarySearchTree.o: BinarySearchTree.cpp
	$(CXX) -c BinarySearchTree.cpp


BSTPathTestTest.o: BSTPathTest.cpp
	$(CXX) -c  BSTPathTest.cpp

BinaryNode.o: BinaryNode.cpp
	$(CXX) -c BinaryNode.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
