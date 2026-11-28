#include <stdio.h>

long long paintersPartition(const int arr[], int n, int k) {
    long long left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > left) left = arr[i];
        right += arr[i];
    }
    long long ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        long long mid = left + (right - left) / 2;
        int painters = 1;
        long long curr = 0;
        for (int i = 0; i < n; i++) {
            if (curr + arr[i] > mid) {
                painters++;
                curr = arr[i];
            } else {
                curr += arr[i];
            }
        }
        if (painters <= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("%lld\n", paintersPartition(arr, n, k));
    }
    return 0;
}