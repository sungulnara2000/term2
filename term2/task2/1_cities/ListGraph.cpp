//
// Created by gulnara on 24.03.19.
//

#include "ListGraph.h"

ListGraph::ListGraph(int vertexCount) : adjacencyList(vertexCount) {}

void ListGraph::AddEdge(int from, int to, int length) {
    adjacencyList[from].push_back(make_pair(to, length));
    adjacencyList[to].push_back(make_pair(from, length));
}

int ListGraph::VerticesCount() const {
    return adjacencyList.size();
}

void ListGraph::GetAdjacentVertices(int vertex, vector<pair<int, int>>& vertices) const {
    vertices.clear();
    vertices = adjacencyList[vertex];
}



