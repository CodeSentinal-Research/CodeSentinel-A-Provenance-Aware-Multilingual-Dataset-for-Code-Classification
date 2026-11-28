#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 100005
int arr[MAX_N];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
bool canPlace(int* a, int n, int c, int dist) {
    int count = 1, last = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - last >= dist) {
            count++;
            last = a[i];
            if (count >= c) return true;
        }
    }
    return count >= c;
}
int main() {
    int n, c;
    if (scanf("%d %d", &n, &c) == 2) {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), cmp);
        int l = 1, r = arr[n - 1] - arr[0], ans = 1;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (canPlace(arr, n, c, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}