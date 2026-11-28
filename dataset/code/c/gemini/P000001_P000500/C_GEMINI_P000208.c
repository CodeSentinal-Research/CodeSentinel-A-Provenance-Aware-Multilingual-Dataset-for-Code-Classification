#include <stdlib.h>

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    if (matSize == 0 || matColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    int m = matSize, n = matColSize[0];
    int* res = (int*)malloc(m * n * sizeof(int));
    *returnSize = m * n;
    int idx = 0;

    for (int d = 0; d < m + n - 1; d++) {
        int temp[10005];
        int tSize = 0;
        int r = (d < n ? 0 : d - n + 1);
        int c = (d < n ? d : n - 1);

        while (r < m && c >= 0) {
            temp[tSize++] = mat[r][c];
            r++;
            c--;
        }

        if (d % 2 == 0) {
            for (int i = tSize - 1; i >= 0; i--) res[idx++] = temp[i];
        } else {
            for (int i = 0; i < tSize; i++) res[idx++] = temp[i];
        }
    }
    return res;
}