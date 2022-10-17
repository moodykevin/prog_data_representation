// Kevin Moody
// CS 2150
// Lab10 Huffman encoding
// Spring 2022

#include "heap.h"
#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int numofSym;
unordered_map<char, string> codes;

// Print function at beginning, read online article on how to print Huff trees
void printHuff(HuffmanNode * h, string s){
  if(h == NULL){
    return;
  }
  if(h->value != '\n'){
    codes.insert({h->value, s});
    if(h->value == ' '){
      cout << "space" << " " << s << "\n";
    } else {
      cout << h->value << " " << s << "\n";
    }
  }
  printHuff(h->left, s + "0");
  printHuff(h->right, s + "1");
}

int main(int argc, char** argv){
  //Error checking
  if (argc != 2){
    cout<<"Must supply input file name as one and only parameter"<<endl;
    exit(1);
  }
  ifstream file(argv[1]);
  if (!file.is_open()){
    cout << "Unable to open specified file for reading" << endl;
    exit(2);
  }

  // Set length and number of different symbols to 0
  int length = 0;
  int numofSym = 0;

  // Create dictionary (unordered map) to store frequency of a given character
  unordered_map<char, int> frequency;
  // Create string from text file, found on GeeksForGeeks
  string filestring((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
  filestring.pop_back(); // Remove newline character at end, found through trial and error

  int k = 0;
  char heap[256];
  // Add each character to the unordered map, unless already in it, then increase value saved in map by 1
  for(char g : filestring){
    if(g=='\n'||g=='\t'){ // If not a printable character, do nothing
    }else if(frequency.find(g) == frequency.end()){
      frequency.insert({g,1});
      numofSym++;
      heap[k]=g;
      k++;
      length++;
    }else{
      frequency[g]++;
      length++;
    }
  }
  // SELECTION SORT to SORT HEAP, found psuedocode online for selection sort and adapted to fit map/array setup that I used
  int min, temp;
  for(int i = 0; i<numofSym-1; i++){
    min = i;
    for(int j = i+1; j<numofSym; j++){
      char heapj =heap[j];
      char heapmin =heap[min];
      if(frequency[heapj] < frequency[heapmin]){
	min = j;
      }
    }
    if(min!=i){
      temp = heap[i];
      heap[i] = heap[min];
      heap[min] = temp;
    }
  }

  // Creating main array of huffman node pointers
  HuffmanNode* heap2 [numofSym];
  for(int i = 0; i < numofSym; i++){
    HuffmanNode * h = new HuffmanNode(heap[i], frequency[heap[i]]);
    heap2[i] = h;
  }
  int numOfNodes = numofSym;
  // Create interior nodes, initializing to newline character
  while(numOfNodes>1){
    HuffmanNode * m = new HuffmanNode();
    m->value = '\n';
    m->left = heap2[0];
    m->right= heap2[1];
    m->frequency = heap2[0]->frequency + heap2[1]->frequency;
    // Shifting all nodes over two spots to the left
    if(numOfNodes >2){
      for(int l = 2; l<numOfNodes;l++){
	heap2[l-2] = heap2[l];
      }
      numOfNodes-=2;
      int justGreaterINDX = heap2[0]->frequency;
      for(int k = 0; k < numOfNodes; k++){
	if(heap2[k]->frequency <= m->frequency){
	  justGreaterINDX = k;
	}
      }
      justGreaterINDX+=1;
      numOfNodes+=1;
      // Adding new interior node into center of list where it should be
      for(int i = numOfNodes; i >= justGreaterINDX; i--){
	heap2[i] = heap2[i-1];
      }
      heap2[justGreaterINDX] = m;
    } else { // If numOfNodes is equal to 2, last two nodes
      numOfNodes = 1;
      heap2[0] = m;
    }
  }
  //Using print funciton from above
  printHuff(heap2[0], "");
  
  
  cout << "----------------------------------------" << endl;
  string s0;
  for (char g : filestring){
    cout << codes[g] << " ";
    s0.append(codes[g]);
  }
  cout << endl << "----------------------------------------" << endl;
  int olength = length*8;
  int clength = s0.length();
  float cratio = (float)olength/clength;
  float cost = (float)clength/length;
  cout << "There are a total of " << length << " symbols that are encoded." << endl;
  cout << "There are " << numofSym  << " distinct symbols used." << endl;
  cout << "There were " << olength << " bits in the original file." << endl;
  cout << "There were " << clength << " bits in the compressed file." << endl;
  cout << "This gives a compression ratio of " << fixed << setprecision(5) << cratio <<  "." << endl;
  cout << "The cost of the Huffman tree is " << fixed << setprecision(5) << cost << " bits per character." << endl;
}
