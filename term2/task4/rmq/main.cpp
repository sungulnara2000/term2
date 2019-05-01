#include <iostream>
#include <vector>
#include "RMQ.h"

using namespace std;


int main() {
    int n, rangesCount;
    cin >> n >> rangesCount;
    vector<int> collection(n);
    for (int i = 0; i < n; ++i) {
        cin >> collection[i];
    }
    RMQ rmq(collection);
    for (int i = 0; i < rangesCount; ++i) {
        int left, right;
        cin >> left >> right;
        cout << rmq.find2Order(left - 1, right - 1) << endl;
    }
    return 0;
}