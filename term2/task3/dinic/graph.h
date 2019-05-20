//
// Created by gulnara on 16.04.19.
//

#ifndef DINIC_GRAPH_H
#define DINIC_GRAPH_H


#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <queue>
#include <unordered_map>

using std::unordered_map;
using std::queue;
using std::vector;
using std::make_pair;
using std::pair;
using std::unordered_set;
using std::cin;
using std::cout;

struct Edge {
    Edge() {}
    Edge(int from, int to, int capacity, int backID): from(from),
                                          to(to),
                                          capacity(capacity),
                                          backID(backID){}
    int from;
    int to;
    int capacity;
    int backID;
};

class Graph{
public:
    Graph(){};
    Graph(int vertexCount);
    void addEdge(int from, int to, int capacity);
    int verticesCount() const;
    void getAdjacentVertices(int vertex, vector<int>& vertices) const;
    void clear();
    void getEdges(int vertex, vector<Edge>& buffer); // НАХОДИТ РЕБРА, ИНЦИДЕНТНЫЕ ВЕРШИНЕ

private:
    vector<vector<Edge>> adjacencyList;
};

#endif //DINIC_GRAPH_H
