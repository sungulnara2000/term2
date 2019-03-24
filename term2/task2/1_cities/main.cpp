#include <iostream>
#include "ListGraph.h"

using std::cin;
using std::cout;

int dijkstra(IGraph const &graph, int from, int to);

int main() {
    int n;
    int m;
    cin >> n >> m;
    ListGraph graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to, length;
        cin >> from >> to >> length;
        graph.AddEdge(from, to, length);
    }
    cin >> n >> m;
    cout << dijkstra(graph, n, m);
    return 0;
}