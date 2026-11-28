#include <stdio.h>
int nums[32], cur[32];
void find_subseq(int n, int idx, int cur_len) {
    if (cur_len >= 2) {
        for (int i = 0; i < cur_len; i++) printf("%d%s", cur[i], i == cur_len - 1 ? "" : " ");
        printf("\n");
    }
    int used[205] = {0};
    for (int i = idx; i < n; i++) {
        if ((cur_len == 0 || nums[i] >= cur[cur_len - 1]) && !used[nums[i] + 100]) {
            used[nums[i] + 100] = 1;
            cur[cur_len] = nums[i];
            find_subseq(n, i + 1, cur_len + 1);
        }
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        find_subseq(n, 0, 0);
    }
    return 0;
}