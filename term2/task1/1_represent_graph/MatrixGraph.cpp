//
// Created by gulnara on 22.02.19.
//

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertexCount) : adjacencyMatrix(vertexCount,
                                            vector<bool>(vertexCount, false)) {}

MatrixGraph::MatrixGraph(IGraph* graph) : adjacencyMatrix(graph->VerticesCount(),
                                          vector<bool>(graph->VerticesCount(), false)) {
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        vector<int> next;
        graph->GetNextVertices(i, next);
        for (int j = 0; j < next.size(); ++j) {
            adjacencyMatrix[i][next[j]] = true;
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    adjacencyMatrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return adjacencyMatrix.size();
}

void MatrixGraph::GetNextVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (int i = 0; i < adjacencyMatrix[vertex].size(); ++i) {
        if (adjacencyMatrix[vertex][i] == true) {
            vertices.push_back(i);
        }
    }
}

void MatrixGraph::GetPrevVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (int i = 0; i < adjacencyMatrix[vertex].size(); ++i) {
        if (adjacencyMatrix[i][vertex] == true) {
            vertices.push_back(i);
        }
    }
}

