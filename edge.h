/***************************************************************************
Name: Natalia Ksenz
Final Project
Purpose: Create a working bi-directional weighted graph class with all the
standard methods for a data structure of that type.

File: edge.h
***************************************************************************/

#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include <string>

using std::string;

struct Edge {
    int destinationVertexID;
    string destinationVertexName;
    int weight;
};

#endif // GRAPH_EDGE_H
