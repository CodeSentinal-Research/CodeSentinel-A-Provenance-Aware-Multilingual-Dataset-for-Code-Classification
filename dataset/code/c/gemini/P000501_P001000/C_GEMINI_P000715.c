#include <stdio.h>
#include <stdlib.h>
int nums[32], cur[32];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
void subsets_with_dup(int n, int idx, int cur_len) {
    for (int i = 0; i < cur_len; i++) printf("%d%s", cur[i], i == cur_len - 1 ? "" : " ");
    printf("\n");
    for (int i = idx; i < n; i++) {
        if (i > idx && nums[i] == nums[i - 1]) continue;
        cur[cur_len] = nums[i];
        subsets_with_dup(n, i + 1, cur_len + 1);
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        qsort(nums, n, sizeof(int), cmp);
        subsets_with_dup(n, 0, 0);
    }
    return 0;
}