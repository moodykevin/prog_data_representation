#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "Stack.h"
using namespace std;

class postfixCalculator {
 public:
  Stack values;
  
  postfixCalculator();
  ~postfixCalculator();
  void addition();
  void subtraction();
  void multiplication();
  void division();
  void negation();
  
};

#endif
