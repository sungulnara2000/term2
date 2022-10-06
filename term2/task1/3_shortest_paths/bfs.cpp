//
// Created by gulnara on 24.02.19.
//
#include<queue>
#include "bfs.h"

using std::queue;

int SetGraph:: bfs(int vertex, int finishVertex) {

    vector<bool> wasUsed(vertexCount_, false);
    wasUsed[vertex] = true;

    vector<int> distance(vertexCount_, vertexCount_);
    distance[vertex] = 0;
    vector<int> pathCount(vertexCount_, 0);
    pathCount[vertex] = 1;

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
            }
            if (distance[nextVertex] > distance[current] + 1) {
                distance[nextVertex] = distance[current] + 1;
                pathCount[nextVertex] = pathCount[current];
            } else if (distance[nextVertex] == distance[current] + 1) {
                pathCount[nextVertex] += pathCount[current];
            }
        }
    }
    return pathCount[finishVertex];
}