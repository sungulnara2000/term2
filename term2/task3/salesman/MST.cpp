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

long MSTweight(ListGraph& graph) {
    long MSTweight = 0;
    int numSets = graph.VerticesCount;
    vector<component> sets(graph.VerticesCount);

    for (int i = 0; i < graph.VerticesCount; ++i) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }


    vector<Edge> safeEdges(graph.VerticesCount, Edge(0, 0, INT_MAX)); // без конструктора?


    while(numSets > 1) {
//        for (auto i : safeEdges) {
//            i.weight = INT_MAX;
//        }
        for (int i = 0; i < graph.VerticesCount; ++i) {
            safeEdges[i].weight = INT_MAX;
        }
        for (auto i : graph.edgesList) {
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
        for (int i = 0; i < graph.VerticesCount; ++i) {
            if (safeEdges[i].weight != INT_MAX) {
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
    return MSTweight;
}
