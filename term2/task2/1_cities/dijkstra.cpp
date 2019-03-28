//
// Created by gulnara on 24.03.19.
//

#include "graph.h"
#include <vector>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>

using std::vector;
using std::set;
using std::min_element;
using std::distance;
using std::pair;
using std::cout;
using std::endl;


int MinDistVertex(vector<int>& dist, vector<bool>& SPT) {
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < dist.size(); ++i) {
        if (SPT[i] == false && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int dijkstra(IGraph const &graph, int from, int to) {
    vector<int> dist(graph.VerticesCount(), INT_MAX);
    dist[from] = 0;

    vector<bool> SPT(graph.VerticesCount(), false);
    for (int j = 0; j < graph.VerticesCount() - 1; ++j) {
//        auto min_elem = min_element(dist.begin(), dist.end()), [SPT](int a, int b) { return SPT.find(a)==SPT.end() && SPT.find(b)==SPT.end() && a < b; }) ;

        int min_dist_vertex = MinDistVertex(dist, SPT);
        SPT[min_dist_vertex] = true;
        vector<pair<int, int>> adjacents;
        graph.GetAdjacentVertices(min_dist_vertex, adjacents);
        for (auto i: adjacents) {
            if (!SPT[i.first] && dist[i.first] > dist[min_dist_vertex] + i.second) {
                dist[i.first] = dist[min_dist_vertex] + i.second;
            }
        }
    }

    return dist[to];
}