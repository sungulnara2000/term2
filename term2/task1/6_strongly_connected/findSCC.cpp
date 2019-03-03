#include "list_graph.h"
#include <stack>
#include <iostream>

using std::stack;

void CListGraph::FindSCC() {
    vector<bool> visited;
    vector<int> order;
    vector<int> component;

    visited.assign(VerticesCount(), false);
    for (int i = 0; i < VerticesCount(); ++i) {
        if (!visited[i]) {
            DFS(i, visited, order);
        }
    }

    CListGraph transposed = GetTranspose();

    visited.assign(VerticesCount(), false);
    for (int i = 0; i < VerticesCount(); ++i) {
        int vertex = order[order.size()-1-i];
        if (!visited[vertex]) {
            TransposeDFS(vertex, visited, component, transposed);
            for (int i : component) {
                std::cout << i << " ";
            }
            std::cout << '\n';
            component.clear();
        }
    }
} 