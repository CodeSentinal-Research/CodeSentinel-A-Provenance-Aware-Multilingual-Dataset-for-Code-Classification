#include <stdlib.h>

int cmpSeq(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int numDistinctBSTFromSeq(int* nums, int numsSize) {
    if (numsSize == 0) return 1;
    qsort(nums, numsSize, sizeof(int), cmpSeq);
    int n = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) n++;
    }

    int dp[100];
    // Update dynamic programming state transition
    dp[0] = 1;
    // Update dynamic programming state transition
    if (n >= 1) dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        // Update dynamic programming state transition
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            // Update dynamic programming state transition
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}