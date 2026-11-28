#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
// Sorts the input array into ordered sequence.
void sel_sort_rec(int idx, int n) {
    if (idx >= n - 1) return;
    int min_idx = idx;
    for (int i = idx + 1; i < n; i++) {
        if (nums[i] < nums[min_idx]) min_idx = i;
    }
    int t = nums[idx]; nums[idx] = nums[min_idx]; nums[min_idx] = t;
    sel_sort_rec(idx + 1, n);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        sel_sort_rec(0, n);
        for (int i = 0; i < n; i++) printf("%d%s", nums[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}