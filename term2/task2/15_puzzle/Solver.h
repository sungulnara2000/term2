//
// Created by gulnara on 29.04.19.
//

#ifndef INC_15_PUZZLE_SOLVER_H
#define INC_15_PUZZLE_SOLVER_H

#include "State.h"

int heuristic(const State& state) {
    int heuristic = 0;
    // манхэттенское расстояние
    for (int i = 0; i < 16; ++i) {
        if (state.get_value(i) != 0) {
            heuristic += abs(i / 4 - (state.get_value(i) - 1) / 4) + abs(i % 4 - (state.get_value(i) - 1) % 4);
        }
    }
    return heuristic;
}

struct cmp {
    bool operator()(const State& first, const State& second) {
        return heuristic(first) > heuristic(second);
    }
};

class Solver {
public:
    bool solve(State& state, vector<char>& rv);

private:
    std::priority_queue<State, std::vector<State>, cmp> q;
    std::unordered_set<ull> visited;
    ull GOAL = 1311768467463790320;
};

#endif //INC_15_PUZZLE_SOLVER_H
