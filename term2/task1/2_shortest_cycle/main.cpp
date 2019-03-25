#include <iostream>
#include "SetGraph.h"
#include "shortestCycle.h"
#include <vector>
#include <iostream>
#include <queue>

#include "SetGraph.h"

using std::vector;
using std::cout;
using std::endl;
using std::queue;

int vertexCycle(int vertex, const IGraph* graph) {

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

int shortestCycle(const IGraph* graph) {
    int rv = graph->VerticesCount() + 1;
    for (int i = 0; i < graph->VerticesCount(); ++i) {
        rv = std::min(vertexCycle(i, graph), rv);
    }
    return rv;
}

int main() {
    int vertexCount, edgesCount;
    std::cin >> vertexCount >> edgesCount;
    SetGraph graph(vertexCount);
    for (int i = 0; i < edgesCount; ++i) {
        int from, to;
        std::cin >> from >> to;
        graph.AddEdge(from, to);
        std::swap(from, to);
        graph.AddEdge(from, to);
    }
    int rv = shortestCycle(&graph);
    std::cout << ( (rv <= graph.VerticesCount()) ? rv : -1);
    return 0;
}