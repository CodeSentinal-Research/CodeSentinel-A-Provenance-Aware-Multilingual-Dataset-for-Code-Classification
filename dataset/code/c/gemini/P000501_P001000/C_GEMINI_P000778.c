#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int nums[64], best_part[64], cur_part[64];
int min_diff = INT_MAX, best_size = 0;
void backtrack(int n, int idx, int count, int cur_sum, int total, int half) {
    if (count == half) {
        int diff = abs(total - 2 * cur_sum);
        if (diff < min_diff) {
            min_diff = diff;
            best_size = half;
            for (int i = 0; i < half; i++) best_part[i] = cur_part[i];
        }
        return;
    }
    if (idx == n || (half - count) > (n - idx)) return;
    cur_part[count] = nums[idx];
    backtrack(n, idx + 1, count + 1, cur_sum + nums[idx], total, half);
    backtrack(n, idx + 1, count, cur_sum, total, half);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int total = 0;
        for (int i = 0; i < n; i++) { scanf("%d", &nums[i]); total += nums[i]; }
        backtrack(n, 0, 0, 0, total, n / 2);
        printf("%d\n", min_diff);
        for (int i = 0; i < best_size; i++) printf("%d%s", best_part[i], i == best_size - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}