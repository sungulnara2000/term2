#include <iostream>

#include "SetGraph.h"

int main() {
    int vertexCount;
    int edgesCount;
    std::cin >> vertexCount >> edgesCount;
    SetGraph graph(vertexCount);
    for (int i = 0; i < edgesCount; ++i) {
        int from;
        int to;
        std::cin >> from >> to;
        graph.AddEdge(from, to);
        std::swap(from, to);
        graph.AddEdge(from, to);
    }
    int start;
    int finish;
    std::cin >> start >> finish;
    std::cout << graph.bfs(start, finish);
    return 0;
}