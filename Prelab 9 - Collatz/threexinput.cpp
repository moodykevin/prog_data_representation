//Kevin Moody (km4ws)
//Lab09 prelab

#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int x);

int main(){
  int x,n,r;
  cout << "Enter a number: ";
  cin >> x;
  cout << "Enter iterations of subroutine: ";
  cin >> n;

  r = threexplusone(x);
  timer t;
  t.start();
  while(n>0){
    r = threexplusone(x);
    n--;
  };
  t.stop();
  cout << "Steps: " << r << endl;
  return 0;
}
