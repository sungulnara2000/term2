//
// Created by gulnara on 24.03.19.
//

#ifndef INC_1_MAKE_GRAPH_LISTGRAPH_H
#define INC_1_MAKE_GRAPH_LISTGRAPH_H

#include "graph.h"

#include <vector>


using std::vector;
using std::make_pair;
using std::pair;

// non-oriented graph with weights

class ListGraph : public IGraph {
public:
    ListGraph(int vertexCount);

    void AddEdge(int from, int to, int length);
    int VerticesCount() const;
    void GetAdjacentVertices(int vertex, vector<pair<int, int>>& vertices) const;


private:
    vector<vector<pair<int, int>>> adjacencyList;
};


#endif //INC_1_MAKE_GRAPH_LISTGRAPH_H
