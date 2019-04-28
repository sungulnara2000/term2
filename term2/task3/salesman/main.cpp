#include "graph.h"
#include "TSP.h"


// undirected everywhere
// addEdge adds from-to and to-from edges

struct City{
    int x;
    int y;
};

int getDistance(City c1, City c2){
    int dx = pow((float)(c1.x - c2.x),2);
    int dy = pow((float)(c1.y - c2.y),2);
    return floor((float)(sqrt(dx + dy) + .5));
}

int check(ListGraph graph);

int main() {
    int n;
    cin >> n;
    ListGraph graph(n);
    vector<City> cities(n);
    for (int i = 0; i < n; ++i) {
        int number;
        cin >> number >> cities[i].x >> cities[i].y;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            graph.addEdge(i, j, getDistance(cities[i], cities[j]));
        }
    }
    TSP tsp(graph);
    vector<int> way;
    tsp.findWay(way);
    for (auto i : way){
        cout << i << " ";
    }
    cout << endl;
    cout << tsp.wayCost << endl;
    cout << check(graph);
    return 0;
}