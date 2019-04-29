//
// Created by gulnara on 22.02.19.
//

#ifndef INC_1_MAKE_GRAPH_MATRIXGRAPH_H
#define INC_1_MAKE_GRAPH_MATRIXGRAPH_H

#include "graph.h"

#include <vector>

using std::vector;

class MatrixGraph : public IGraph {
public:
    MatrixGraph(int vertexCount);
    MatrixGraph(IGraph* graph);

    virtual void AddEdge(int from, int to);
    virtual int VerticesCount() const;
    virtual void GetNextVertices(int vertex, vector<int>& vertices) const;
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const;

private:
    vector<vector<bool>> adjacencyMatrix;
};


#endif //INC_1_MAKE_GRAPH_MATRIXGRAPH_H
