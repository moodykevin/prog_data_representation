#include "HuffmanNode.h"
#include <string>
using namespace std;

HuffmanNode::HuffmanNode(){
  value = '-';
  frequency = 1;
  left = NULL;
  right = NULL;
}

HuffmanNode::HuffmanNode(char x, int i) {
  value = x;
  frequency = i;
  left = NULL;
  right = NULL;
}

HuffmanNode::~HuffmanNode() {
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}
