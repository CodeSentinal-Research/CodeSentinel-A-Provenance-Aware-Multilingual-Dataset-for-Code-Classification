#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int aggressiveCows(int stalls[], int n, int k) {
    qsort(stalls, n, sizeof(int), cmp);
    int left = 1, right = stalls[n - 1] - stalls[0];
    int ans = 1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        int cows = 1, last = stalls[0];
        for (int i = 1; i < n; i++) {
            if (stalls[i] - last >= mid) {
                cows++;
                last = stalls[i];
            }
        }
        if (cows >= k) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2 && n > 0) {
        int stalls[n];
        for (int i = 0; i < n; i++) scanf("%d", &stalls[i]);
        printf("%d\n", aggressiveCows(stalls, n, k));
    }
    return 0;
}