/***************************************************************************
Name: Natalia Ksenz
Final Project
Purpose: Create a working bi-directional weighted graph class with all the
standard methods for a data structure of that type.

File: graph.cpp
***************************************************************************/

#include "graph.h"

Graph::~Graph() {
    clearGraph();
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

bool Graph::addEdge(int from, pair<int,int> edge) {
    bool added = false;
    int to = edge.first;
    int weight = edge.second;
    if (vertexExists(from) && vertexExists(to) && !edgeExists(from, to)) {
        for (int i = 0; i < vertexList.size(); i++) {
            if (vertexList.at(i).id == from) {
                Edge temp;
                temp.destinationVertexID = to;
                temp.destinationVertexName = vertexList.at(to).city;
                temp.weight = weight;
                vertexList.at(i).edgeList.push_back(temp);
                added = true;
            }
            else if (vertexList.at(i).id == to) {
                Edge temp;
                temp.destinationVertexID = from;
                temp.destinationVertexName = vertexList.at(from).city;
                temp.weight = weight;
                vertexList.at(i).edgeList.push_back(temp);
                added = true;
            }
        }
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

bool Graph::edgeExists(int from, int to) {
    bool found = false;
    Vertex temp = vertexList[from];
    for (auto i = temp.edgeList.begin(); i < temp.edgeList.end(); i++) {
        if (i->destinationVertexID == to) {
            found = true;
        }
    }
    return found;
}

int Graph::getWeight(int from, int to) {
    int weight;
    if (edgeExists(from, to )) {
        for (auto i = vertexList.at(from).edgeList.begin(); i < vertexList.at(from).edgeList.end(); i++) {
            if (i->destinationVertexID == to) {
                weight = i->weight;
            }
        }
    }
    return weight;
}

bool Graph::deleteEdge(int from, int to) {
    bool deleted = false;
    if (edgeExists(from, to)) {
        for (auto i = vertexList.at(from).edgeList.begin(); i < vertexList.at(from).edgeList.end(); i++) {
            if (i->destinationVertexID == to) {
                vertexList.at(from).edgeList.erase(i);
                deleted = true;
            }
        }
        for (auto i = vertexList.at(to).edgeList.begin(); i < vertexList.at(to).edgeList.end(); i++) {
           if (i->destinationVertexID == from) {
                vertexList.at(to).edgeList.erase(i);
                deleted = true;
           }
        }
    }
    return deleted;
}

bool Graph::deleteVertex(int from) {
    bool deleted = false;
    if (vertexExists(from)) {
        for (int i = 0; i < vertexList.size(); i++) {
            deleteEdge(from, i);
        }
        vertexList.erase(vertexList.begin() + from);
        deleted = true;
    }
    return deleted;
}

void Graph::printGraph() {
    if (vertexList.empty()) {
        cout << "The graph is empty." << endl;
    }
    else {
        for (int i = 0; i < vertexList.size(); i++) {
            cout << vertexList[i].id << ": " << vertexList[i].city;
            for (int j = 0; j < vertexList[i].edgeList.size(); j++) {
                cout << " --> " << vertexList[i].edgeList[j].destinationVertexName
                <<  ": " << vertexList[i].edgeList[j].weight;
            }
            cout << endl;
        }
    }
    return;
}

void Graph::depthFirst(int fVert) {
    bool *visited = new bool[MAXVECTSIZE-1];
    for (int i = 0; i < (MAXVECTSIZE-1); i++) {
        visited[i] = false;
    }
    depthFirst(fVert, visited);
}

void Graph::depthFirst(int vert, bool visited[]) {
    visited[vert] = true;
    cout << vert << " ";

    for (auto i = vertexList.at(vert).edgeList.begin(); i != vertexList.at(vert).edgeList.end(); i++) {
        if (visited[i->destinationVertexID] != true) {
            depthFirst(i->destinationVertexID, visited);
        }
    }
    return;
}

void Graph::breadthFirst(int fVert) {
    bool *visited = new bool[MAXVECTSIZE-1];
    for (int i = 0; i < (MAXVECTSIZE-1); i++) {
        visited[i] = false;
    }
    breadthFirst(fVert, visited);
    return;
}

void Graph::breadthFirst(int vert, bool visited[]) {
    visited[vert] = true;
    list<int> queue;
    queue.push_back(vert);

    while(!queue.empty()) {
       // Dequeue a vertex from queue and print it
       vert = queue.front();
       cout << vert << " ";
       queue.pop_front();

       // Get all adjacent vertices of the dequeued
       // vertex s. If a adjacent has not been visited,
       // then mark it visited and enqueue it
       for (auto i = vertexList.at(vert).edgeList.begin(); i != vertexList.at(vert).edgeList.end(); i++) {
           if (visited[i->destinationVertexID] != true) {
             visited[i->destinationVertexID] = true;
             queue.push_back(i->destinationVertexID);
           }
       }
    }
    return;
}

void Graph::clearGraph() {
    for (int i = 0; i < vertexList.size(); i++) {
          vertexList[i].edgeList.clear();
    }
    vertexList.clear();
    return;
}
