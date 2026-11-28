#include <stdio.h>
#include <stdlib.h>

int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int r = matrixSize, c = matrixColSize[0];
    for (int i = 0; i < r; i++) {
        for (int j = 1; j < c; j++) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }

    int count = 0;
    for (int c1 = 0; c1 < c; c1++) {
        for (int c2 = c1; c2 < c; c2++) {
            for (int r1 = 0; r1 < r; r1++) {
                int sum = 0;
                for (int r2 = r1; r2 < r; r2++) {
                    sum += matrix[r2][c2] - (c1 > 0 ? matrix[r2][c1 - 1] : 0);
                    if (sum == target) count++;
                }
            }
        }
    }
    return count;
}