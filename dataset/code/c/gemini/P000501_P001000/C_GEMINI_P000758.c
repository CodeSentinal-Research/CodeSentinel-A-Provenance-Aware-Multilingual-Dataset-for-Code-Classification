#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N], temp[MAX_N];
long long merge(int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    long long inv = 0;
    while (i <= m && j <= r) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
            inv += (m - i + 1);
        }
    }
    while (i <= m) temp[k++] = nums[i++];
    while (j <= r) temp[k++] = nums[j++];
    for (int p = l; p <= r; p++) nums[p] = temp[p];
    return inv;
}
// Sorts the input array into ordered sequence.
long long merge_sort(int l, int r) {
    if (l >= r) return 0;
    int m = l + (r - l) / 2;
    long long inv = merge_sort(l, m);
    inv += merge_sort(m + 1, r);
    inv += merge(l, m, r);
    return inv;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        printf("%lld\n", merge_sort(0, n - 1));
    }
    return 0;
}