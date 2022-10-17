// Kevin Moody
// Lab8 Prelab: CS2150
// mathfun.cpp

#include <iostream>
#include <cstdlib>

extern "C" int product(int, int);
extern "C" int power(int, int);

using namespace std;

int main() {
  int x, y;

  cout << "Enter integer 1: ";
  cin >> x;
  cout << "Enter integer 2: ";
  cin >> y;

  cout << "Product: " << product(x,y) << endl;
  cout << "Power : " <<  power(x,y) << endl;
  return 0;
}
