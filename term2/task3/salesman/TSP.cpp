//
// Created by gulnara on 25.04.19.
//

#include "TSP.h"

void MST(MatrixGraph& inputGraph, MatrixGraph& mst);


TSP::TSP(MatrixGraph& graph): inputGraph(graph),
                            map(graph.getVerticesCount()),
                            wayCost(0) {
    initMap();
}

void TSP::initMap() {
    MST(inputGraph, map);
}

void TSP::findOdds(vector<int> &bufferForOdds) {
    bufferForOdds.clear();
    for (int vertex = 0; vertex < map.getVerticesCount(); ++vertex) {
        vector<Edge> nextEdges;
        map.getNextEdges(vertex, nextEdges);
        if (nextEdges.size() % 2 == 1) {
            bufferForOdds.push_back(vertex);
        }
    }
}

void TSP::perfectMatching() {
    vector<int> odds;
    findOdds(odds);
    while(!odds.empty()) {
        int curOdd = odds[0];
        int closest = odds[1];
        int closestId = 1;
        vector<float> neighbours;
        inputGraph.getNextVertices(curOdd, neighbours);
        for (int j = 2; j < odds.size(); ++j) {
            if (neighbours[closest] > neighbours[j]) {
                closest = odds[j];
                closestId = j;
            }
        }
        map.addEdge(curOdd, closest, neighbours[closest]);
        odds.erase(odds.begin() + closestId);
        odds.erase(odds.begin());
    }
}

void TSP::findEulerTour(int start, vector<int> &path) {
    vector<vector<Edge>> tempList;
    for (int j = 0; j < map.getVerticesCount(); ++j) {
        vector<Edge> nextEdges;
        map.getNextEdges(j, nextEdges);
        tempList.push_back(nextEdges);
    }
    path.clear();

    stack<int> stack;
    int pos = start;

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
}


float TSP::makeTourHamiltonian(vector<int>& path) {
    vector<bool> visited(map.getVerticesCount(), false);
    float pathCost = 0;

    int root = path.front();
    visited[root] = true;

    vector<int>::iterator cur = path.begin();
    vector<int>::iterator iter = path.begin() + 1;

    vector<float> neighbours;
    while(iter != path.end()){
        if(!visited[*iter]){
            inputGraph.getNextVertices(*cur, neighbours);
            pathCost += neighbours[*iter];
            cur = iter;
            visited[*cur] = true;
            iter = cur + 1;
        } else {
            iter = path.erase(iter);
        }
    }
    inputGraph.getNextVertices(*cur, neighbours);
    pathCost += neighbours[*iter];
    return pathCost;
}


void TSP::findWay(vector<int>& way) {
    perfectMatching();
    int bestId = 0;
    float minLength = std::numeric_limits<int>::max();
    for (int start = 0; start < map.getVerticesCount(); ++start) {
        findEulerTour(start, way);
        float length = makeTourHamiltonian(way);
        minLength = std::min(minLength, length);
        bestId = start;
    }
    findEulerTour(bestId, way);
    wayCost = makeTourHamiltonian(way);
    way.push_back(bestId);
}