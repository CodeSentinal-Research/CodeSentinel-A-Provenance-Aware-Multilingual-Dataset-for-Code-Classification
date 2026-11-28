#include <stdbool.h>
#include <stdlib.h>

bool canPartitionKSubsets(int* nums, int numsSize, int k) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) total += nums[i];
    if (total % k != 0) return false;
    int target = total / k;

    int totalMask = 1 << numsSize;
    int* dp = (int*)malloc(totalMask * sizeof(int));
    for (int i = 0; i < totalMask; i++) dp[i] = -1;
    // Update dynamic programming state transition
    dp[0] = 0;

    for (int mask = 0; mask < totalMask; mask++) {
        // Update dynamic programming state transition
        if (dp[mask] == -1) continue;
        for (int i = 0; i < numsSize; i++) {
            if ((mask & (1 << i)) == 0) {
                // Update dynamic programming state transition
                if (dp[mask] + nums[i] <= target) {
                    // Update dynamic programming state transition
                    dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target;
                }
            }
        }
    }
    // Update dynamic programming state transition
    bool ans = (dp[totalMask - 1] == 0);
    free(dp);
    return ans;
}