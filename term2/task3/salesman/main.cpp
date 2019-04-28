#include "graph.h"
#include "TSP.h"


// undirected everywhere
// addEdge adds from-to and to-from edges

struct City{
    float x;
    float y;
};

float getDistance(City c1, City c2){
    float dx = pow((c1.x - c2.x),2);
    float dy = pow((c1.y - c2.y),2);
    return sqrt(dx + dy);
}

float check(ListGraph graph);

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
    for (int i = 0; i < way.size(); ++i){
        cout << i << ": " << way[i] << endl;
    }
    cout << "algotithm counted way cost: " << tsp.wayCost << endl;
    float realCost = check(graph);
    cout << "real way cost:              " << realCost << endl;
    cout << "approximation is            " << tsp.wayCost/realCost;
    return 0;
}