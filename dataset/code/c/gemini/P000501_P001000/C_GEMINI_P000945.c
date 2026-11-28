#include <stdbool.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool predictTheWinner(int* nums, int numsSize) {
    int* dp = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) dp[i] = nums[i];
    for (int i = numsSize - 2; i >= 0; i--) {
        for (int j = i + 1; j < numsSize; j++) {
            // Update dynamic programming state transition
            dp[j] = MAX(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
    }
    // Update dynamic programming state transition
    bool ans = dp[numsSize - 1] >= 0;
    free(dp);
    return ans;
}