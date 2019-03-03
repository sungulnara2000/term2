#include "list_graph.h"

CListGraph CListGraph::GetTranspose() {
    CListGraph transposed(VerticesCount());
    for (int i = 0; i < VerticesCount(); ++i) {
        vector<int> next;
        GetNextVertices(i, next);
        for (int j : next) {
            transposed.AddEdge(j, i);
        }
    }
    return transposed;
} 