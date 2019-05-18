//
// Created by gulnara on 11.05.19.
//

#ifndef SEGMENT_TREE_SEGMENTTREE_H
#define SEGMENT_TREE_SEGMENTTREE_H

#include <vector>
using std::vector;

struct Node {
    int sum;
    int suffix;
    int prefix;
    int max;
};

class SegmentTree {
public:
    SegmentTree(vector<int>& input);
    int getMaxRow(int v, int left, int right);
private:
    Node getMaxNode(int v, int leftPos, int rightPos, int left, int right);
    Node merge(Node left, Node right);
    vector<Node> tree;
    void build(vector<int>& values, int vertex, int left, int right);
};


#endif //SEGMENT_TREE_SEGMENTTREE_H
