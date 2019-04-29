//
// Created by gulnara on 22.02.19.
//

#include "ArcGraph.h"

using std::make_pair;

ArcGraph::ArcGraph(int vertexCount) : edges(vertexCount), vertexCount_(vertexCount) {}

ArcGraph::ArcGraph(IGraph* graph) : vertexCount_(graph->VerticesCount()) {
    for (int i = 0; i < vertexCount_; ++i) {
        vector<int> next;
        graph->GetNextVertices(i, next);
        for (int j = 0; j < next.size(); ++j) {
            auto p = make_pair(i, next[j]);
            edges.push_back(p);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    auto p = make_pair(from,to);
    edges.push_back(p);
}

int ArcGraph::VerticesCount() const {
    return vertexCount_;
}

void ArcGraph::GetNextVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (int i = 0; i < edges.size(); ++i) {
        if (edges[i].first == vertex) {
            vertices.push_back(edges[i].second);
        }
    }
}

void ArcGraph::GetPrevVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (int i = 0; i < edges.size(); ++i) {
        if (edges[i].second == vertex) {
            vertices.push_back(edges[i].first);
        }
    }
}

