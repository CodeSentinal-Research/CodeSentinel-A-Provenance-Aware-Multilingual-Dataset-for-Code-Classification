#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

long long minDiffTug;

void backtrackTug(int* arr, int n, int idx, int count, long long curSum, long long totalSum, int halfSize) {
    if (count == halfSize) {
        long long diff = llabs(totalSum - 2 * curSum);
        if (diff < minDiffTug) minDiffTug = diff;
        return;
    }
    if (idx == n) return;

    backtrackTug(arr, n, idx + 1, count + 1, curSum + arr[idx], totalSum, halfSize);
    backtrackTug(arr, n, idx + 1, count, curSum, totalSum, halfSize);
}

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* arr = (int*)malloc(n * sizeof(int));
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            totalSum += arr[i];
        }
        minDiffTug = LLONG_MAX;
        backtrackTug(arr, n, 0, 0, 0, totalSum, n / 2);
        printf("%lld\n", minDiffTug);
        free(arr);
    }
    return 0;
}