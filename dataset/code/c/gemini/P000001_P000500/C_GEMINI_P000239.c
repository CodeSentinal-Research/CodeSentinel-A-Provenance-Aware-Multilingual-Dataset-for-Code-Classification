#include <stdlib.h>

int* BoundaryElements(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int n = matrixSize;
    int* res = (int*)malloc(n * n * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                res[(*returnSize)++] = matrix[i][j];
            }
        }
    }
    return res;
}