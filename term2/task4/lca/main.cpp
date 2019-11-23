#include <iostream>
#include "lca.h"

using std::pair;
using std::make_pair;
using std::cin;
using std::cout;

int main() {
    int n, m;
    cin >> n >> m;
    LCA lca(n);
    for (int vertex = 1; vertex < n; ++vertex) {
        int parent;
        cin >> parent;
        lca.addEdge(vertex, parent);
    }
    lca.preprocess(0);
    unsigned long long a1, a2;
    unsigned long long x, y, z;
    cin >> a1 >> a2 >> x >> y >> z;
    int answer = 0;
    int v = lca.getCommonAncestor(a1, a2);
    answer += v;
    for (int i = 2; i <= m; ++i) {
        unsigned long long new_a1 = (a1 * x + a2 * y + z) % n;
        a2 = (a2 * x + new_a1 * y +z) % n;
        a1 = new_a1;
        v = lca.getCommonAncestor((a1 + v) % n, a2);

        answer += v;
    }
    cout << answer;
    return 0;
}