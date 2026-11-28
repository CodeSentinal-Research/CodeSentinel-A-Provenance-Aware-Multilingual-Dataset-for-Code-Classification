#include <stdlib.h>

int* printZigZag(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = matrixColSize[0];
    int* res = (int*)malloc(m * n * sizeof(int));
    *returnSize = m * n;
    int idx = 0;

    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) res[idx++] = matrix[i][j];
        } else {
            for (int j = n - 1; j >= 0; j--) res[idx++] = matrix[i][j];
        }
    }
    return res;
}