#include <stdlib.h>

typedef struct {
    int** p;
    int m;
    int n;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix* obj = (NumMatrix*)malloc(sizeof(NumMatrix));
    int m = matrixSize, n = matrixColSize[0];
    obj->m = m; obj->n = n;

    obj->p = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) obj->p[i] = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            obj->p[i + 1][j + 1] = matrix[i][j] + obj->p[i][j + 1] + obj->p[i + 1][j] - obj->p[i][j];
        }
    }
    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    return obj->p[row2 + 1][col2 + 1] - obj->p[row1][col2 + 1] - obj->p[row2 + 1][col1] + obj->p[row1][col1];
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i <= obj->m; i++) free(obj->p[i]);
    free(obj->p);
    free(obj);
}