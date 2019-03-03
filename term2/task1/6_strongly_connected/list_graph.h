#pragma once

#include "graph.h"

#include <vector>

using std::vector;

class CListGraph : public IGraph {
public:
    CListGraph(int vertexCount);

    virtual void AddEdge(int from, int to);
    virtual int VerticesCount() const;
    virtual void GetNextVertices(int vertex, vector<int>& vertices) const;
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const;

    void FindSCC();

private:
    CListGraph GetTranspose();
    void DFS(int vertex, vector<bool>& visited, vector<int>& order);
    void TransposeDFS(int vertex, vector<bool>& visited, vector<int>& component, CListGraph transposed);

    vector<vector<int>> components;
    vector<vector<int>> adjacencyList;
};