#include <stdlib.h>
int* diagonalElements(int** matrix, int n) {
    int* res = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) res[i] = matrix[i][i];
    return res;
}
