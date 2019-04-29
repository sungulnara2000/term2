#include <iostream>
#include "State.h"
#include "Solver.h"


using std::cin;
using std::cout;

int main() {
    vector<int> combination(16, 0);
    for (int i = 0; i < 16; ++i) {
        std::cin >> combination[i];
    }
    State state(combination);

    vector<char> moves;
    Solver solver;
    if (solver.solve(state, moves)) {
        std::cout << moves.size() << '\n';
        for (auto i: moves) {
            std::cout << i;
        }
    } else {
        std::cout << -1;
    }
}
