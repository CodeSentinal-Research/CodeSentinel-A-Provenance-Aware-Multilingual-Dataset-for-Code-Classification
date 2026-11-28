#include <stdlib.h>

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    if (n <= 2) {
        int* res = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) res[i] = i;
        *returnSize = n;
        return res;
    }

    int* deg = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        deg[edges[i][0]]++;
        deg[edges[i][1]]++;
    }

    int* leaves = (int*)malloc(n * sizeof(int));
    int lCount = 0;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) leaves[lCount++] = i;
    }

    int remaining = n;
    while (remaining > 2) {
        remaining -= lCount;
        int* nextLeaves = (int*)malloc(n * sizeof(int));
        int nlCount = 0;
        for (int i = 0; i < lCount; i++) {
            int leaf = leaves[i];
            deg[leaf]--;
            for (int j = 0; j < edgesSize; j++) {
                if (edges[j][0] == leaf && deg[edges[j][1]] > 0) {
                    if (--deg[edges[j][1]] == 1) nextLeaves[nlCount++] = edges[j][1];
                } else if (edges[j][1] == leaf && deg[edges[j][0]] > 0) {
                    if (--deg[edges[j][0]] == 1) nextLeaves[nlCount++] = edges[j][0];
                }
            }
        }
        free(leaves);
        leaves = nextLeaves;
        lCount = nlCount;
    }

    *returnSize = lCount;
    free(deg);
    return leaves;
}