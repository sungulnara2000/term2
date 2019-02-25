//
// Created by gulnara on 22.02.19.
//

#ifndef INC_1_MAKE_GRAPH_SETGRAPH_H
#define INC_1_MAKE_GRAPH_SETGRAPH_H


#include "graph.h"

#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class SetGraph : public IGraph {
public:
    SetGraph(int vertexCount);
    SetGraph(IGraph* graph);

    virtual void AddEdge(int from, int to);
    virtual int VerticesCount() const;
    virtual void GetNextVertices(int vertex, vector<int>& vertices) const;
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const;

private:
    vector<unordered_set<int>> arrayOfSets;
    int vertexCount_;
};


#endif //INC_1_MAKE_GRAPH_SETGRAPH_H
