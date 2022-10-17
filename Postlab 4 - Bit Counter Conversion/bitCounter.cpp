// Kevin Moody (km4ws)

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int bitCount(int num){
  int final=0;
  if(num == 1){
    return 1;
  }
  if(num % 2 == 0){
    return  bitCount(num/2);
  }
  if(num % 2 != 0){
    return 1 + bitCount(num/2);
  }
  return 0;
}

int valueToASCII(char s){
  int x;
  if(int(s) > 47 && int(s) < 58){
    x = int(s) - 48;
  } else {
    x = int(s) - 55;
  }
  return x; 
}

int valueFromASCII(int i){
  int x;
  if(i < 10 && i >= 0){
    x = (char)(i+48);
  } else {
    x = (char)(i+55);
  }
  return x;
}

void baseConvert(string numToConvert, int startBase, int endBase){
  int result1;
  int power = 1;
  for(int i = numToConvert.length()-1; i >= 0; i--){
    result1 += valueToASCII(numToConvert[i]) * power;
    power = startBase * power;
  }

  int result2;
  string fin;
  int quotient = result1;
  while(quotient > 0){
    fin += valueFromASCII(quotient % endBase);
    quotient = quotient / endBase;
    
  }
  reverse(fin.begin(),fin.end());
  cout <<  numToConvert << " (base " << startBase << ") = " << fin  << " (base " << endBase << ")" << endl;
}

int main(int argc, char **argv){
  if(argv[1]!=NULL){
    cout << argv[1] << " has " << bitCount(stoi(argv[1])) << " bit(s)" << endl;
    baseConvert(argv[2], stoi(argv[3]), stoi(argv[4]));
  } else {
    cout << "ERROR: NO COMMAND LINE PARAMETERS PASSED" << endl;
  }
  return 0;
}
