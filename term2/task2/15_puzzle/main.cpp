#include <iostream>
#include "State.h"


using std::cin;
using std::cout;

int heuristic(State& state);

bool solve_15_puzzle(State& state, vector<char>& rv);

int main() {
    vector<int> combination(16, 0);
    for (int i = 0; i < 16; ++i) {
        cin >> combination[i];
    }
    State state(combination);

    vector<char> moves;
    if (state.row == 1311768467463790320) {
        cout <<  0;
    } else {
        if (solve_15_puzzle(state, moves)) {
            cout << moves.size() << '\n';
            for (auto i: moves) {
                cout << i;
            }
        } else {
            cout << -1;
        }
    }
    return 0;
}