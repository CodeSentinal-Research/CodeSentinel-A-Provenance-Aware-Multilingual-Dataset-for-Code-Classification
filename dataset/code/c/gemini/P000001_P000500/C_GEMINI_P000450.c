#include <stdio.h>
#define MAX_N 100005
int arr[MAX_N];
int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int l = 0, r = n - 1;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) l = mid + 1;
            else r = mid - 1;
        }
        printf("%d\n", l + k);
    }
    return 0;
}