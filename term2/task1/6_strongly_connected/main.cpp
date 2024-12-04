#include "list_graph.h"

#include <iostream>


using namespace std;

#include "StronglyConnected.h"

int main() {
    int vertexCount;
    int edgesCount;
    std::cin >> vertexCount >> edgesCount;
    CListGraph graph(vertexCount);
    for (int i = 0; i < edgesCount; i++) {
        int from;
        int to;
        cin >> from >> to;
        graph.AddEdge(from - 1, to - 1);
    }

    StronglyConnected sc;
    cout << sc.CountAddEdges(graph);

    return 0;
}