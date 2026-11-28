#include <stdlib.h>

int cmpIntDiff2(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findPairs(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmpIntDiff2);
    int ans = 0;
    int l = 0, r = 1;

    while (l < numsSize && r < numsSize) {
        if (l == r || nums[r] - nums[l] < k) {
            r++;
        } else if (nums[r] - nums[l] > k) {
            l++;
        } else {
            ans++;
            l++;
            while (l < numsSize && nums[l] == nums[l - 1]) l++;
            r = l + 1;
        }
    }
    return ans;
}