#include <stdio.h>
#include <stdbool.h>
int nums[32], cur[32];
bool find_one_subseq(int n, int idx, int cur_len, int cur_sum, int target) {
    if (idx == n) {
        if (cur_sum == target && cur_len > 0) {
            for (int i = 0; i < cur_len; i++) printf("%d%s", cur[i], i == cur_len - 1 ? "" : " ");
            printf("\n");
            return true;
        }
        return false;
    }
    cur[cur_len] = nums[idx];
    if (find_one_subseq(n, idx + 1, cur_len + 1, cur_sum + nums[idx], target)) return true;
    if (find_one_subseq(n, idx + 1, cur_len, cur_sum, target)) return true;
    return false;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int target; scanf("%d", &target);
        if (!find_one_subseq(n, 0, 0, 0, target)) {
            printf("-1\n");
        }
    }
    return 0;
}