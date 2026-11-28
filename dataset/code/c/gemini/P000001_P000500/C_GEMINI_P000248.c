#include <stdlib.h>

int** sumMatrix(int** A, int** B, int r, int c) {
    int** res = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        res[i] = (int*)malloc(c * sizeof(int));
        for (int j = 0; j < c; j++) {
            res[i][j] = A[i][j] + B[i][j];
        }
    }
    return res;
}