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


int MinDistVertex(vector<int>& dist, set<int>& SPT) {
    int min = INT_MAX;
    int min_index;
    for (int i = 0; i < dist.size(); ++i) {
        if (SPT.find(i) == SPT.end() && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

int dijkstra(IGraph const &graph, int from, int to) {
    vector<int> dist(graph.VerticesCount(), INT_MAX);
    dist[from] = 0;

    set<int> SPT;
    while(SPT.size() < graph.VerticesCount()) {
//        auto min_elem = min_element(dist.begin(), dist.end()), [SPT](int a, int b) { return SPT.find(a)==SPT.end() && SPT.find(b)==SPT.end() && a < b; }) ;
//        int min_dist_vertex = min_element(dist.begin(), dist.end()), [SPT](int a, int b) { return SPT.find(a)==SPT.end() && SPT.find(b)==SPT.end() && a < b; }) ;
        int min_dist_vertex = MinDistVertex(dist, SPT);
        SPT.insert(min_dist_vertex);
        vector<pair<int, int>> adjacents;
        graph.GetAdjacentVertices(min_dist_vertex, adjacents);
        for (auto i: adjacents) {
            if (dist[i.first] > dist[min_dist_vertex] + i.second) {
                dist[i.first] = dist[min_dist_vertex] + i.second;
            }
        }
    }
//    for (int i = 0; i < graph.VerticesCount(); ++i) {
//        cout << i << " " << dist[i] << endl;
//    }
    return ((dist[to] != INT_MAX) ? (static_cast<int>(dist[to])) : (-1));
}