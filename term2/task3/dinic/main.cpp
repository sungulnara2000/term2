//
// Created by gulnara on 16.04.19.
//

#include "graph.h"
#include "MaxFlow.h"

int main() {
    int n;
    int m;
    cin >> n >> m;
    Graph graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to, capacity;
        cin >> from >> to >> capacity;
        graph.addEdge(from, to, capacity);
    }
    MaxFlow maxFlow(graph);
    cout << maxFlow.getMaxFlow(0, n-1);

    return 0;
}