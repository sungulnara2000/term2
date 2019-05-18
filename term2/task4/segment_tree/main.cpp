#include <iostream>
#include "SegmentTree.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    cin >> n;
    int queriesNumber;
    cin >> queriesNumber;
    vector<int> collection(n, -n);
    for (int j = 0; j < n; ++j) {
        int number;
        cin >> number;
        if (number == 1) {
            collection[j] = 1;
        }
    }
    SegmentTree segmentTree(collection);
    for (int i = 0; i < queriesNumber; ++i) {
        int left, right;
        cin >> left >> right;
        int rv = segmentTree.getMaxRow(collection.size() - 1, left, right);
        cout << (rv < 0 ? 0 : rv) << endl;
    }
    return 0;
}