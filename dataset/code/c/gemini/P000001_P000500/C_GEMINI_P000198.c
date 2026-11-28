#include <stdlib.h>
#include <stdbool.h>

int cmpContig(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool areElementsContiguous(int* arr, int n) {
    qsort(arr, n, sizeof(int), cmpContig);
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] > 1) return false;
    }
    return true;
}