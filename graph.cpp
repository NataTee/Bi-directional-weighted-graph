/***************************************************************************
Name: Natalia Ksenz
Final Project
Purpose: Create a working bi-directional weighted graph class with all the
standard methods for a data structure of that type.

File: graph.cpp
***************************************************************************/

#include "graph.h"

Graph::Graph() {

}

bool Graph::addVertex(int id, string *name) {
    bool added = false;
    if (!vertexExists(id)) {
        Vertex temp;
        temp.id = id;
        temp.city = *name;
        vertexList.push_back(temp);
        added = true;
    }
    return added;
}

bool Graph::vertexExists(int id) {
    bool found = false;
    for (int i = 0; i < vertexList.size(); i++) {
        if (vertexList.at(i).id == id) {
            found = true;
        }
    }
    return found;
}

void Graph::printGraph() {
    if (vertexList.size() == 0) {
        cout << "The graph is empty" << endl;
    }
    else {
        for (int i = 0; i < vertexList.size(); i++) {
            cout << vertexList[i].id << ": " << vertexList[i].city << endl;
        }
    }
    return;
}
