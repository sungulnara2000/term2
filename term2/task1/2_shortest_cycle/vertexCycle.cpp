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