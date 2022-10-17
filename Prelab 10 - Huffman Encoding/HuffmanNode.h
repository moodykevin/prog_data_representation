#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <string>
using namespace std;

class HuffmanNode {
public:
  HuffmanNode();
  HuffmanNode(char x, int i);
  ~HuffmanNode();

  char value;
  HuffmanNode* left;
  HuffmanNode* right;
  int frequency;

  friend class heap;

};
#endif
