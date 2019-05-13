//
// Created by gulnara on 13.05.19.
//

#ifndef DINIC_MAXFLOW_H
#define DINIC_MAXFLOW_H

#include "graph.h"

class MaxFlow {
public:
    MaxFlow(Graph& graph);
    int getMaxFlow(int source, int dest);
private:
    Graph _input;
    Graph _network;
    int findBlockFlow(int start, int end, int flow, vector<int>& used);
    vector<int> level;
    bool BFS(int source, int dest);
};


#endif //DINIC_MAXFLOW_H
