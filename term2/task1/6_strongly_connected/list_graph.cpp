#include "list_graph.h"

CListGraph::CListGraph(int vertexCount) : adjacencyList(vertexCount), colors(vertexCount) {
}

void CListGraph::AddEdge(int from, int to) {
    adjacencyList[from].push_back(to);
}

int CListGraph::VerticesCount() const {
    return adjacencyList.size();
}

void CListGraph::GetNextVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    vertices = adjacencyList[vertex];
}

void CListGraph::GetPrevVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (int i = 0; i < adjacencyList.size(); i++) {
        for (int second : adjacencyList[i]) {
            if (second == vertex) {
                vertices.push_back(i);
            }
        }
    }
}

void CListGraph::DFS(int vertex, vector<bool>& visited, vector<int>& order) {
    visited[vertex] = true;
    vector<int> next;
    GetNextVertices(vertex, next);

    for (int i : next) {
        if (!visited[i]) {
            DFS(i, visited, order);
        }
    }
    order.push_back(vertex);
}

void CListGraph::TransposeDFS(int vertex, vector<bool>& visited, vector<int>& component, CListGraph transposed) {
    visited[vertex] = true;
    vector<int> next;
    transposed.GetNextVertices(vertex, next);
    component.push_back(vertex);
    for (int i : next) {
        if (!visited[i]) {
            TransposeDFS(i, visited, component, transposed);
        }
    }
}

