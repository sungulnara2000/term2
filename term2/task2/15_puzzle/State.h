//
// Created by gulnara on 31.03.19.
//

#ifndef INC_15_PUZZLE_STATE_H
#define INC_15_PUZZLE_STATE_H


#include <vector>
#include <queue>
#include <set>

using std::set;
using std::vector;
using std::queue;

typedef unsigned long long ull;

class State {
public:
    State() {};
    State(vector<int>& combination);

    State up() const;
    State down() const;
    State left() const;
    State right() const;

    // храним расстановку одним 64 битным числом, на каждую ячейку приходится 4 бита,
    ull row = 0;

    int spacePos;

    ull get_value(int position) const;
    void set_value(int position, ull value);

    vector<char> path;
};


#endif //INC_15_PUZZLE_STATE_H
