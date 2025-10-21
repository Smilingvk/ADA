#include <bits/stdc++.h>
using namespace std;

struct UGraph {
    int V;
    vector<vector<int>> adj;
    UGraph(int V) : V(V), adj(V) {}
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

void UGRAPHinsertEdge(UGraph &G, int v, int w) {
    if (v < 0 || v >= G.V || w < 0 || w >= G.V) return;
    if (v == w) {
        int cnt = (int)count(G.adj[v].begin(), G.adj[v].end(), v);
        if (cnt >= 2) return;
        if (cnt == 1) G.adj[v].push_back(v);
        else { G.adj[v].push_back(v); G.adj[v].push_back(v); }
        return;
    }
    if (find(G.adj[v].begin(), G.adj[v].end(), w) == G.adj[v].end())
        G.adj[v].push_back(w);
    if (find(G.adj[w].begin(), G.adj[w].end(), v) == G.adj[w].end())
        G.adj[w].push_back(v);
}

void printGraph(const UGraph &G) {
    for (int i = 0; i < G.V; ++i) {
        cout << i << ":";
        for (int u : G.adj[i]) cout << " " << u;
        cout << "\n";
    }
}

int main() {
    UGraph G(6);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(4,5);

    cout << "Grafo inicial:\n";
    printGraph(G);

    cout << "\nInsertar arista 2-4:\n";
    UGRAPHinsertEdge(G, 2, 4);
    printGraph(G);

    cout << "\nIntentar insertar arista 2-4 de nuevo (no debe duplicar):\n";
    UGRAPHinsertEdge(G, 2, 4);
    printGraph(G);

    cout << "\nInsertar lazo 3-3:\n";
    UGRAPHinsertEdge(G, 3, 3);
    printGraph(G);

    cout << "\nIntentar insertar lazo 3-3 de nuevo (no debe duplicar):\n";
    UGRAPHinsertEdge(G, 3, 3);
    printGraph(G);

    return 0;
}
