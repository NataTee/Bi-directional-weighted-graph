/***************************************************************************
Name: Natalia Ksenz
Final Project
Purpose: Create a working bi-directional weighted graph class with all the
standard methods for a data structure of that type.

File: main.cpp
***************************************************************************/

#include "main.h"

int main(int argc, char** argv) {
    srand(time(NULL));

    /*
    *  test data
    */

    string names1[TESTDATA1] = {"Austin", "San Marcos", "San Antonio", "Houston",
                                "Dallas", "Fort Worth", "Beaumont", "Corpus Christi"};
    vector<pair<int, pair<int,int>>> edges = {
                              {0,{1,31}}, {0,{2,80}}, {0,{3,162}}, {0,{4,195}},
                              {1,{2,49}},
                              {2,{3,197}}, {2,{7,145}},
                              {3,{4,239}}, {3,{6,85}},
                              {4,{5,32}}
                              };

    /*
    *  make and display graph
    */
    Graph graph;
    cout << endl << "Graph created" << endl << endl;
    graph.printGraph();

    /*
    *  fill in the graph
    */
    cout << "\nFilling the Graph" << endl;
    cout << "==============================================" << endl;

    for (int i = 0; i < TESTDATA1; i++) {
        cout << "Adding " << i << ": " << names1[i] << "...";
        if (graph.addVertex(i, &names1[i])) {
            cout << "added." << endl;
        }
        else {
            cout << "not added." << endl;
        }
    }

    cout << "\nChecing the Graph" << endl;
    cout << "==============================================" << endl;
    graph.printGraph();

    /*
    *  make connections between vertices
    */
     cout << "\nAdding the Edges" << endl;
     cout << "==============================================" << endl;
     for (int i = 0; i < edges.size(); i++) {
        cout << "Addign the edge between " << edges[i].first << " and " <<
        edges[i].second.first << " with weight " << edges[i].second.second << "... ";
        if (graph.addEdge(edges[i].first, edges[i].second)) {
            cout << "added." << endl;
        }
        else {
            cout << "NOT added." << endl;
        }
     }

     cout << "\nChecing the Graph" << endl;
     cout << "==============================================" << endl;
     graph.printGraph();

     cout << "\nChecking if vertices are neighbours" << endl;
     cout << "==============================================" << endl;
     for (int i = 0; i < TESTDATA1/2; i++) {
        int vert1 = rand()%TESTDATA1;
        int vert2 = rand()%(TESTDATA1-1);
        cout << "Checking vertices " << vert1 << " and " << vert2 << "... ";
        if (graph.edgeExists(vert1, vert2)) {
            cout << "neighbours." << endl;
        }
        else {
            cout << "NOT neighbours." << endl;
        }
     }

     /*
     *  delete vertices and edges
     */
     cout << "\nDeleting random edges" << endl;
     cout << "==============================================" << endl;
     for (int i = 0; i < TESTDATA1/2; i++) {
        int delEdgeFrom = rand()%TESTDATA1;
        int delEdgeTo = rand()%(TESTDATA1-1);
        cout << "Deleting the edge between " << delEdgeFrom << " and " << delEdgeTo << "... ";
        if (graph.deleteEdge(delEdgeFrom, delEdgeTo)) {
            cout << "deleted." << endl;
        }
        else {
            cout << "NOT deleted." << endl;
        }
     }

     cout << "\nChecing the Graph" << endl;
     cout << "==============================================" << endl;
     graph.printGraph();


     cout << endl;
     return 0;
}
