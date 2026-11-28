#include <stdio.h>
int nums[32], cur[32];
void gen_subseq(int n, int idx, int cur_len) {
    if (idx == n) {
        for (int i = 0; i < cur_len; i++) {
            printf("%d%s", cur[i], i == cur_len - 1 ? "" : " ");
        }
        printf("\n");
        return;
    }
    gen_subseq(n, idx + 1, cur_len);
    cur[cur_len] = nums[idx];
    gen_subseq(n, idx + 1, cur_len + 1);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        gen_subseq(n, 0, 0);
    }
    return 0;
}