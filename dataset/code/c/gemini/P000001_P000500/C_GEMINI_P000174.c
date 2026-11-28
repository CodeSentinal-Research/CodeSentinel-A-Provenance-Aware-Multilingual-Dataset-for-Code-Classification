#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmpMinDiff(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minDiff(int* arr, int n) {
    qsort(arr, n, sizeof(int), cmpMinDiff);
    int minDiff = INT_MAX;
    for (int i = 1; i < n; i++) {
        minDiff = MIN(minDiff, arr[i] - arr[i - 1]);
    }
    return minDiff;
}