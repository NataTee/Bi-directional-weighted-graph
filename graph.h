/***************************************************************************
Name: Natalia Ksenz
Final Project
Purpose: Create a working bi-directional weighted graph class with all the
standard methods for a data structure of that type.

File: graph.h
***************************************************************************/
#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "vertex.h"
#include <iostream>     /* cout, endl */
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::pair;
using std::cout;
using std::endl;

class Graph {

public:
    Graph();

    bool addVertex(int, string*);
    bool addEdge(int, pair<int,int>);
    void printGraph();
    bool edgeExists(int, int);
    vector<Vertex> vertexList;

private:
    bool vertexExists(int);
};

#endif /* GRAPH_GRAPH_H */
