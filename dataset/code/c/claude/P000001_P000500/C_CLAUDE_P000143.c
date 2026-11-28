#include <stdlib.h>
int** transpose(int** matrix, int m, int n) {
    int** res = (int**)malloc(n * sizeof(int*));
    for (int j = 0; j < n; j++) {
        res[j] = (int*)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) res[j][i] = matrix[i][j];
    }
    return res;
}
