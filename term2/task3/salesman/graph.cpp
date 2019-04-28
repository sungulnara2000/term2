//
// Created by gulnara on 25.04.19.
//

#include "graph.h"

ListGraph::ListGraph(int vertexCount) : verticesCount(vertexCount),
                                        weightMatrix(vertexCount, vector<int>(vertexCount, std::numeric_limits<int>::max())),
                                        adjacencyList(vertexCount){
    for (int i = 0; i < weightMatrix.size(); ++i) {
        weightMatrix[i][i] = 0;
    }
}

//ListGraph::ListGraph(const ListGraph& graph) : verticesCount(graph.verticesCount), edgesList(graph.edgesList) {}


void ListGraph::addEdge(int from, int to, long weight) {
    Edge edge(from, to, weight);
    adjacencyList[from].push_back(edge);
    Edge backEdge(to, from, weight);
    adjacencyList[to].push_back(backEdge);

    weightMatrix[from][to] = weight;
    weightMatrix[to][from] = weight;
    edgesList.push_back(edge);
}
