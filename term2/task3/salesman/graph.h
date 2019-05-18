//
// Created by gulnara on 25.04.19.
//

#ifndef SALESMAN_GRAPH_H
#define SALESMAN_GRAPH_H

#include <vector>
#include <limits>
#include <math.h>

using std::vector;
using std::min;

struct Edge {
    Edge() {}
    Edge(int from, int to, float weight): from(from), to(to), weight(weight) {}
    ~Edge(){}
    int from;
    int to;
    float weight;
};

struct City{
    float x;
    float y;
};

// non-oriented graph with weights

class MatrixGraph{
public:
    MatrixGraph() {};
    MatrixGraph(int vertexCount);
    void addEdge(int from, int to, float weight);
    int getVerticesCount();
    void clear();
    void getAllEdges(vector<Edge>& edges);
    void getNextEdges(int vertex, vector<Edge>& edges);
    void getNextVertices(int vertex, vector<float>& vertices);
private:
    vector<vector<float>> weightMatrix;
    int verticesCount;
};


#endif //SALESMAN_GRAPH_H
