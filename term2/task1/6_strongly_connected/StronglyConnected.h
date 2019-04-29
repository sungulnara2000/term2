//
// Created by gulnara on 28.04.19.
//
#include "list_graph.h"
#include <algorithm>
#include <stack>

using std::stack;

class StronglyConnected{
public:
    StronglyConnected(){};
    int CountAddEdges(CListGraph& graph);

private:
    void DFS(CListGraph& graph, int vertex, vector<int>& buffer);
    void FindSCC(CListGraph& graph);

    vector<int> colors; // colors[i] - цвет i-ой вершины
    vector<vector<int>> components; // хранит все компоненты сильной связности
    vector<bool> visited;
    vector<int> order;
    vector<int> component;
};
