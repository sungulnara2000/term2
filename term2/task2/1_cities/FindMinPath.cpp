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
using std::make_pair;

int FindMinPath(IGraph const &graph, int from, int to) {
    vector<int> dist(graph.VerticesCount(), std::numeric_limits<int>::max());
    dist[from] = 0;

    vector<bool> used(graph.VerticesCount(), false);

    set<pair<int, int>> queue;
    queue.emplace(0, from);
    while(!queue.empty()) {
        int min_dist_vertex = queue.begin()->second;
        queue.erase(queue.begin());
        used[min_dist_vertex] = true;
        vector<pair<int, int>> adjacents;
        graph.GetAdjacentVertices(min_dist_vertex, adjacents);
        for (auto i: adjacents) {
            if (dist[i.first] > dist[min_dist_vertex] + i.second) {
                if (dist[i.first] != std::numeric_limits<int>::max()) {
                    queue.erase(make_pair(dist[i.first], i.first));
                }
                dist[i.first] = dist[min_dist_vertex] + i.second;
                queue.emplace(dist[i.first], i.first);
            }
        }
    }

    return dist[to] != std::numeric_limits<size_t>::max() ? dist[to] : -1;
}