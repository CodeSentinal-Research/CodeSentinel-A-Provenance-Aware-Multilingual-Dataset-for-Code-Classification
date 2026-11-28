#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
int last_occ_rec(int target, int l, int r, int ans) {
    if (l > r) return ans;
    // Calculate midpoint to prevent potential overflow
    int mid = l + (r - l) / 2;
    if (nums[mid] == target) return last_occ_rec(target, mid + 1, r, mid);
    if (nums[mid] > target) return last_occ_rec(target, l, mid - 1, ans);
    return last_occ_rec(target, mid + 1, r, ans);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int target; scanf("%d", &target);
        printf("%d\n", last_occ_rec(target, 0, n - 1, -1));
    }
    return 0;
}