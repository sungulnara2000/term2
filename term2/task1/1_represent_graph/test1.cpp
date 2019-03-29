//
// Created by gulnara on 29.03.19.
//
#include <assert.h>
#include <algorithm>

#include "graph.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"

using std::sort;

static bool compareVectors(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return (a == b);
}

void test1(){
    SetGraph set_graph(10);

    set_graph.AddEdge(1, 2);
    set_graph.AddEdge(1, 3);
    set_graph.AddEdge(0, 1);
    set_graph.AddEdge(3, 4);
    set_graph.AddEdge(4, 5);
    set_graph.AddEdge(5, 6);
    set_graph.AddEdge(2, 7);
    set_graph.AddEdge(8, 9);

    ListGraph list_graph(10);

    list_graph.AddEdge(1, 2);
    list_graph.AddEdge(1, 3);
    list_graph.AddEdge(0, 1);
    list_graph.AddEdge(3, 4);
    list_graph.AddEdge(4, 5);
    list_graph.AddEdge(5, 6);
    list_graph.AddEdge(2, 7);
    list_graph.AddEdge(8, 9);

    ArcGraph arc_graph(10);

    arc_graph.AddEdge(1, 2);
    arc_graph.AddEdge(1, 3);
    arc_graph.AddEdge(0, 1);
    arc_graph.AddEdge(3, 4);
    arc_graph.AddEdge(4, 5);
    arc_graph.AddEdge(5, 6);
    arc_graph.AddEdge(2, 7);
    arc_graph.AddEdge(8, 9);
    MatrixGraph matrix_graph = MatrixGraph(&list_graph);
    vector<int> matrix_buffer;
    vector<int> set_buffer;
    vector<int> list_buffer;
    vector<int> arc_buffer;

    matrix_graph.GetNextVertices(5, matrix_buffer);
    set_graph.GetNextVertices(5, set_buffer);
    list_graph.GetPrevVertices(8, list_buffer);
    arc_graph.GetPrevVertices(8, arc_buffer);
    assert(compareVectors(matrix_buffer, set_buffer));
    assert(compareVectors(list_buffer, arc_buffer));

}
