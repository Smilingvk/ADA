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

void UGRAPHremoveEdge(UGraph &G, int v, int w) {
    auto &av = G.adj[v];
    av.erase(remove(av.begin(), av.end(), w), av.end());
    if (v != w) {
        auto &aw = G.adj[w];
        aw.erase(remove(aw.begin(), aw.end(), v), aw.end());
    }
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
    G.addEdge(2,4);
    G.addEdge(4,5);
    cout << "Antes de eliminar arista 2-4:\n";
    printGraph(G);
    UGRAPHremoveEdge(G, 2, 4);
    cout << "\nDespués de eliminar arista 2-4:\n";
    printGraph(G);
    cout << "\nEliminamos arista 0-1:\n";
    UGRAPHremoveEdge(G, 0, 1);
    printGraph(G);
    cout << "\nAñadimos lazo 3-3 y luego lo eliminamos:\n";
    G.addEdge(3,3);
    printGraph(G);
    UGRAPHremoveEdge(G, 3, 3);
    cout << "\nDespués de eliminar lazo 3-3:\n";
    printGraph(G);
    return 0;
}
