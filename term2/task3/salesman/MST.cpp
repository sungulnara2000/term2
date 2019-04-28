//
// Created by gulnara on 25.04.19.
//

// disjoint-set-union

#include "graph.h"

struct component {
    int parent;
    int rank;
};


int findSet(vector<component>& sets, int v) {
    if (v == sets[v].parent) {
        return v;
    }
    return sets[v].parent = findSet(sets, sets[v].parent);
}

void unionSets(vector<component>& sets, int a, int b) {
    a = findSet(sets, a);
    b = findSet(sets, b);
    if (a != b) {
        if (sets[a].rank < sets[b].rank) {
            std::swap(a, b);
        }
        sets[b].parent = a;
        if (sets[a].rank == sets[b].rank) {
            ++sets[a].rank;
        }
    }
}

void MST(ListGraph& inputGraph, ListGraph& mst) {
    long MSTweight = 0;
    int numSets = inputGraph.verticesCount;
    vector<component> sets(inputGraph.verticesCount);

    for (int i = 0; i < inputGraph.verticesCount; ++i) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }
    vector<Edge> safeEdges(inputGraph.verticesCount, Edge(0, 0, std::numeric_limits<int>::max()));

    while(numSets > 1) {
        for (int i = 0; i < inputGraph.verticesCount; ++i) {
            safeEdges[i].weight = std::numeric_limits<int>::max();
        }
        for (auto i : inputGraph.edgesList) {
            int leader1 = findSet(sets, i.from);
            int leader2 = findSet(sets, i.to);
            if (leader1 != leader2) {
                if(i.weight < safeEdges[leader1].weight) {
                    safeEdges[leader1] = i;
                }
                if(i.weight < safeEdges[leader2].weight) {
                    safeEdges[leader2] = i;
                }
            }
        }
        for (int i = 0; i < inputGraph.verticesCount; ++i) {
            if (safeEdges[i].weight != std::numeric_limits<int>::max()) {
                int leader1 = findSet(sets, safeEdges[i].from);
                int leader2 = findSet(sets, safeEdges[i].to);

                if (leader1 != leader2) {
                    MSTweight += safeEdges[i].weight;
                    unionSets(sets, leader1, leader2);
                    --numSets;
                }
            }
        }
    }

    for (auto i : safeEdges) {
        bool added = false;
        for (auto j : mst.adjacencyList[i.from]) {
            if (j.to == i.to && j.weight == i.weight) {
                added = true;
            }
        }
        if (!added) {
            mst.addEdge(i.from, i.to, i.weight);
        }
    }
}
