// Prelab 6 Kevin Moody
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <string>
#include <vector>

using namespace std;

class hashTable{
  
 public:
  
  list<string> *table;
  hashTable(int i);
  void insertItem(string x);
  bool findItem(string x);
  int hashFunction(string x);

  int tablesize;
  
};

#endif
