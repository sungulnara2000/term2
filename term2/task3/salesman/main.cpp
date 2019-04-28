#include "graph.h"
#include "TSP.h"

void MST(ListGraph& inputGraph, ListGraph& mst);

// undirected everywhere
// addEdge adds from-to and to-from edges

int main() {
    int n;
    int m;
    cin >> n >> m;
    ListGraph graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to;
        long weight;
        cin >> from >> to >> weight;
        graph.addEdge(from, to, weight);
    }
    TSP tsp(graph);
    vector<int> way;
    tsp.findWay(way);
    for (auto i : way){
        cout << i << " ";
    }
    return 0;
}