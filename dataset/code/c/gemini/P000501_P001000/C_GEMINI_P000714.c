#include <stdio.h>
#include <stdlib.h>
int nums[32], res[100000];
int r_cnt = 0;
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
void subset_sum(int n, int idx, int cur_sum) {
    if (idx == n) {
        res[r_cnt++] = cur_sum;
        return;
    }
    subset_sum(n, idx + 1, cur_sum);
    subset_sum(n, idx + 1, cur_sum + nums[idx]);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        subset_sum(n, 0, 0);
        qsort(res, r_cnt, sizeof(int), cmp);
        for (int i = 0; i < r_cnt; i++) printf("%d%s", res[i], i == r_cnt - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}