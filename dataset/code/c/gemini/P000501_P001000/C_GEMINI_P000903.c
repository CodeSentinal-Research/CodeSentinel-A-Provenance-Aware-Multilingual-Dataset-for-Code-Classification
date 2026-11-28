#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int* parent = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        // Update dynamic programming state transition
        dp[i] = 1;
        parent[i] = -1;
    }
    int maxLen = 1, maxIdx = 0;
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            // Update dynamic programming state transition
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                // Update dynamic programming state transition
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            // Update dynamic programming state transition
            maxLen = dp[i];
            maxIdx = i;
        }
    }
    *returnSize = maxLen;
    int* res = (int*)malloc(maxLen * sizeof(int));
    int curr = maxIdx;
    for (int i = maxLen - 1; i >= 0; i--) {
        res[i] = nums[curr];
        curr = parent[curr];
    }
    free(dp);
    free(parent);
    return res;
}