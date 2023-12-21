#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

class Graph
{
    int vert;
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> weights;
    std::vector<std::vector<int>> Doubleweights;
public:
    Graph(int vertecies);
    void showMatrix();
    void removeVertex(int num);
    void addVertex();
    void removeEdge(int s, int e);
    void addEdge(int s, int e);
    void addWeight(int s, int e, int w);
    void sortWeights();
    int weightsSum();
    int numEdges();
    std::vector<std::vector<int>> getWeights();
    void displayWeights();
    int degreeV(int num);
    void showDegree(int num);
    void maxDegree();
    void minDegree();
    int numEven();
    int numOdd();
    void sequence();
    void findCycle3naive();
    void findCycle3fancy();
    void findCycleDfs(int vert);
    std::vector<std::vector<int>> dfs(int vert);
    void drawSpanningTree(int vert);
    std::vector<std::vector<int>> multiplyMatrices();
    std::vector<int> fleurAlgorithm(int vert);
    std::vector<int> countDegrees();
    std::vector<std::vector<int>> kruskalMST();
    bool isEulerinan();
    bool isSemiEulerian();
    std::vector<std::vector<int>> findCPP();

    std::vector<std::vector<int>> dijkstra(int a);
    int getWeight(int a, int b);
    std::vector<int> getNeighbours(int i);
    int findMin();
    int getMin(std::vector<int>, std::vector<int>);
    int getMin(std::vector<int> from, std::vector<int> to, int start);
    int minDistance(int a, int b);
    std::vector<int> getDijkstraPath(int a, int b);
    bool isBridge(int a, int b);
    std::vector<std::vector<int>> dfs(std::vector<std::vector<int>> graph, int vert);
    std::vector<int> getOdd();
    std::vector<std::vector<int>> getMinimalWeightMatch();
    std::vector<std::vector<int>> getEdgesForCPP();

    int getMaxWeight();


    void addDoubleEdges(int s, int e, int w);

    std::vector<int> christofides();

    std::vector<std::vector<int>> findEdges(int a, int b);

    std::vector<std::vector<int>> findEdges(std::vector<int> ed);

    bool triangle();
};
