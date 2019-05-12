//
// Created by gulnara on 11.05.19.
//

#ifndef SEGMENT_TREE_SEGMENTTREE_H
#define SEGMENT_TREE_SEGMENTTREE_H

#include <vector>
using std::vector;

struct node {
    int sum;
    int suffix;
    int prefix;
    int max;
};

class SegmentTree {
public:
    SegmentTree(vector<int>& input);
    node getMaxRow(int v, int leftPos, int rightPos, int left, int right);
private:
    node merge(node left, node right);
    vector<node> tree;
    void build(vector<int>& values, int vertex, int left, int right);
};


#endif //SEGMENT_TREE_SEGMENTTREE_H
