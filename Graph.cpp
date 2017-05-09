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
	labelsToInt[s] = i;
}

// add an edge between vertices i and j
void Graph::addEdge(Vertex i, Vertex j)
{
	edges[i][j] = true;
}

// return a vector of vertices adjacent to vertex n
vector<Vertex> Graph::getAdjacentVertices(Vertex N)
{
	vector<Vertex> vertices;
	vector<vector<bool>>::iterator row;
	vector<bool>::iterator col;

	if (N == 0)
	{
		for (row = edges.begin(); row != edges.end(); row++)
		{
			if (row->at(N) == true)
			{
				vertices.push_back(row->at(N));
			}

		}
		return vertices;
	}
	else
	{
		for (row = edges.begin(); row != edges.end(); row++)
		{
			for (col = row->begin(); col != row->end(); col++)
			{
				if (row->at(N) == true)
				{
					vertices.push_back(row->at(N).operator=(col.operator*()));
				}
			}
		}
		return vertices;
	}
}

// return a list of names that contain friends of friends of person
// names should not be repeated
vector<string> recommendFriends(Graph &graph, const string &person) 
{
	vector<string> v;
	return v;
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

string Graph::getLabel(Vertex N)
{
	return labels[N];
}

Vertex Graph::getVertex(string label)
{
	if (labelsToInt.find(label) != labelsToInt.end())
		return labelsToInt.find(label)->second;
	else
		return 0;
}
