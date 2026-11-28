#include <stdlib.h>

int** printFloydTriangle(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;  // write through pointer
    *returnColumnSizes = (int*)malloc(n * sizeof(int));  // write through pointer
    int** res = (int**)malloc(n * sizeof(int*));
    int num = 1;

    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = i + 1;
        res[i] = (int*)malloc((i + 1) * sizeof(int));
        for (int j = 0; j <= i; j++) {
            res[i][j] = num++;
        }
    }
    return res;
}
