//
// Created by gulnara on 25.04.19.
//

#include "graph.h"

ListGraph::ListGraph(int vertexCount) : verticesCount(vertexCount),
                                        weightMatrix(vertexCount, vector<float>(vertexCount, std::numeric_limits<int>::max())) {
    for (int i = 0; i < weightMatrix.size(); ++i) {
        weightMatrix[i][i] = 0;
    }
}

void ListGraph::addEdge(int from, int to, float weight) {
    Edge edge(from, to, weight);
    Edge backEdge(to, from, weight);

    weightMatrix[from][to] = weight;
    weightMatrix[to][from] = weight;
}

void ListGraph::clear() {
    weightMatrix.clear();
    verticesCount = 0;
}

int ListGraph::getVerticesCount() {
    return verticesCount;
}

void ListGraph::getAllEdges(vector<Edge> &edges) {
    edges.clear();
    for (int j = 0; j < verticesCount; ++j) {
        for (int i = j + 1; i < verticesCount; ++i) {
            if (weightMatrix[j][i] != 0 && weightMatrix[j][i] != std::numeric_limits<int>::max()) {
                edges.push_back(Edge(j, i, weightMatrix[j][i]));
            }
        }
    }
}

void ListGraph::getNextEdges(int vertex, vector<Edge> &edges) {
    for (int i = 0; i < weightMatrix[vertex].size(); ++i) {
        if (weightMatrix[vertex][i] != 0 && weightMatrix[vertex][i] != std::numeric_limits<int>::max()) {
            edges.push_back(Edge(vertex, i, weightMatrix[vertex][i]));
        }
    }
}

void ListGraph::getNextVertices(int vertex, vector<float> &vertices) {
    vertices.clear();
    vertices = weightMatrix[vertex];
}
