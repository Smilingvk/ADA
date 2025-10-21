#include <iostream>
using namespace std;

#define MAX 100


void GRAPHshow(int G[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 1)
                cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    int G[MAX][MAX];
    int n;

    cout << "Ingrese número de vértices: ";
    cin >> n;

    cout << "Ingrese la matriz de adyacencia (" << n << " x " << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G[i][j];

    cout << "\n=== Vértices adyacentes ===\n";
    GRAPHshow(G, n);

    return 0;
}
