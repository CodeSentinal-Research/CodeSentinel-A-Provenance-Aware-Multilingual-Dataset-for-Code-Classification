#include <stdlib.h>

int** multiplyMatrix(int** A, int** B, int r1, int c1, int r2, int c2) {
    if (c1 != r2) return NULL;
    int** res = (int**)malloc(r1 * sizeof(int*));

    for (int i = 0; i < r1; i++) {
        res[i] = (int*)calloc(c2, sizeof(int));
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return res;
}