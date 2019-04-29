//
// Created by gulnara on 29.04.19.
//

#include "Solver.h"

bool solvable(State& state) {
    int inversions = 0;
    for (int i = 0; i < 16; ++i) {
        for (int j = i + 1; j < 16; ++j) {
            if (state.get_value(i) != 0 && state.get_value(j) != 0 && state.get_value(i) > state.get_value(j)) {
                ++inversions;
            }
        }
    }
    return ((inversions + state.spacePos / 4 + 1) % 2 == 0);
}

bool Solver::solve(State& state, vector<char>& rv) {
    if (!solvable(state)) {
        return false;
    }
    visited.clear();
    q.push(state);

    while (!q.empty()) {
        State curState = q.top();
        q.pop();

        if (curState.row == GOAL) {
            rv = curState.path;
            break;
        }

        if (visited.find(curState.row) == visited.end()) {
            if (curState.spacePos >= 4) {
                q.push(curState.up());
            }
            if (curState.spacePos <= 11) {
                q.push(curState.down());
            }
            if (curState.spacePos % 4 != 0) {
                q.push(curState.left());
            }
            if (curState.spacePos % 4 != 3) {
                q.push(curState.right());
            }
            visited.insert(curState.row);
        }
    }
    return true;
}