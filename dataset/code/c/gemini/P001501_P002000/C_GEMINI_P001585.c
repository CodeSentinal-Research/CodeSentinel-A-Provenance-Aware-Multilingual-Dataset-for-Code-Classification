#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cmpIntFreq(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxFrequency(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmpIntFreq);
    int l = 0, ans = 1;
    long long total = 0;

    for (int r = 0; r < numsSize; r++) {
        total += nums[r];
        while ((long long)nums[r] * (r - l + 1) - total > k) {
            total -= nums[l++];
        }
        ans = MAX(ans, r - l + 1);
    }
    return ans;
}