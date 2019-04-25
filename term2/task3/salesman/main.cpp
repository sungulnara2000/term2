#include "graph.h"

long MSTweight(ListGraph& graph);

int main() {
    int n;
    int m;
    cin >> n >> m;
    ListGraph graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to;
        long weight;
        cin >> from >> to >> weight;
        graph.AddEdge(from - 1, to - 1, weight);
    }
    cout << MSTweight(graph);
    return 0;
}