//
// Created by gulnara on 16.04.19.
//

#include <cmath>
#include "graph.h"

Graph::Graph(int vertexCount) : adjacencyList(vertexCount) {}

void Graph::addEdge(int from, int to, int capacity) {
    Edge edge(from, to, capacity, adjacencyList[to].size());
    Edge back_edge(to, from, 0, adjacencyList[from].size());
    adjacencyList[from].push_back(edge);
    adjacencyList[to].push_back(back_edge);
}

int Graph::verticesCount() const {
    return adjacencyList.size();
}

void Graph::getAdjacentVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (auto i : adjacencyList[vertex]) {
        vertices.push_back(i.to);
    }
}

void Graph::clear() {
    for (auto& i : adjacencyList) {
        for (auto& edge : i) {
            edge.capacity = 0;
        }
    }
}

void Graph::getEdges(int vertex, vector<Edge>& buffer) {
    buffer.clear();
    buffer = adjacencyList[vertex];
}