//
// Created by gulnara on 25.04.19.
//

#ifndef SALESMAN_TSP_H
#define SALESMAN_TSP_H

#include "graph.h"

class TSP {
public:
    TSP(MatrixGraph& graph);
    void findWay(vector<int>& bufferForPath);

    float wayCost;

private:
    MatrixGraph inputGraph;
    MatrixGraph map;

    void initMap();
    void findOdds(vector<int>& bufferForOdds);
    void perfectMatching();
    void findEulerTour(int start, vector<int>& path);
    float makeTourHamiltonian(vector<int>& path); // make path hamiltonian and return length of the path
};


#endif //SALESMAN_TSP_H
