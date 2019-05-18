//
// Created by gulnara on 31.03.19.
//

#ifndef INC_15_PUZZLE_STATE_H
#define INC_15_PUZZLE_STATE_H


#include <queue>
#include <set>
#include <cstdlib>
#include <unordered_set>
#include <iostream>

using std::set;
using std::vector;
using std::queue;

typedef unsigned long long ull;

class State {
public:
    State() {};
    State(vector<int>& combination);

    State move(char letter) const;

    // храним расстановку одним 64 битным числом, на каждую ячейку приходится 4 бита,
    ull row = 0;

    int spacePos;

    ull get_value(int position) const;
    void set_value(int position, ull value);

    vector<char> path;
};



#endif //INC_15_PUZZLE_STATE_H
