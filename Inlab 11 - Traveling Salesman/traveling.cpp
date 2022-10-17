#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    // TODO: YOUR CODE HERE
    float minDist = computeDistance(me, dests[0], dests);
    float temp;
    string START = dests[0];
    vector<string> finalX = dests;
    dests.erase(dests.begin());
    sort(dests.begin(), dests.end());
    while(next_permutation(dests.begin(),dests.end())){
      dests.insert(dests.begin(), START);
      temp = computeDistance(me, dests[0], dests);
      if(temp < minDist){
	minDist = temp;
	finalX = dests;
      }
      dests.erase(dests.begin());
    }
    dests.insert(dests.begin(), START);
    cout << "Minimum path has distance " << minDist  << ": ";
    printRoute(finalX[0], finalX);
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
  float dist = 0.0;
  int i = 0;
  while(i<dests.size()-1){
    dist+=me.getDistance(dests[i],dests[i+1]);
    i++;
  } 
  return dist+me.getDistance(dests[dests.size()-1],dests[0]);
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
  int i = 1;
  cout << start;
  while(i<dests.size()){
    cout << " -> " << dests[i];
    i++;
  }
  cout << " -> " << start << endl;
}
