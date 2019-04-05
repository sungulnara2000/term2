#include "list_graph.h"
#include <stack>
#include <iostream>

using std::stack;

CListGraph GetTranspose(CListGraph& graph) {
    CListGraph transposed(graph.VerticesCount());
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        vector<int> next;
        graph.GetNextVertices(i, next);
        for (int j : next) {
            transposed.AddEdge(j, i);
        }
    }
    return transposed;
}

void DFS(int vertex, vector<bool>& visited, vector<int>& component, CListGraph& graph) {
    visited[vertex] = true;
    vector<int> next;
    graph.GetNextVertices(vertex, next);
    component.push_back(vertex);
    for (int i : next) {
        if (!visited[i]) {
            DFS(i, visited, component, graph);
        }
    }
}

void FindSCC(CListGraph& graph, vector<vector<int>>& components, vector<int>& colors) {
    vector<bool> visited;
    vector<int> order;
    vector<int> component;


    visited.assign(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            DFS(i, visited, order, graph);
        }
    }

    CListGraph transposed = GetTranspose(graph);
    int cur_color = 0;

    visited.assign(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        int vertex = order[order.size()-1-i];
        if (!visited[vertex]) {
            DFS(vertex, visited, component, transposed);
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
    vector<int> colors(graph.VerticesCount()); // colors[i] - цвет i-ой вершины
    vector<vector<int>> components; // хранит все компоненты сильной связности
    FindSCC(graph, components, colors);
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