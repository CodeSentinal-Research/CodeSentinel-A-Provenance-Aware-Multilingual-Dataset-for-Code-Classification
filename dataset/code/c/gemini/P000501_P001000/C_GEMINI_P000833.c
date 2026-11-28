#include <stdio.h>

long long findPages(const int arr[], int n, int k) {
    if (k > n) return -1;
    long long left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > left) left = arr[i];
        right += arr[i];
    }
    long long ans = -1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        long long mid = left + (right - left) / 2;
        int students = 1;
        long long pages = 0;
        for (int i = 0; i < n; i++) {
            if (pages + arr[i] > mid) {
                students++;
                pages = arr[i];
            } else {
                pages += arr[i];
            }
        }
        if (students <= k) {
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
        printf("%lld\n", findPages(arr, n, k));
    }
    return 0;
}