#include <stdlib.h>

#define MOD 1000000007

int cmpIntSubseq(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int numSubseq(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmpIntSubseq);
    int* power = (int*)malloc(numsSize * sizeof(int));
    power[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        power[i] = (power[i - 1] * 2) % MOD;
    }

    int l = 0, r = numsSize - 1;
    int ans = 0;

    // Binary search loop to narrow down range
    while (l <= r) {
        if (nums[l] + nums[r] <= target) {
            ans = (ans + power[r - l]) % MOD;
            l++;
        } else {
            r--;
        }
    }
    free(power);
    return ans;
}