#include <fstream>

#include "State.h"
#include <iostream>

using std::cin;
using std::cout;


bool solve_8_puzzle(State& state, vector<char>& rv);

int main() {
    vector<int> combination(9, 0);
    for (int i = 0; i < 9; ++i) {
        cin >> combination[i];
    }
    State state(combination);

    vector<char> moves;
    if(solve_8_puzzle(state, moves)) {
        cout << moves.size() << '\n';
        for (auto i: moves) {
            cout << i;
        }
    } else{
        cout << -1;
    }
    return 0;

}