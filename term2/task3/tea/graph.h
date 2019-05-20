//
// Created by gulnara on 17.04.19.
//

#ifndef TEA_GRAPH_H
#define TEA_GRAPH_H



#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <queue>

using std::queue;
using std::vector;
using std::make_pair;
using std::pair;
using std::unordered_set;
using std::cin;
using std::cout;

struct Edge {
    Edge() {}
    Edge(int from, int to, int capacity, int flow, int backID): from(from),
                                                                to(to),
                                                                capacity(capacity),
                                                                flow(flow),
                                                                backID(backID){}
    int from;
    int to;
    int capacity;
    int flow;
    int backID; // id of back edge
};

class Graph{
public:
    Graph(int vertexCount);
    void addEdge(int from, int to, int capacity);
    int verticesCount() const;
    int getMaxFlow(int source, int dest);
    int countDays(int n);

private:
    int findBlockFlow(int start, int end, int flow, vector<int>& used);
    vector<int> level;
    bool BFS(int source, int dest);
    bool canDrink(int n, int days);

    void clearFlows();
    vector<vector<Edge>> adjacencyList;
};


#endif //TEA_GRAPH_H
