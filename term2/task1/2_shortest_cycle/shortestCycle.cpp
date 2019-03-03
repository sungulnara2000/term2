//
// Created by gulnara on 24.02.19.
//

#include "SetGraph.h"

int SetGraph:: shortestCycle() {
    int rv = vertexCount_ + 1;
    for (int i = 0; i < vertexCount_; ++i) {
        int currentCycle = vertexCycle(i);
        if (currentCycle < rv) {
            rv = currentCycle;
        }
    }
    return rv;
}