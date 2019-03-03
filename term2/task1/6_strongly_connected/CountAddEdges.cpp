//
// Created by gulnara on 03.03.19.
//

#include "list_graph.h"
#include <algorithm>

int CListGraph::CountAddEdges() {
    FindSCC();
    if (components.size() == 1) {
        return 0;
    }

    vector<int> SCCsInDegree(components.size(), 0);
    vector<int> SCCsOutDegree(components.size(), 0);
    for (int i = 0; i < adjacencyList.size(); ++i) {
        for (int j : adjacencyList[i]) {
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
