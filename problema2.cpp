#include <stdio.h>

#define MAX 100

int GRAPHindeg(int G[MAX][MAX], int n, int v) {
    int indeg = 0;
    for (int i = 0; i < n; i++) {
        if (G[i][v] == 1)
            indeg++;
    }
    return indeg;
}

int GRAPHoutdeg(int G[MAX][MAX], int n, int v) {
    int outdeg = 0;
    for (int j = 0; j < n; j++) {
        if (G[v][j] == 1)
            outdeg++;
    }
    return outdeg;
}

int main() {
    int G[MAX][MAX];
    int n, v;

    printf("Ingrese número de vértices: ");
    scanf("%d", &n);

    printf("Ingrese la matriz de adyacencia (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    printf("Ingrese el vértice (0..%d): ", n-1);
    scanf("%d", &v);

    printf("Grado de entrada de %d: %d\n", v, GRAPHindeg(G, n, v));
    printf("Grado de salida de %d: %d\n", v, GRAPHoutdeg(G, n, v));

    return 0;
}
