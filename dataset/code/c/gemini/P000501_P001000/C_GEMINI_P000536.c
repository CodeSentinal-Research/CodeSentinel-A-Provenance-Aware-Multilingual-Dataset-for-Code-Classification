#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N], q[MAX_N];
long long dp[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int k;
        scanf("%d", &k);
        // Update dynamic programming state transition
        dp[0] = nums[0];
        int head = 0, tail = 0;
        q[tail++] = 0;
        for (int i = 1; i < n; i++) {
            while (head < tail && q[head] < i - k) head++;
            // Update dynamic programming state transition
            dp[i] = nums[i] + dp[q[head]];
            // Update dynamic programming state transition
            while (head < tail && dp[q[tail - 1]] <= dp[i]) tail--;
            q[tail++] = i;
        }
        printf("%lld\n", dp[n - 1]);
    }
    return 0;
}