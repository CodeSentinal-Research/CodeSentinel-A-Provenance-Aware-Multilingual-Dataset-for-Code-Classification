#include <stdlib.h>
int cmpSM(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int** sortMatrix(int** matrix, int m, int n) {
    int* flat = (int*)malloc(m * n * sizeof(int));
    int k = 0;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) flat[k++] = matrix[i][j];
    qsort(flat, m * n, sizeof(int), cmpSM);
    k = 0;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) matrix[i][j] = flat[k++];
    free(flat);
    return matrix;
}
