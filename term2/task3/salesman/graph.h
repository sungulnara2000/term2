//
// Created by gulnara on 25.04.19.
//

#ifndef SALESMAN_GRAPH_H
#define SALESMAN_GRAPH_H


#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>
#include <stack>

using std::stack;
using std::endl;
using std::vector;
using std::make_pair;
using std::pair;
using std::unordered_set;
using std::cin;
using std::cout;

struct Edge {
    Edge() {}
    Edge(int from, int to, long weight): from(from), to(to), weight(weight) {}
    ~Edge(){}
    int from;
    int to;
    long weight;
};


// non-oriented graph with weights

class ListGraph{
public:
    ListGraph() {};
    ListGraph(int vertexCount);
//    ListGraph(const ListGraph& graph);
    void addEdge(int from, int to, long weight);

    vector<Edge> edgesList;
    vector<vector<Edge>> adjacencyList;
    vector<vector<int>> weightMatrix;
    int verticesCount;
};


#endif //SALESMAN_GRAPH_H
