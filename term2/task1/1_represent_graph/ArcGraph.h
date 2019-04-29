//
// Created by gulnara on 22.02.19.
//

#ifndef INC_1_MAKE_GRAPH_MATRIXGRAPH_H
#define INC_1_MAKE_GRAPH_MATRIXGRAPH_H

#include "graph.h"

#include <vector>
#include <utility>

using std::vector;
using std::pair;

class ArcGraph : public IGraph {
public:
    ArcGraph(int vertexCount);
    ArcGraph(IGraph* graph);

    virtual void AddEdge(int from, int to);
    virtual int VerticesCount() const;
    virtual void GetNextVertices(int vertex, vector<int> &vertices) const;
    virtual void GetPrevVertices(int vertex, vector<int> &vertices) const;

private:
    vector<pair<int, int>> edges;
    int vertexCount_;
};

#endif //INC_1_MAKE_GRAPH_MATRIXGRAPH_H
