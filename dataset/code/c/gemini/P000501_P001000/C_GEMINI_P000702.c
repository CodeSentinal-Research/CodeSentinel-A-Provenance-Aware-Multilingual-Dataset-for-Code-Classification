#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
int count_occ_rec(int n, int target, int idx) {
    if (idx >= n) return 0;
    return (nums[idx] == target ? 1 : 0) + count_occ_rec(n, target, idx + 1);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int target; scanf("%d", &target);
        printf("%d\n", count_occ_rec(n, target, 0));
    }
    return 0;
}