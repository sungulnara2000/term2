//
// Created by gulnara on 13.05.19.
//

#include "MaxFlow.h"

MaxFlow::MaxFlow(Graph &graph): _input(graph), _network(graph), level(_input.verticesCount(), -1)  {
    for (int i = 0; i < graph.verticesCount(); ++i) {
        _network.clear();
    }
}

bool MaxFlow::BFS(int source, int dest) {
    queue<int> q;
    q.push(source);
    level.assign(_network.verticesCount(), -1);
    level[source] = 0;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        vector<Edge> nextEdgesFlow;
        vector<Edge> nextEdgesCapacity;
        _input.getEdges(current, nextEdgesCapacity);
        _network.getEdges(current, nextEdgesFlow);
        for (auto edge: nextEdgesCapacity) {
            for (auto flowEdge : nextEdgesFlow) {
                if (level[edge.to] < 0 && flowEdge.capacity < edge.capacity) {
                    level[edge.to] = level[current] + 1;
                    q.push(edge.to);
                }
            }
        }
    }
    return level[dest] > 0;
}

int MaxFlow::findBlockFlow(int start, int end, int flow, vector<int>& used) {
    if (start == end) {
        return flow;
    }
    vector<Edge> nextEdgesFlow;
    vector<Edge> nextEdgesCapacity;
    _input.getEdges(start, nextEdgesCapacity);
    _network.getEdges(start, nextEdgesFlow);
    for ( ; used[start] < nextEdgesCapacity.size(); ++used[start]) {
        auto& edge = nextEdgesCapacity[used[start]];
        auto& flowEdge = nextEdgesFlow[used[start]];
        if (level[edge.to] == level[start] + 1 && edge.capacity > flowEdge.capacity) {
            int possibleFlow = std::min(flow, edge.capacity - flowEdge.capacity);

            int pushedFlow = findBlockFlow(edge.to, end, possibleFlow, used);
            if (pushedFlow > 0) {
                flowEdge.capacity += pushedFlow;
                vector<Edge> nextEdges;
                _network.getEdges(edge.to, nextEdges);
                nextEdges[edge.backID].capacity -= pushedFlow;

                return pushedFlow;
            }
        }
    }
    return 0;
}

int MaxFlow::getMaxFlow(int source, int dest) {
    if (source == dest) {
        return -1;
    }
    int maxFlow = 0;
    while(BFS(source, dest)) {
        vector<int> used(_input.verticesCount() + 1, 0);
        while (int flow = findBlockFlow(source, dest, INT_MAX, used)) {
            maxFlow += flow;
        }
    }
    return maxFlow;
}