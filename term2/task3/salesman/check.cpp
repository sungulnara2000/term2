//
// Created by gulnara on 28.04.19.
//
#include "graph.h"

float check(ListGraph graph) {
    vector<int> cities(graph.getVerticesCount());
    for (int i = 0; i < cities.size(); ++i) {
        cities[i] = i;
    }
    float minPath = numeric_limits<int>::max();
    do {
        vector<float> neighbours;
        float currentPath = 0;
        for (int i = 1; i < cities.size(); ++i) {
            graph.getNextVertices(cities[i], neighbours);
            currentPath += neighbours[cities[i-1]];
        }
        graph.getNextVertices(cities[0], neighbours);
        currentPath += neighbours[cities.back()];
        minPath = min(minPath, currentPath);
    } while (next_permutation(cities.begin(), cities.end()));

    return minPath;
}