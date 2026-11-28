#include <stdlib.h>

int findSet(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int maxNumEdgesToRemove(int n, int** edges, int edgesSize, int* edgesColSize) {
    int parentA[n + 1], parentB[n + 1];
    for (int i = 0; i <= n; i++) { parentA[i] = i; parentB[i] = i; }

    int used = 0, edgesA = 0, edgesB = 0;

    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 3) {
            int rA1 = findSet(parentA, edges[i][1]), rA2 = findSet(parentA, edges[i][2]);
            int rB1 = findSet(parentB, edges[i][1]), rB2 = findSet(parentB, edges[i][2]);
            if (rA1 != rA2 || rB1 != rB2) {
                parentA[rA1] = rA2;
                parentB[rB1] = rB2;
                used++;
                edgesA++;
                edgesB++;
            }
        }
    }

    for (int i = 0; i < edgesSize; i++) {
        if (edges[i][0] == 1) {
            int r1 = findSet(parentA, edges[i][1]), r2 = findSet(parentA, edges[i][2]);
            if (r1 != r2) {
                parentA[r1] = r2;
                used++;
                edgesA++;
            }
        } else if (edges[i][0] == 2) {
            int r1 = findSet(parentB, edges[i][1]), r2 = findSet(parentB, edges[i][2]);
            if (r1 != r2) {
                parentB[r1] = r2;
                used++;
                edgesB++;
            }
        }
    }

    return (edgesA == n - 1 && edgesB == n - 1) ? edgesSize - used : -1;
}