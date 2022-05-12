/***************************************************************************
Name: Natalia Ksenz
Final Project
Purpose: Create a working bi-directional weighted graph class with all the
standard methods for a data structure of that type.

File: vertex.h
***************************************************************************/
#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H

#include "edge.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Vertex {
    int id;
    string city;
    vector<Edge> edgeList;
};

#endif /* GRAPH_VERTEX_H */
