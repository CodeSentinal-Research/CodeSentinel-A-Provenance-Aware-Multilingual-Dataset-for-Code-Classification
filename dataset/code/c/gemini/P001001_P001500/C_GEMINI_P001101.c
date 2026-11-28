#include <stdlib.h>

int findSet(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int n = edgesSize + 1;
    int* parent = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) parent[i] = i;

    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        int ru = findSet(parent, u), rv = findSet(parent, v);
        if (ru == rv) {
            res[0] = u; res[1] = v;
            free(parent);
            return res;
        }
        parent[ru] = rv;
    }
    free(parent);
    return res;
}