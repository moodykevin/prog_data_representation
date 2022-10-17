// Kevin Moody
// CS 2150
// Lab10 Huffman decoding
// Spring 2022

// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.
//#include "heap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

class listNodes{
public:
  char value;
  string code;
  int number;

};

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    unordered_map<char, string> prefixcodes;
    unordered_map<char, int> arrayindex;
    string charstring;
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
	int arrindex = 1;
	for(int i = 0; i<prefix.length();i++){
	  if(prefix[i]=='0'){
	    arrindex = arrindex * 2;
	  } else {
	    arrindex = arrindex * 2 + 1;
	  }
	}
	//cout << character << arrindex << endl;
	prefixcodes.insert({character[0], prefix});
	arrayindex.insert({character[0], arrindex});
	charstring.append(character);
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }
    
    set<int> arrayPos;
    listNodes * heap [5000];
    int number = 0;
    for(char g : charstring){
      listNodes * m = new listNodes;
      m->value = g;
      m->code = prefixcodes[g];
      m->number = arrayindex[g];
      heap[arrayindex[g]] = m;
      arrayPos.insert(arrayindex[g]);
    }
    
    for(int i : arrayPos){
      //cout << "ARRAY POS: " << i << "\t" <<  heap[i]->value << " " << heap[i]->code << " " << heap[i]->number << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        //sstm << bits << endl;
	int arrindex = 1;
	//cout << bits << endl;
	for(int i = 0; i<bits.length(); i++){
	  if(bits[i]=='0'){
	    arrindex = arrindex * 2;
	  } else {
	    arrindex = arrindex * 2 + 1;
	  }
	}
	cout<<heap[arrindex]->value;
	
		
    }
    cout << endl;
    file.close();

    return 0;
}
