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
    string names2[TESTDATA2] = {"San Angelo", "Big Spring", "Midland", "Fort Stockton"};
    vector<pair<int, pair<int,int>>> edges2 = {
                              {0,{8,205}},
                              {5,{8,227}},
                              {8,{9,87}}, {8,{10,112}},
                              {9,{10,40}},
                              {10,{11,105}}
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

     cout << "\nChecking the Graph" << endl;
     cout << "==============================================" << endl;
     graph.printGraph();

     /*
     *  DFS and BFS traversals
     */
     cout << "\nDepth-First Traversal" << endl;
     cout << "==============================================" << endl;
     int fVert = rand()%(TESTDATA1 + TESTDATA2);
     cout << "Starting at the vertex " << fVert << "... " << endl;
     graph.depthFirst(fVert);
     cout << endl;

     cout << "\nBreadth-First Traversal" << endl;
     cout << "==============================================" << endl;
     graph.breadthFirst(fVert);
     cout << endl;


     cout << "\nChecking if random vertices are neighbours" << endl;
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

     cout << "\nAdding more vertices" << endl;
     cout << "==============================================" << endl;
     for (int i = 0; i < TESTDATA2; i++) {
         cout << "Adding " << TESTDATA1 + i << ": " << names2[i] << "...";
         if (graph.addVertex((TESTDATA1 + i), &names2[i])) {
             cout << "added." << endl;
         }
         else {
             cout << "not added." << endl;
         }
     }
     cout << "\nAdding more edges" << endl;
     cout << "==============================================" << endl;
     for (int i = 0; i < edges2.size(); i++) {
        cout << "Adding the edge between " << edges2[i].first << " and " <<
        edges2[i].second.first << " with weight " << edges2[i].second.second << "... ";
        if (graph.addEdge(edges2[i].first, edges2[i].second)) {
            cout << "added." << endl;
        }
        else {
            cout << "NOT added." << endl;
        }
     }

     cout << "\nChecking the Graph" << endl;
     cout << "==============================================" << endl;
     graph.printGraph();

     /*
     *  DFS and BFS traversals
     */
     cout << "\nDepth-First Traversal" << endl;
     cout << "==============================================" << endl;
     //int fVert = rand()%(TESTDATA1 + TESTDATA2);
     cout << "Starting at the vertex " << fVert << "... " << endl;
     graph.depthFirst(fVert);
     cout << endl;

     cout << "\nBreadth-First Traversal" << endl;
     cout << "==============================================" << endl;
     graph.breadthFirst(fVert);
     cout << endl;


     /*
     *  delete vertices and edges
     */
     cout << "\nDeleting random edges" << endl;
     cout << "==============================================" << endl;
     for (int i = 0; i < TESTDATA2; i++) {
        int delEdgeFrom = rand()%(TESTDATA1+TESTDATA2);
        int delEdgeTo = rand()%TESTDATA1;
        cout << "Deleting the edge between " << delEdgeFrom << " and " << delEdgeTo << "... ";
        if (graph.deleteEdge(delEdgeFrom, delEdgeTo)) {
            cout << "deleted." << endl;
        }
        else {
            cout << "NOT deleted." << endl;
        }
     }

     cout << "\nChecking the Graph" << endl;
     cout << "==============================================" << endl;
     graph.printGraph();

     cout << "\nDeleting random vertex" << endl;
     cout << "==============================================" << endl;
     int delVert = rand()%(TESTDATA1 + TESTDATA2);
     cout << "Deleting the vertex " << delVert << "... ";
     if (graph.deleteVertex(delVert)) {
         cout << "vertex and all its edges deleted." << endl;
     }
     else {
         cout << "NOT deleted." << endl;
     }

     cout << "\nChecking the Graph" << endl;
     cout << "==============================================" << endl;
     graph.printGraph();


     /*
     *  delete vertices
     */
     cout << "\nDeleting more vertices" << endl;
     cout << "==============================================" << endl;
     for (int i = 0; i < TESTDATA2; i++) {
        int delVert = rand()%(TESTDATA1 + TESTDATA2);
        cout << "Deleting the vertex " << delVert << "... ";
        if (graph.deleteVertex(delVert)) {
         cout << "vertex and all its edges deleted." << endl;
        }
        else {
         cout << "NOT deleted." << endl;
       }
     }

     cout << "\nChecking the Graph" << endl;
     cout << "==============================================" << endl;
     graph.printGraph();

     cout << "\nClearing the Graph" << endl;
     cout << "==============================================" << endl;
     graph.clearGraph();
     graph.printGraph();

     cout << endl;
     return 0;
}
