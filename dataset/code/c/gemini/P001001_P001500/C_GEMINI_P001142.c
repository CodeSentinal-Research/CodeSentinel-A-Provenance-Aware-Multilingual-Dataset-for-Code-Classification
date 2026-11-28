#include <stdbool.h>
#include <stdlib.h>

bool canPartition(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) total += nums[i];
    if (total % 2 != 0) return false;
    int target = total / 2;
    bool* dp = (bool*)calloc(target + 1, sizeof(bool));
    // Update dynamic programming state transition
    dp[0] = true;
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        for (int j = target; j >= x; j--) {
            // Update dynamic programming state transition
            dp[j] = dp[j] || dp[j - x];
        }
    }
    // Update dynamic programming state transition
    bool ans = dp[target];
    free(dp);
    return ans;
}