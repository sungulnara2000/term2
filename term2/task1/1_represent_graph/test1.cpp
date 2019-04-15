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

void InitGraph(IGraph& graph) {
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(0, 1);
    graph.AddEdge(3, 4);
    graph.AddEdge(4, 5);
    graph.AddEdge(5, 6);
    graph.AddEdge(2, 7);
    graph.AddEdge(8, 9);
}

void test1(){
    SetGraph set_graph(10);
    InitGraph(set_graph);

    ListGraph list_graph(10);
    InitGraph(list_graph);

    ArcGraph arc_graph(10);
    InitGraph(arc_graph);

    MatrixGraph matrix_graph(10);
    InitGraph(matrix_graph);

    MatrixGraph matrix_graph_copy = MatrixGraph(&list_graph);
    ArcGraph arc_graph_copy = ArcGraph(&set_graph);
    ListGraph list_graph_copy = ListGraph(&matrix_graph);
    SetGraph set_graph_copy = SetGraph(&arc_graph);


    vector<int> matrix_buffer;
    vector<int> set_buffer;
    vector<int> list_buffer;
    vector<int> arc_buffer;

    vector<int> matrix_copy_buffer;
    vector<int> set_copy_buffer;
    vector<int> list_copy_buffer;
    vector<int> arc_copy_buffer;

    matrix_graph.GetNextVertices(5, matrix_buffer);
    set_graph.GetNextVertices(5, set_buffer);
    list_graph.GetPrevVertices(8, list_buffer);
    arc_graph.GetPrevVertices(8, arc_buffer);
    matrix_graph_copy.GetNextVertices(2, matrix_copy_buffer);
    set_graph_copy.GetNextVertices(2, set_copy_buffer);
    list_graph_copy.GetPrevVertices(9, list_copy_buffer);
    arc_graph_copy.GetPrevVertices(9, arc_copy_buffer);

    assert(compareVectors(matrix_buffer, set_buffer));
    assert(compareVectors(list_buffer, arc_buffer));
    assert(compareVectors(matrix_copy_buffer, set_copy_buffer));
    assert(compareVectors(list_copy_buffer, arc_copy_buffer));
}
