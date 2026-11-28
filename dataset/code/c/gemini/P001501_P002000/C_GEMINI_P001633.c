#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSumSubmatrix(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int m = matrixSize, n = matrixColSize[0];
    int maxSum = INT_MIN;
    int* rowSum = (int*)malloc(m * sizeof(int));

    for (int l = 0; l < n; l++) {
        for (int i = 0; i < m; i++) rowSum[i] = 0;
        for (int r = l; r < n; r++) {
            for (int i = 0; i < m; i++) rowSum[i] += matrix[i][r];

            for (int i = 0; i < m; i++) {
                int cur = 0;
                for (int j = i; j < m; j++) {
                    cur += rowSum[j];
                    if (cur <= k) maxSum = MAX(maxSum, cur);
                }
            }
        }
    }
    free(rowSum);
    return maxSum;
}