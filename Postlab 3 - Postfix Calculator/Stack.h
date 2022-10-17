#ifndef STACK_H
#define STACK_H

#include "stacknode.h"

class Stack {
 public:
  Stack();
  ~Stack();
  void push(int e);
  void pop();
  int top();
  bool empty();

  stacknode* head;
  stacknode* tail;
  int count;
};

#endif
