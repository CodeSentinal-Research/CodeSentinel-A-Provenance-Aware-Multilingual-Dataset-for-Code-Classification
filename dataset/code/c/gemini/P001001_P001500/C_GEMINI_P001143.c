#include <stdlib.h>
#include <math.h>

int findTargetSumWays(int* nums, int numsSize, int target) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) total += nums[i];
    if ((total + target) % 2 != 0 || total < abs(target)) return 0;
    int s1 = (total + target) / 2;
    int* dp = (int*)calloc(s1 + 1, sizeof(int));
    // Update dynamic programming state transition
    dp[0] = 1;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        for (int j = s1; j >= x; j--) {
            // Update dynamic programming state transition
            dp[j] += dp[j - x];
        }
    }
    // Update dynamic programming state transition
    int ans = dp[s1];
    free(dp);
    return ans;
}