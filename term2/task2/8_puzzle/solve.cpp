//
// Created by gulnara on 29.03.19.
//
#include <map>
#include "State.h"

using std::map;

bool solvable(State& state) {
    int inversions = 0;
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if (state.get_value(i) != 0 && state.get_value(j) != 0 && state.get_value(i) > state.get_value(j)) {
                ++inversions;
            }
        }
    }
    return (inversions % 2 == 0);
}

void visit(State& state, map<ul, State>& visited, queue<ul>& q) {
    if (visited.find(state.row) == visited.end()) {
        visited[state.row] = state;
        q.push(state.row);
    }
}

bool solve_8_puzzle(State& state, vector<char>& rv) {
    if (!solvable(state)) {
        return false;
    }
    rv.clear();

    queue<ul> q;
    q.push(state.row);

    map<ul, State> visited;
    visited[state.row] = state;

    ul vertex;

    while(true) {
        vertex = q.front();
        q.pop();
        if (vertex == 4886718336) {
            break;
        }

        State vertexState = visited[vertex];

        if (vertexState.spacePos >= 3) {
            State up = vertexState.up();
            visit(up, visited, q);
        }
        if (vertexState.spacePos <= 5){
            State down = vertexState.down();
            visit(down, visited, q);
        }
        if (vertexState.spacePos % 3 != 0){
            State left = vertexState.left();
            visit(left, visited, q);
        }
        if (vertexState.spacePos % 3 != 2){
            State right = vertexState.right();
            visit(right, visited, q);
        }

    }

    while (vertex != state.row) {
        rv.push_back(visited[vertex].move);
        vertex = visited[vertex].prev;
    }
    return true;
}