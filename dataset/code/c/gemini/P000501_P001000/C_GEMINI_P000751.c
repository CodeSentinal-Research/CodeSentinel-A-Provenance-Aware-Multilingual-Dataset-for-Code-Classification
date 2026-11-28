#include <stdio.h>
int nums[32];
long long count_subseq_sum(int n, int idx, int cur_sum, int target) {
    if (idx == n) return (cur_sum == target ? 1 : 0);
    return count_subseq_sum(n, idx + 1, cur_sum, target) + count_subseq_sum(n, idx + 1, cur_sum + nums[idx], target);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int target; scanf("%d", &target);
        printf("%lld\n", count_subseq_sum(n, 0, 0, target));
    }
    return 0;
}