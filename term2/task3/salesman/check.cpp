//
// Created by gulnara on 28.04.19.
//
#include "graph.h"

int check(ListGraph graph) {
    vector<int> cities(graph.verticesCount);
    for (int i = 0; i < cities.size(); ++i) {
        cities[i] = i;
    }
    int minPath = numeric_limits<int>::max();
    do {
        int currentPath = 0;
        for (int i = 1; i < cities.size(); ++i) {
            currentPath += graph.weightMatrix[cities[i]][cities[i-1]];
        }
        currentPath += graph.weightMatrix[cities[0]][cities.back()];
        minPath = min(minPath, currentPath);
    } while (next_permutation(cities.begin(), cities.end()));

    return minPath;
}