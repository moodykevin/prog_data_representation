#ifndef WORDPUZZLE_H
#define WORDPUZZLE_H
#include <string>
#include <iostream>
using namespace std;

class wordPuzzle{
  string getWordInGrid(int startRow, int startCol, int dir, int len, int numRows, int numCols);
};

#endif
