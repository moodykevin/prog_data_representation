#ifndef STACKNODE_H
#define STACKNODE_H


class stacknode {
 public:
  stacknode();
  int value;
  stacknode* next;
  stacknode* previous;

  friend class Stack;
};

#endif
