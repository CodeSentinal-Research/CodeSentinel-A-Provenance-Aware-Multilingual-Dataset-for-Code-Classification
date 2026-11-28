#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes) {
    int m = matSize, n = matColSize[0];
    int** p = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) p[i] = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            p[i + 1][j + 1] = mat[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
        }
    }

    int** res = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        res[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            int r1 = MAX(0, i - k), c1 = MAX(0, j - k);
            int r2 = MIN(m - 1, i + k), c2 = MIN(n - 1, j + k);
            res[i][j] = p[r2 + 1][c2 + 1] - p[r1][c2 + 1] - p[r2 + 1][c1] + p[r1][c1];
        }
    }

    for (int i = 0; i <= m; i++) free(p[i]);
    free(p);
    *returnSize = m;
    return res;
}