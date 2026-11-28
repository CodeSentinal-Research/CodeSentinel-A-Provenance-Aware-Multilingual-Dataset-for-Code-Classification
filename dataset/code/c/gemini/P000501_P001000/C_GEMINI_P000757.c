#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N], temp[MAX_N];
void merge(int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else temp[k++] = nums[j++];
    }
    while (i <= m) temp[k++] = nums[i++];
    while (j <= r) temp[k++] = nums[j++];
    for (int p = l; p <= r; p++) nums[p] = temp[p];
}
// Sorts the input array into ordered sequence.
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    merge(l, m, r);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        merge_sort(0, n - 1);
        for (int i = 0; i < n; i++) printf("%d%s", nums[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}