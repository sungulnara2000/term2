//
// Created by gulnara on 22.02.19.
//

#include "SetGraph.h"

SetGraph::SetGraph(int vertexCount) : vertexCount_(vertexCount), arrayOfSets(vertexCount) {}

SetGraph::SetGraph(IGraph* graph) : vertexCount_(graph->VerticesCount()), arrayOfSets(graph->VerticesCount()) {
    for (int i = 0; i < vertexCount_; ++i) {
        vector<int> next;
        graph->GetNextVertices(i, next);
        arrayOfSets[i].insert(next.begin(), next.end());
    }
}

void SetGraph::AddEdge(int from, int to) {
    arrayOfSets[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return vertexCount_;
}

void SetGraph::GetNextVertices(int vertex, vector<int>& vertices) const {
    for(auto itr = arrayOfSets[vertex].begin(); itr != arrayOfSets[vertex].end(); ++itr) {
        vertices.push_back(*itr);
    }
}

void SetGraph::GetPrevVertices(int vertex, vector<int>& vertices) const {
    for (int i = 0; i < vertexCount_; ++i) {
        if (arrayOfSets[i].find(vertex) != arrayOfSets[i].end()) {
            vertices.push_back(i);
        }
    }
}

