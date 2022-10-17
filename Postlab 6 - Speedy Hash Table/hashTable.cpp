// Prelab 6 Kevin Moody
#include "hashTable.h"
#include <algorithm>

using namespace std;

hashTable::hashTable(int i){
  this->tablesize = i;
  table = new list<string>[tablesize]; // Struggling with creating table, Read article from GeeksForGeeks which inspired some code


}

void hashTable::insertItem(string key){
  int index = hashFunction(key);
  table[index].push_back(key);
}

bool hashTable::findItem(string key){
  int index = hashFunction(key);
  return find(table[index].begin(), table[index].end(), key) != table[index].end();
}

int hashTable::hashFunction(string x){
  int sum = 0;
  for(int k = 0; k < x.length(); k++){
    sum = sum + int(x[k]);
  }
  return sum % tablesize;

}

