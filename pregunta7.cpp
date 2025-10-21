#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int u, int v) { adj[u].push_back(v); }
};

bool GRAPHundir(const Graph &G) {
    for (int v = 0; v < G.V; ++v) {
        for (int w : G.adj[v]) {
            auto &listW = G.adj[w];
            if (find(listW.begin(), listW.end(), v) == listW.end())
                return false;
        }
    }
    return true;
}

void printGraph(const Graph &G) {
    for (int i = 0; i < G.V; ++i) {
        cout << i << ":";
        for (int u : G.adj[i]) cout << " " << u;
        cout << "\n";
    }
}

int main() {
    Graph G1(4);
    G1.addEdge(0,1);
    G1.addEdge(1,0);
    G1.addEdge(1,2);
    G1.addEdge(2,1);
    G1.addEdge(2,3);
    G1.addEdge(3,2);

    cout << "Grafo G1:\n";
    printGraph(G1);
    cout << "\n¿G1 es no dirigido?: " << (GRAPHundir(G1) ? "Sí" : "No") << "\n";

    Graph G2(4);
    G2.addEdge(0,1);
    G2.addEdge(1,2);
    G2.addEdge(2,3);

    cout << "\nGrafo G2:\n";
    printGraph(G2);
    cout << "\n¿G2 es no dirigido?: " << (GRAPHundir(G2) ? "Sí" : "No") << "\n";

    return 0;
}
