#pragma once
#include <vector>
#include <string>
#include <map>

typedef int Vertex;
using namespace std;

class Graph 
{
public:
	Graph(int n);
	int size();
	void addLabel(Vertex i, string s); 
	void addEdge(Vertex i, Vertex j);
	vector<Vertex> getAdjacentVertices(Vertex); // TO DO

	Vertex getVertex(string label); // OPTIONAL: may help your code
	string getLabel(Vertex n); // OPTIONAL: may help your code

private:
	// member variables and functions to implement the public member functions
	map<string,Vertex> labelsToInt;
	map<Vertex,string> intToLabels;
	vector<vector<bool>> edges;
};

// TO DO
// return a list of names that contain friends of friends of person
// names should not be repeated
vector<string> recommendFriends(Graph &graph, const string& person);

// read from a text file, the labels (names) to be associate with each vertex (int)
void readNamesFromFile(Graph &graph, const string& filename);

// read from a text file, the list of friends for each vertex (int)
void readFriendsFromFile(Graph &graph, const string& filename);
