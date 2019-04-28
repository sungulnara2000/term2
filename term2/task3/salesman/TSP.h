//
// Created by gulnara on 25.04.19.
//

#ifndef SALESMAN_TSP_H
#define SALESMAN_TSP_H

#include "graph.h"

class TSP {
public:
    TSP(ListGraph& graph): inputGraph(graph), map(graph.verticesCount) {
        initMap();
        cout << "created TSP" << endl;
    }
    void findWay(vector<int>& bufferForPath);

private:
    ListGraph inputGraph;
    ListGraph map;

    void initMap();
    void findOdds(vector<int>& bufferForOdds);
    void perfectMatching();
    void EulerTour(int start, vector<int>& path);
    int makeHamiltonian(vector<int>& path);
    int findBestPath(int start, vector<int>& path);
};


#endif //SALESMAN_TSP_H
