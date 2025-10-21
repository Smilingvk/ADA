#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    Graph(int V) : V(V), adj(V) {}
    void addArc(int v, int w) { adj[v].push_back(w); }
};

void GRAPHremoveArc(Graph &G, int v, int w) {
    if (v < 0 || v >= G.V || w < 0 || w >= G.V) return;
    auto &listV = G.adj[v];
    listV.erase(remove(listV.begin(), listV.end(), w), listV.end());
}

void printGraph(const Graph &G) {
    for (int i = 0; i < G.V; ++i) {
        cout << i << ":";
        for (int u : G.adj[i]) cout << " " << u;
        cout << "\n";
    }
}

int main() {
    Graph G(5);
    G.addArc(0,1);
    G.addArc(0,2);
    G.addArc(1,2);
    G.addArc(2,3);
    G.addArc(3,4);
    G.addArc(4,0);

    cout << "Grafo original:\n";
    printGraph(G);

    cout << "\nEliminar arco 0->2:\n";
    GRAPHremoveArc(G, 0, 2);
    printGraph(G);

    cout << "\nEliminar arco 3->4:\n";
    GRAPHremoveArc(G, 3, 4);
    printGraph(G);

    cout << "\nIntentar eliminar arco inexistente 2->0:\n";
    GRAPHremoveArc(G, 2, 0);
    printGraph(G);

    return 0;
}
