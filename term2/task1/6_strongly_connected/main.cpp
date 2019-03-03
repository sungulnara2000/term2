#include "list_graph.h"

#include <iostream>


using namespace std;

int main() {
    CListGraph graph(4);
    graph.AddEdge(0, 1);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 0);
    graph.AddEdge(0, 2);
    graph.AddEdge(2, 1);
    graph.AddEdge(1, 0);
    graph.AddEdge(2, 3);

    graph.FindSCC();
    return 0;
}