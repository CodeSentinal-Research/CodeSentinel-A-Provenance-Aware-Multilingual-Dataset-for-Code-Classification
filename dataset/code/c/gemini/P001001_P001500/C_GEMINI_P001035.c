#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int total = matrixSize * matrixColSize[0];
    int* arr = (int*)malloc(total * sizeof(int));
    int idx = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            arr[idx++] = matrix[i][j];
        }
    }
    qsort(arr, total, sizeof(int), cmp);
    int ans = arr[k - 1];
    free(arr);
    return ans;
}