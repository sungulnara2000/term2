#include <vector>
#include <iostream>
#include <queue>

#include "SetGraph.h"
#include "vertexCycle.h"

using std::vector;
using std::cout;
using std::endl;
using std::queue;

int SetGraph:: vertexCycle(int vertex) {

    vector<bool> wasUsed(vertexCount_, false);
    wasUsed[vertex] = true;

    vector<int> prev(vertexCount_, -1);
    vector<int> depth(vertexCount_, 0);

    queue<int> bufferQueue;
    bufferQueue.push(vertex);

    while(!bufferQueue.empty()) {
        int current = bufferQueue.front();
        bufferQueue.pop();
        vector<int> next;
        GetNextVertices(current, next);
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
    return vertexCount_ + 1;
}