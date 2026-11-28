#include <stdlib.h>

int cmpFlatP000231(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** sortedMatrix(int N, int** Mat) {
    int* flat = (int*)malloc(N * N * sizeof(int));
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) flat[idx++] = Mat[i][j];
    }
    qsort(flat, N * N, sizeof(int), cmpFlatP000231);

    idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) Mat[i][j] = flat[idx++];
    }
    free(flat);
    return Mat;
}