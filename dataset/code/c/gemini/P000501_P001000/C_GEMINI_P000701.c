#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
int min_rec(int n, int idx) {
    if (idx == n - 1) return nums[idx];
    int r = min_rec(n, idx + 1);
    return (nums[idx] < r) ? nums[idx] : r;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        printf("%d\n", min_rec(n, 0));
    }
    return 0;
}