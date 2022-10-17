// Kevin Moody
// CS 2150
// Lab 11 Prelab
// Spring 2022

#include <fstream>
#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Topological sort of a given graph as adjacency list
 * @return None, but will cout a valid topological map
 * @param NumV Number of vertices
 * @param indegree Map of each string's indegree value
 * @param index Map of each string's index in the graph
 * @param indexQ Map of each index in graph to string
 * @param graph Arrray of vectors for adjacency list
 * @author Kevin Moody
 * @date April 25 2022
 */
void topSort(int NumV, unordered_map<string,int> indegree, unordered_map<string,int> index, unordered_map<int,string> indexQ, vector<string> graph[NumV]){
   queue<string> q;
    string x, v;
    for (int i = 0; i < NumV; i++){
      x = indexQ[i];
      if(indegree[x]==0){
	q.push(x);
      }
    }
    while(!q.empty()) {
      v = q.front();
      q.pop();
      cout << v << " ";
      for (string x : graph[index[v]]){
	indegree[x]--;
	if(indegree[x]==0){
	  q.push(x);
	}
      }
    }
    cout << endl;
}


/**
 * @brief Given a input of edges between two vertices, creates a topological
 * sort for the graph created by edges/vertices
 *
 * @return 0; main method
 * @param argc The input string as a text file, ending in /n 0 0
 * @param argv Index of the given commandline parameter
 *
 * @todo: NULL
 * @author Kevin Moody
 * @date April 25 2022
 *
 */

int main(int argc, char** argv) {
   // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
  
    string s1, s2;
    set<string> vertexes;
    int NumV = 0;
    unordered_map<string, int> index;
    unordered_map<int, string> indexQ;
    unordered_map<string, int> indegree;
    int i = 0;

    
    while(true){
      file >> s1;
      file >> s2;
      if(s1 == "0" && s2 == "0"){
	break;
      } else {
	if(vertexes.find(s1) == vertexes.end()){
	  vertexes.insert(s1);
	  NumV++;
	  //cout << s1 << endl;
	  index.insert({s1,i});
	  indexQ.insert({i,s1});
	  i++;
	}
	if(vertexes.find(s2) == vertexes.end()){
	  vertexes.insert(s2);
	  NumV++;
	  //cout << s2 << endl;
	  index.insert({s2, i});
	  indexQ.insert({i,s2});
	  i++;
	}
      }
    }
    file.seekg(0);
    /**
     * @brief Goes thrugh the file input and creates adjacency list for each vertex and edge
     * @return none
     * @param NumV The number of vertices
     * @param file The file to search through
     * @param graph An array of vectors to use for adjacency list
     **/
    vector<string> graph[NumV];
    while(true){
      file >> s1;
      file >> s2;
      if(s1 == "0" && s2 == "0"){
	break;
      } else {
	indegree[s2]++;
	graph[index[s1]].push_back(s2);
      }
    }
    topSort(NumV, indegree, index, indexQ, graph);
    file.close();
    return 0;
}
