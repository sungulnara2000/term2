//
// Created by gulnara on 24.02.19.
//

#include "SetGraph.h"
#include "vertexCycle.h"

int shortestCycle(const IGraph* graph) {
    int rv = graph->VerticesCount() + 1;
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        rv = std::min(vertexCycle(i, graph), rv);
    }
    return rv;
}