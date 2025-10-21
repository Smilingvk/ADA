#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    Graph(int V) : V(V), adj(V) {}
    void addArc(int v, int w) { adj[v].push_back(w); }
};

void GRAPHdestroy(Graph &G) {
    G.adj.clear();
    G.V = 0;
}

void printGraph(const Graph &G) {
    cout << "Vértices: " << G.V << "\n";
    for (int i = 0; i < G.V; ++i) {
        cout << i << ":";
        for (int u : G.adj[i]) cout << " " << u;
        cout << "\n";
    }
}

int main() {
    Graph G(4);
    G.addArc(0,1);
    G.addArc(1,2);
    G.addArc(2,3);
    G.addArc(3,0);

    cout << "Grafo antes de destruir:\n";
    printGraph(G);

    GRAPHdestroy(G);

    cout << "\nDespués de GRAPHdestroy:\n";
    printGraph(G);

    return 0;
}
