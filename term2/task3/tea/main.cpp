#include <iostream>

#include "graph.h"


int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> teaKinds(m);
    for (auto& i : teaKinds) {
        cin >> i;
    }
    int verticesCount = n + teaKinds.size() + 2;
    Graph graph(verticesCount);

    for (int teaID = n + 1; teaID < verticesCount - 1 ; ++teaID) {
        graph.addEdge(teaID, verticesCount - 1, teaKinds[teaID - n - 1]);
    }
    for (int i = 0; i < n; ++i) {
        graph.addEdge(0, i + 1, 0);
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int lovelyTea;
            cin >> lovelyTea;
            graph.addEdge(i + 1, n + lovelyTea, INT_MAX);
        }
    }
    cout << graph.countDays(n);
    return 0;
}