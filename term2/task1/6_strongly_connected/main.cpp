#include "list_graph.h"

#include <iostream>


using namespace std;

int main() {
    int vertexCount;
    int edgesCount;
    std::cin >> vertexCount >> edgesCount;
    CListGraph graph(vertexCount);
    for (int i = 0; i < edgesCount; i++) {
        int from;
        int to;
        cin >> from >> to;
        graph.AddEdge(from - 1, to - 1);
    }

    cout << graph.CountAddEdges();
    //return 0;

//    CListGraph graph(5);
//    graph.AddEdge(0, 1);
//    graph.AddEdge(1, 2);
//    graph.AddEdge(2, 0);
//    graph.AddEdge(0, 3);
//    graph.AddEdge(3, 4);
//
//    cout << graph.CountAddEdges();

//    for (int i = 0; i < graph.components.size(); ++i) {
//        cout << i << ": ";
//        for (int j : graph.components[i]) {
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
//
//    for (int i : graph.colors) {
//        cout << i << ' ';
//    }


    return 0;
}