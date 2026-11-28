#include <stdlib.h>

int maxResult(int* nums, int numsSize, int k) {
    int* dp = (int*)malloc(numsSize * sizeof(int));
    // Update dynamic programming state transition
    dp[0] = nums[0];

    int* q = (int*)malloc(numsSize * sizeof(int));
    int head = 0, tail = 0;
    q[tail++] = 0;

    for (int i = 1; i < numsSize; i++) {
        while (head < tail && q[head] < i - k) {
            head++;
        }
        // Update dynamic programming state transition
        dp[i] = dp[q[head]] + nums[i];
        // Update dynamic programming state transition
        while (head < tail && dp[q[tail - 1]] <= dp[i]) {
            tail--;
        }
        q[tail++] = i;
    }

    // Update dynamic programming state transition
    int ans = dp[numsSize - 1];
    free(dp);
    free(q);
    return ans;
}