#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::cout;
using std::cin;

void floyd(vector<vector<int>>& matrix) {
    for (int k = 0; k < matrix.size(); ++k) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for (auto i: matrix) {
        for (auto j: i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    floyd(matrix);
}