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

    int ids1[TESTDATA1] = {1, 2, 3, 4, 5};
    string strings1[TESTDATA1] = {"Austin", "San Marcos", "San Antonio", "Houston", "Dallas"};

    /*
     *  make and display graph
     */
    Graph graph;
    cout << endl << "Graph created" << endl << endl;
    graph.printGraph();

    cout << "Filling the Graph" << endl;
    cout << "==============================================" << endl;

    for (int i = 0; i < TESTDATA1; i++) {
        cout << "Adding " << ids1[i] << ": " << strings1[i] << "...";
        if (graph.addVertex(ids1[i], &strings1[i])) {
            cout << "added." << endl;
        }
        else {
            cout << "not added." << endl;
        }
    }
    cout << endl;
    graph.printGraph();

    cout << endl;
    return 0;
}
