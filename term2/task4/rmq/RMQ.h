//
// Created by gulnara on 30.04.19.
//

#ifndef RMQ_RMQ_H
#define RMQ_RMQ_H

#include <vector>

using std::vector;

class RMQ {
public:
    explicit RMQ(const vector<int>& numbers);

    int find2Order(int left, int right) const;

private:
    void initOrderCell(size_t k, size_t i);
    int log2(int n) const;

    vector<vector<int>> firstOrder;
    vector<vector<int>> secondOrder;
    vector<int> _numbers;
};

#endif //RMQ_RMQ_H
