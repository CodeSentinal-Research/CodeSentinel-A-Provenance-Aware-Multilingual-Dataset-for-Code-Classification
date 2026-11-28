#include <stdlib.h>
#include <limits.h>
int cmpChoc(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int chocolateDistribution(int* nums, int n, int m) {
    if (m == 0 || n == 0) return 0;
    qsort(nums, n, sizeof(int), cmpChoc);
    if (m > n) return -1;
    int minDiff = INT_MAX;
    for (int i = 0; i <= n - m; i++) {
        int d = nums[i + m - 1] - nums[i];
        if (d < minDiff) minDiff = d;
    }
    return minDiff;
}
