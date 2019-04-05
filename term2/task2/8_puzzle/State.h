//
// Created by gulnara on 29.03.19.
//

#ifndef INC_8_PUZZLE_STATE_H
#define INC_8_PUZZLE_STATE_H

#include <vector>
#include <queue>
#include <set>

using std::set;
using std::vector;
using std::queue;

typedef unsigned long ul;

class State {
public:
    State() {};
    State(vector<int>& combination);

    State up();
    State down();
    State left();
    State right();

    // храним расстановку одним 32 битным числом, на каждую ячейку приходится 4 бита
    ul row = 0;

    int spacePos;

    ul get_value(int position);
    void set_value(int position, ul value);

    ul prev;
    char move;
};


#endif //INC_8_PUZZLE_STATE_H
