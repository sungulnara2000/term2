//
// Created by gulnara on 29.04.19.
//

#ifndef INC_15_PUZZLE_SOLVER_H
#define INC_15_PUZZLE_SOLVER_H

#include "State.h"

int heuristic(const State& state);

struct cmp {
    bool operator()(const State& first, const State& second) {
        return heuristic(first) > heuristic(second);
    }
};

class Solver {
public:
    bool solve(State& state, vector<char>& rv);

private:
    std::set<State, cmp> q;
    std::unordered_set<ull> visited;
    const ull GOAL = 1311768467463790320;
};

#endif //INC_15_PUZZLE_SOLVER_H
