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

pair<int, vector<int>> UGRAPHdegrees_and_vertices(const UGraph &G) {
    int maxDeg = 0;
    vector<int> verts;
    for (int v = 0; v < G.V; ++v) {
        int deg = (int)G.adj[v].size();
        if (deg > maxDeg) {
            maxDeg = deg;
            verts = {v};
        } else if (deg == maxDeg) {
            verts.push_back(v);
        }
    }
    return {maxDeg, verts};
}

void printGraphAndDegrees(const UGraph &G) {
    cout << "Listas de adyacencia:\n";
    for (int v = 0; v < G.V; ++v) {
        cout << "  " << v << ":";
        for (int u : G.adj[v]) cout << " " << u;
        cout << "\n";
    }

    cout << "\nGrados por vértice:\n";
    for (int v = 0; v < G.V; ++v) {
        cout << "  grado(" << v << ") = " << G.adj[v].size() << "\n";
    }
}

int main() {
    UGraph G(6);

    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 2);
    G.addEdge(2, 3);
    G.addEdge(2, 4);
    G.addEdge(4, 5);

    printGraphAndDegrees(G);

    auto [maxDeg, vertices] = UGRAPHdegrees_and_vertices(G);

    cout << "\nGrado máximo del grafo: " << maxDeg << "\n";
    cout << "Vértice(s) con grado máximo:";
    for (int v : vertices) cout << " " << v;
    cout << "\n";

    return 0;
}
