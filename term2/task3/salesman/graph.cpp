//
// Created by gulnara on 25.04.19.
//

#include "graph.h"

ListGraph::ListGraph(int vertexCount) : VerticesCount(vertexCount) {}

void ListGraph::AddEdge(int from, int to, long weight) {

    Edge edge(from, to, weight);
    edgesList.push_back(edge);
}
