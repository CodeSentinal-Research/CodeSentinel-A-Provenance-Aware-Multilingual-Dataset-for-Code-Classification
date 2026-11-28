#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int* diagonalElements(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    int n = MIN(matrixSize, matrixColSize[0]);
    int* res = (int*)malloc(n * sizeof(int));
    *returnSize = n;
    for (int i = 0; i < n; i++) res[i] = matrix[i][i];
    return res;
}