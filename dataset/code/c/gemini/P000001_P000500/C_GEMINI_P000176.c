#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cmpChoc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long findMinDiff(int* a, int n, int m) {
    if (m == 0 || n == 0 || m > n) return 0;
    qsort(a, n, sizeof(int), cmpChoc);
    long long minDiff = LLONG_MAX;
    for (int i = 0; i <= n - m; i++) {
        long long diff = (long long)a[i + m - 1] - a[i];
        minDiff = MIN(minDiff, diff);
    }
    return minDiff;
}