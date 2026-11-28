#include <stdlib.h>

int findSet(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findSet(parent, parent[i]);
}

void unionSet(int parent[], int i, int j) {
    int ri = findSet(parent, i), rj = findSet(parent, j);
    if (ri != rj) parent[ri] = rj;
}

int regionsBySlashes(char** grid, int gridSize) {
    int n = gridSize;
    int total = 4 * n * n;
    int* parent = (int*)malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) parent[i] = i;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int root = 4 * (r * n + c);
            char val = grid[r][c];
            if (val != '/') {
                unionSet(parent, root + 0, root + 1);
                unionSet(parent, root + 2, root + 3);
            }
            if (val != '\\') {
                unionSet(parent, root + 0, root + 3);
                unionSet(parent, root + 1, root + 2);
            }
            if (r + 1 < n) {
                unionSet(parent, root + 2, 4 * ((r + 1) * n + c) + 0);
            }
            if (c + 1 < n) {
                unionSet(parent, root + 1, 4 * (r * n + c + 1) + 3);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < total; i++) {
        if (findSet(parent, i) == i) count++;
    }
    free(parent);
    return count;
}