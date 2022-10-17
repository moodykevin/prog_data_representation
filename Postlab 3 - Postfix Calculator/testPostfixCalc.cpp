#include <iostream>

#include <string>
using namespace std;

#include "postfixCalculator.h"

int main(){
  postfixCalculator calc;
  string token;
  while (cin >> token) {
    if(token == "+"){
      calc.addition();
    } else if(token == "-" && token.length() == 1){
	calc.subtraction();
    } else if(token == "*"){
      calc.multiplication();
    } else if(token == "/"){
      calc.division();
    } else if(token == "~"){
      calc.negation();
    } else {
      calc.values.push(stoi(token));
    }
  }
  cout << calc.values.top() << endl;
  return 0;
}
