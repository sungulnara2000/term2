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
    int cur_color = 0;

    visited.assign(VerticesCount(), false);
    for (int i = 0; i < VerticesCount(); ++i) {
        int vertex = order[order.size()-1-i];
        if (!visited[vertex]) {
            TransposeDFS(vertex, visited, component, transposed);
            components.push_back(component);

            for (int j : component) {
                colors[j] = cur_color;
            }
            cur_color++;
            component.clear();
        }
    }
} 