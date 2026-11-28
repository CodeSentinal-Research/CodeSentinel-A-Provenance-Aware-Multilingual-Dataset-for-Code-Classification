#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
// Sorts the input array into ordered sequence.
void quick_sort(int l, int r) {
    if (l >= r) return;
    int pivot = nums[r], p_idx = l;
    for (int i = l; i < r; i++) {
        if (nums[i] < pivot) {
            int t = nums[i]; nums[i] = nums[p_idx]; nums[p_idx] = t;
            p_idx++;
        }
    }
    int t = nums[p_idx]; nums[p_idx] = nums[r]; nums[r] = t;
    quick_sort(l, p_idx - 1);
    quick_sort(p_idx + 1, r);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        quick_sort(0, n - 1);
        for (int i = 0; i < n; i++) printf("%d%s", nums[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}