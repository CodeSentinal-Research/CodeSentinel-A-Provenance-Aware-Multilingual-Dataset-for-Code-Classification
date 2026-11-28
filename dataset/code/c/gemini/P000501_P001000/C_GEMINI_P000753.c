#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int nums[32], cur[32];
typedef struct { int arr[32]; int len; } Subseq;
Subseq res[1024];
int res_cnt = 0;
int cmp(const void* a, const void* b) {
    Subseq* s1 = (Subseq*)a; Subseq* s2 = (Subseq*)b;
    int min_l = (s1->len < s2->len) ? s1->len : s2->len;
    for (int i = 0; i < min_l; i++) {
        if (s1->arr[i] != s2->arr[i]) return s1->arr[i] - s2->arr[i];
    }
    return s1->len - s2->len;
}
void find_all_subseq(int n, int idx, int cur_len, int cur_sum, int target) {
    if (idx == n) {
        if (cur_sum == target && cur_len > 0) {
            for (int i = 0; i < cur_len; i++) res[res_cnt].arr[i] = cur[i];
            res[res_cnt].len = cur_len;
            res_cnt++;
        }
        return;
    }
    find_all_subseq(n, idx + 1, cur_len, cur_sum, target);
    cur[cur_len] = nums[idx];
    find_all_subseq(n, idx + 1, cur_len + 1, cur_sum + nums[idx], target);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int target; scanf("%d", &target);
        find_all_subseq(n, 0, 0, 0, target);
        qsort(res, res_cnt, sizeof(res[0]), cmp);
        for (int i = 0; i < res_cnt; i++) {
            for (int j = 0; j < res[i].len; j++) printf("%d%s", res[i].arr[j], j == res[i].len - 1 ? "" : " ");
            printf("\n");
        }
    }
    return 0;
}