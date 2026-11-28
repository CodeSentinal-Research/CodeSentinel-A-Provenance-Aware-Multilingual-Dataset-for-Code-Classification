#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N], dp[MAX_N], q[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int k; scanf("%d", &k);
        int head = 0, tail = 0;
        int max_ans = -2000000000;
        for (int i = 0; i < n; i++) {
            while (head < tail && q[head] < i - k) head++;
            // Update dynamic programming state transition
            dp[i] = nums[i] + (head < tail && dp[q[head]] > 0 ? dp[q[head]] : 0);
            // Update dynamic programming state transition
            if (dp[i] > max_ans) max_ans = dp[i];
            // Update dynamic programming state transition
            while (head < tail && dp[q[tail - 1]] <= dp[i]) tail--;
            q[tail++] = i;
        }
        printf("%d\n", max_ans);
    }
    return 0;
}