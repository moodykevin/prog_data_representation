#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
using namespace std;

class postfixCalculator {
 public:
  stack<int>  values;
  
  postfixCalculator();
  ~postfixCalculator();
  void addition();
  void subtraction();
  
};

#endif
