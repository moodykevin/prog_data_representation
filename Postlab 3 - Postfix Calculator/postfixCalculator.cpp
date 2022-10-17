
#include <iostream>

using namespace std;
#include "postfixCalculator.h"
#include "Stack.h"


postfixCalculator::postfixCalculator(){
  values = Stack();
}

postfixCalculator::~postfixCalculator(){
  while(!values.empty()){
    values.pop();
  }
}

void postfixCalculator::addition(){
  int t1;
  int t2;
  
  if(!values.empty()){
    t1 = values.top();
    values.pop();
    t2 = values.top();
    values.pop();
    values.push(t2+t1);
  }
  
  
}
void postfixCalculator::subtraction(){
  int t1;
  int t2;
  
  if(!values.empty()){
    t1 = values.top();
    values.pop();
    t2 = values.top();
    values.pop();
    values.push(t2-t1);
  }
}

void postfixCalculator::multiplication(){
  int t1;
  int t2;
  
  if(!values.empty()){
    t1 = values.top();
    values.pop();
    t2 = values.top();
    values.pop();
    values.push(t2*t1);
  }
}

void postfixCalculator::division(){
  int t1;
  int t2;
  
  if(!values.empty()){
    t1 = values.top();
    values.pop();
    t2 = values.top();
    values.pop();
    values.push(t2/t1);
  }
}

void postfixCalculator::negation(){
  int t1;
  
  if(!values.empty()){
    t1 = values.top();
    values.pop();
    values.push(t1*-1);
  }
}
