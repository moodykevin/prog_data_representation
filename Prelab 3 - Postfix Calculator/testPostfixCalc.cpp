#include <iostream>
#include <stack>
#include <string>
using namespace std;

#include "postfixCalculator.h"

int main(){
  postfixCalculator calc;
  string token;
  while (cin >> token) {
    if(token == "+"){
      calc.addition();
    } else if(token == "-"){
      calc.subtraction();
    } else {
      calc.values.push(stoi(token));
    }
  }
  cout << calc.values.top() << endl;
  return 0;
}
