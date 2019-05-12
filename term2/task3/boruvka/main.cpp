#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <limits>

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
    void addEdge(int from, int to, long weight);
    Edge getEdge(int i) const;
    int getEdgesCount() const;

    int verticesCount;

private:
    vector<Edge> edgesList;
};

ListGraph::ListGraph(int vertexCount) : verticesCount(vertexCount) {}

void ListGraph::addEdge(int from, int to, long weight) {

    Edge edge(from, to, weight);
    edgesList.push_back(edge);
}

Edge ListGraph::getEdge(int i) const {
    return edgesList[i];
}

int ListGraph::getEdgesCount() const {
    return edgesList.size();
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
    sets[v].parent = findSet(sets, sets[v].parent);
    return sets[v].parent;
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

long CalculateMSTweight(const ListGraph& graph) {
    long MSTweight = 0;
    int numSets = graph.verticesCount;
    vector<component> sets(graph.verticesCount);

    for (int i = 0; i < graph.verticesCount; ++i) {
        sets[i].parent = i;
        sets[i].rank = 0;
    }

    vector<Edge> safeEdges(graph.verticesCount, Edge(0, 0, std::numeric_limits<int>::max()));


    while(numSets > 1) {
        for (int i = 0; i < graph.verticesCount; ++i) {
            safeEdges[i].weight = std::numeric_limits<int>::max();
        }
        for (int j = 0; j < graph.getEdgesCount(); ++j) {
            Edge edge = graph.getEdge(j);
            int leader1 = findSet(sets, edge.from);
            int leader2 = findSet(sets, edge.to);
            if (leader1 != leader2) {
                if(edge.weight < safeEdges[leader1].weight) {
                    safeEdges[leader1] = edge;
                }
                if(edge.weight < safeEdges[leader2].weight) {
                    safeEdges[leader2] = edge;
                }
            }
        }
        for (int v = 0; v < graph.verticesCount; ++v) {
            if (safeEdges[v].weight != std::numeric_limits<int>::max()) {
                int leader1 = findSet(sets, safeEdges[v].from);
                int leader2 = findSet(sets, safeEdges[v].to);

                if (leader1 != leader2) {
                    MSTweight += safeEdges[v].weight;
                    unionSets(sets, leader1, leader2);
                    --numSets;
                }
            }
        }
    }
    return MSTweight;
}




long CalculateMSTweight(const ListGraph& graph);

int main() {
    int n;
    int m;
    cin >> n >> m;
    ListGraph graph(n);
    for (int i = 0; i < m; ++i) {
        int from, to;
        long weight;
        cin >> from >> to >> weight;
        graph.addEdge(from - 1, to - 1, weight);
    }
    cout << CalculateMSTweight(graph);
    return 0;
}