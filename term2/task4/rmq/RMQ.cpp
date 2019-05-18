//
// Created by gulnara on 30.04.19.
//

#include <cmath>
#include <limits>
#include <iostream>
#include <algorithm>
#include "RMQ.h"

using std::log;
using std::max;
using std::min;
using std::numeric_limits;

RMQ::RMQ(const vector<int>& numbers) : _numbers(numbers),
                                       firstOrder(log2(numbers.size()) + 1, vector<int>(numbers.size())),
                                       secondOrder(log2(numbers.size()) + 1, vector<int>(numbers.size())){
    for (size_t k = 0; k < secondOrder.size(); ++k) {
        for (size_t i = 0; i < secondOrder[k].size(); ++i) {
            initOrderCell(k, i);
        }
    }
}

int RMQ::log2(int n) const {
    return (int)(log(n)/log(2));
}

void RMQ::initOrderCell(size_t k, size_t i) {
    if (i + pow(2, k) > _numbers.size()) {
        secondOrder[k][i] = numeric_limits<int>::max();
        firstOrder[k][i] = _numbers[i];
        return;
    }
    if (k == 0) {
        secondOrder[k][i] = numeric_limits<int>::max();
        firstOrder[k][i] = _numbers[i];
    } else if (k == 1) {
        secondOrder[k][i] = max(_numbers[i], _numbers[i+1]);
        firstOrder[k][i] = min(_numbers[i], _numbers[i+1]);
    } else {
        vector<int> tmp;
        tmp.push_back(firstOrder[k-1][i]);
        tmp.push_back(firstOrder[k-1][i+pow(2, k-1)]);
        tmp.push_back(secondOrder[k-1][i]);
        tmp.push_back(secondOrder[k-1][i+pow(2, k-1)]);
        std::sort(tmp.begin(), tmp.end());
        firstOrder[k][i] = tmp[0];
        for (int j = 1; j < 4; ++j) {
            if (tmp[j] != tmp[0]) {
                secondOrder[k][i] = tmp[1];
                break;
            }
        }
    }
}

int RMQ::find2Order(int left, int right) const {
    int k = log2(right - left + 1);
    vector<int> tmp;
    tmp.push_back(firstOrder[k][left]);
    tmp.push_back(firstOrder[k][right - pow(2, k) +1]);
    tmp.push_back(secondOrder[k][left]);
    tmp.push_back(secondOrder[k][right - pow(2, k) +1]);
    std::sort(tmp.begin(), tmp.end());
    for (int j = 1; j < 4; ++j) {
        if (tmp[j] != tmp[0]) {
            return tmp[j];
        }
    }
    return tmp[0];
}
