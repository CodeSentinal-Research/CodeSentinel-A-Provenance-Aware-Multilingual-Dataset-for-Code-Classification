#include <stdio.h>
#include <stdlib.h>
int cands[64], cur[64];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
void comb_sum(int n, int target, int idx, int cur_len) {
    if (target == 0) {
        for (int i = 0; i < cur_len; i++) printf("%d%s", cur[i], i == cur_len - 1 ? "" : " ");
        printf("\n");
        return;
    }
    for (int i = idx; i < n; i++) {
        if (cands[i] > target) break;
        cur[cur_len] = cands[i];
        comb_sum(n, target - cands[i], i, cur_len + 1);
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &cands[i]);
        int target; scanf("%d", &target);
        qsort(cands, n, sizeof(int), cmp);
        comb_sum(n, target, 0, 0);
    }
    return 0;
}