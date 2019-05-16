//
// Created by gulnara on 12.05.19.
//

#include <cmath>
#include "lca.h"

int LCA::log2(int n) const {
    return (int)(ceil)(log(n)/log(2));
}

LCA::LCA(int vertecesCount) : ancestors(vertecesCount, vector<int>(log2(vertecesCount) + 1)),
                              timer(0), tin(vertecesCount), tout(vertecesCount), tree(vertecesCount), parents(vertecesCount) {}

void LCA::addEdge(int vertex, int parent) {
    tree[parent].push_back(vertex);
    parents[vertex] = parent;
}

// a > b
bool LCA::cmp(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

void LCA::preprocess(int vertex, int ancestor) {
    tin[vertex] = ++timer;
    ancestors[vertex][0] = ancestor;
    for (int i = 1; i < log2(tree.size()); ++i) {
        ancestors[vertex][i] = ancestors[ancestors[vertex][i-1]][i-1];
    }
    for (auto i : tree[vertex]) {
        if (i != ancestor) {
            preprocess(i, vertex);
        }
    }
    tout[vertex] = ++timer;
}

int LCA::getCommonAncestor(int a, int b) {
    if (a >= tree.size() || b >= tree.size()) {
        return 0;
    }
    if (cmp(a, b)) {
        return a;
    }
    if (cmp(b, a)) {
        return b;
    }
    for (int i = log2(tree.size()); i >= 0; --i) {
        if (!cmp(ancestors[a][i], b))
            a = ancestors[a][i];
    }
    return ancestors[a][0];
}
