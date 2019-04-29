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
    vector<IGraph*> graphs;
    SetGraph set_graph(10);
    graphs.push_back(&set_graph);

    ListGraph list_graph(10);
    graphs.push_back(&list_graph);

    ArcGraph arc_graph(10);
    graphs.push_back(&arc_graph);

    MatrixGraph matrix_graph(10);
    graphs.push_back(&matrix_graph);

    for (auto i: graphs) {
        InitGraph(*i);
    }

    vector<int> first_buffer;
    vector<int> second_buffer;
    for (size_t i = 0; i < graphs.size(); ++i) {
        for (size_t j = i + 1; j < graphs.size(); ++j) {
            IGraph* firstGraph = graphs[i];
            IGraph* secondGraph = graphs[j];

            firstGraph->GetPrevVertices(5, first_buffer);
            secondGraph->GetPrevVertices(5, second_buffer);
            assert(compareVectors(first_buffer, second_buffer));

            firstGraph->GetNextVertices(3, first_buffer);
            secondGraph->GetNextVertices(3, second_buffer);
            assert(compareVectors(first_buffer, second_buffer));

            MatrixGraph matrix_graph_copy = MatrixGraph(firstGraph);
            ArcGraph arc_graph_copy = ArcGraph(firstGraph);
            ListGraph list_graph_copy = ListGraph(firstGraph);
            SetGraph set_graph_copy = SetGraph(firstGraph);

            matrix_graph_copy.GetNextVertices(2, first_buffer);
            set_graph_copy.GetNextVertices(2, second_buffer);
            assert(compareVectors(first_buffer, second_buffer));

            list_graph_copy.GetPrevVertices(9, first_buffer);
            arc_graph_copy.GetPrevVertices(9, second_buffer);
            assert(compareVectors(first_buffer, second_buffer));
        }
    }
}
