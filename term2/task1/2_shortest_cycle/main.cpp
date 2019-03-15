#include <iostream>
#include "SetGraph.h"
#include "shortestCycle.h"

int main() {
    int vertexCount, edgesCount;
    std::cin >> vertexCount >> edgesCount;
    SetGraph graph(vertexCount);
    for (int i = 0; i < edgesCount; ++i) {
        int from, to;
        std::cin >> from >> to;
        graph.AddEdge(from, to);
        std::swap(from, to);
        graph.AddEdge(from, to);
    }
    int rv = shortestCycle(&graph);
    std::cout << ( (rv <= graph.VerticesCount()) ? rv : -1);
    return 0;
}