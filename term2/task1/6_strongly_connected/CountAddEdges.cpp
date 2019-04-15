//
// Created by gulnara on 03.03.19.
//

#include "list_graph.h"
#include <algorithm>
#include <stack>

using std::stack;

vector<int> colors; // colors[i] - цвет i-ой вершины
vector<vector<int>> components; // хранит все компоненты сильной связности
vector<bool> visited;
vector<int> order;
vector<int> component;

void DFS(CListGraph& graph, int vertex) {
    visited[vertex] = true;
    vector<int> next;
    graph.GetNextVertices(vertex, next);
    for (int i : next) {
        if (!visited[i]) {
            DFS(graph, i);
        }
    }
    order.push_back(vertex);
}

void TransposeDFS(CListGraph& transposed, int vertex) {
    visited[vertex] = true;
    vector<int> next;
    transposed.GetNextVertices(vertex, next);
    component.push_back(vertex);
    for (int i : next) {
        if (!visited[i]) {
            TransposeDFS(transposed, i);
        }
    }
}

void FindSCC(CListGraph& graph) {
    visited.assign(graph.VerticesCount(), false);
    colors.assign(graph.VerticesCount(), -1);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            DFS(graph, i);
        }
    }

    CListGraph transposed = graph.GetTranspose();
    int cur_color = 0;

    visited.assign(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        int vertex = order[order.size()-1-i];
        if (!visited[vertex]) {
            TransposeDFS(transposed, vertex);
            components.push_back(component);
            for (int j : component) {
                colors[j] = cur_color;
            }
            cur_color++;
            component.clear();
        }
    }
}

int CountAddEdges(CListGraph& graph) {
    FindSCC(graph);
    if (components.size() == 1) {
        return 0;
    }

    vector<int> SCCsInDegree(components.size(), 0);
    vector<int> SCCsOutDegree(components.size(), 0);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        vector<int> next;
        graph.GetNextVertices(i, next);
        for (int j : next) {
            if (colors[i] != colors[j]) {
                SCCsOutDegree[colors[i]]++;
                SCCsInDegree[colors[j]]++;
            }
        }
    }
    int X = 0;
    int Y = 0;
    for (int i : SCCsInDegree) {
        if (i == 0) {
            X++;
        }
    }
    for (int i : SCCsOutDegree) {
        if (i == 0) {
            Y++;
        }
    }
    return (std::max(X, Y));
}




