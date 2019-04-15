//
// Created by gulnara on 14.04.19.
//

#include "graph.h"

int main() {
//    int n;
//    int m;
//    cin >> n >> m;
//    Graph graph(n);
//    for (int i = 0; i < m; ++i) {
//        int from, to, capacity;
//        cin >> from >> to >> capacity;
//        graph.addEdge(from - 1, to - 1, capacity);
//        graph.addEdge(to - 1, from - 1, capacity);
//    }
//    cout << graph.getMaxFlow(0, n - 1);

    Graph g(6);
    g.addEdge(0, 1, 16 );
    g.addEdge(0, 2, 13 );
    g.addEdge(1, 2, 10 );
    g.addEdge(1, 3, 12 );
    g.addEdge(2, 1, 4 );
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9 );
    g.addEdge(3, 5, 20 );
    g.addEdge(4, 3, 7 );
    g.addEdge(4, 5, 4);
    cout << g.getMaxFlow(0, 5);
    return 0;
}