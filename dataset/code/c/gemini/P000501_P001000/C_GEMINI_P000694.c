#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
// Performs search to locate target element within the given collection.
int bin_search_rec(int target, int l, int r) {
    if (l > r) return -1;
    // Calculate midpoint to prevent potential overflow
    int mid = l + (r - l) / 2;
    if (nums[mid] == target) return mid;
    if (nums[mid] > target) return bin_search_rec(target, l, mid - 1);
    return bin_search_rec(target, mid + 1, r);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int target; scanf("%d", &target);
        printf("%d\n", bin_search_rec(target, 0, n - 1));
    }
    return 0;
}