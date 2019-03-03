#include <iostream>
#include "SetGraph.h"

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
    int rv = graph.shortestCycle();
    std::cout << ( (rv <= graph.VerticesCount()) ? rv : -1);
    return 0;
}