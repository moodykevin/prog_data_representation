
#include <iostream>
#include <stack>
using namespace std;
#include "postfixCalculator.h"


postfixCalculator::postfixCalculator(){
  values = stack<int>();
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
