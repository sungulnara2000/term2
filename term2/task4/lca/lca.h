//
// Created by gulnara on 12.05.19.
//

#ifndef LCA_LCA_H
#define LCA_LCA_H

#include <iostream>
#include <vector>

using std::vector;

class LCA {
public:
    LCA(int vertecesCount);
    int getCommonAncestor(int a, int b);
    void addEdge(int vertex, int parent);
    void preprocess(int vertex, int ancestor = 0);

private:
    int log2(int n) const;
    bool cmp(int a, int b);

    vector<vector<int>> ancestors;
    vector<int> parents;

    vector<int> tin;
    vector<int> tout;
    int timer;
    vector<vector<int>> tree;
};


#endif //LCA_LCA_H
