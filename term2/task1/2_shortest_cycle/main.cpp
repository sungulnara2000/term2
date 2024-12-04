#include <iostream>
#include "SetGraph.h"
#include <vector>
#include <iostream>
#include <queue>


using std::vector;
using std::cout;
using std::endl;
using std::queue;

int findMinCycleFromVertex(int vertex, const IGraph* graph) {

    vector<bool> wasUsed(graph->VerticesCount(), false);
    wasUsed[vertex] = true;

    vector<int> prev(graph->VerticesCount(), -1);
    vector<int> depth(graph->VerticesCount(), 0);

    queue<int> bufferQueue;
    bufferQueue.push(vertex);

    while(!bufferQueue.empty()) {
        int current = bufferQueue.front();
        bufferQueue.pop();
        vector<int> next;
        graph->GetNextVertices(current, next);
        for (int nextVertex : next) {
            if (!wasUsed[nextVertex]) {
                bufferQueue.push(nextVertex);
                wasUsed[nextVertex] = true;
                prev[nextVertex] = current;
                depth[nextVertex] = depth[current] + 1;
            } else if (prev[current] != nextVertex) {
                return depth[nextVertex] + depth[current] + 1;
            }
        }
    }
    return graph->VerticesCount() + 1;
}

bool shortestCycle(const IGraph* graph, int& rv) {
    rv = graph->VerticesCount() + 1;
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        rv = std::min(findMinCycleFromVertex(i, graph), rv);
    }
    if (rv == graph->VerticesCount() + 1) {
        return false;
    }
    return true;
}

int main() {
    int vertexCount, edgesCount;
    std::cin >> vertexCount >> edgesCount;
    SetGraph graph(vertexCount);
    for (int i = 0; i < edgesCount; ++i) {
        int from, to;
        std::cin >> from >> to;
        graph.AddEdge(from, to);
        graph.AddEdge(to, from);
    }
    int rv;
    std::cout << ( shortestCycle(&graph, rv) ? rv : -1);
    return 0;
}