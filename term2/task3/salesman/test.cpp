//
// Created by gulnara on 28.04.19.
//

#include "graph.h"
#include "TSP.h"


float getDistance(const City& c1, const City& c2){
    float dx = pow((c1.x - c2.x),2);
    float dy = pow((c1.y - c2.y),2);
    return sqrt(dx + dy);
}

float check(MatrixGraph graph);

void createMap(int n, vector<City>& cities) {
    std::random_device rd;
    std::mt19937 gen(rd());

    for(int i = 0; i < n; ++i) {
        std::normal_distribution<float> d(0, 1);
        cities[i].x = d(gen);
        cities[i].y = d(gen);
    }
}

double expirement(int n) {
    MatrixGraph graph(n);
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
    double realCost = check(graph);
    cout << "wayCost / realCost: " << tsp.wayCost << " / " << realCost << " = " << tsp.wayCost/realCost << endl;
    return tsp.wayCost/realCost;
}

void test() {
    for (int n = 2; n < 11; ++n) {
        cout << "Current n: " << n << endl;
        vector<double> values;
        for (int j = 0; j < 5; ++j) {
            double value = expirement(n);
            values.push_back(value);
        }

        double sumOfElems = 0;
        for (auto value : values) {
            sumOfElems += value;
        }
        double middle = sumOfElems / values.size();
        cout << "Middle of values: " << middle << endl;
        double standardDeviation;
        double sumOfSquares = 0;
        for (auto value : values) {
            sumOfSquares += pow(value - middle, 2);
        }
        standardDeviation = pow(sumOfSquares / values.size(), 0.5);
        cout << "Standart deviation: " << standardDeviation << endl;
        cout << endl;
    }
}