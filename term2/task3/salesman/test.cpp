//
// Created by gulnara on 28.04.19.
//

#include "graph.h"
#include "TSP.h"


float getDistance(City c1, City c2){
    float dx = pow((c1.x - c2.x),2);
    float dy = pow((c1.y - c2.y),2);
    return sqrt(dx + dy);
}

float check(ListGraph graph);

void createMap(int n, vector<City>& cities) {
    std::random_device rd;
    std::mt19937 gen(rd());

    int i;
    float sample;
    for(i = 0; i < n; ++i) {
        std::normal_distribution<float> d(0, 1);
        cities[i].x = d(gen);
        cities[i].y = d(gen);
    }
}

void test() {
    for (int n = 2; n < 11; ++n) {
        ListGraph graph(n);
        vector<City> cities(n);
        createMap(n, cities);
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
        cout << "approximation is            " << tsp.wayCost/realCost << endl;
    }
}