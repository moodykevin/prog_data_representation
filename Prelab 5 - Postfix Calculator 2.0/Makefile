# This is a comment

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2# Enable all warnings
DEBUG=-g

TreeCalc: TreeCalc.o TreeCalcTest.o TreeNode.o
	$(CXX) TreeCalc.o TreeCalcTest.o TreeNode.o

TreeCalc.o: TreeCalc.cpp
	$(CXX) -c TreeCalc.cpp


TreeCalcTest.o: TreeCalcTest.cpp
	$(CXX) -c  TreeCalcTest.cpp

TreeNode.o: TreeNode.cpp
	$(CXX) -c TreeNode.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
