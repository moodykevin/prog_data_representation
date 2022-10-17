// Kevin Moody, CS 2150
#include <iostream>
#include <fstream>
#include <string>
#include "wordPuzzle.h"
#include "hashTable.h"

using namespace std;
char grid[500][500];

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    static string output;
    output.clear(); 
    output.reserve(256);
    int r = startRow, c = startCol;
    string direction;
    
    for (int i = 0; i < len; i++) {
      if (c >= numCols || r >= numRows || r < 0 || c < 0) {break;}

        output += grid[r][c];

        switch (dir) {
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    return output;

}

bool checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}


int main(int argc, char **argv){

  string line;
  ifstream file1(argv[1]);

  int count = 0;
  if(file1.is_open()){
    while(getline(file1,line)){
      count++;
    }
  }
  count = getNextPrime(count/2);
  hashTable hash1(count);
  file1.close();

  ifstream file2(argv[1]);
  
  if (file2.is_open()){
    while ( getline (file2, line)){
      hash1.insertItem(line);
    }
  };
  file2.close();

  ifstream gridfile(argv[2]);
  if(!gridfile.is_open()) {
    cout << "FILE NOT OPEN" << endl;
      return 0;
    }

  
  int rows; int cols;
  //file >> rows;
  string line2;
  getline(gridfile, line2);
  rows = stoi(line2);
  string line3;
  getline(gridfile, line3);
  cols = stoi(line3);

  string grid1;
  getline(gridfile, grid1);

  for(int i = 0; i < cols; i++){
    for(int j = 0; j < rows; j++){
      int k = cols*j+i;
      grid[j][i] = grid1[k];
    }
  }

  int found = 0;
  

  string previous = "";

  for(int r = 0; r<rows; r++){
    for(int c = 0; c<cols; c++){
      for(int dir = 0; dir<8;dir++){
	string direction;
	if(dir==0){direction = "N ";};
	if(dir==1){direction = "NE";};
	if(dir==2){direction = "E ";};
	if(dir==3){direction = "SE";};
	if(dir==4){direction = "S ";};
	if(dir==5){direction = "SW";};
	if(dir==6){direction = "W ";};
	if(dir==7){direction = "NW";};

	for(int L = 0; L < 23; L++){

	string s = getWordInGrid(r,c,dir,L,rows,cols);
	if(hash1.findItem(s) && s.length() > 2){
	  string coords = "(" + to_string(r) + "," + to_string(c) + "):";

	  string placement = direction + coords + " \t" + s;
	  if(placement!=previous){
	    previous = placement;
	    found+=1;
	    cout << placement << endl;
	  }
	}
	}
      }
    }
  }
  cout << found << " words found" << endl;

  return 0;
}
