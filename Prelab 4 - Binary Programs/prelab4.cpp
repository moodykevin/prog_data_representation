// Kevin Moody (km4ws)
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

void sizeOfTest(){
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
    
}

void overflow(){
  unsigned int x = 4294967295;
  cout << x << " + 1 = " << x + 1 << endl;
}

void outputBinary(unsigned int x){
  std::string s = "00000000000000000000000000000000";
  for(int i = 31; i >= 0; i--){
    if(x >= pow(2,i)){
      s[31-i] = '1';
      x = x - pow(2,i);
    }
  }
  std::string space = " ";
  s.insert(28,space);
  s.insert(24,space);
  s.insert(20,space);
  s.insert(16,space);
  s.insert(12,space);
  s.insert(8,space);
  s.insert(4,space);

  cout << s << endl;
}

int main(){
  unsigned int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  return 0;
}
