//
// Created by gulnara on 31.03.19.
//
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include "State.h"

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

void search(const State& state, int cost, int bound, int new_bound, vector<char>& rv, set<ull>& visited);

void visit(const State& state, int cost, int bound, int new_bound, vector<char>& rv, set<ull>& visited, bool& finish) {
    if (state.row == 1311768467463790320) {
        if (rv.size() ==0 || state.path.size() < rv.size() ) {
            rv = state.path;
        }
        finish = true;
        return;
    }
    if (visited.find(state.row) == visited.end()) {
        int full_cost = cost + heuristic(state);
        if (full_cost > bound) {
            new_bound = std::min(full_cost, new_bound);
            return;
        }
        visited.insert(state.row);
        search(state, cost + 1, bound, new_bound, rv, visited);
        visited.erase(state.row);
    }

}

void search(const State& state, int cost, int bound, int new_bound, vector<char>& rv, set<ull>& visited) {
    bool finish = false;
    if (state.spacePos >= 4) {
        visit(state.up(), cost, bound, new_bound, rv, visited, finish);
        if (finish) {
            return;
        }
    }
    if (state.spacePos <= 11) {
        visit(state.down(), cost, bound, new_bound, rv, visited, finish);
        if (finish) {
            return;
        }
    }
    if (state.spacePos % 4 != 0) {
        visit(state.left(), cost, bound, new_bound, rv, visited, finish);
        if (finish) {
            return;
        }
    }
    if (state.spacePos % 4 != 3) {
        visit(state.right(), cost, bound, new_bound, rv, visited, finish);
        if (finish) {
            return;
        }
    }
}

bool solve_15_puzzle(State& state, vector<char>& rv) {
    if (!solvable(state)) {
        return false;
    }
    set<ull> visited;
    int bound = heuristic(state);
    while(rv.size() == 0) {
        visited.insert(state.row);
        int new_bound = INT_MAX;
        search(state, 1, bound, new_bound, rv, visited);
        bound = new_bound;
        visited.clear();
    }
    return true;
}