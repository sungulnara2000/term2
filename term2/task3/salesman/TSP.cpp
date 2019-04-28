//
// Created by gulnara on 25.04.19.
//

#include "TSP.h"

void MST(ListGraph& inputGraph, ListGraph& mst);


TSP::TSP(ListGraph& graph): inputGraph(graph),
                            map(graph.verticesCount),
                            wayCost(0) {
    initMap();
//    cout << "created TSP" << endl;
}

void TSP::initMap() {
    MST(inputGraph, map);
//    cout << "inited map" << endl;
}

void TSP::findOdds(vector<int> &bufferForOdds) {
    bufferForOdds.clear();
    for (int i = 0; i < map.verticesCount; ++i) {
        if (map.adjacencyList[i].size() % 2 == 1) {
            bufferForOdds.push_back(i);
        }
    }
//    cout << "found odds" << endl;
}

void TSP::perfectMatching() {
    vector<int> odds;
    findOdds(odds);
    while(!odds.empty()) {
        int curOdd = odds[0];
        int closest = odds[1];
        int closestId = 1;
        for (int j = 2; j < odds.size(); ++j) {
            if (inputGraph.weightMatrix[curOdd][closest] > inputGraph.weightMatrix[curOdd][j]) {
                closest = odds[j];
                closestId = j;
            }
        }
        map.addEdge(curOdd, closest, inputGraph.weightMatrix[curOdd][closest]);
        odds.erase(odds.begin() + closestId);
        odds.erase(odds.begin());
    }
//    cout << "perfect matching completed" << endl;
}

void TSP::EulerTour(int start, vector<int> &path) {
    vector<vector<Edge>> tempList = map.adjacencyList;
    path.clear();

    stack<int> stack;
    int pos = start;
//    path.push_back(start); // not needed

    while(!stack.empty() || !tempList[pos].empty()){
        if(tempList[pos].empty()){
            path.push_back(pos);
            pos = stack.top();
            stack.pop();
        } else {
            stack.push(pos);
            int neighbor = tempList[pos].back().to;
            tempList[pos].pop_back();
            for(int i = 0; i < tempList[neighbor].size(); i++){
                if(tempList[neighbor][i].to == pos){
                    tempList[neighbor].erase(tempList[neighbor].begin()+i);
                }
            }
            pos = neighbor;
        }
    }
    path.push_back(pos);
//    cout << "Euler tour" << endl;
}


float TSP::makeHamiltonian(vector<int>& path) {
    vector<bool> visited(map.verticesCount, false);
    float pathCost = 0;

    int root = path.front();
    visited[root] = true;

    vector<int>::iterator cur = path.begin();
    vector<int>::iterator iter = path.begin() + 1;

    while(iter != path.end()){
        if(!visited[*iter]){
            pathCost += inputGraph.weightMatrix[*cur][*iter];
            cur = iter;
            visited[*cur] = true;
            iter = cur + 1;
        } else {
            iter = path.erase(iter);
        }
    }
    pathCost += inputGraph.weightMatrix[*cur][*iter];
//    cout << "made it Hamiltonian" << endl;
    return pathCost;
}

//int TSP::findBestPath(int start, vector<int>& path){
//    EulerTour(start, path);
//
//    int length;
//    makeHamiltonian(path, length);
//
//    return length;
//}

void TSP::findWay(vector<int>& way) {
    perfectMatching();
    int bestId = 0;
    float minLength = std::numeric_limits<int>::max();
    for (int start = 0; start < map.verticesCount; ++start) {
//        int length = findBestPath(start, way);
        EulerTour(start, way);
        float length = makeHamiltonian(way);
        minLength = std::min(minLength, length);
        bestId = start;
    }
    EulerTour(bestId, way);
    wayCost = makeHamiltonian(way);
    way.push_back(bestId);
}