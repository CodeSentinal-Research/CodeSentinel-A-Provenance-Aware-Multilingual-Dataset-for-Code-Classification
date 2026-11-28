#include <stdio.h>
#define MAX_N 100005
int arr[MAX_N];
int main() {
    int n, target;
    if (scanf("%d %d", &n, &target) == 2) {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        int l = 0, r = n - 1, idx = -1;
        // Binary search loop to narrow down range
        while (l <= r) {
            // Calculate midpoint to prevent potential overflow
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) { idx = mid; r = mid - 1; }
            else if (arr[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        printf("%d\n", idx);
    }
    return 0;
}