#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int r = matrixSize, c = matrixColSize[0];
    *returnSize = c;
    *returnColumnSizes = (int*)malloc(c * sizeof(int));
    int** res = (int**)malloc(c * sizeof(int*));
    for (int j = 0; j < c; j++) {
        (*returnColumnSizes)[j] = r;
        res[j] = (int*)malloc(r * sizeof(int));
        for (int i = 0; i < r; i++) {
            res[j][i] = matrix[i][j];
        }
    }
    return res;
}