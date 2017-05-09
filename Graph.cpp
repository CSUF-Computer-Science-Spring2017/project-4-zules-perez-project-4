#include <fstream>
#include <iostream>
#include <sstream>  // for std::istringstream
#include "Graph.h"


// initialize an undirected graph that can store at most n vertices
Graph::Graph(int n) 
{
	this->n = n;
	edges.resize(n, vector<bool>(n,false));
	labels.resize(n,string());
}
// return the maximum number of vertices
int Graph::size() 
{
	return labels.size();
}

// give a string label to vertex
void Graph::addLabel(Vertex i, string s) 
{
	labelsToInt.insert(make_pair(s,i));
	intToLabels.insert(make_pair(i, s));
}


// add an edge between vertices i and j
void Graph::addEdge(Vertex i, Vertex j)
{
	edges[i][j] = true;
}

// return a vector of vertices adjacent to vertex n
vector<Vertex> Graph::getAdjacentVertices(Vertex n)
{
	
}

// return a list of names that contain friends of friends of person
// names should not be repeated
vector<string> recommendFriends(Graph &graph, const string &person) 
{
	
}

// read from a text file, the labels (names) to be associate with each vertex (int)
void readNamesFromFile(Graph &graph, const string& filename) 
{
	ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile)
		throw invalid_argument("Unable to open file " + filename);
	string s;
	int i;
	while (!inputFile.eof()) 
	{
		inputFile >> i >> s;
		// cout << "adding label " << i << ": " << s << endl;
		graph.addLabel(i, s);
	}
}

// read from a text file, the list of friends for each vertex (int)
void readFriendsFromFile(Graph &graph, const string& filename) 
{
	ifstream inputFile;
	inputFile.open(filename);
	if (!inputFile)
		throw invalid_argument("Unable to open file " + filename);

	for (string line; getline(inputFile, line); ) 
	{
		istringstream iss(line);
		int i;
		iss >> i;
		int j;
		while (!iss.eof()) 
		{
			iss >> j;
			// cout << "adding edge " << i << " to " << j << endl;
			graph.addEdge(i, j);
		}
	}
}
