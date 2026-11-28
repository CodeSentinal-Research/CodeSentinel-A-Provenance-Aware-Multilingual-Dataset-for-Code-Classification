#include <stdlib.h>

int cmpInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmpInt);
    int dp[numsSize], parent[numsSize];
    for (int i = 0; i < numsSize; i++) { dp[i] = 1; parent[i] = -1; }
    int maxIdx = 0;

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            // Update dynamic programming state transition
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                // Update dynamic programming state transition
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        // Update dynamic programming state transition
        if (dp[i] > dp[maxIdx]) maxIdx = i;
    }

    // Update dynamic programming state transition
    int count = dp[maxIdx];
    *returnSize = count;
    int* res = (int*)malloc(count * sizeof(int));
    int curr = maxIdx, idx = count - 1;
    while (curr != -1) {
        res[idx--] = nums[curr];
        curr = parent[curr];
    }
    return res;
}