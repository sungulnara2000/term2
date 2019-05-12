//
// Created by gulnara on 11.05.19.
//

#include <algorithm>
#include "SegmentTree.h"

using std::max;

SegmentTree::SegmentTree(vector<int>& input) {
    tree.assign(2 * input.size(), node());
    build(input, 0, 0, input.size() - 1);
}

node SegmentTree::merge(node left, node right) {
    node result;
    result.sum = left.sum + right.sum;
    result.prefix = max(left.prefix, left.sum + right.prefix);
    result.suffix = max(right.suffix, right.sum + left.suffix);
    result.max = max(max(left.max, right.max), left.suffix + right.prefix);
    return result;
}

void SegmentTree::build(vector<int> &values, int vertex, int left, int right) {
    if (left == right) {
        tree[vertex].max = values[left];
        tree[vertex].prefix = values[left];
        tree[vertex].suffix = values[left];
        tree[vertex].sum = values[left];
    } else {
        int middle = left + (right - left) / 2;
        build(values, vertex*2 + 1, left, middle);
        build(values, vertex*2 + 2, middle + 1, right);
        tree[vertex] = merge(tree[vertex*2 + 1], tree[vertex*2 + 2]);
    }
}

node SegmentTree::getMaxRow(int v, int leftPos, int rightPos, int left, int right) {
    if (left == leftPos && right == rightPos) {
        return tree[v];
    }
    int middle = (leftPos + rightPos) / 2;
    if (right <= middle ) return getMaxRow(2*v + 1,leftPos, middle, left, right);
    if (left > middle) {
        return getMaxRow(2 * v + 2, middle + 1, rightPos, left, right);
    }
    node leftNode  = getMaxRow(2*v + 1,leftPos,middle, left, middle);
    node rightNode = getMaxRow(2*v + 2, middle + 1, rightPos, middle + 1, right);
    return merge(leftNode, rightNode);
}