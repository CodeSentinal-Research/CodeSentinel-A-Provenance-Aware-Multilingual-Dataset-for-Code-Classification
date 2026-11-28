#include <stdlib.h>

int** multiply(int** mat1, int mat1Size, int* mat1ColSize, int** mat2, int mat2Size, int* mat2ColSize, int* returnSize, int** returnColumnSizes) {
    int r1 = mat1Size, c1 = mat1ColSize[0];
    int c2 = mat2ColSize[0];
    *returnSize = r1;
    *returnColumnSizes = (int*)malloc(r1 * sizeof(int));
    int** res = (int**)malloc(r1 * sizeof(int*));
    for (int i = 0; i < r1; i++) {
        (*returnColumnSizes)[i] = c2;
        res[i] = (int*)calloc(c2, sizeof(int));
    }
    for (int i = 0; i < r1; i++) {
        for (int k = 0; k < c1; k++) {
            if (mat1[i][k] != 0) {
                for (int j = 0; j < c2; j++) {
                    if (mat2[k][j] != 0) {
                        res[i][j] += mat1[i][k] * mat2[k][j];
                    }
                }
            }
        }
    }
    return res;
}