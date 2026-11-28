#include <stdlib.h>

int cmpMed(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

double getMedian(int* arr1, int* arr2, int n) {
    int* merged = (int*)malloc(2 * n * sizeof(int));
    for (int i = 0; i < n; i++) merged[i] = arr1[i];
    for (int i = 0; i < n; i++) merged[n + i] = arr2[i];
    qsort(merged, 2 * n, sizeof(int), cmpMed);
    double ans = (merged[n - 1] + merged[n]) / 2.0;
    free(merged);
    return ans;
}