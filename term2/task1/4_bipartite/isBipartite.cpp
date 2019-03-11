//
// Created by gulnara on 24.02.19.
//
#include<queue>
#include "SetGraph.h"

using std::queue;

bool SetGraph:: isBipartite(int vertex) {

    vector<int> color(vertexCount_, -1);
    color[vertex] = 1;

    queue<int> bufferQueue;
    bufferQueue.push(vertex);

    while(!bufferQueue.empty()) {
        int current = bufferQueue.front();
        bufferQueue.pop();

        vector<int> next;
        GetNextVertices(current, next);

        for (int nextVertex : next) {
            if (color[nextVertex] == -1) {
                color[nextVertex] = 1 - color[current];
                bufferQueue.push(nextVertex);
            } else if (color[nextVertex] == color[current]) {
                return false;
            }
        }
    }
    return true;
}