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

void MST(MatrixGraph& inputGraph, MatrixGraph& mst) {
    float MSTweight = 0;
    int numSets = inputGraph.getVerticesCount();
    vector<component> sets(inputGraph.getVerticesCount());

    for (int i = 0; i < inputGraph.getVerticesCount(); ++i) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }
    vector<Edge> safeEdges(inputGraph.getVerticesCount(), Edge(0, 0, std::numeric_limits<int>::max()));

    while(numSets > 1) {
        for (int i = 0; i < inputGraph.getVerticesCount(); ++i) {
            safeEdges[i].weight = std::numeric_limits<int>::max();
        }
        vector<Edge> edgesList;
        inputGraph.getAllEdges(edgesList);
        for (auto edge : edgesList) {
            int leader1 = findSet(sets, edge.from);
            int leader2 = findSet(sets, edge.to);
            if (leader1 != leader2) {
                if(edge.weight < safeEdges[leader1].weight) {
                    safeEdges[leader1] = edge;
                }
                if(edge.weight < safeEdges[leader2].weight) {
                    safeEdges[leader2] = edge;
                }
            }
        }
        for (int vertex = 0; vertex < inputGraph.getVerticesCount(); ++vertex) {
            if (safeEdges[vertex].weight != std::numeric_limits<int>::max()) {
                int leader1 = findSet(sets, safeEdges[vertex].from);
                int leader2 = findSet(sets, safeEdges[vertex].to);

                if (leader1 != leader2) {
                    MSTweight += safeEdges[vertex].weight;
                    mst.addEdge(safeEdges[vertex].from, safeEdges[vertex].to, safeEdges[vertex].weight);
                    unionSets(sets, leader1, leader2);
                    --numSets;
                }
            }
        }
    }
}
