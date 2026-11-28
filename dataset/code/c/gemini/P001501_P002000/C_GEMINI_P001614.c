#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int** mat = (int**)malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            mat[i] = (int*)malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) scanf("%d", &mat[i][j]);
        }

        int maxSum = INT_MIN;
        int* rowSum = (int*)malloc(m * sizeof(int));

        for (int left = 0; left < n; left++) {
            for (int i = 0; i < m; i++) rowSum[i] = 0;
            for (int right = left; right < n; right++) {
                for (int i = 0; i < m; i++) rowSum[i] += mat[i][right];

                int curMax = rowSum[0];
                int curSum = 0;
                for (int i = 0; i < m; i++) {
                    curSum = MAX(rowSum[i], curSum + rowSum[i]);
                    curMax = MAX(curMax, curSum);
                }
                maxSum = MAX(maxSum, curMax);
            }
        }

        printf("%d\n", maxSum);
        for (int i = 0; i < m; i++) free(mat[i]);
        free(mat);
        free(rowSum);
    }
    return 0;
}