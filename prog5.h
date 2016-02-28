#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;





void buildMineField(vector<vector<bool>>&, const double&);
void fixCounts(const vector<vector<bool>>&, vector<vector<unsigned>>&);
void displayMineLocations(const vector<vector<bool>>&);
void displayMineCounts(const vector<vector<unsigned>>&);

