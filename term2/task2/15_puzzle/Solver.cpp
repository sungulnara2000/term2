//
// Created by gulnara on 29.04.19.
//

#include "Solver.h"

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

bool is_solvable(const State& state) {
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

bool Solver::solve(State& state, vector<char>& steps) {
    if (!is_solvable(state)) {
        return false;
    }
    visited.clear();
    q.clear();
    q.insert(state);

    while (!q.empty()) {
        State curState = *q.begin();
        q.erase(q.begin());

        if (curState.row == GOAL) {
            steps = curState.path;
            break;
        }

        if (visited.find(curState.row) == visited.end()) {
            if (curState.spacePos >= 4) {
                q.insert(curState.move('U'));
            }
            if (curState.spacePos <= 11) {
                q.insert(curState.move('D'));
            }
            if (curState.spacePos % 4 != 0) {
                q.insert(curState.move('L'));
            }
            if (curState.spacePos % 4 != 3) {
                q.insert(curState.move('R'));
            }
            visited.insert(curState.row);
        }


    }
    return true;
}