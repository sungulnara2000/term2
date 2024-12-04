//
// Created by gulnara on 22.02.19.
//

#include <limits>
#include "ListGraph.h"

ListGraph::ListGraph(int vertexCount) : adjacencyList(vertexCount) {
}

ListGraph::ListGraph(IGraph* graph) : adjacencyList(graph->VerticesCount(), vector<int>(0)) {
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        graph->GetNextVertices(i, adjacencyList[i]);
    }
}

void ListGraph::AddEdge(int from, int to) {
    adjacencyList[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return adjacencyList.size();
}

void ListGraph::GetNextVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    vertices = adjacencyList[vertex];
}

void ListGraph::GetPrevVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (int i = 0; i < adjacencyList.size(); i++) {
        for (int second : adjacencyList[i]) {
            if (second == vertex) {
                vertices.push_back(i);
            }
        }
    }
}

