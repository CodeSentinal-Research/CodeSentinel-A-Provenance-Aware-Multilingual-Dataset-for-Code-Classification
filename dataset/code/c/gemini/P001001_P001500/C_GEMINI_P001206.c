#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool predictTheWinner(int* nums, int numsSize) {
    int dp[numsSize];
    for (int i = 0; i < numsSize; i++) dp[i] = nums[i];

    for (int diff = 1; diff < numsSize; diff++) {
        for (int i = 0; i < numsSize - diff; i++) {
            int j = i + diff;
            // Update dynamic programming state transition
            dp[i] = MAX(nums[i] - dp[i + 1], nums[j] - dp[i]);
        }
    }
    // Update dynamic programming state transition
    return dp[0] >= 0;
}