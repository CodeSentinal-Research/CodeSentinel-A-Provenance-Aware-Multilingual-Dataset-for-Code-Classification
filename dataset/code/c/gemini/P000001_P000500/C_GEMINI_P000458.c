#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100005
int arr[MAX_N];
bool canSplit(int* a, int n, int m, long long maxSum) {
    int count = 1;
    long long curr = 0;
    for (int i = 0; i < n; i++) {
        if (curr + a[i] > maxSum) { count++; curr = a[i]; }
        else curr += a[i];
    }
    return count <= m;
}
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) == 2) {
        long long sum = 0, max_v = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
            if (arr[i] > max_v) max_v = arr[i];
        }
        long long l = max_v, r = sum, ans = sum;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            long long mid = l + (r - l) / 2;
            if (canSplit(arr, n, m, mid)) { ans = mid; r = mid - 1; }
            else l = mid + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}