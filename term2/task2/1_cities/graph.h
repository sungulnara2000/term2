//
// Created by gulnara on 24.03.19.
//

#ifndef INC_1_MAKE_GRAPH_GRAPH_H
#define INC_1_MAKE_GRAPH_GRAPH_H

#include <vector>

using std::pair;

struct IGraph {
    virtual ~IGraph() {}

    // Добавление ребра от from к to.
    virtual void AddEdge(int from, int to, int length) = 0;

    virtual int VerticesCount() const  = 0;

    virtual void GetAdjacentVertices(int vertex, std::vector<pair<int, int>>& vertices) const = 0;

};


#endif //INC_1_MAKE_GRAPH_GRAPH_H
