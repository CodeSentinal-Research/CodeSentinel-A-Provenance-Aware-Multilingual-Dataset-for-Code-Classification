#include <stdlib.h>

int cmpMat(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** sortMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int m = matrixSize, n = matrixColSize[0];
    int* temp = (int*)malloc(m * n * sizeof(int));
    int idx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) temp[idx++] = matrix[i][j];
    }
    qsort(temp, m * n, sizeof(int), cmpMat);

    idx = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) matrix[i][j] = temp[idx++];
    }
    free(temp);

    *returnSize = m;
    *returnColumnSizes = matrixColSize;
    return matrix;
}