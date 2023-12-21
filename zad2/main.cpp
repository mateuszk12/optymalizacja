#include <iostream>
#include "Graph.h"

int main() {
    Graph g1 = Graph(5);
    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(0,3);
    g1.addEdge(0,4);
    g1.addEdge(1,2);
    g1.addEdge(1,4);
    g1.addEdge(1,3);
    g1.addEdge(2,3);
    g1.addEdge(4,3);
    g1.addEdge(4,2);
    g1.addWeight(0,1,1);
    g1.addWeight(0,2,1);
    g1.addWeight(0,3,1);
    g1.addWeight(0,4,1);
    g1.addWeight(1,2,1);
    g1.addWeight(1,4,1);
    g1.addWeight(2,3,1);
    g1.addWeight(3,4,1);
    g1.addWeight(2,4,2);
    g1.addWeight(1,3,2);

    //g1.displayWeights();
    //g1.kruskalMST();
//    g1.findCPP();
      g1.christofides();

}
