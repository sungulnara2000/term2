#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>

using std::vector;
using std::make_pair;
using std::pair;
using std::unordered_set;
using std::cin;
using std::cout;

struct Edge {
    Edge() {}
    Edge(int from, int to, long weight): from(from), to(to), weight(weight) {}
    ~Edge(){}
    int from;
    int to;
    long weight;
};


// non-oriented graph with weights

class ListGraph{
public:
    ListGraph(int vertexCount);
    void AddEdge(int from, int to, long weight);

    vector<Edge> edgesList;
    int VerticesCount;
};

ListGraph::ListGraph(int vertexCount) : VerticesCount(vertexCount) {}

void ListGraph::AddEdge(int from, int to, long weight) {

    Edge edge(from, to, weight);
    edgesList.push_back(edge);
}




// disjoint-set-union

struct component {
    int parent;
    int rank;
};


int findSet(vector<component>& sets, int v) {
    if (v == sets[v].parent) {
        return v;
    }
    return sets[v].parent = findSet(sets, sets[v].parent);
}

void unionSets(vector<component>& sets, int a, int b) {
    a = findSet(sets, a);
    b = findSet(sets, b);
    if (a != b) {
        if (sets[a].rank < sets[b].rank) {
            std::swap(a, b);
        }
        sets[b].parent = a;
        if (sets[a].rank == sets[b].rank) {
            ++sets[a].rank;
        }
    }
}

long MSTweight(ListGraph& graph) {
    long MSTweight = 0;
    int numSets = graph.VerticesCount;
    vector<component> sets(graph.VerticesCount);

    for (int i = 0; i < graph.VerticesCount; ++i) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }


    vector<Edge> safeEdges(graph.VerticesCount, Edge(0, 0, INT_MAX)); // без конструктора?


    while(numSets > 1) {
//        for (auto i : safeEdges) {
//            i.weight = INT_MAX;
//        }
        for (int i = 0; i < graph.VerticesCount; ++i) {
            safeEdges[i].weight = INT_MAX;
        }
        for (auto i : graph.edgesList) {
            int leader1 = findSet(sets, i.from);
            int leader2 = findSet(sets, i.to);
            if (leader1 != leader2) {
                if(i.weight < safeEdges[leader1].weight) {
                    safeEdges[leader1] = i;
                }
                if(i.weight < safeEdges[leader2].weight) {
                    safeEdges[leader2] = i;
                }
            }
        }
        for (int i = 0; i < graph.VerticesCount; ++i) {
            if (safeEdges[i].weight != INT_MAX) {
                int leader1 = findSet(sets, safeEdges[i].from);
                int leader2 = findSet(sets, safeEdges[i].to);

                if (leader1 != leader2) {
                    MSTweight += safeEdges[i].weight;
                    unionSets(sets, leader1, leader2);
                    --numSets;
                }
            }
        }
    }
    return MSTweight;
}




long MSTweight(ListGraph& graph);

int main() {
    int n;
    int m;
    cin >> n >> m;
    ListGraph graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to;
        long weight;
        cin >> from >> to >> weight;
        graph.AddEdge(from - 1, to - 1, weight);
    }
    cout << MSTweight(graph);
    return 0;
}