#include <iostream>
#include <vector>

using std::vector;
using std::max;
using std::cin;
using std::cout;


// modified Floyd' algotithm
bool ifNegativeCycle(vector<vector<double>>& matrix) {
    for (int k = 0; k < matrix.size(); ++k) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                matrix[i][j] = max(matrix[i][j], matrix[i][k] * matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][i] > 1) {
            return true;
        }
    }
    return false;
}



int main() {
    int n;
    cin >> n;
    vector<vector<double>> matrix(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                matrix[i][j] = -1;
            } else {
                cin >> matrix[i][j];
            }
        }
    }
    cout << (ifNegativeCycle(matrix) ? "YES" : "NO");
    return 0;
}