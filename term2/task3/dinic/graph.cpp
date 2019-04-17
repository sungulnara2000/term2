//
// Created by gulnara on 16.04.19.
//

#include "graph.h"

Graph::Graph(int vertexCount) : adjacencyList(vertexCount), level(vertexCount, -1)  {}

void Graph::addEdge(int from, int to, int capacity) {
    Edge edge(from, to, capacity, 0, adjacencyList[to].size());
    Edge back_edge(to, from, 0, 0, adjacencyList[from].size());
    adjacencyList[from].push_back(edge);
    adjacencyList[to].push_back(back_edge);
}

int Graph::verticesCount() const {
    return adjacencyList.size();
}

void Graph::getAdjacentVertices(int vertex, vector<int>& vertices) const {
    vertices.clear();
    for (auto i : adjacencyList[vertex]) {
        vertices.push_back(i.to);
    }
}

bool Graph::BFS(int source, int dest) {
    queue<int> q;
    q.push(source);
    level.assign(verticesCount(), -1);
    level[source] = 0;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for (auto i: adjacencyList[current]) {
            if (level[i.to] < 0 && i.flow < i.capacity) {
                level[i.to] = level[current] + 1;
                q.push(i.to);
            }
        }
    }
    return level[dest] > 0;
}

int Graph::findBlockFlow(int start, int end, int flow, vector<int>& used) {
    if (start == end) {
        return flow;
    }
    for ( ; used[start] < adjacencyList[start].size(); ++used[start]) {
        if (level[adjacencyList[start][used[start]].to] == level[start] + 1 && adjacencyList[start][used[start]].capacity > adjacencyList[start][used[start]].flow) {
            int possibleFlow = std::min(flow, adjacencyList[start][used[start]].capacity - adjacencyList[start][used[start]].flow);

            int pushedFlow = findBlockFlow(adjacencyList[start][used[start]].to, end, possibleFlow, used);
            if (pushedFlow > 0) {
                adjacencyList[start][used[start]].flow += pushedFlow;
                adjacencyList[adjacencyList[start][used[start]].to][adjacencyList[start][used[start]].backID].flow -= pushedFlow;

                return pushedFlow;
            }
        }
    }
    return 0;
}

int Graph::getMaxFlow(int source, int dest) {
    if (source == dest) {
        return -1;
    }
    int maxFlow = 0;
    while(BFS(source, dest)) {
        vector<int> used(verticesCount() + 1, 0);
        while (int flow = findBlockFlow(source, dest, INT_MAX, used)) {
            maxFlow += flow;
        }
    }
    return maxFlow;
}