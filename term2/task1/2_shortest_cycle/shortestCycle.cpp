//
// Created by gulnara on 24.02.19.
//

#include "SetGraph.h"
#include "vertexCycle.h"

int shortestCycle(const IGraph* graph) {
    int rv = graph->VerticesCount() + 1;
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        int currentCycle = vertexCycle(i, graph);
        if (currentCycle < rv) {
            rv = currentCycle;
        }
    }
    return rv;
}